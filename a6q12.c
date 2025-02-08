#include<stdio.h>
#include <stdlib.h>

void display(int arr[], int n){
	int i;
	for(i =0; i< n; i++){
		printf("%d\t", arr[i]);
	}
}

void shellSort(int *arr, int n){
	int gap;
	int i, j;
	
	for(gap = n/2; gap > 0; gap /= 2){
		for(i = 0; i< n-gap; i++){
			j = i+ gap;
			while(j >= gap && arr[j] < arr[j-gap]){
				int t = arr[j];
				arr[j] = arr[j-gap];
				arr[j-gap] = t;
				j -= gap;
			}
		}
		
		printf("\nGap = %d:\n", gap);
		display(arr, n);
	}
}

int main(void){
	int n; //size of array
	int i;
	int *arr; //array
	
	printf("\nEnter size of array:\t");
	scanf("%d", &n);
	
	arr = (int *)calloc(n, sizeof(int));
	
	printf("\nEnter elements in array:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("\nThe array is:\n");
	display(arr, n);
	
	shellSort(arr, n);
	printf("\nThe sorted array is:\n");
	display(arr, n);
	
	free(arr);
	return 0;
}
