// Cezar Batto

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Global
#define size 100000
long count = 0;
long counter= 0;

 
// Prototype for insertion sort
void insertion_sort(int *a, int n) {
	// For loop for sort
	for(size_t i = 1; i < n; ++i) {
		// Create a temp var which will take initial array
		int tmp = a[i];
		// size and count
		size_t j = i;					
		// Condition for values larger than 0 and if new array is less then temp
		while(j > 0 && tmp < a[j - 1]) {		
			a[j] = a[j - 1];
			// decrement for next value
			--j;					
		count++;
		}
		// swap
		a[j] = tmp;					
	}
	//return count;
}

// Prototype for merge sort
void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));			// Allocating required memory per sort
    for (i = 0, j = m, k = 0; k < n; k++) {		// compare two and output smallest one
    counter++;	
        x[k] = j == n      ? a[i++]			// and moves to next variable to be 
             : i == m      ? a[j++]			// compared with first leftover var
             : a[j] < a[i] ? a[j++]
             :               a[i++];

    }
    for (i = 0; i < n; i++){				// for loop to go to next val in either list
        a[i] = x[i];
    }

    //free(x);
    //return counter;
}
 
void merge_sort (int *a, int n){
	// for generated arrays of three or more vals
    	if (n < 2)						
        	return;
   	// Divide and conquer method  
    	int m = n / 2;	
	// Keeps dividing until reached single value to compare
    	merge_sort(a, m);					
    	merge_sort(a + m, n - m);
	// calls for merge prototype	
    	merge(a, n, m);					
    
}

// Start of Main
int main (){
	// declare variables
	int input;
	int i;
	// Input for desired sizes
	printf("Enter length of array: ");		
	scanf("%d", &input);
	
	printf("\n");
	
	int a[input];
	srand(0);
	// Rand to generate random arrays
	for (i = 0; i < input; i++)			
	{
    	a[i] = rand() % size + 1;
	}
	
    	int n = sizeof a / sizeof a[0];
    	printf("\n");

	//Output for original array
	printf("\n\nOriginal Unsorted Array: \n");
    	for (i = 0; i < n; i++)
        	printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
        
    	// Output for insertion sort
   	 printf("\n\n\nInsertion Sorted Array: \n\n");
    	// Insertion sort proto
    	insertion_sort(a, n);
    	for (i = 0; i < n; i++)
        	printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    
    	// Merge sort prototype
    	printf("\n\n\nMerge Sorted Array: \n\n");
    	merge_sort(a, n);
    	for (i = 0; i < n; i++)
        	printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    
    	printf("\n\n\nMerge Count: %ld", counter);
    	printf("\n\n\nInsertion Count: %ld\n", count);

    return 0;
}
