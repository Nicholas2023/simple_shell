#include "alx.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _realloc - Reallocate a memory block using malloc and free
 * @ptr: A pointer to the previously allocated memory
 * @o_size: The size in bytes of the allocated space for ptr
 * @n_size: The size in bytes for the new memory block
 *
 * Return: A pointer if new_size == oldsize and rellocated mem
 */

void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (n_size == o_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * n_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < o_size && index < n_size; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (mem);
}


/**
 * _lineptr - Reassigns the lineptr cariable for _getline
 * @p_line: A buffer to store an input string
 * @n: The size of lineptr
 * @buffer: The string to assign to lineptr
 * @b: The size of buffer
 */

void _lineptr(char **p_line, size_t *n, char *buffer, size_t b)
{
	if (*p_line == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*p_line = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*p_line = buffer;
	}
	else
	{
		_strcpy(*p_line, buffer);
		free(buffer);
	}
}


/**
 * _getline - Reads input form the user stream
 * @p_line: A buffer to stre user input
 * @n: The size of lineptr
 * @stream: The stream to read from
 *
 * Return: The number of bytes read from user input
 */

ssize_t _getline(char **p_line, size_t *n, FILE *stream)
{
	static ssize_t inp;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (inp == 0)
		fflush(stream);
	else
		return (-1);
	inp = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && inp == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && inp != 0)
		{
			inp++;
			break;
		}

		if (inp >= 120)
			buffer = _realloc(buffer, inp, inp + 1);

		buffer[inp] = c;
		inp++;
	}
	buffer[inp] = '\0';

	_lineptr(p_line, n, buffer, inp);

	ret = inp;
	if (r != 0)
		inp = 0;
	return (ret);
}
