/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:02:37 by khuynh            #+#    #+#             */
/*   Updated: 2023/05/27 15:28:23 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(char const *s, const char *accept)
{
	const char	*ss;

	ss = s;
	while (*ss != 0 && ft_strchr(accept, *ss) == NULL)
		++ss;
	if (*ss == 0)
		ss = NULL;
	return ((char *)ss);
}
