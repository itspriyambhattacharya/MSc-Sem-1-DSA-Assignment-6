#include <stdio.h>
#include <stdlib.h>

int *createHeap(int *arr, int n){
	int *heap; // heap array
	int i, j; // loop
	
	heap = (int *)calloc(n, sizeof(int));
	
	for(i = 0; i< n; i++){
		*(heap + i) = *(arr+i);
		j = i;
		while(j > 0){
			int parent = (j-1)/2;
			if(heap[j] > heap[parent]){
				int temp = heap[j];
				heap[j] = heap[parent];
				heap[parent] = temp;
				j = parent;	
			}
			else{
				break;
			}
		}
	}
	
	return heap;
}

void rebuildHeap(int *heap, int n){
    int j = 0; // Start from the root
    int fl = 0; // Flag to indicate whether the heap is rebuilt

    while (fl == 0) {
        int lc = 2 * j + 1; // Left child index
        int rc = 2 * j + 2; // Right child index
        int largest = j;    // Assume current node is the largest

        // Check if left child exists and is larger
        if (lc < n && heap[lc] > heap[largest]) {
            largest = lc;
        }

        // Check if right child exists and is larger
        if (rc < n && heap[rc] > heap[largest]) {
            largest = rc;
        }

        // If the largest is not the current node, swap and continue
        if (largest != j) {
            int temp = heap[j];
            heap[j] = heap[largest];
            heap[largest] = temp;
            j = largest; // Move to the largest child
        } else {
            // Heap property is restored
            fl = 1;
        }
    }
}

void display(int arr[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d\t", *(arr + i));
	}
}

int main(void){
	int n; // size of array
	int i; // loop variable
	int *arr; // array to be created dynamically
	
	printf("\nEnter size of the array:\t");
	scanf("%d",&n);
	
	arr = (int *)calloc(n, sizeof(int));
	
	printf("\nEnter elements in array:\n");
	for(i = 0; i < n; i++){
		scanf("%d", (arr + i));
	}
	
	printf("\nThe array entered is:\n");
	display(arr, n);
	
	int *h1 = createHeap(arr, n);
	printf("\nThe max heap is:\n");
	display(h1, n);
	
	for(i= n-1; i >= 0; i--){
		int temp = h1[0];
        h1[0] = h1[i];
        h1[i] = temp;
		rebuildHeap(h1, i);
		
		printf("\nThe new heap is:\n");
	display(h1, n);
	}
	
	printf("\nThe sorted array is:\n");
	display(h1, n);
	
	free(arr);
	free(h1);
	return 0;
}