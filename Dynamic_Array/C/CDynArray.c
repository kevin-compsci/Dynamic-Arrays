//Kevin Nguyen
//Basic program for C (C files) that implements a dynammic array for use. This array should act similar to an arraylist in java. 

/*
How to run (linux):
	1.) open command line and cd into directory folder of where this code is
	2.) type in "gcc *.c" to compile c files
	3.) type in "a.out" to run out file
*/

//include statements
#include <stdio.h>
#include <stdlib.h>

//struct definitions
typedef struct {
	int *arraylist;
	size_t size;
	size_t elemSoFar;
} Arraylist;

//function definitions
void add(Arraylist*, int);
Arraylist reverse(Arraylist*);
Arraylist sublist(Arraylist*, int, int);
size_t listSize(Arraylist*);
void init(Arraylist*);
void freeArraylist(Arraylist*);

//main driver
int main() {
	//local declarations
  	Arraylist list, subListA, subListB;
  	int i;
  	//initialize list and insert numbers into it
  	init(&list);
  	for (i = 0; i < 25; i++) {
  		add(&list, i);
  	}
   	//print out elements
  	for (i = 0; i < 25; i++) {
  		printf("ORIGINAL:: Element: %d, at i = %d\n", list.arraylist[i], i);
  	}  	
  	printf("\n"); //newline
  	subListA = sublist(&list, 0, (list.size/2));
  	//print out elements
  	for (i = 0; i < subListA.size; i++) {
  		printf("SublistA:: Element: %d, at i = %d\n", subListA.arraylist[i], i);
  	}
  	printf("\n"); //newline
  	subListB = sublist(&list, (list.size/2), list.size);
  	//print out elements
  	for (i = 0; i < subListB.size; i++) {
  		printf("SublistB:: Element: %d, at i = %d\n", subListB.arraylist[i], i);
  	}
  	//reverse list
  	list = reverse(&list);
  	printf("\n"); //newline
  	//print out elements
  	for (i = 0; i < 25; i++) {
  		printf("REVERSE:: Element: %d, at i = %d\n", list.arraylist[i], i);
  	}
  	//print out sizes of each arraylists
  	printf("\n");
  	printf("Size:: Arraylist size: %zu\n", listSize(&list));
  	printf("Size:: Sub-ArraylistA size: %zu\n", listSize(&subListA));
  	printf("Size:: Sub-ArraylistB size: %zu\n", listSize(&subListB));  	
  	//free up the memory used for our arraylist
  	freeArraylist(&list); freeArraylist(&subListA); freeArraylist(&subListB);
  	return 0;
}

//Functions implementations goes below
//add function will add an integer item to this arraylist of integers
void add(Arraylist *list, int newItem) {
	(*list).size = (*list).size + 1;
	(*list).arraylist = (int*)realloc((*list).arraylist, (*list).size * sizeof(int));
	(*list).arraylist[(*list).elemSoFar++] = newItem;
}

//reverse function will reverse the entire arraylist of elements. Return is struct type Arraylist.
Arraylist reverse(Arraylist *list) {
	//local declarations
	Arraylist reverseList;
	int i, limit = (*list).size-1;
	//initialize new reverselist
	init(&reverseList);
	//loop through from i = 0+kth and set size-kth element to it
	for(i = 0; i < (*list).size; i++) {
		add(&reverseList, (*list).arraylist[limit-i]);
	}
	freeArraylist(list); //free up old memory list and then return new reverselist
	return reverseList;
}

//sublist function will take in arguments of the list and ranges (start to finish) and return a subset of the array
Arraylist sublist(Arraylist *list, int start, int end) {
	//local declarations
	Arraylist sublist;
	int i;
	//initialize new reverselist
	init(&sublist);
	//loop through from and add list ith element to sublist ith position
	for(i = start; i < end; i++) {
		add(&sublist, (*list).arraylist[i]);
	}
	return sublist;
}

//size function will return the size of the arraylist
size_t listSize(Arraylist *list) {
	return (*list).size;
}

//init function will initialize and allocate memory for this arraylist
void init(Arraylist *list) {
	(*list).arraylist = (int *)malloc(sizeof(int));
	(*list).size = 0;
	(*list).elemSoFar = 0;
}

//free function will go through all obj of the array and clears/deletes them from memory to avoid leakages
void freeArraylist(Arraylist *list) {
	free((*list).arraylist);
	(*list).arraylist = NULL;
	(*list).arraylist = 0; (*list).size = 0;
}