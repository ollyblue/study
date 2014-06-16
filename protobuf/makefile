

BIN		:=proto
CXX		:=g++
CPPFLAGS	:=-g -Wall
INCLUDE		:=-I/home/bluezheng/third-src/include
LIB			:=-L/home/bluezheng/third-src/lib -lprotobuf

SOURCES		:=addr.pb.cc main.cpp
OBJECTS		:=addr.pb.o main.o

all:$(BIN)


$(OBJECTS):$(SOURCES)
	$(CXX) $(CPPFLAGS) $(INCLUDE) -c $^

$(BIN):$(OBJECTS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LIB)

clean:
	rm -rf $(BIN) $(OBJECTS)
