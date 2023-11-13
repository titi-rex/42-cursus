FROM debian:11
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y curl dumb-init php php-fpm php-mysql mariadb-client 

ARG	PHP_VERSION

WORKDIR /var/www/html/

ADD https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar /usr/local/bin/wp
RUN chmod +x /usr/local/bin/wp \
	&& mkdir -p /run/php /var/www/html/wordpress

COPY conf/www.conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /tmp/

EXPOSE 9000

ENTRYPOINT  ["/usr/bin/dumb-init", "--"]
CMD  ["sh", "/tmp/entrypoint.sh"]



# RUN apk update && apk upgrade && apk add \
# wget php php-fpm php-phar php-opcache php-icon php-mysqli mariadb-client shadow

# ADD		https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar /usr/local/bin/wp
# RUN		chmod +x /usr/local/bin/wp

# php-fpm php-mysqli curl
