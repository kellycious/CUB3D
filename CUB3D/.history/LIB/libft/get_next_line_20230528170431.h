/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:04:31 by fwong             #+#    #+#             */
/*   Updated: 2023/05/28 17:04:31 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>	

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_new_line(char *str);
size_t	ft_strlen1(const char *s);
char	*ft_free(char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*get_next_line(int fd);
char	*clear_line_from_stash(char *stash, char *buffer);

#endif
