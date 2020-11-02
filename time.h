#ifndef GET_TIME_H
#define GET_TIME_H

/**
 * the struct constructs two int variables
 * seconds and milliseconds. It returns a new
 * struct with seconds and milliseconds
 */
struct time {
};

/**
 * This function takes in two arguments of type int
 * where the first one is seconds while the second one is milli.
 * The function returns the time assigned.
 *
 */
struct time time_assign(int seconds, int milli);

/**
 * The function takes two time assigned and return the
 * difference of them
 */
int time_diff_in_milli(struct time t1, struct time t2);

#endif
