#include <stdio.h>
#include <stdlib.h>

int cnt;

int partition(int a[], int l, int r)	{

	int pivot = a[l], i = (l + 1), j = r, temp;

	while(1)	{
		
		while(i <= r && a[i] <= pivot)	  {
			cnt++;
			i++;
		}

		while(j >= l && a[j] > pivot)	  {
			cnt++;
			j--;
		}

		if(i >= j)
			break;
		
		else	{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

	}

	temp = a[l];
	a[l] = a[j];
	a[j] = temp;

	return j;

}

void quicksort(int a[], int l, int r)	{

	if(l < r)	{
		
		int (*part_func_ptr)(int *, int, int) = partition;
		int s = part_func_ptr(a, l, r);
		quicksort(a, l, s-1);
		quicksort(a, s+1, r);

	}

}

int main()	{
	
	char ch;

	do	{

		int n;
		printf("Enter the value of n: \t");
		scanf("%d", &n);

		void (*func_ptr)(int *, int, int) = quicksort;

		int a1[n], a2[n], a3[n];

		for(int i = 0; i < n; i++)	{

			a1[i] = i + 1;
			a2[i] = n - i;
			a3[i] = rand() % n;

		}

		cnt = 0;
		func_ptr(a1, 0, n-1);
		printf("Value of n for ascending array:%d \n", cnt);
	
		cnt = 0;
	        func_ptr(a2, 0, n-1);
        	printf("Value of n for descending array:%d \n", cnt);

		cnt = 0;
	        func_ptr(a3, 0, n-1);
	        printf("Value of n for random array:%d \n", cnt);

		printf("Do you want to try again? (Y/N)\t");
		scanf("%s", &ch);

	} while(ch == 'y' || ch == 'Y');

	return 0;
}
