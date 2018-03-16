CILKTOOL_LIB_DIR = '/efs/home/sunphil/tapir/install/lib/clang/6.0.0/lib/linux'
CILKTOOL_INC_DIR = '/efs/home/sunphil/tapir/install/lib/clang/6.0.0/include'

CC = ~/tapir/install/bin/clang++
LD = $(CPP)

CFLAGS = -Wall -std=c++11 -O0 -g -fcilkplus
LDFLAGS = -ldl -lcilkrts

ifeq ($(CILKSAN), 1)
  CFLAGS += -fsanitize=cilk
  LDFLAGS += -fsanitize=cilk -Wl,--as-needed -L $(CILKTOOL_LIB_DIR) -I $(CILKTOOL_INC_DIR) -Wl,-rpath,$(CILKTOOL_LIB_DIR) -lclang_rt.cilksan-x86_64
endif

TARGET = demo.x
SRC = demo.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

clean::
	rm -f $(TARGET)
