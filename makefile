FrontDesk:
	g++ -g -std=c++11 Node.cpp Dequeue.cpp main.cpp -o FrontDesk

OBJECTS = Node.o Dequeue.o main.o
	  #(listing all of your object files here, separated by space)
HEADERS = Node.h Dequeue.h
	  #(listing all header files here, separated by spaces)

FrontDesk: $(OBJECTS)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -i *.o FrontDesk
