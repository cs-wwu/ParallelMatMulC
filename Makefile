CC=gcc
CPP=g++
CFLAGS=-g
CPPFLAGS=-g -std=c++11
DEPS =
OBJS = matmul.o main.o simplerand.o
TARGET = ./matmul
TESTOBJS = test/test_matmul.o
TESTTARGET = test_matmul

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

clean:
	rm -f *.o $(TARGET) test/test_matmul.o test_matmul

run: default
	./$(TARGET)

$(TESTTARGET): $(TESTOBJS) matmul.o
	$(CPP) -o $(TESTTARGET) $(TESTOBJS) matmul.o $(CPPFLAGS)

test: $(TESTTARGET)
	./$(TESTTARGET)
