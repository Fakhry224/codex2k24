# Use a lightweight base image
FROM debian:latest

# Install necessary tools
RUN apt-get update && \
    apt-get install -y socat && \
    rm -rf /var/lib/apt/lists/*

# Copy the binary and set permissions
WORKDIR /challenge
COPY /src/vuln /challenge/vuln
RUN chmod +x /challenge/vuln 

# Expose the application on port 3333 using socat
CMD ["socat", "TCP-LISTEN:1212,reuseaddr,fork", "EXEC:/challenge/vuln,pty,stderr"]