#ifndef STATS_H
#define STATS_H

/**
 * This function returns the average over two integer numbers.
 *
 * @param a First number
 * @param b Second number
 * @returns The arithmetic mean of the two numbers
 */
float two_averages(int a, int b);

/**
 * This function returns the average of an array of integers. If
 * the array is empty (0), or array is NULL, the function should
 * return 0.0.
 *
 * @param array The integer array. If the array is empty or NULL,
 *              return 0.
 * @param array_len The length of the array
 * @returns The arithmetic mean of the numbers, or 0.0 if there
 *          was a problem.
 */
float array_averages(int *array, int array_len);

#endif
