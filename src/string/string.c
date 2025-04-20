#include "string.h"

#include <string.h>
#include <stdio.h>

static size_t get_len(size_t value)
{
    size_t tmp = (value + 15) & ~15;
    return tmp + 32;
}

String* create_string(const char* str)
{
    if (str == NULL)
    {
        return NULL;
    }
    
    String* new_str = malloc(sizeof(String));
    if (new_str == NULL)
    {
        return NULL;
    }

    new_str->len = strlen(str);
    new_str->allocated_len = get_len(new_str->len);
    new_str->str = malloc(new_str->allocated_len * sizeof(char));
    if (new_str->str == NULL)
    {
        free(new_str);
        return NULL;
    }
    strcpy(new_str->str, str);

    return new_str;
}

String* create_string_with_length(size_t len)
{
    len = get_len(len);
    String* new_str = malloc(sizeof(String));
    if (new_str == NULL)
    {
        return NULL;
    }

    new_str->len = 0;
    new_str->allocated_len = len;
    new_str->str = malloc(new_str->allocated_len * sizeof(char));
    if (new_str->str == NULL)
    {
        free(new_str);
        return NULL;
    }
    new_str->str[0] = '\0';

    return new_str;
}

void delete_string(String* str)
{
    if (str != NULL)
    {
        if (str->str != NULL)
        {
            free(str->str);
        }
        free(str);
    }
}

String* concat(const String* str1, const String* str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    
    size_t new_len = str1->len + str2->len;
    String* new_str = create_string_with_length(new_len);
    if (new_str == NULL)
    {
        return NULL;
    }

    strcpy(new_str->str, str1->str);
    strcat(new_str->str, str2->str);
    new_str->len = new_len;
    return new_str;
}

int compare(const String* str1, const String* str2)
{
    size_t len = str1->len - str2->len;
    if (len != 0)
    {
        return len;
    }
    return memcmp(str1->str, str2->str, str1->len);
}

String* append(String* str1, char* str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }
    
    size_t len_str2 = strlen(str2);
    if (len_str2 + str1->len > str1->allocated_len)
    {
        size_t new_len = get_len(len_str2 + str1->len);
        str1->str = realloc(str1->str, new_len);
        str1->allocated_len = new_len;
    }

    for (size_t i = 0; i < len_str2; i++)
    {
        str1->str[str1->len + i] = str2[i];
    }
    
    str1->len += len_str2;

    return str1;
}

void split(const String* str, const char* delim)
{
    char* res = calloc(str->len, sizeof(char));
    // memcpy(res, str->str);
    delim = delim;
    res = res;
}