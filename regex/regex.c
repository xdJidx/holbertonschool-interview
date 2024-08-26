#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: the string to scan
 * @pattern: the regular expression pattern
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
	/* Base case: if the pattern is empty, check if the string is also empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if the first character of the pattern matches the first */
	/* character of the string*/
	if ((*str != '\0') && (*pattern == *str || *pattern == '.'))
	{
		/* If there's a '*' in the pattern */
		if (*(pattern + 1) == '*')
		{
			/* Consider the '*' as matching zero or more of the preceding character */
			return (regex_match(str, pattern + 2) ||
				(*str != '\0' && regex_match(str + 1, pattern)));
		}
		else
		{
			/* Proceed to the next character in both the string and pattern */
			return (regex_match(str + 1, pattern + 1));
		}
	}
	else if (*(pattern + 1) == '*')
	{
		/* Consider the '*' as matching zero of the preceding character */
		return (regex_match(str, pattern + 2));
	}

	return (0);
}
