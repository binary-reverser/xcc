TARGET=compiler
CC=g++
SRCS=main.cpp \
	lexial.cpp
CFLAGS=-g -Wno-deprecated
INC=-I../include
OBJS=$(SRCS:.c=.o)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^
	rm $(OBJ) *~ -f

clean:
	rm $(TARGET) $(OBJS) *~ -f
