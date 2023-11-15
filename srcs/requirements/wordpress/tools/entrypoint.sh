#!/bin/bash

if [ ! -f "/var/www/html/wordpress/wp-config.php " ];
then
	wp core download --allow-root --path="/var/www/html/wordpress" \
	&& wp config create --allow-root --path="/var/www/html/wordpress" --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_USER_PASSWORD --dbhost=$DB_HOST --dbprefix=wp_ \
	&& wp core install --allow-root --path="/var/www/html/wordpress" --url=$DOMAIN --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email \
	&& wp plugin update --allow-root --path="/var/www/html/wordpress" --all \
	&& wp theme install --allow-root --path="/var/www/html/wordpress" twentytwentythree --activate \
	&& wp user create --allow-root --path="/var/www/html/wordpress" $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD \
	&& chown www-data:www-data /var/www/html/wordpress/wp-content/uploads -R 
else
	echo "$(date '+%Y-%m-%d %H:%M:%S') Wordpress script end!" 
fi

/usr/sbin/php-fpm${PHP_VERSION} -F
