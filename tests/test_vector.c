#include <criterion/criterion.h>
#include "../src/vector/vector.h"

Test(vector, test_init) {
    vector vec;
    vector_init(&vec, NULL);

    cr_assert_eq(vec.size, 0, "Vec size should be 0");
    cr_assert_eq(vec.capacity, VECTOR_INIT_CAPACITY, "Vec capacity should be %d.", VECTOR_INIT_CAPACITY);
    cr_assert_not_null(vec.items, "items should not be null");

    vector_free(&vec);
}

Test(vector, test_add) {
    vector vec;
    vector_init(&vec, NULL);

    int value1 = 10, value2 = 20;
    vector_add(&vec, &value1);
    vector_add(&vec, &value2);

    cr_assert_eq(vec.size, 2, "Vec size should be 2");
    cr_assert_eq(*(int *)vec.items[0], value1, "First elem should be %d.", value1);
    cr_assert_eq(*(int *)vec.items[1], value2, "Second elem should be %d.", value2);

    vector_free(&vec);
}

Test(vector, test_set) {
    vector vec;
    vector_init(&vec, NULL);

    int value1 = 10, value2 = 20;
    vector_add(&vec, &value1);
    vector_set(&vec, 0, &value2);

    cr_assert_eq(*(int *)vec.items[0], value2, "First elem sould be updated %d.", value2);

    vector_free(&vec);
}

Test(vector, test_get) {
    vector vec;
    vector_init(&vec, NULL);

    int value1 = 10, value2 = 20;
    vector_add(&vec, &value1);
    vector_add(&vec, &value2);

    int *retrieved_value = (int *)vector_get(&vec, 1);
    cr_assert_eq(*retrieved_value, value2, "Second elem sould be %d.", value2);

    vector_free(&vec);
}

Test(vector, test_delete) {
    vector vec;
    vector_init(&vec, NULL);

    int value1 = 10, value2 = 20, value3 = 30;
    vector_add(&vec, &value1);
    vector_add(&vec, &value2);
    vector_add(&vec, &value3);

    vector_delete(&vec, 1);

    cr_assert_eq(vec.size, 2, "Vec size should be 2");
    cr_assert_eq(*(int *)vec.items[1], value3, "Second elem should be %d", value3);

    vector_free(&vec);
}

Test(vector, test_free_function) {
    vector vec;
    vector_init(&vec, free);

    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));

    vector_add(&vec, value1);
    vector_add(&vec, value2);
    vector_add(&vec, value3);
    vector_free(&vec);

    cr_assert_null(vec.items, "Items sould be NULL");
    cr_assert_eq(vec.size, 0, "Vec size sould be 0");
    cr_assert_eq(vec.capacity, 0, "Vec capacity should be 0");
}
