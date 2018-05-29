CC = ~/tapir/src/build/bin/clang++
LD = $(CPP)

CFLAGS = -Wall -std=c++11 -O1 -g -fcilkplus -fno-exceptions
LDFLAGS = -L/efs/home/sunphil/tapir/src/build/lib/clang/6.0.0/lib/linux/ -ldl -lcilkrts -lclang_rt.csi-x86_64

ifeq ($(CILKSAN), 1)
  CFLAGS += -fsanitize=cilk
  LDFLAGS += -fsanitize=cilk
endif

TARGET = combinations.x
SRC = combinations.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

clean::
	rm -f $(TARGET)
