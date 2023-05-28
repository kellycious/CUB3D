/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:53:36 by fwong             #+#    #+#             */
/*   Updated: 2023/05/28 12:55:09 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_not_closed_and_clean(t_map *map)
{
	ft_putstr_fd("Error\nMap not closed or invalid char in map!\n", 2);
	ft_clean(map, map->elements);
}