/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:33:32 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/09 16:50:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_bzero(void *s, size_t n);

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_mallocprotect(char *s1, char *s2);

int		ft_strchr(char *str, char c);
int		ft_strlen(char *str);

#endif
