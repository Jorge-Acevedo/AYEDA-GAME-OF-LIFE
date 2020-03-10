CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-g -O2
LDFLAGS=-g -O2

CELL_SRS=include/Board_t.cc 
EXAMPLE_SRS=examples/FibonacciP.cpp examples/FibonacciS.cpp
MERGE_SRS=merge_sort/merge_sortP.cpp merge_sort/merge_sortS.cpp
QUICK_SRS=quick_sort/quick_sortP.cpp quick_sort/quick_sortS.cpp

SRCS=main.cpp $(FRAMEWORK_SRS) $(EXAMPLE_SRS) $(MERGE_SRS) $(QUICK_SRS)
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS) 

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .dependtool

include .depend
