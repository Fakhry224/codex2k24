# Use Ubuntu 20.04 as the base image
FROM --platform=linux/amd64 ubuntu:22.04

# Install necessary tools, libraries, and QEMU for cross-architecture support
RUN apt-get update && \
    apt-get install -y socat libc6 && \
    rm -rf /var/lib/apt/lists/*

# Set working directory and copy the binary
WORKDIR /challenge
COPY /src/vuln /challenge/vuln
RUN chmod +x /challenge/vuln 

# Expose the application on port 1212 using socat
CMD ["socat", "TCP-LISTEN:1212,reuseaddr,fork", "EXEC:/challenge/vuln,pty,echo=0,raw"]
