# podman build -t hello-static .
# podman run --rm hello-static --noTLS
FROM scratch

COPY tocopy/cfg /default_config/cfg

# Copy the compiled binary
COPY build/hello_world /hello_world

# Set the startup command, allows to pass arguments
ENTRYPOINT ["/hello_world"] 