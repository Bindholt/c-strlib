#include <stdio.h>
#include "strlib.h"

char str_charAt(char* s, int index) 
{
    return (index < 0 || index >= str_length(s)) ? '\0' : s[index];
}

int str_length(char* s) 
{
    char* p = s;
    while(*++p);
    return p-s;
}

int str_getASCII(char c)
{
    return (int)c;
}

int str_charCodeAt(char* s, int index)
{
    return str_getASCII(str_charAt(s, index));
}

void str_copy(char* to, char* from)
{
    while(*to++ = *from++);
}

int str_compare(char* s1, char* s2)
{
    while(*s1 && *s2 && *s1 == *s2) s1++, s2++;
    return *s1 - *s2;
}

int str_endsWith(char* s, char* substr)
{
    return str_compare(s + str_length(s) - str_length(substr), substr) == 0;
}

int str_startsWith(char* s, char* substr) 
{
    while(*s && *substr && *s == *substr) s++, substr++;
    return *substr == '\0';
}

int str_includes(char* s, char* substr)
{
    return str_indexOf(s, substr) != -1;
}

int str_indexOf(char* s, char* substr)
{
    char* init_substr = substr;
    int index = 0;
    while(*s)
    {
        if(*s++ == *substr)
        {
            if(*++substr == '\0') return index;
        }
        else substr = init_substr;
        index++;
    }
    return -1;
}

int str_lastIndexOf(char* s, char* substr) 
{
    char* init_substr = substr;
    int index = 0;
    int last_index = -1;
    while(*s)
    {
        if(*s++ == *substr)
        {
            if(*++substr == '\0') last_index = index;
        }
        else substr = init_substr;
        index++;
    }
    return last_index;
}

void str_toLowerCase(char* s, char* result)
{
    while(*s)
    {
        if(*s >= 'A' && *s <= 'Z') *result++ = *s + 32;
        else *result++ = *s;
        s++;
    }
    *result = '\0';
}

void str_toUpperCase(char* s, char* result)
{
    while(*s)
    {
        if(*s >= 'a' && *s <= 'z') *result++ = *s - 32;
        else *result++ = *s;
        s++;
    }
    *result = '\0';
}

void str_trimStart(char* s, char* result)
{
    while(*s == ' ' || *s == '\t' || *s == '\n') s++;
    while(*s) *result++ = *s++;
    *result = '\0';
}


void str_trimEnd(char* s, char* result)
{
    int len = str_length(s);
    while(len > 0 && (s[len-1] == ' ' || s[len-1] == '\t' || s[len-1] == '\n')) len--;
    for(int i = 0; i < len; i++) *result++ = s[i];
    *result = '\0';
}

void str_trim(char* s, char* result)
{
    char temp_result[256]; 
    str_trimStart(s, temp_result);
    str_trimEnd(temp_result, result);
}

void str_concat(char* s1, char* s2, char* result)
{
    while(*s1) *result++ = *s1++;
    while(*s2) *result++ = *s2++;
    *result = '\0';
}


void str_repeat(char* s, int count, char* result)
{
    *result = '\0';
    for (int i = 0; i < count; i++) {
        str_concat(result, s, result);
    }
}


void str_substring(char* s, int start, int end, char* result)
{
    int length = str_length(s);
    // Negative indices
    if(start < 0) start = 0;
    if(end < 0) end = 0;
    // Swap if start is greater than end
    if(start > end) {
        int temp = start;
        start = end;
        end = temp;
    }
    // Empty string if start is greater than length
    if (start >= length) {
        *result = '\0';
        return;
    }

    char* p = s + start;
    while(start++ < end && *p) *result++ = *p++;

    *result = '\0';
}

void str_slice(char* s, int start, int end, char* result)
{
    int length = str_length(s);
    // Negative indices
    if(start < 0) start += length;
    if(end < 0) end += length;
    // Clamp indices
    if(start < 0) start = 0;
    if(end > length) end = length;
    // Empty string if start is greater than end
    if(start > end) {
        *result = '\0';
        return;
    }

    char* p = s + start;
    while(start++ < end && *p) *result++ = *p++;

    *result = '\0';
}   

void str_padStart(char* s, int target_length, char* pad, char* result)
{
    int length = str_length(s);
    if(target_length <= length) {
        str_copy(result, s);
        return;
    }

    int padLength = target_length - length;
    str_repeat(pad, padLength, result);
    str_concat(result, s, result);
}

void str_padEnd(char* s, int target_length, char* pad, char* result)
{
    int length = str_length(s);
    if(target_length <= length) {
        str_copy(result, s);
        return;
    }

    int padLength = target_length - length;
    str_copy(result, s);
    str_repeat(pad, padLength, result + length);
}