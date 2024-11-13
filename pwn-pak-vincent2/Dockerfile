FROM --platform=linux/amd64 ubuntu:22.04

RUN apt-get update && apt-get install -y \
    libc6 \
    socat \
    xinetd \
    wget \
    make \
    glibc-source \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -m challenge_user

WORKDIR /home/challenge_user

COPY /src/chall /home/challenge_user/chall
COPY /src/flag.txt /home/challenge_user/flag.txt
COPY xinetd.conf /etc/xinetd.d/pak-vincent-2

RUN chmod +x /home/challenge_user/chall
RUN chown -R challenge_user:challenge_user /home/challenge_user

EXPOSE 51234

CMD ["socat", "TCP-LISTEN:51234,reuseaddr,fork", "EXEC:/home/challenge_user/chall,pty,stderr"]
