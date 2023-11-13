FROM debian:11
RUN apt update -y && apt upgrade -y && apt install -y openssl nginx dumb-init
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
RUN ln -s /etc/nginx/sites-available/tlegrand.42.fr.conf /etc/nginx/sites-enabled/tlegrand.42.fr.conf 

EXPOSE 443

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["nginx", "-g", "daemon off;"]
