#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * print_error - Prints error message to stderr and exits with status code 98
 * @msg: The error message to print
 */
void print_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd, bytes_read;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	bytes_read = read(fd, &elf_header, sizeof(elf_header));
	if (bytes_read == -1 || bytes_read != sizeof(elf_header))
		print_error("Error: Cannot read from file");

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
	    elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
	    elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
	    elf_header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", elf_header.e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n",
	       elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
	       elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
	       "Invalid class");
	printf("  Data:                              %s\n",
	       elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	       elf_header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
	       "Invalid data encoding");
	printf("  Version:                           %d (current)\n",
	       elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
	       elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
	       elf_header.e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
	       elf_header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
	       elf_header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
	       "Unknown");
	printf("  ABI Version:                       %d\n",
	       elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
	       elf_header.e_type == ET_NONE ? "NONE (No file type)" :
	       elf_header.e_type == ET_REL ? "REL (Relocatable file)" :
	       elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" :
	       elf_header.e_type == ET_DYN ? "DYN (Shared object file)" :
	       elf_header.e_type == ET_CORE ? "
