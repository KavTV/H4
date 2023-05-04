#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 16

int numbers[LEN];
int sortedNumbers[LEN];
void getRandomNumbers() {
	for (int i = 0; i < LEN; i++) {
		numbers[i] = rand();
		sortedNumbers[i] = i;
	}
}

void printTime(clock_t start, clock_t stop) {
	printf("Time-\t %d : %d : %d \n", ((stop - start) / 1000) / 60, ((stop - start) / 1000) % 60, (stop - start) % 1000);
}

// Selection-sort

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swapv2(int* x, int* y) {
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void selectionsort(int arr[], int n) {
	int minindex = 0;

	for (int i = 0; i < n - 1; i++) {

		minindex = i;
		for (int j = i+1; j < n; j++) {
			if (arr[j] < arr[minindex]) {
				minindex = j;
			}
		}

		if (minindex != i) {
			swap(&arr[minindex], &arr[i]);
		}
	}
}

void insertionSort(int arr[], int n) {
	int key;
	int j;

	for (int i = 0; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			swap(&arr[j], &arr[j + 1]);
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void merge(int* arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int i;
	int j;
	int k;

	int* left = malloc(n1 * sizeof(int));
	int* right = malloc(n2 * sizeof(int));


	for (i = 0; i < n1; i++)
		left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];


	i = 0; 
	j = 0;  
	k = l;  
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}


	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}

	free(left);
	free(right);
}

void mergeSort(int* arr, int l, int r) {
	if (l < r) {
		int middle = l + (r - l) / 2;

		mergeSort(arr, l, middle);
		mergeSort(arr, middle+1, r);

		merge(arr, l, middle, r);
	}
}

int main() {
	getRandomNumbers();
	int n = sizeof(numbers) / sizeof(numbers[0]);

	clock_t start, stop;

	//SELECITON
	start = clock();
	//selectionsort(numbers, n);
	stop = clock();
	start = start + (clock() - stop);
	printf("SELECTION SORT \n");
	printTime(start, stop);

	//INSERTION
	getRandomNumbers();
	start = clock();
	insertionSort(numbers, n);
	stop = clock();
	start = start + (clock() - stop);
	printf("INSERTION SORT \n");
	printTime(start, stop);

	//MERGE SORT
	getRandomNumbers();
	start = clock();
	//mergeSort(numbers, 0,  LEN - 1);
	stop = clock();

	start = start + (clock() - stop);
	printf("MERGE SORT \n");
	printTime(start, stop);
	//for (int i = 0; i < sizeof(numbers) / sizeof(numbers[1]); i++) {
	//	printf("%d\n", numbers[i]);
	//}




}