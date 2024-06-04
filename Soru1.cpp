#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void generateRandomArray(int *array, int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 1001;
    }
}

void copyArray(int *source, int *destination, int size) {
    for(int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void insertionSort(int *array, int size) {
    int key, j;
    for(int i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void selectionSort(int *array, int size) {
    int minIndex, temp;
    for(int i = 0; i < size - 1; i++) {
        minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

int main() {
    int originalArray[SIZE];
    int arrayToSort[SIZE];
    clock_t start, end;
    double insertionSortTime, selectionSortTime;

    srand(time(NULL));

    generateRandomArray(originalArray, SIZE);

    copyArray(originalArray, arrayToSort, SIZE);
    start = clock();
    insertionSort(arrayToSort, SIZE);
    end = clock();
    insertionSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    copyArray(originalArray, arrayToSort, SIZE);
    start = clock();
    selectionSort(arrayToSort, SIZE);
    end = clock();
    selectionSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Insertion Sort time: %f seconds\n", insertionSortTime);
    printf("Selection Sort time: %f seconds\n", selectionSortTime);

    return 0;
}
