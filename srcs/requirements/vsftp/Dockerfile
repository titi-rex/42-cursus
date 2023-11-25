FROM debian:11

ARG FTP_USER
ARG FTP_PASS

RUN apt-get --quiet update -y \
	&& apt-get --quiet upgrade -y \
	&& apt-get --quiet install -y --no-install-recommends vsftpd

COPY conf/ftp.conf /etc/vsftpd.conf
# COPY conf/vsftpd.userlist /etc/vsftpd.userlist

RUN mkdir -p /var/www/

RUN adduser $FTP_USER --disabled-password
RUN echo "$FTP_USER:$FTP_PASS" | /usr/sbin/chpasswd &> /dev/null
RUN touch /var/log/vsftpd.log 
RUN chown -R $FTP_USER:$FTP_USER var/www/ /var/log/vsftpd.log 
RUN chmod +x /etc/vsftpd.conf



ENTRYPOINT ["vsftpd", "/etc/vsftpd.conf"]
