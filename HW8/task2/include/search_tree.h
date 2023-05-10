#ifndef TASK2_SEARCH_TREE_H
#define TASK2_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_t {
    int val;
    struct Node_t *left;
    struct Node_t *right;
} Node_t;

Node_t *new_node(int item);

Node_t *insert_node(Node_t *node, int val);

Node_t *create_tree(char *buffer);

int height(Node_t *node);

void print_given_level(Node_t *root, int level);

void print_tree(Node_t *root);

Node_t *slice_tree(Node_t *root, int min, int max);

void delete_tree(Node_t *root);

char *get_string(FILE *file_ptr);


#endif
