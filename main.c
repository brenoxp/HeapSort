/*

  Title: HeapSort implementation using list structure
  Autor: Breno Xavier Pinto
  Date: 09/25/2015

*/


#include <stdio.h>
#include <time.h>

#include "heap_sort.h"

int main(){  

	clock_t begin, end;
	double time_spent;

	int numbersArray[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	long int sizeNumbersArray = sizeof(numbersArray) / sizeof(int);

	List *list = createListWithArray(numbersArray, sizeNumbersArray);

	printf("Original List: \n");
	printList(list);

	
	begin = clock();
	heapSort(list);
	end = clock();

	printf("\n\nSorted List:\n");
	printList(list);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\nTime spent: %lf seconds\n", time_spent);

	deleteList(list);

	printf("\n");
	return 0;
}
