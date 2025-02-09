Sorting Algorithms Repository

Overview

This repository contains implementations of three sorting algorithms in C:

Heap Sort

Shell Sort

Rkpian Graph Sort (A graph-based custom sorting technique)

Each algorithm is implemented as a standalone C program and demonstrates different approaches to sorting.

Implementations

1. Heap Sort

Heap Sort is an efficient, comparison-based sorting algorithm that utilizes a binary heap data structure.

File: heap_sort.c

Algorithm Steps:

Construct a max heap from the input array.

Extract the maximum element (root of the heap) and place it at the end of the array.

Reduce the heap size and rebuild the heap to maintain the max heap property.

Repeat until all elements are sorted.

Key Functions:

int* createHeap(int *arr, int n): Builds a max heap.

void rebuildHeap(int \*heap, int n): Maintains the heap property after extraction.

void display(int arr[], int n): Prints the array.

2. Shell Sort

Shell Sort is an optimization over Insertion Sort, using gap-based comparisons to improve efficiency.

File: shell_sort.c

Algorithm Steps:

Start with a large gap and reduce it over iterations.

Sort elements at each gap using Insertion Sort.

Continue reducing the gap until it becomes 1.

Key Functions:

void shellSort(int \*arr, int n): Implements the Shell Sort algorithm.

void display(int arr[], int n): Prints the array.

3. Rkpian Graph Sort

This is a graph-based sorting approach where elements are represented as nodes in a directed graph.

File: graph_sort.c

Algorithm Steps:

Construct an adjacency matrix where directed edges indicate relative ordering.

Identify source nodes (nodes with no incoming edges).

Extract and remove the largest source node iteratively to form the sorted array.

Key Functions:

void initializeMatrix(int a[MAX][MAX], int v): Initializes the adjacency matrix.

void createMatrix(int a[MAX][MAX], int arr[], int n): Creates the adjacency matrix based on element comparisons.

int* graphSort(int a[MAX][MAX], int *arr, int *n, int nc, int *src, int *sorted, int *sortedIdx): Implements the sorting process.

void displayMatrix(int a[MAX][MAX], int v): Prints the adjacency matrix.

void display(int arr[], int n): Prints the array.

Compilation & Execution

Each program can be compiled using gcc and executed in a terminal.

# Compile heap sort

gcc heap_sort.c -o heap_sort
./heap_sort

# Compile shell sort

gcc shell_sort.c -o shell_sort
./shell_sort

# Compile Rkpian Graph Sort

gcc graph_sort.c -o graph_sort
./graph_sort

Example Usage

Heap Sort Input & Output:

Enter size of the array: 5
Enter elements in array: 10 50 20 60 30
The max heap is: 60 50 20 10 30
Sorted array: 10 20 30 50 60

Shell Sort Input & Output:

Enter size of the array: 5
Enter elements in array: 9 1 6 3 7
Gap = 2: 6 1 9 3 7
Gap = 1: 1 3 6 7 9
Sorted array: 1 3 6 7 9

Graph Sort Input & Output:

Enter n: 4
Enter elements in array to sort: 40 10 30 20
Adjacency Matrix:
0 1 1 1
-1 0 0 0
-1 0 0 1
-1 0 -1 0
Sorted array: 10 20 30 40

Memory Management

All implementations use dynamic memory allocation (malloc and calloc) to store arrays and matrices. Ensure proper memory cleanup using free().

License

This project is released under the MIT License.

Author

Developed by Priyam Bhattacharya.
