#include "main.h"
#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits with a specified code
 * @code: The exit code
 * @message: The error message to print
 */
void error_exit(int code, char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * cp - Copies the content of one file to another
 * @file_from: The name of the source file
 * @file_to: The name of the destination file
 */
void cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, r_status, w_status;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, dprintf("Error: Can't read from file %s", file_from));

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, dprintf("Error: Can't write to %s", file_to));

	while ((r_status = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w_status = write(fd_to, buffer, r_status);
		if (w_status != r_status)
			error_exit(99, dprintf("Error: Can't write to %s", file_to));
	}

	if (r_status == -1)
		error_exit(98, dprintf("Error: Can't read from file %s", file_from));

	if (close(fd_from) == -1)
		error_exit(100, dprintf("Error: Can't close fd %d", fd_from));

	if (close(fd_to) == -1)
		error_exit(100, dprintf("Error: Can't close fd %d", fd_to));
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 on success, otherwise an error code
 */
int main(int argc, char **argv)
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	cp(argv[1], argv[2]);

	return (0);
}
