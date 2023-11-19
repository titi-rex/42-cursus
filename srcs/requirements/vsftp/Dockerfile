FROM debian:11

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update -y --quiet && apt-get upgrade -y --quiet && apt-get install -y --quiet --no-install-recommends vsftpd

COPY conf/ftp.conf /etc/vsftpd.conf
COPY conf/vsftpd.userlist /etc/vsftpd.userlist

RUN mkdir -p /var/www/

RUN addgroup --system vsftp && adduser --system --group vsftp 
RUN chown -R vsftp:vsftp /etc/vsftpd.conf
RUN touch /var/log/vsftpd.log 
RUN chown vsftp:vsftp /var/log/vsftpd.log /var/www/

RUN adduser borys --disabled-password
RUN echo "borys:marvelpass" | /usr/sbin/chpasswd
RUN mkdir -p var/www/borys/
RUN chmod 550 var/www/borys/
RUN chown -R borys: var/www/borys/


USER vsftp

EXPOSE 7042

ENTRYPOINT ["vsftpd", "/etc/vsftpd.conf"]
