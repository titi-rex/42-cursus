FROM debian:11

RUN apt-get --quiet update -y \
	&& apt-get --quiet upgrade -y \
	&& apt-get --quiet install -y --no-install-recommends redis

COPY conf/redis.conf /etc/redis/redis.conf

EXPOSE 6379

ENTRYPOINT ["redis-server", "--protected-mode", "no"]
