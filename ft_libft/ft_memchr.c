/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 15:46:24 by kgajadie      #+#    #+#                 */
/*   Updated: 2021/03/04 20:24:29 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memchr() function locates the first occurrence of c (converted to an
unsigned char) in string s. */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return ((void *)&(s[i]));
		}
		i++;
	}
	return (0);
}
