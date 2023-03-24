/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_loulou.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/24 23:18:24 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
