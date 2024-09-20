/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:51:13 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 10:59:20 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = s;
	while (n > 0)
	{
		*temp = (unsigned char)c;
		temp++;
		n--;
	}
	return (s);
}
/*
int main ()
{
char src[] = {'a', 'b'};
printf("char aray 'a', 'b'.\nmemset says: \n");
memset(src, -33, 1);
printf("%d, %c\n", src[0], src[0]);
printf("\n");

src[0] = 'a';
ft_memset(src, -33, 1);
printf("ft_memset says:\n%d, %c\n",  src[0], src[0]);

printf("\n\n int array 1,2\nmemset says:\n\n");

int src_int[] = {1, 2};

memset(src_int, -33, 1);
printf("%d, %c\n", src_int[0], src_int[0]);
src_int[0] = 1;
ft_memset(src_int, -33, 1);

printf("ft_memset says:\n%d, %c\n", src_int[0], src_int[0]);



printf("\n\nunsigned char array 123,234.\nmemset says:\n\n");

unsigned char src_un[] = {123, 234};

memset(src_un, -33, 1);
printf("%d, %c\n", src_un[0], src_un[0]);
src_int[0] = 123;
ft_memset(src_un, -33, 1);

printf("and ft_memset says:\n%d, %c\n", src_un[0], src_un[0]);
return 0;
}
*/