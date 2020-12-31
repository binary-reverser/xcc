TARGET=compiler
CC=g++
SRCS=main.cpp \
	scanner.cpp \
	lexial.cpp
CFLAGS=-g -Wno-deprecated
INC=-I../include -I./include
OBJS=$(SRCS:.c=.o)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^
#	rm $(OBJ) *~ -f

clean:
	rm $(TARGET) $(OBJS) *~ -f
