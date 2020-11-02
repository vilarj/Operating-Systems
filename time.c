#include "time.h"

struct time time_assign(int seconds, int milli) {
    // Make sure the milli field's invariants are satisfied
    // If the milli field is too large
    while(milli > 1000) {
        seconds += 1;
        milli -= 1000;
    }
    // If the milli field is too small
    while(milli < 0) {
        seconds -= 1;
        milli += 1000;
    }

    // The member variables values are correct, so assign them
    struct time new_time = {
            .seconds = seconds,
            .milli = milli
    };
    return new_time;
}

int time_diff_in_milli(struct time t1, struct time t2) {
    int seconds = t1.seconds - t2.seconds;
    int milli = t1.milli - t2.milli;

    return seconds * 1000 + milli;
}

