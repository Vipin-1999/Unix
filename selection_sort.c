#include <stdio.h> 
#include <stdlib.h>

void swap(int *xp, int *yp)	  {
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int arr[], int n)	  { 
	int i, j, min_idx; 

	for (i = 0; i < n-1; i++) 	{ 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		swap(&arr[min_idx], &arr[i]); 
	} 
} 

void printArray(int arr[], int size)	  { 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main()	{

	int n;
	printf("Enter the value of n:\t");
	scanf("%d", &n);	

	int a1[n], a2[n], a3[n];
	for(int i = 0; i < n; i++)	{
		a1[i] = i + 1;
		a2[i] = n - i;
		a3[i] = rand() % n;
	} 

	printf("Unsorted random array\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", a3[i]);
	printf("\n");

	selectionSort(a1, n); 
	printf("Sorted array: \n"); 
	printArray(a1, n); 
	
	selectionSort(a2, n);
        printf("Sorted array: \n");
        printArray(a2, n);
	
	selectionSort(a3, n);
        printf("Sorted array: \n");
        printArray(a3, n); 

	return 0; 
} 

