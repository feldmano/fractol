/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:13:00 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/06 16:40:04 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static void	*ft_free(char **s1)
{
	if (*s1 != NULL)
	{
		free (*s1);
		*s1 = NULL;
	}
	return (NULL);
}

// trim_right is called if the output string from ft_stack contains 
// a newline character. It allocates memory for the characters 
// to the right of the newline, and points buffer[fd] to that memory.
static char	*trim_right(char **out)
{
	char	*temp;
	char	*newline;
	int		len;

	newline = ft_strchr(*out, '\n');
	len = ft_strlen(newline + 1);
	temp = ft_calloc(sizeof(char), len + 1);
	if (temp == NULL)
		return (ft_free(out), NULL);
	ft_strlcpy(temp, newline + 1, ft_strlen(newline + 1) + 1);
	return (temp);
}

// When trim_left is called, the output string is trimmed of all characters
// to the right of the newline, if it exists, as well as of any unused memory 
// that may have been created by ft_stack.
static char	*trim_left(char **out)
{
	char	*temp;
	char	*newline;
	int		len;

	newline = ft_strchr(*out, '\n');
	if (newline == NULL)
		len = ft_strlen(*out);
	else
		len = newline - *out + 1;
	temp = ft_calloc(sizeof(char), len + 1);
	if (temp == NULL)
		return (ft_free(out), NULL);
	ft_strlcpy(temp, *out, len + 1);
	ft_free(out);
	return (temp);
}

//	ft_stack reads from the file descriptor until bytes_read < BUFFER_SIZE
//  or else a newline is encountered. It returns a pointer to allocated memory
//  which contains a newline character, if it exists, or else the entire file.
char	*ft_stack(char **src, int fd)
{
	char	*temp;
	ssize_t	bytes_read;

	temp = ft_calloc(sizeof(char), ft_strlen(*src) + BUFFER_SIZE + 1);
	if (temp == NULL)
		return (ft_free(src), NULL);
	ft_strlcpy(temp, *src, ft_strlen(*src) + 1);
	bytes_read = read(fd, temp + ft_strlen(*src), BUFFER_SIZE);
	if (bytes_read == -1 || *temp == '\0')
		return (ft_free(src), ft_free (&temp), NULL);
	ft_free(src);
	if (ft_strchr(temp, '\n') != NULL || bytes_read < BUFFER_SIZE)
		return (temp);
	return (ft_stack(&temp, fd));
}

// ft_get_next_line draws from buffer if it exists, and calls ft_stack. 
// If ft_stack returns a string with a newline character, get_next_line 
//	allocates a new buffer, trims the out string, and then returns the trim.
//	Otherwise, it directly returns the out string.
char	*ft_get_next_line(int fd)
{
	static char		*buffer[1024];
	char			*out;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	out = buffer[fd];
	buffer[fd] = NULL;
	out = ft_stack(&out, fd);
	if (out == NULL)
		return (NULL);
	if (ft_strlen(ft_strchr(out, '\n')) > 1)
	{
		buffer[fd] = trim_right(&out);
		if (buffer[fd] == NULL)
			return (ft_free(&out), NULL);
	}
	out = trim_left(&out);
	if (out == NULL)
		return (ft_free(&buffer[fd]), NULL);
	return (out);
}
