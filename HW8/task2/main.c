#include <stdio.h>
#include <stdlib.h>
#include "include/search_tree.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        puts("Wrong number of args");
        exit(EXIT_FAILURE);
    }
    char *file_path = argv[1];
    int min = strtol(argv[2], NULL, 10);
    int max = strtol(argv[3], NULL, 10);
    if (max < min) {
        puts("The first value is bigger or than the second!");
        exit(EXIT_FAILURE);
    }
    FILE *file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }
    char *buffer = get_string(file_ptr);
    fclose(file_ptr);
    Node_t *root = create_tree(buffer);
    root = slice_tree(root, min, max);
    print_tree(root);
    delete_tree(root);
}