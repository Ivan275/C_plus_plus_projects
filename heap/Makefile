
all: test 

test: test.o heap.o 
	g++ -o test test.o heap.o

test.o: test.cpp heap.h
	g++ -c test.cpp 
	      
heap.o: heap.cpp heap.h
	g++ -c heap.cpp

clean:
	rm -f test *.o  
