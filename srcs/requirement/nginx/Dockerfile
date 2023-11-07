FROM alpine:3.18
RUN apk update && apk upgrade && apk add nginx
COPY ./nginx.conf /etc/nginx/conf.d/nginx.conf.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]