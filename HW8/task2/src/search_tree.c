#include "../include/search_tree.h"

Node_t *new_node(int item) {
    Node_t *temp = (Node_t *) malloc(sizeof(Node_t));
    temp->val = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node_t *insert_node(Node_t *node, int val) {
    if (node == NULL)
        return new_node(val);
    if (val < node->val)
        node->left = insert_node(node->left, val);
    else
        node->right = insert_node(node->right, val);
    return node;
}

Node_t *create_tree(char *buffer) {
    Node_t *root = NULL;
    char *token = strtok(buffer, ",");
    while (token != NULL) {
        if (strcmp("null", token) != 0) {
            int val = strtol(token, NULL, 10);
            root = insert_node(root, val);
        }
        token = strtok(NULL, ",");
    }
    return root;
}

int height(Node_t *node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void print_given_level(Node_t *root, int level) {
    if (root == NULL) {
        printf("null,");
        return;
    }
    if (level == 1)
        printf("%d,", root->val);
    else if (level > 1) {
        print_given_level(root->left, level - 1);
        print_given_level(root->right, level - 1);
    }
}

void print_tree(Node_t *root) {
    int h = height(root);
    for (int i = 1; i <= h; i++)
        print_given_level(root, i);
    printf("\b \n");
}

Node_t *slice_tree(Node_t *root, int min, int max) {
    if (root == NULL)
        return root;
    root->left = slice_tree(root->left, min, max);
    root->right = slice_tree(root->right, min, max);
    if (root->val < min) {
        Node_t *temp = root->right;
        free(root);
        return temp;
    }
    if (root->val > max) {
        Node_t *temp = root->left;
        free(root);
        return temp;
    }
    return root;
}

void delete_tree(Node_t *root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

char *get_string(FILE *file_ptr) {
    fseek(file_ptr, 0, SEEK_END);
    int len = ftell(file_ptr) + 1;
    fseek(file_ptr, 0, SEEK_SET);
    char *buffer;
    buffer = (char *) malloc(sizeof(char) * len);
    fgets(buffer, len, file_ptr);
    return buffer;
}