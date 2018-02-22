CILKTOOL_LIB_DIR = ~/cilktools/lib
CILKTOOL_INC_DIR = '~/cilktools/include ~/cilktools/cilksan'

CC = ~/tapir/src/build/bin/clang++
LD = $(CPP)

CFLAGS = -Wall -std=c++11 -O2 -g -ftapir -fcilkplus
LDFLAGS = -ldl -lcilkrts

ifeq ($(CILKSAN), 1)
  CFLAGS += -fsanitize=cilk
  LDFLAGS += -fsanitize=cilk -Wl,--as-needed -L $(CILKTOOL_LIB_DIR) -I $(CILKTOOL_INC_DIR) -Wl,-rpath,$(CILKTOOL_LIB_DIR) -lcilksan
endif

TARGET = demo.x
SRC = demo.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

clean::
	rm -f $(TARGET)
