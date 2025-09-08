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
