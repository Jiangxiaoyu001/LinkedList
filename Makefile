CC=g++

CFLAGS:= -std=c++11 -g

LDFLAGS:=-shared -fPIC

SRCS=linkedMap.cpp

TARGET=linkMap

OBJS=$(SRCS:.cpp=.o)
 
EXEC=$(TARGET)
 


main:
	  $(CC) $(CFLAGS) $(SRCS) -o $(EXEC)

lib:
	  $(CC) -g $(CFLAGS) $(LDFLAGS) $(SRCS) -o $(EXEC)

clean:
	rm -rf $(OBJS)

