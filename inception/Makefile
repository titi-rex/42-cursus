# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 19:52:12 by tlegrand          #+#    #+#              #
#    Updated: 2024/06/20 18:26:49 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COMPOSE	=	docker-compose -f src/compose.yml 


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
	@${COMPOSE} ps

volumes	:
		mkdir -p /home/${USER}/data/wordpress
		mkdir -p /home/${USER}/data/mariadb


.PHONY:	all re clean fclean up down prune ps data volumes

# docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q);
