#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

typedef struct String String;

struct String {
    char* str;
    size_t len;
    size_t allocated_len;
};

String* create_string(const char* str);
String* create_string_with_length(size_t len);

void delete_string(String* str);

String* concat(const String* str1, const String* str2);
int compare(const String* str1, const String* str2);
String* append(String* str1, char * str2);

void split(const String* str, const char* delim);

#endif /* STRING_H */