FROM debian:12
RUN apt update -y && apt upgrade -y && apt install -y openssl nginx
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]