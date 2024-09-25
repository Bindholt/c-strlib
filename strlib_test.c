#include <stdio.h>
#include "strlib.h"

int main() {

    char* s = "Hello, World!";
    int index = 4;

    printf("Character at index %d is %c\n", index, str_charAt(s, index));
    
    printf("Length of string is %d\n", str_length(s));

    printf("ASCII value of character at index %d is %d\n", index, str_charCodeAt(s, index));

    char* s1 = "Hello, ";
    char* s2 = "World!";
    char result[100];

    str_concat(s1, s2, result);
    printf("Concatenated string is %s\n", result);

    char copy[100];
    str_copy(copy, s);
    printf("Copied string is %s\n", copy);

    char* substr = "ld!";
    int endsWith = str_endsWith(s, substr);
    
    printf("Does %s end with ld!? Answer: %s\n", s, (endsWith) ? "Yes!" : "No!");

    char* s3 = "World";
    char* s4 = "World";
    int compare = str_compare(s3, s4);

    printf("Are %s and %s equal? Answer: %s\n", s3, s4, (compare == 0) ? "Yes!" : "No!");


    char* substr1 = "Worl";
    int contains = str_includes(s, substr1);

    printf("Does %s contain %s? Answer: %s\n", s, substr1, (contains) ? "Yes!" : "No!");

    char* substr2 = "o";
    int index_of = str_indexOf(s, substr2);

    printf("Index of %s in %s is %d\n", substr1, s, index_of);

    int last_index_of = str_lastIndexOf(s, substr2);

    printf("Last index of %s in %s is %d\n", substr1, s, last_index_of);
    
    char* substr3 = "Hello";
    int startsWith = str_startsWith(s, substr3);

    printf("Does %s start with %s? Answer: %s\n", s, substr3, (startsWith) ? "Yes!" : "No!");

    char result1[100];
    char* s5 = "Julie wants to sell some of her clothes";
    str_slice(s5, 6, 20, result1);

    printf("Slice of %s from 6 to 20 forward is: %s\n", s5, result1);

    char* s6 = "Hello, World!";
    char result2[100];
    str_toLowerCase(s6, result2);
    printf("Lowercase of %s is %s\n", s6, result2);

    char result3[100];
    str_toUpperCase(s6, result3);
    printf("Uppercase of %s is %s\n", s6, result3);

    char s7[100] = "   Hello, World!   ";
    char result4[100];

    str_trimStart(s7, result4);
    printf("Trimmed start of %s is |%s|\n", s7, result4);

    char result5[100];
    str_trimEnd(s7, result5);
    printf("Trimmed end of %s is |%s|\n", s7, result5);

    char result6[100];
    str_trim(s7, result6);
    printf("Trimmed %s is |%s|\n", s7, result6);


    char result7[100];
    str_repeat(s6, 3, result7);
    printf("Repeated %s 3 times is %s\n", s6, result7);

    char result8[100];
    str_substring(s6, 7, 2, result8);

    printf("Substring of %s from 7 to 2 is %s\n", s6, result8);

    char result9[100];
    str_padStart(s6, 20, "0", result9);

    printf("Padded start of %s to 20 with 0 is %s\n", s6, result9);

    char result10[100];
    str_padEnd(s6, 20, "0", result10);

    printf("Padded end of %s to 20 with 0 is %s\n", s6, result10);

    return 0;
}