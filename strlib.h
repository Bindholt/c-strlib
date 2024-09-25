#ifndef STRLIB_H
#define STRLIB_H

char str_charAt(char* s, int index);
int str_length(char* s);
int str_charCodeAt(char* s, int index);
void str_concat(char* s1, char* s2, char* result);
int str_getASCII(char c);
int str_endsWith(char* s, char* substr);
int str_startsWith(char* s, char* substr);
int str_compare(char* s1, char* s2);
void str_copy(char* to, char* from);
int str_includes(char* s, char* substr);
int str_indexOf(char* s, char* substr);
int str_lastIndexOf(char* s, char* substr);
void str_slice(char* s, int start, int end, char* result);
void str_toLowerCase(char* s, char* result);
void str_toUpperCase(char* s, char* result);
void str_trimStart(char* s, char* result);
void str_trimEnd(char* s, char* result);
void str_trim(char* s, char* result);
void str_repeat(char* s, int count, char* result);
void str_substring(char* s, int start, int length, char* result);
void str_padStart(char* s, int target_length, char* pad, char* result);
void str_padEnd(char* s, int target_length, char* pad, char* result);
void str_replace(char* s, char* substr, char* new_substr, char* result);

#endif