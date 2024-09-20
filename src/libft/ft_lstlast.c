/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 13:03:38 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/06 18:22:35 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	return (ptr);
}

// int main ()
// {
// 	t_list *first = ft_lstnew("alpha");
// 	t_list *second = ft_lstnew("beta");
// 	t_list *third = ft_lstnew("gamma");
// 	first -> next =	second;
// 	second -> next = third;
// 	ft_printf("[%s]", first -> next -> content); // should be "beta"
// 	ft_printf("[%s]", first -> next -> next -> content); // should be "gamma"
// // add front
// 	t_list *start = ft_lstnew("start");
// 	ft_lstadd_front(&first, start);
// 	ft_printf("[%s]", start -> next -> content); // should be "alpha"
// // fetch last
// 	ft_printf("[%s]", ft_lstlast(start) -> content); // should be "gamma:"

// // add back
// 	t_list *end = ft_lstnew("end");
// 	ft_lstadd_back(&first, end);
// 	ft_printf("[%s]", ft_lstlast(start) -> content); //should be "end"

// 	return (0);
// }
