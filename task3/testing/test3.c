// Quick sort
#include <stdio.h>

unsigned lfsr = 0xACE1u;
unsigned bit;
unsigned rand(){
    bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    return lfsr =  (lfsr >> 1) | (bit << 31);
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++){
        if (array[j] <= pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high){
    if (low < high){
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < 20; ++i) printf("%d  ", array[i]);
    printf("\n");
}

#define N 100
int data[N];

int main()
{
    for (int i = 0; i < N; ++i) data[i] = (int)(rand());

    printf("Unsorted Array\n");
    printArray(data, N);

    quickSort(data, 0, N - 1);

    printf("Sorted array in ascending order: \n");
    printArray(data, N);
    return 0;
}