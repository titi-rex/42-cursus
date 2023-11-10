all:


fclean :
	docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q);docker network rm $(docker network ls -q) 2>/dev/null
	
	
docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q);docker network rm $(docker network ls -q) 2>/dev/null


if [ "127.0.0.1	iel-amra.42.fr" = "$(head -n1 /etc/hosts)" ]
then
    :
else
    sudo sed -i '1s/^/127.0.0.1	iel-amra.42.fr\n/' /etc/hosts
fi