#include <criterion/criterion.h>
#include "../src/string/string.h"

Test(string, test_create_string) {
    char *str_ref = "Hello World";
    String* str = create_string(str_ref);
    cr_assert_eq(memcmp(str->str, str_ref, strlen(str_ref)), 0);
    cr_assert_eq(str->allocated_len, 48, "should be 48 but it was %i\n", str->allocated_len);
    cr_assert_eq(str->len, strlen(str_ref));
    delete_string(str);
}