
TARGET		:=main
CC			:=gcc
CFLAGS		:=-g -Wall

.PHONY: all clean

INCLUDE		:=-I./
LIB			:=-lpthread

SOURCES		:=$(wildcard *.c)
OBJECTS		:=$(patsubst %.c,%.o,$(SOURCES))
#OBJECTS		:=	main.o	\
				thread_pool.o

all:$(TARGET)

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

$(TARGET):$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm -rf $(OBJECTS) $(TARGET)

