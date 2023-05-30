/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:06:34 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/30 07:27:40 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	copy = ft_calloc(i + 1, sizeof(char));
	if (!copy)
		return (0);
	j = 0;
	while (j < i)
	{
		copy[j] = s1[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

/*

#include <stdio.h>
#include<string.h>
int main() {
   char *str = "Kelly&Genny";
   char *result;
   result = ft_strdup(str);
   printf("The string : %s\n", result);
   return 0;
}
*/