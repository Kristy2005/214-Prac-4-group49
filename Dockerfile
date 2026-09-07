FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    make \
    gdb \
    valgrind \
    doxygen \
    graphviz \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

CMD ["bash", "-c", "make clean && make && ./taskforge"]
