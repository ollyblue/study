
BINS		:=list sort
INCLUDE		:=-I../
CXX			:=g++
CFLAGS		:=-g -Wall


all:$(BINS)

.cpp:
	$(CXX) $(CFLAGS) -o $* $*.cpp $(INCLUDE)

clean:
	rm -rf $(BINS)
