#ifndef STRING_H
#define STRING_H

/** 
 * This function receives a string array
 * and checks whether s is empty or not.
 * If it is, it returns -1. Otherwise,
 * it returns the actual length of the array
 */
int get_string_length(char* s);

/** 
 * This function receives two string array, dest and s,
 * and an int, dest_size. The method copies one array from one
 * place into another. The function copies the string inside s
 * into dest. If s is too large to fit within dest,
 * then dest_size - 1 characters are copied,
 * not dest_size characters. The function returns -1 if either s
 * or dest is null. Otherwise, it returns
 */
int string_copy(char* dest, char* s, int dest_size);

#endif
