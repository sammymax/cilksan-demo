CC = ~/tapir/src/build/bin/clang++
LD = $(CPP)

CFLAGS = -Wall -std=c++11 -O1 -g -fcilkplus -fno-exceptions
LDFLAGS = -ldl -lcilkrts

ifeq ($(CILKSAN), 1)
  CFLAGS += -fsanitize=cilk
  LDFLAGS += -fsanitize=cilk
endif

TARGET = clear_test.x
SRC = clear_test.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

clean::
	rm -f $(TARGET)
