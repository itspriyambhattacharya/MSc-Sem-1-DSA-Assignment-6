#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

void initializeMatrix(int a[MAX][MAX], int v){
	int i, j; // loop 
	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++){
			a[i][j] = 0;
		}
	}
}

void displayMatrix(int a[MAX][MAX], int v){
	int i, j; // loop
	
	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void display(int arr[], int n){
	int i;
	
	for(i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void createMatrix(int a[MAX][MAX], int arr[], int n){
	int i, j; // loop
	
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(arr[j] >= arr[i]){
				a[i][j] = 1;
				a[j][i] = -1;
			}
		}
	}
}

int *graphSort(int a[MAX][MAX], int *arr, int *n, int nc, int *src, int *sorted, int *sortedIdx){
	int i, j; // loop
	int srcIdx = 0;
	int max = INT_MIN;
	
	initializeMatrix(a, nc);
	createMatrix(a, arr, nc);
	printf("\nThe adjacency matrix is:\n");
	displayMatrix(a, nc);
	
	// checking for rows that doesn't contain -1. Rows which contain -1 can't be source
	for(i = 0; i< nc; i++){
		int fl = 0;
		for(j = 0 ; j < nc; j++){
			if(a[i][j] == -1){
				fl = 1;
				break;
			}
		}
		if(fl == 0){
			src[srcIdx] = i;
			srcIdx++;
		}
	}
	
	printf("\nThe intermediate src array is:\n");
	display(src, srcIdx);
	
	for(i = 0; i< srcIdx; i++){
		if(src[i] > max){
			max = src[i];
		}
	}

	sorted[(*sortedIdx)++] = arr[max];
	
	for(i = max; i <nc-1; i++){
		arr[i] = arr[i+1];
	}
	
	arr = (int *)realloc(arr, (nc-1)*sizeof(int));
	*n = (*n) -1;
	
	printf("\nThe intermediate sorted array is:\n");
	display(sorted, *sortedIdx);
	
	return arr;
	
}

int main(void){
	int n; // number of elements to sort
	int i; //loop
	int *arr;
	int adj[MAX][MAX]; // adjacency matrix for graph
	int *src; // source array
	int *sorted; // sorted array
	int nCopy;
	int sortedIdx = 0;
	
	printf("\nEnter n:\t");
	scanf("%d",&n);
	
	arr = (int *)calloc(n, sizeof(int));
	
	printf("\nEnter elements in array to sort:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("\nThe unsorted array is:\n");
	display(arr, n);
	
	initializeMatrix(adj, n);
	
	src = (int *)calloc(n, sizeof(int));
	for(i = 0; i < n; i++){
		src[i] = INT_MIN;
	}
	sorted = (int *)calloc(n, sizeof(int));
	
	nCopy = n;
	for(i = 0; i < nCopy; i++){
		arr = graphSort(adj, arr, &n, n, src, sorted, &sortedIdx);
	}
	printf("\nThe sorted array is:\n");
	display(sorted, nCopy);
	
	free(arr);
	free(src);
	free(sorted);
	return 0;
}