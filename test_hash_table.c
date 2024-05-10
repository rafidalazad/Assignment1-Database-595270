#include "../include/hash_table.h"
#include <assert.h>
#include <stdio.h>

void test_insert_and_search() {
    initHashTable();
    insertHashTable(1, "Playlist 1");
    insertHashTable(2, "Playlist 2");
    char *result = searchHashTable(1);
    assert(strcmp(result, "Playlist 1") == 0);
    printf("Test Insert and Search Passed\n");
}

void test_delete() {
    initHashTable();
    insertHashTable(1, "Playlist 1");
    deleteHashTable(1);
    assert(searchHashTable(1) == NULL);
    printf("Test Delete Passed\n");
}

int main() {
    test_insert_and_search();
    test_delete();
    return 0;
}
