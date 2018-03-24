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

//struct definition
typedef struct {
	int *arraylist;
	size_t size;
	size_t elemSoFar;
} Arraylist;

//function definitions
void add(Arraylist*, int);
Arraylist reverse(Arraylist*);
void init(Arraylist*);
void freeArraylist(Arraylist*);

//main driver
int main() {
	//local declarations
  	Arraylist list;
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
  	//reverse list
  	list = reverse(&list);
  	//print out elements
  	for (i = 0; i < 25; i++) {
  		printf("\nREVERSE:: Element: %d, at i = %d\n", list.arraylist[i], i);
  	}  	
  	//free up the memory used for our arraylist
  	freeArraylist(&list);
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
	int i, limit = (*list).size-2;
	//initialize new reverselist
	init(&reverseList);
	//loop through from i = 0+kth and set size-kth element to it
	for(i = 0; i < (*list).size; i++) {
		add(&reverseList, (*list).arraylist[limit-i]);
	}
	freeArraylist(list); //free up old memory list and then return new reverselist
	return reverseList;
}

//init function will initialize and allocate memory for this arraylist
void init(Arraylist *list) {
	(*list).arraylist = (int *)malloc(sizeof(int));
	(*list).size = 1;
	(*list).elemSoFar = 0;
}

//free function will go through all obj of the array and clears/deletes them from memory to avoid leakages
void freeArraylist(Arraylist *list) {
	free((*list).arraylist);
	(*list).arraylist = NULL;
	(*list).arraylist = 0; (*list).size = 0;
}