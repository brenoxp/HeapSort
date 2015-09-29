all:	executable	clean

executable:	list.o	list_as_tree.o heap_sort.o	main.o
	gcc list.o list_as_tree.o heap_sort.o main.o -o heap -lm

main.o:	main.c
	gcc -c main.c

heap_sort.o: heap_sort.c	list.h	list_as_tree.h	heap_sort.h
	gcc -c heap_sort.c

list_as_tree.o: list_as_tree.c	list.h	list_as_tree.h
	gcc -c list_as_tree.c

list.o:	list.c	list.h
	gcc -c list.c


clean: 
	rm *.o
	clear
