FROM debian:11

RUN apt-get update -y --quiet && apt-get upgrade -y --quiet && apt-get install -y --quiet curl php php-fpm php-mysql mariadb-client 

ARG	PHP_VERSION

COPY conf/www.conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /tmp/

ADD https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar /usr/local/bin/wp
ADD https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php /var/www/html/wordpress/adminer.php 

RUN chmod +x /usr/local/bin/wp \
	&& chmod +r /var/www/html/wordpress/adminer.php \
	&& mkdir -p /run/php /var/www/html/wordpress 
	
WORKDIR /var/www/html/

EXPOSE 9000

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
