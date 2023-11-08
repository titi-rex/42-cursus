FROM debian:12
RUN apt update -y && apt upgrade -y && apt install -y openssl nginx 
RUN openssl req -x509 -newkey rsa:2048 -nodes -keyout /etc/ssl/tlegrand.42.fr.key -out /etc/ssl/tlegrand.42.fr.cert -subj "/C=FR/ST=France/L=Lyon/O=42/CN=tlegrand.42.fr"
#	req -x509 : demande certificat autosigne
# 	-newkey rsa:2048 :demande new key 
# 	-keyout et -out 	:fichier de soritr de la cle et du cert
#	-subj	: data pour le certificat
#	-nodes	: pas d'encryption de la cle


COPY ./conf/localhost.conf /etc/nginx/sites-available/localhost.conf
RUN ln -s /etc/nginx/sites-available/localhost.conf /etc/nginx/sites-enabled/localhost.conf 

# COPY ./conf/default.conf /etc/nginx/conf.d/default.conf

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]