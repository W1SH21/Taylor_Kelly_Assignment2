compile: main.o ItemType.o SortedLinkedList.o
	g++ -Wall -pedantic-errors -o main main.o ItemType.o SortedLinkedList.o

main.o: main.cpp ItemType.h SortedLinkedList.h ListNode.h
	g++ -Wall -pedantic-errors -c -g main.cpp

ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -pedantic-errors -c -g ItemType.cpp

SortedLinkedList.o: SortedLinkedList.cpp SortedLinkedList.h ListNode.h
	g++ -Wall -pedantic-errors -c -g SortedLinkedList.cpp

run: compile
	./main

clean:
	rm -f main
	rm -f *.o
