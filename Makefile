CC=gcc
CPP=g++
CFLAGS=-g
CPPFLAGS=-g -std=c++11
DEPS =
OBJS = matmul.o main.o simplerand.o
TARGET = ./matmul

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

clean:
	rm -f *.o $(TARGET) test/out

run: default
	./$(TARGET)
