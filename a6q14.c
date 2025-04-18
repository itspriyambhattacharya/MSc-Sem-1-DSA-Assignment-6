#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

// Append value to the end of a linked list
void appendNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Check if an array is already sorted
int isSorted(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) return 0;
    }
    return 1;
}

// Print a single subsequence
void printSubsequence(Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

// Merge all subsequences into array
void mergeSubsequences(Node** subseqs, int numSubseq, int* arr, int* index) {
    for (int i = 0; i < numSubseq; i++) {
        Node* curr = subseqs[i];
        while (curr) {
            arr[(*index)++] = curr->value;
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

// Recursive Sieve Sort
void sieveSort(int* arr, int n) {
    if (n <= 1 || isSorted(arr, n)) return;

    Node** subseqs = (Node**)calloc(n, sizeof(Node*)); // Use calloc for initialization
    int numSubseq = 0;

    // First sieve pass
    for (int i = 0; i < n; i++) {
        int placed = 0;
        for (int j = 0; j < numSubseq; j++) {
            Node* curr = subseqs[j];
            // Find the last node or a node where arr[i] can be inserted
            if (curr->value >= arr[i]) {
                // Insert at the beginning of the subsequence
                Node* newNode = createNode(arr[i]);
                newNode->next = subseqs[j];
                subseqs[j] = newNode;
                placed = 1;
                break;
            } else {
                // Traverse to find the correct position
                while (curr->next && curr->next->value < arr[i]) {
                    curr = curr->next;
                }
                if (!curr->next) {
                    // Append to the end
                    appendNode(&subseqs[j], arr[i]);
                    placed = 1;
                    break;
                } else {
                    // Insert in the middle
                    Node* newNode = createNode(arr[i]);
                    newNode->next = curr->next;
                    curr->next = newNode;
                    placed = 1;
                    break;
                }
            }
        }
        if (!placed) {
            subseqs[numSubseq] = createNode(arr[i]);
            numSubseq++;
        }
    }

    // Debug print
    printf("\nSubsequences at current level:\n");
    for (int i = 0; i < numSubseq; i++) {
        printf("S%d: ", i + 1);
        printSubsequence(subseqs[i]);
    }

    // Recursively sort each subsequence
    for (int i = 0; i < numSubseq; i++) {
        // Convert linked list to array
        int size = 0;
        Node* temp = subseqs[i];
        while (temp) {
            size++;
            temp = temp->next;
        }

        int* subArr = (int*)malloc(size * sizeof(int));
        temp = subseqs[i];
        for (int k = 0; k < size; k++) {
            subArr[k] = temp->value;
            temp = temp->next;
        }

        // Recursive sieve sort
        sieveSort(subArr, size);

        // Rebuild the list from sorted array
        temp = subseqs[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }

        subseqs[i] = NULL;
        for (int k = 0; k < size; k++) {
            appendNode(&subseqs[i], subArr[k]);
        }

        free(subArr);
    }

    // Merge all subsequences into original array
    int index = 0;
    mergeSubsequences(subseqs, numSubseq, arr, &index);

    free(subseqs);
}

// Print array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {6, 4, 1, 9, 5, 8, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    sieveSort(arr, n);

    printf("\nFinal sorted array:\n");
    printArray(arr, n);

    return 0;
}