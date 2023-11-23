FROM debian:11

RUN apt-get update -y --quiet && apt-get upgrade -y --quiet && apt-get install -y --quiet --no-install-recommends openssl nginx 

RUN openssl req -x509 -newkey rsa:2048 -nodes \
	-keyout /etc/ssl/tlegrand.42.fr.key \
	-out /etc/ssl/tlegrand.42.fr.cert \
	-subj "/C=FR/ST=France/L=Lyon/O=42/CN=tlegrand.42.fr"
#	req -x509 : demande certificat autosigne
# 	-newkey rsa:2048 : demande new key 
# 	-keyout et -out 	: fichier de soritr de la cle et du cert
#	-subj	: data pour le certificat
#	-nodes	: pas d'encryption de la cle

COPY conf/nginx.conf /etc/nginx/sites-available/tlegrand.42.fr.conf
COPY static/cv.html /srv/static/cv.html
COPY static/mainpage.html /srv/static/mainpage.html
COPY static/rush.css /srv/static/rush.css

RUN ln -s /etc/nginx/sites-available/tlegrand.42.fr.conf /etc/nginx/sites-enabled/tlegrand.42.fr.conf 

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
