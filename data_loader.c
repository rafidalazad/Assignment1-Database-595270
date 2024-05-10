#include "data_loader.h"
#include "avl_tree.h"
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern AVLNode *root;  // Reference to the root of the AVL Tree, managed in main.c or another appropriate module

void loadSongs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open the file");
        exit(EXIT_FAILURE);
    }
    int id;
    char title[100], artist[100];
    int year;
    char genre[50];

    while (fscanf(file, "%d, %[^,], %[^,], %d, %s\n", &id, title, artist, &year, genre) == 5) {
        char data[256];
        sprintf(data, "%s by %s, %d, %s", title, artist, year, genre);
        root = insertAVLNode(root, id, data);
    }
    fclose(file);
}

void loadPlaylists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open the file");
        exit(EXIT_FAILURE);
    }
    int id;
    char name[100];

    while (fscanf(file, "%d, %[^\n]\n", &id, name) == 2) {
        insertHashTable(id, name);
    }
    fclose(file);
}
