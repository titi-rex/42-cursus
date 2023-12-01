# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 19:52:12 by tlegrand          #+#    #+#              #
#    Updated: 2023/11/23 22:22:46 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COMPOSE	=	docker-compose -f srcs/compose.yml 


all	:	up

clean	:
		${COMPOSE} down --rmi all -v --remove-orphans

fclean	:	clean
		sudo rm -rf /home/${USER}/data/

re	:	fclean all


up 	:	volumes
	${COMPOSE} up -d --build
	
down:
	${COMPOSE} down 
	
top:
	${COMPOSE} top

logs:
	@echo "			**** LOGS ****"
	@echo "=========== mariadb ================"
	@docker logs mariadb
	@echo "=========== nginx ================"
	@docker logs nginx
	@echo "=========== wordpress ================"
	@docker logs wordpress
	@echo "=========== redis ================"
	@docker logs redis	

ps :
	@echo "=========== containers ================"
	@${COMPOSE} ps

volumes	:
		mkdir -p /home/${USER}/data/wordpress
		mkdir -p /home/${USER}/data/mariadb


.PHONY:	all re clean fclean up down prune ps data volumes

# docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q);
