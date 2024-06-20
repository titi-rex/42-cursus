/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:12 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/06 23:23:44 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*gnl_chr_nl(char *s);
size_t	gnl_strlcat(char *dst, char *src, size_t start);
char	*gnl_refresh(char *s_buff);
char	*gnl_expand(char *line, size_t *size);
char	*gnl_init(size_t *idx, size_t *size, int *n_read);

#endif