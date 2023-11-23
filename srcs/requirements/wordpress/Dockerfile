FROM debian:11

RUN apt-get --quiet update -y  \
	&& apt-get --quiet upgrade -y \
	&& apt-get --quiet install -y curl php php-fpm php-mysql mariadb-client 

ARG	PHP_VERSION

COPY conf/www.conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /tmp/

ADD https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar /usr/local/bin/wp
ADD https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php /var/www/wordpress/adminer.php 

RUN chmod +x /usr/local/bin/wp \
	&& chmod +r /var/www/wordpress/adminer.php \
	&& mkdir -p /run/php /var/www/wordpress 
	
WORKDIR /var/www/

EXPOSE 9000

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
