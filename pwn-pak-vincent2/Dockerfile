FROM --platform=linux/amd64 ubuntu:22.04

RUN apt-get update && \
    apt-get install -y socat libc6 && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /challenge
COPY /src/chall /challenge/chall
RUN chmod +x /challenge/chall

CMD ["socat", "TCP-LISTEN:12121,reuseaddr,fork", "EXEC:/challenge/chall,pty,echo=0,raw"]
