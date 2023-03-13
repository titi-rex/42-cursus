/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_varfd_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:05:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/13 19:47:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*			EXPERIEMENTAL VARFD LST			*/
int			*ft_varfd_acces_fd(t_varfd *varfd);
char		*ft_varfd_acces_varname(t_varfd *varfd);
t_varfd		*ft_varfd_new(char *varname, int fdcount);
void		ft_varfd_del(void *addr);
t_list		*ft_varfd_search(t_list *lst, char *name);
int			ft_varfd_get_value_from_key(t_line *line, char *name);

/*	structure storing fd called by a varname
	varname must be {name} format
	int is the fd linked
*/
typedef struct s_varfd
{
	char			*varname;
	int				fd;
}	t_varfd;

int	*ft_varfd_acces_fd(t_varfd *varfd)
{
	if (!varfd)
		return (NULL);
	return (&varfd->fd);
}

char	*ft_varfd_acces_varname(t_varfd *varfd)
{
	if (!varfd)
		return (NULL);
	return (varfd->varname);
}

t_varfd	*ft_varfd_new(char *varname, int fdcount)
{
	t_varfd	*new;

	new = ft_calloc(1, sizeof(t_varfd));
	if (!new)
		return (NULL);
	new->varname = ft_strdup(varname);
	if (!new->varname)
	{
		free(new);
		return (NULL);
	}
	new->fd = 10 + fdcount;
	return (new);
}

void	ft_varfd_del(void *addr)
{
	t_varfd	*varfd;

	varfd = addr;
	if (varfd->varname)
		free(varfd->varname);
	free(varfd);
}

void	s_init_varfd(t_varfd *varfd)
{
	varfd->varname = NULL;
	varfd->fd = 10;
}
