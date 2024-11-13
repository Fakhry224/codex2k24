FROM ubuntu:20.04

RUN echo "deb http://security.ubuntu.com/ubuntu jammy-security main" >> /etc/apt/sources.list
RUN apt-get update && apt-get install -y \
    libc6 \
    socat \
    xinetd \
    libc6-i386 \
    wget \
    make \
    glibc-source \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -m challenge_user

WORKDIR /home/challenge_user

COPY /src/chall /home/challenge_user/chall
COPY flag.txt /home/challenge_user/flag.txt
COPY xinetd.conf /etc/xinetd.d/balik_ke_perpus

RUN chmod +x /home/challenge_user/chall
RUN chown -R challenge_user:challenge_user /home/challenge_user

EXPOSE 51234

CMD ["socat", "TCP-LISTEN:51234,reuseaddr,fork", "EXEC:/home/challenge_user/chall,pty,stderr"]
