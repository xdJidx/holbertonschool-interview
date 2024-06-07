#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * print_error_and_exit - Prints an error message and exits with status 98
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * is_digit_string - Checks if a string is composed only of digits
 * @str: The string to check
 *
 * Return: 1 if the string is composed only of digits, 0 otherwise
 */
int is_digit_string(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * main - Entry point of the program
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	char command[1000];

	if (argc != 3)
	{
		print_error_and_exit();
	}

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit_string(num1) || !is_digit_string(num2))
	{
		print_error_and_exit();
	}

	snprintf(command, sizeof(command), "echo '%s * %s' | bc", num1, num2);
	system(command);

	return (0);
}
