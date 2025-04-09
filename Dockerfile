# podman build -t hello-static .
# podman run --rm hello-static --noTLS
FROM scratch

# Copy the compiled binary
COPY build/hello_world /hello_world

# Set the startup command, allows to pass arguments
ENTRYPOINT ["/hello_world"] 