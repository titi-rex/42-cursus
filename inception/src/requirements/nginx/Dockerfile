FROM debian:11

RUN apt-get --quiet update -y \
	&& apt-get --quiet upgrade -y \
	&& apt-get --quiet install -y --no-install-recommends nginx 

COPY conf/tlegrand.42.fr.cert /etc/ssl/tlegrand.42.fr.cert 
COPY conf/tlegrand.42.fr.key /etc/ssl/tlegrand.42.fr.key 

COPY conf/nginx.conf /etc/nginx/sites-available/tlegrand.42.fr.conf
COPY static/ /srv/static/

RUN ln -s /etc/nginx/sites-available/tlegrand.42.fr.conf /etc/nginx/sites-enabled/tlegrand.42.fr.conf 

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
