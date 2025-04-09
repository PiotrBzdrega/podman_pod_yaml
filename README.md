Goal: be able to add arguments from .yaml file or podman run command to pass them to ENTRY[] application

1. build cmake
2. podman build -t hello-static .
3a.podman run --rm hello-static --noTLS
3b. podman play kube pod.yaml
    podman pod logs hello-pod