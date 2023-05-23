/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:55:53 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/23 22:39:02 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
s:  The string on which to iterate.
f:  The function to apply to each character.

Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’. */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*my;
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	my = malloc(sizeof(char) * i + 1);
	if (!my)
		return (0);
	i = 0;
	while (s[i])
	{
		my[i] = (*f)(i, s[i]);
		i++;
	}
	my[i] = '\0';
	return (my);
}

/*
char	f(unsigned int i, char c)
{
    char str;
	
    str = c + 1;
    return (str);
}

#include <stdio.h>

int main()
{
    char str1[] = "abc";
    char* str2;
    str2 = ft_strmapi(str1, *f);
    printf("%s\n", str2);
}*/
