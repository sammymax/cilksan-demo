CILKTOOL_LIB_DIR = '/efs/home/sunphil/tapir/install/lib/clang/6.0.0/lib/linux'
CILKTOOL_INC_DIR = '/efs/home/sunphil/tapir/install/lib/clang/6.0.0/include'

CC = ~/tapir/src/build/bin/clang++
LD = $(CPP)

CFLAGS = -Wall -std=c++11 -O0 -g -fcilkplus
LDFLAGS = -ldl -lcilkrts

ifeq ($(CILKSAN), 1)
  CFLAGS += -fsanitize=cilk
  LDFLAGS += -fsanitize=cilk
endif

TARGET = demo.x
SRC = demo.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

clean::
	rm -f $(TARGET)
