#include <criterion/criterion.h>
#include "../src/string/string.h"

Test(string, test_create_string) {
    char *str_ref = "Hello World";
    String* str = create_string(str_ref);
    cr_assert_not_null(str, "create_string returned NULL");
    cr_assert_eq(memcmp(str->str, str_ref, strlen(str_ref)), 0, "String content is incorrect");
    cr_assert_eq(str->allocated_len, 48, "should be 48 but it was %i\n", str->allocated_len);
    cr_assert_eq(str->len, strlen(str_ref));
    delete_string(str);
}

Test(string, test_create_string_with_length) {
    size_t len = 5;
    String* str = create_string_with_length(len);
    
    cr_assert_not_null(str, "create_string_with_length() returned NULL");
    cr_assert_eq(str->len, 0, "String length is incorrect");
    cr_assert_eq(str->allocated_len, 48, "Allocated length is incorrect");
    
    delete_string(str);
}

Test(string, test_concat) {
    String* str1 = create_string("Hello");
    String* str2 = create_string(" World");
    
    String* result = concat(str1, str2);
    
    cr_assert_not_null(result, "concat() returned NULL");
    cr_assert_str_eq(result->str, "Hello World", "Concatenation result is incorrect");
    cr_assert_eq(result->len, strlen("Hello World"), "Concatenated string length is incorrect\nShould be %i but was %i", strlen("Hello World"), result->len);
    cr_assert_eq(result->allocated_len, 48, "Allocated length is incorrect");

    
    delete_string(str1);
    delete_string(str2);
    delete_string(result);
}

Test(string, test_compare_true) {
    String* str1 = create_string("Hello");
    String* str2 = create_string("Hello");
    
    int result = compare(str1, str2);
    
    cr_assert_eq(result, 0, "compare() should return 0 for equal strings");
    
    delete_string(str1);
    delete_string(str2);
}

Test(string, test_compare_false) {
    String* str1 = create_string("Hello");
    String* str2 = create_string("World");
    
    int result = compare(str1, str2);
    
    cr_assert_neq(result, 0, "compare() should return non-zero for unequal strings");
    
    delete_string(str1);
    delete_string(str2);
}

Test(string, test_basic_append) {
    String* str1 = create_string("Hello");
    char str2[] = " World";
    
    String* result = append(str1, str2);
    
    cr_assert_not_null(result, "append() returned NULL");
    cr_assert_str_eq(result->str, "Hello World", "Append result is incorrect");
    cr_assert_eq(result->len, strlen("Hello World"), "Appended string length is incorrect");
    cr_assert_eq(result->allocated_len, 48, "Allocated length is incorrect");
    
    delete_string(result);
}

Test(string, test_all_function) {
    char str_base1[] = "aaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeee";
    String* str1 = create_string(str_base1);
    cr_assert_not_null(str1, "create_string returned NULL");
    cr_assert_eq(str1->allocated_len, 96, "Allocated length is incorrect for str1: %i", str1->allocated_len);
    cr_assert_eq(str1->len, strlen(str_base1), "Len is not correct str1: %i", str1->len);


    char str_base2[] = "ffffffffffgggggggggghhhhhhhhhhjjjjjjjjjjkkkkkkkkkkllllllllll";
    String* str2 = create_string_with_length(4);
    cr_assert_not_null(str2, "create_string_with_length returned NULL");
    cr_assert_eq(str2->allocated_len, 48, "Allocated length is incorrect for str2: %i", str2->allocated_len);

    str2 = append(str2, str_base2);
    cr_assert_not_null(str2, "append returned NULL");
    cr_assert_eq(str2->allocated_len, 96, "Allocated length is incorrect for str2: %i", str2->allocated_len);
    cr_assert_eq(str2->len, strlen(str_base2), "Len is not correct str2: %i", str2->len);
    
    int cmp = compare(str1, str2);
    cr_assert_neq(cmp, 0, "compare return 0");

    String* result = concat(str1, str2);
    cr_assert_not_null(result, "append returned NULL");
    
    cr_assert_eq(result->len, strlen(str_base1) + strlen(str_base2), "Len is not correct: %i", result->len);
    cr_assert_eq(result->allocated_len, 144, "Allocated length is incorrect: %i", result->allocated_len);
    
    delete_string(str1);
    delete_string(str2);
    delete_string(result);
}
