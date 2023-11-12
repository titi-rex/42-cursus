# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 19:52:12 by tlegrand          #+#    #+#              #
#    Updated: 2023/11/12 20:21:06 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COMPOSE	=	docker-compose -f srcs/compose.yml 


all:


up :	volumes
	${COMPOSE} up -d --build

down:
	${COMPOSE} down 

clean:
	${COMPOSE} down --rmi all -v --remove-orphans

ps :
	${COMPOSE} ps
	

volumes:
		mkdir -p /home/${USER}/data/wordpress
		mkdir -p /home/${USER}/data/mariadb








nginx-build	:
		docker build -t my_nginx srcs/requirements/nginx

db-build	:
	docker build  -t my_mariadb  srcs/requirements/mariadb

wp-build	:
		docker build -t my_wp srcs/requirements/wordpress



nginx-run	:	nginx-build
		docker run -p 8443:443 --rm --name nginx my_nginx

db-run	:	db-build
	docker run --env-file=srcs/.env --rm --name db my_db

wp-run	:	wp-build
		docker run --env-file=srcs/.env --rm --name wp my_wp




fclean :
	docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q);docker network rm $(docker network ls -q) 2>/dev/null 


# if [ "127.0.0.1	iel-amra.42.fr" = "$(head -n1 /etc/hosts)" ]
# then
#     :
# else
#     sudo sed -i '1s/^/127.0.0.1	iel-amra.42.fr\n/' /etc/hosts
# fi