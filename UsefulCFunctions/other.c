//File containing useful C functions

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/**
 * Function used to split a string given a delimeter
 * 
 * param str: char pointer to the string
 * param deli: char pointer to a single delimeter
 * param res: char pointer to a physical array
 * param n: number of output items
 */
void split(char *str, const char *deli, const char *res[], size_t n){
    for (size_t i = 0; i < n; i++) {
        size_t len = strcspn(str, deli);

        *(res + i) = str;
        str += len;

        if (*str){
          *str++ = '\0';
        }
        
    }
}