#include <criterion/criterion.h>
#include "../src/hashmap/hashmap.h"

Test(hash_map, test_init) {
    size_t size = 10;
    hash_map *hashMap = hash_map_init(size);

    cr_assert_not_null(hashMap, "Hash map should not be NULL");
    cr_assert_eq(hashMap->size, size, "Hash map size should be %zu", size);
    cr_assert_not_null(hashMap->data, "Hash map data should not be NULL");

    hash_map_free(hashMap);
}

Test(hash_map, test_hash_map_insert) {
    hash_map *hashMap = hash_map_init(10);
    bool updated;

    bool result = hash_map_insert(hashMap, "key1", "value1", &updated);
    cr_assert(result, "Insertion should succeed");
    cr_assert(!updated, "Key should not be updated");

    const char *value = hash_map_get(hashMap, "key1");
    cr_assert_str_eq(value, "value1", "Value should be 'value1'");

    result = hash_map_insert(hashMap, "key1", "value2", &updated);
    cr_assert(result, "Insertion should succeed");
    cr_assert(updated, "Key should be updated");

    value = hash_map_get(hashMap, "key1");
    cr_assert_str_eq(value, "value2", "Value should be 'value2'");

    hash_map_free(hashMap);
}

Test(hash_map, test_hash_map_get) {
    hash_map *hashMap = hash_map_init(10);
    bool updated;

    hash_map_insert(hashMap, "key1", "value1", &updated);
    hash_map_insert(hashMap, "key2", "value2", &updated);

    const char *value1 = hash_map_get(hashMap, "key1");
    cr_assert_str_eq(value1, "value1", "Value for 'key1' should be 'value1'");

    const char *value2 = hash_map_get(hashMap, "key2");
    cr_assert_str_eq(value2, "value2", "Value for 'key2' should be 'value2'");

    const char *value3 = hash_map_get(hashMap, "key3");
    cr_assert_null(value3, "Value for non-existent key should be NULL");

    hash_map_free(hashMap);
}

Test(hash_map, test_hash_map_remove) {
    hash_map *hashMap = hash_map_init(10);
    bool updated;

    hash_map_insert(hashMap, "key1", "value1", &updated);
    hash_map_insert(hashMap, "key2", "value2", &updated);

    bool result = hash_map_remove(hashMap, "key1");
    cr_assert(result, "Removal should succeed");

    const char *value1 = hash_map_get(hashMap, "key1");
    cr_assert_null(value1, "Value for 'key1' should be NULL after removal");

    result = hash_map_remove(hashMap, "key3");
    cr_assert(!result, "Removal of non-existent key should fail");

    hash_map_free(hashMap);
}
