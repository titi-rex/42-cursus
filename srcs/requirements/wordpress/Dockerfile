FROM debian:11
RUN apt-get update -y -q && apt-get upgrade -y -q && apt-get install -y -q curl php php-fpm php-mysql mariadb-client 

ARG	PHP_VERSION

WORKDIR /var/www/html/

ADD https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar /usr/local/bin/wp
RUN chmod +x /usr/local/bin/wp \
	&& mkdir -p /run/php /var/www/html/wordpress 

ADD https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php /var/www/html/wordpress/adminer.php 
RUN	chmod +r /var/www/html/wordpress/adminer.php
	

COPY conf/www.conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /tmp/

EXPOSE 9000

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
