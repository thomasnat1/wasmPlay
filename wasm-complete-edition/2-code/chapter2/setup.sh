#!/bin/bash

# Fetch emsdk image
docker pull robertaboukhalil/emsdk

# Create folder
mkdir ~/wasm
cd ~/wasm

# Create container
docker run \
    -d \
    -t \
    -p 12345:80 \
    --name wasm \
    --volume "$(pwd)":/src \
    robertaboukhalil/emsdk

# Enter container
docker exec -it wasm bash
