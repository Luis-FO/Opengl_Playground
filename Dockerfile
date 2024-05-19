FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    build-essential \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    freeglut3-dev \
    libx11-dev \
    x11-xserver-utils \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN make

CMD ["./RotatingSquare"]