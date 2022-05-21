#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initialize_array(int* array) {
    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 10 + 1;
    }
}

void print_array(int* array) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void bubble_sort(int* array) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (array[j] < array[i]) {
                int aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            } 
        }
    }
}

int main() {
    int* array = (int*) malloc(sizeof(int) * SIZE);

    initialize_array(array);
    print_array(array);

    bubble_sort(array);
    print_array(array);

    return 0;
}
