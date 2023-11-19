# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 19:52:12 by tlegrand          #+#    #+#              #
#    Updated: 2023/11/19 22:15:20 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COMPOSE	=	docker-compose -f srcs/compose.yml 
COMPOSE_BONUS	=	docker-compose -f srcs/compose-bonus.yml 


all	:	up


up 	:	volumes
	${COMPOSE} up -d --build
	
down:
	${COMPOSE} down 

clean	:
		${COMPOSE} down --rmi all -v --remove-orphans

fclean	:	clean
		sudo rm -rf /home/${USER}/data/

re	:	fclean all


bonus:	volumes
	${COMPOSE_BONUS} up -d --build

bdown:
	${COMPOSE_BONUS} down 
	

logs:
	# @docker logs mariadb
	# @docker logs nginx
	@docker logs wordpress

ps :
	@echo "=========== containers ================"
	@${COMPOSE} ps
	@echo "============= volumes ================="
	@docker volume ls
	@echo "============== images ================="
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




# BONUS
build-ftp	:
	docker build -t ftptest srcs/bonus/ftp/

ftp-run	:	build-ftp
	docker run -d -p 7042:7042 --rm --name testftp ftptest

enter-ftp	:
	docker exec -it testftp /bin/bash




# MANDATORY
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

