# Use a lightweight base image
FROM debian:latest

# Install necessary tools
RUN apt-get update && \
    apt-get install -y socat && \
    rm -rf /var/lib/apt/lists/*

# Copy the binary and set permissions
WORKDIR /challenge
COPY vuln /challenge/vuln
COPY flag.txt /challenge/flag.txt
RUN chmod +x /challenge/vuln && chmod 444 /challenge/flag.txt

# Expose the application on port 3333 using socat
CMD ["socat", "TCP-LISTEN:33333,reuseaddr,fork", "EXEC:/challenge/vuln,pty,stderr"]