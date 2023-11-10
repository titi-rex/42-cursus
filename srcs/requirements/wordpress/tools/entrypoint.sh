#!/bin/bash

if [! -f "/var/www/html/wordpress/" ]; then
	wp core download --allow-root --path="/var/www/html/wordpress" 
	wp config create --allow-root --path="/var/www/html/wordpress" --skip-check --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=p$DB_USER_PASSWORD --dbhost=$DB_HOST 
	wp core install --allow-root --path="/var/www/html/wordpress" --url=$DOMAIN --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASS --admin_email=$WP_ADMIN_EMAIL --skip-email
	wp plugin update --allow-root --path="/var/www/html/wordpress" --all
	wp theme install --allow-root --path="/var/www/html/wordpress" inspiro --activate
	wp user create --allow-root --path="/var/www/html/wordpress" $WP_USER $WP_USER_EMAIL --user_pass+$WP_USER_PASS
	chown www:data:www-data /var/www/html/wordpress -R
fi

/usr/sbin/php-fpm8.2 -F
