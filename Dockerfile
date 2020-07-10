FROM i3thuan5/rime-taigi-testing-env:kati

#RUN apt-get update && apt-get install -y
WORKDIR /app
RUN git clone https://github.com/fcitx/fcitx
WORKDIR /app/fcitx
RUN apt-get update && apt-get install -y extra-cmake-modules libxkbcommon-dev libenchant-dev libxml2-dev iso-codes libxkbfile-dev libjson-c-dev qt4-default
RUN apt-get update && apt-get install -y libcairo2-dev

WORKDIR /app/fcitx/build
RUN cmake ..
RUN apt-get update && apt-get install -y curl
RUN make
RUN make install
