FROM debian:11
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y mariadb-server

RUN service mariadb start && mysql -u root -e \
	"CREATE DATABASE IF NOT EXISTS ${DB_NAME}; \
	ALTER USER 'root'@'localhost' IDENTIFIED BY 'root'; \
	CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_USER}'; \
	GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%'; \
	FLUSH PRIVILEGES;"

EXPOSE 3306

ENTRYPOINT ["mariadb", "--bind-address=0.0.0.0"]

