FROM debian:12
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y wget php php-fpm php-mysql php-mysqli mariadb-client 

WORKDIR /var/www/html/

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& wp core download --allow-root \
	&& wp config create --allow-root --skip-check --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=p$DB_USER_PASSWORD --dbhost=$DB_HOST \
	&& wp core install --allow-root --url=$DOMAIN --title=$WP_TITLE --admin_user=&WP_ADMIN --admin_password=$WP_ADMIN_PASS --admin_email=&WP_ADMIN_MAIL --skip-email



RUN sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php \
	&& sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php \
	&& sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php \
	&& sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php \
	&& mv wp-config-sample.php wp-config.php

RUN rm -rf /etc/php/7.4/fpm/pool.d/www.conf
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
RUN mkdir /run/php

EXPOSE 9000

ENTRYPOINT ["/usr/sbin/php-fpm7.4", "-F"]