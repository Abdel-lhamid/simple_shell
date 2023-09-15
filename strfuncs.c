#include "shell.h"


/**
 * _strlen - returns the size of string
 * @s: the string we want to calculate the lenght for
 * Return: the lenght of the string
 */

int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}

