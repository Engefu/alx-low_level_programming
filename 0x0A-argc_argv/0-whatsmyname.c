#include <stdio.h>
#include "main.h"
/**
* main - print name of program
* @argv: pointer to array of arguments
* @argc: is the  cou
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
if (argc > 0)
printf("%s\n", argv[0]);

return (0);
}
