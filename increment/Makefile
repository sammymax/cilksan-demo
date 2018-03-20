CC = ~/tapir/src/build/bin/clang++
LD = $(CPP)

CFLAGS = -Wall -std=c++11 -O0 -g -fcilkplus
LDFLAGS = -ldl -lcilkrts

ifeq ($(CILKSAN), 1)
  CFLAGS += -fsanitize=cilk
  LDFLAGS += -fsanitize=cilk
endif

TARGET = increment.x
SRC = increment.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

clean::
	rm -f $(TARGET)
