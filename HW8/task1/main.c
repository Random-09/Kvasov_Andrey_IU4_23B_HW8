#include <stdio.h>
#include <stdlib.h>
#include "include/search_tree.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        puts("Wrong number of args");
        exit(EXIT_FAILURE);
    }
    char *file_path = argv[1];
    int subtree_root_node = strtol(argv[2], NULL, 10);
    FILE *file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }
    char *buffer = get_string(file_ptr);
    fclose(file_ptr);
    Node_t *root = create_tree(buffer);
    Node_t *subtree_root = search(root, subtree_root_node);
    if (is_subtree(root, subtree_root))
        print_tree(subtree_root);
    else
        puts("Subtree not found!");
    delete_tree(root);
}