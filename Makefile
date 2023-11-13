# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 19:52:12 by tlegrand          #+#    #+#              #
#    Updated: 2023/11/13 19:41:40 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COMPOSE	=	docker-compose -f srcs/compose.yml 


all	:	up


up 	:	volumes
	${COMPOSE} up -d --build
	
down:
	${COMPOSE} down 

clean	:
		${COMPOSE} down --rmi all -v --remove-orphans

fclean	:	clean
		sudo rm -rf /home/${USER}/data/wordpress/*
		sudo rm -rf /home/${USER}/data/mariadb/*

re	:	fclean all

prune	:	fclean
		docker system prune -f

ps :
	@echo "=============================="
	@${COMPOSE} ps
	@echo "=============================="
	@docker volume ls
	@echo "=============================="
	@docker images
	@echo "=============================="
	
data:
	ls -l /home/${USER}/data/*
	

volumes	:
		mkdir -p /home/${USER}/data/wordpress
		mkdir -p /home/${USER}/data/mariadb

sclean:
	docker stop $(docker ps -qa); 
	docker rm $(docker ps -qa); 
	docker rmi -f $(docker images -qa); 
	docker volume rm $(docker volume ls -q);
	docker network rm $(docker network ls -q);

.PHONY:	all re clean fclean up down prune ps data volumes


nginx-build	:
		docker build -t my_nginx srcs/requirements/nginx

db-build	:
	docker build  -t my_mariadb  srcs/requirements/mariadb

wp-build	:
		docker build -t my_wp srcs/requirements/wordpress



nginx-run	:	nginx-build
		docker run -d -p 443:443 --rm --name nginx my_nginx

db-run	:	db-build
	docker run --env-file=srcs/.env --rm --name db my_db

wp-run	:	wp-build
		docker run --env-file=srcs/.env --rm --name wp my_wp

