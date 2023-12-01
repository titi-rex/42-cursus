#!/bin/bash

if [ ! -f "/var/www/wordpress/wp-config.php" ];
then
	# dwl and install wp
	wp core download --allow-root --path="/var/www/wordpress" 
	wp config create --allow-root --path="/var/www/wordpress" --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_USER_PASSWORD --dbhost=$DB_HOST --dbprefix=wp_ 
	wp core install --allow-root --path="/var/www/wordpress" --url=$DOMAIN --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email 
	wp user create --allow-root --path="/var/www/wordpress" $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD 
	chown www-data:www-data /var/www/wordpress/wp-content/uploads -R 
	# (bonus) setup wp for redis
	wp plugin install --allow-root --path="/var/www/wordpress" redis-cache --activate 
	wp config set --allow-root --path="/var/www/wordpress" WP_REDIS_HOST "redis"
	wp config set --allow-root --path="/var/www/wordpress" WP_REDIS_PORT "6379"
	wp config set --allow-root --path="/var/www/wordpress" WP_REDIS_DATABASE "0"
	wp config set --allow-root --path="/var/www/wordpress" WP_REDIS_TIMEOUT "1"
	wp config set --allow-root --path="/var/www/wordpress" WP_REDIS_READ_TIMEOUT "1"
	wp config set --allow-root --path="/var/www/wordpress" WP_REDIS_PREFIX "incep-redis"
	wp plugin update --allow-root --path="/var/www/wordpress" --all 
	wp redis enable --allow-root --path="/var/www/wordpress"
else
	echo "$(date '+%Y-%m-%d %H:%M:%S') Wordpress script end!" 
fi

/usr/sbin/php-fpm${PHP_VERSION} -F