#include "stats.h" // Include user header file
#include <stdlib.h> // For NULL

float two_averages(int a, int b) {
    return (a + b) / 2.0;
}

float array_averages(int *array, int array_len) {
    if (array_len == 0 || array[0] == '\0') {return 0.0;}

    // Input is okay. Compute the actual average
    int sum = 0;

    for(int i = 0; i < array_len; i++) {sum += array[i];}
    return sum / (float)array_len;
}
