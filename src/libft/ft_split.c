/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 20:21:30 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/22 19:21:11 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static void	ft_free(char **dbl_array)
{
	int	i;

	i = 0;
	while (dbl_array[i] != NULL)
	{
		free(dbl_array[i]);
		i++;
	}
	free(dbl_array);
}

static char	*ft_makestr(char *src, char c)
{
	char	*str;
	size_t	len;

	if (ft_strchr(src, c) == NULL)
		len = ft_strlen(src);
	else
		len = ft_strchr(src, c) - src;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, src, len + 1);
	return (str);
}

static const char	*ft_nextchar(const char *src, char c)
{
	while (*src != '\0' && *src != c)
		src++;
	return (src);
}

static size_t	ft_len(char const *src, char c)
{
	size_t	len;

	len = 0;
	if (*src == '\0')
		return (0);
	while (*src != '\0')
	{
		while (*src == c)
			src++;
		if (*src == '\0')
			break ;
		len++;
		src = ft_nextchar(src, c);
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;

	array = (char **)ft_calloc(ft_len(s, c) + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		array[i] = ft_makestr((char *)s, c);
		if (array[i] == NULL)
		{
			ft_free(array);
			return (NULL);
		}
		i++;
		s = ft_nextchar(s, c);
	}
	return (array);
}

// int	main()
// {

// 	char const *src = "wc -l";
// 	char spliter = ' ';
// 	char **a = ft_split(src, spliter);
// 	int i;
// 	i = 0;

// 	while (a[i] != NULL)
// 	{
// 		ft_printf("[%s]", a[i]);
// 		free(a[i]);
// 		i++;
// 	}
// 	ft_printf("[%s]", a[i]);
// 	free(a);
// 	return (0);
// }
