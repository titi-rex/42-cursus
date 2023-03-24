/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_loulou.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/24 22:52:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

//	"X  c #174544"
/*
char	*ft_get_color_value(char c, char **color_table)
{
	char	*ptr;
	char	*res;
	int		value;
	int		i;

	i = 0;
	while (color_table[i] && color_table[i][0] != c)
		i++;
	if (!color_table[i])
		return (NULL);
	ptr = ft_strchr(color_table[i], '#');
	if (!ptr)
		return (NULL);
	value = ft_atoi(ptr);
	return (res);
}
*/

char	*ft_get_color_std(char c)
{
	if (c == 'n')
		return (BLACK);
	if (c == 'r')
		return (RED);
	if (c == 'v')
		return (GREEN);
	if (c == 'y')
		return (YELLOW);
	if (c == 'b')
		return (BLUE);
	if (c == 'p')
		return (PURPLE);
	if (c == 'c')
		return (CYAN);
	if (c == 'g')
		return (GRAY);
	else
		return (NULL);
}


char	*ft_set_color(char c, char **color_table)
{
	char	*color;

	if (!color_table)
		return (ft_get_color_std(ft_tolower(c)));
	//color = ft_strjoin3("\001\033[38;5;", value, "m]\002");
	color = NULL;
	return (color);
}

int	ft_colorprint(char *str, char **color_table)
{
	char	*color;

	while (*str)
	{
		color = ft_set_color(*str, color_table);
		ft_putstr_fd(color, 1);
		if (*str != '\n' && *str != ' ')
			ft_putchar_fd('*', 1);
		else
			ft_putchar_fd(*str, 1);
		ft_putstr_fd(END, 1);
		str++;
	}
	ft_putchar('\n');
	(void)color_table;
	return (EXIT_SUCCESS);
}

static char	**bi_loulou_init_frame(void)
{
	char	**frame;

	frame = ft_calloc(10, sizeof(void *));
	if (!frame)
		return (perror("Error "), NULL);
	frame[0] = ft_strdup(\
"                         nccccnnccngncn           \n\
                      nggvpvcgnngcgggvgn          \n\
                     nrccgngccggcggggnnngn        \n\
                   ncrnnnnnnvpvcccgggnnncn        \n\
                  ncgggnggnncpcggnggnnnnnncn      \n\
                ncggngvppccgcpgnrrrrcggcggngn     \n\
               nncggncppppppppgnrrrrrggpvnnnggn   \n\
               ccnngppppppppppgnrrrrcggppcnncnc   \n\
             ncrnngcypppppppppcggcrrngcppcgnccn   \n\
             npgnncppppppppppprnngngnnyppcgggrg   \n\
            ngnnngnvppppppppppvnnnnnncppprgnccn   \n\
         nggggnnccgcpppppppppppvccnncvpppcnncvg   \n\
      nccrcngccvpprnrrccvpppppppppppppppvgncn     \n\
     nrcrgnncpppppycccggcccvppppppppppppcgncc     \n\
   ncggnnrppppppppppppppppppppppppppppppvgncc     \n\
  nrcnggcvppppppppppppppppppppppppppppppvgncn     \n\
gvygnnnrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrcgnnn     \n\
cncnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn      ");
frame[1] = ft_strdup("\
                ncpyngnnnnnnnnggcn                \n\
             nggcgggggcyyccccgggggggn             \n\
            ncvcgnngrppccrrrrrcnnnnvg             \n\
            ncnngcgnnngnnggngnnnnnnnnn            \n\
           gcnngvyyggcgngcrrcggggggngcn           \n\
           ncnrpypyyyyrnnrrrrrnrpyccnggcn         \n\
         gvcncyyyyyyyyrngrrrrrnryyyyygcvg         \n\
         nccncyyyyyyyycnggrrgngcyyyycngrg         \n\
         grnnpyyyyyyyyvgnggggnnvyyyycngrg         \n\
         grngvyyyyyyyyvygnnnggcvyyyyyggyg         \n\
         grnnpyyyyyyyyyppcrncyyyyyyycncnc         \n\
        gcgnncppvyyyyyyyyyyvvyyyyyyyvgncgn        \n\
      nggnnngvcggccccpyyyyyyyyyyyyyyycnncn        \n\
    ngggggccvyyvpppyycyyyyyyyyyyyyyyyccnnnrn      \n\
  ngngnncyyyyyyyyyyyyyyyyyyyyyyyyyyyyypcngngn     \n\
nrvcnngccypyyyyyypyypyyyyyyyyyyyyyyyyyyycnncc     \n\
gvcnnngvyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyycgngg     \n\
cncnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnng     ");
	return (frame);
}

int	bi_loulou(t_line *line)
{
	char			**frame;
	unsigned int	i;

	frame = bi_loulou_init_frame();
	if (!frame)
		return (EXIT_FAILURE);
	i = 0;
	while (i < 10)
	{
		printf(CLEAR CURSOR"\n");
		ft_colorprint(frame[i % 2], NULL);
		sleep(1);
		i++;
	}
	ft_free2d((void **)frame, 0);
	printf("\n");
	return (EXIT_SUCCESS);
	(void)line;
}
