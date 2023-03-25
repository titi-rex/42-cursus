/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_loulou.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/25 16:09:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

char	*ft_load_frame(char *pathname)
{
	char	*frame;
	int		fd;
	int		len;

	len = ft_file_size(pathname);
	dprintf(2, "size : %d\n", len);
	if (len == -1)
		return (NULL);
	if (len < 256)
		return (ft_putstr_fd("Error : picture too smol\n", 2), NULL);
	if (len > 14000)
		return (ft_putstr_fd("Error : picture too large\n", 2), NULL);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (perror("Error "), NULL);
	frame = ft_calloc(len, sizeof(char));
	if (!frame)
		return (perror("Error "), NULL);
	if (read(fd, frame, len) == -1)
		perror("Error ");
	close (fd);
	return (frame);
}

//	"frame/parrot_0.frame"
static char	**bi_loulou_init_frame(int len, char *pathname)
{
	char	**frame;
	char	*ptr;
	char	i;
	int		j;

	if (len > 10)
		return (ft_putstr_fd("Error : max 10 frame\n", 2), NULL);
	ptr = ft_strnstr(pathname, ".frame", ft_strlen(pathname));
	if (!ptr)
		return (ft_putstr_fd("Error : wrong file\n", 2), NULL);
	j = ft_strlen(pathname) - ft_strlen(ptr) - 1;
	frame = ft_calloc(len + 1, sizeof(void *));
	if (!frame)
		return (perror("Error "), NULL);
	i = 48;
	while (--len >= 0)
	{
		pathname[j] = i;
		dprintf(2, "%s\n", pathname);
		frame[len] = ft_load_frame(pathname);
		if (!frame[len])
		{
			ft_free2d((void **)frame, len);
			return (NULL);
		}
		i++;
	}
	return (frame);
}

int	bi_loulou(t_line *line)
{
	char	**frame;
	char	*pathname;
	int		i;
	int		pid;
	int		len;

	len = 2;
	pathname = ft_strdup("frame/parrot_0.frame");
	frame = bi_loulou_init_frame(len, pathname);
	free(pathname);
	if (!frame)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		return (perror("Error : "), EXIT_FAILURE);
	else if (pid == 0)
	{
		ft_sig_init(ft_sig_handler_loulou);
		i = 0;
		while (!(g_status & INTERRUPT))
		{
			printf(CLEAR CURSOR"\n");
			ft_colorprint(frame[i % len], NULL);
			sleep(1);
			i++;
		}
		ft_free2d((void **)frame, len);
		ft_clean_exit(line, EXIT_SUCCESS);
	}
	else
	{
		ft_free2d((void **)frame, len);
		wait(NULL);
		printf(CLEAR CURSOR"\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
