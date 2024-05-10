#include "data_loader.h"
#include "avl_tree.h"
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern AVLNode *root;  // Reference to the root of the AVL Tree, managed in main.c or another appropriate module

// Loads songs from a file into the AVL tree. Each song has an ID, title, and artist.
void loadSongs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open the file");
        exit(EXIT_FAILURE);
    }
    int id;
    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
        char title[100], artist[100];
        if (sscanf(line, "%d, Song %99[^,], Artist %99[^\n]", &id, title, artist) == 3) {
            char data[256];
            sprintf(data, "%s by %s", title, artist);
            if (!insertAVLNode(root, id, data)) {
                fprintf(stderr, "Failed to insert song with ID %d into the AVL tree\n", id);
            }
        } else {
            fprintf(stderr, "Failed to parse line: %s\n", line);
        }
    }
    fclose(file);
}

// Loads playlists from a file into the hash table. Each playlist has an ID and a descriptive name.
void loadPlaylists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open the file");
        exit(EXIT_FAILURE);
    }
    int id;
    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
        char name[100];
        if (sscanf(line, "%d, %[^\n]", &id, name) == 2) {
            if (!insertHashTable(id, name)) {
                fprintf(stderr, "Failed to insert playlist with ID %d into the hash table\n", id);
            }
        } else {
            fprintf(stderr, "Failed to parse line: %s\n", line);
        }
    }
    fclose(file);
}
