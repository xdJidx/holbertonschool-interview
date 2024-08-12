#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - Compares two strings and returns 1 if the strings can be
 *           considered identical, otherwise returns 0. The second string
 *           can contain the special character *.
 * @s1: The first string.
 * @s2: The second string which can contain the special character *.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);


	if (*s2 == '*' && *(s2 + 1) == '*')
		return (wildcmp(s1, s2 + 1));

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
