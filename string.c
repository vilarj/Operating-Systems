#include "string.h"
#include <stdlib.h>

int get_string_length(char* s) {
    int length = sizeof(s);

    for (int i = 0; i < length; i++) {
        if (s[i] == '\0') {return -1; exit(0);} // checks if the string is empty
        else {length = s[i];}
    }

    return (length-1);
}

int string_copy(char* dest, char* s, int dest_size) {
    int s_length = get_string_length(s); // Getting the length of s
    int char_copied = 0;

    if (dest == NULL || s == NULL) {return -1;} // Empty string
    else if (s_length > dest_size) { // if the length of s > than the length of destination
        for (int i = 0; i <= (s_length - 1); i++) {
            dest[i] = s[i]; // copying the string s into dest up to s length - 1
            char_copied++;
        }
    }

    else {
        for (int i = 0; i < dest_size; i++) {
            dest[i] = s[i];
            char_copied++;
        }
    }

    return char_copied;
}