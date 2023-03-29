#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

void tree_print(struct bstree * tree) {
    if (tree == NULL){} 
    else {
        tree_print(tree->left);
        printf("%d \n", tree->value); 
        tree_print(tree->right);
    }
}

struct bstree *bstree_create(char *key, int value)
{
    struct bstree *tmp = malloc(sizeof(struct bstree));
    if(tmp != NULL){
        tmp -> key = key;
        tmp -> value = value;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    return tmp;
}

void bstree_add(struct bstree *tree, char *key, int value)
{
    if(tree == NULL){
        return;
    }
    struct bstree *parent, *node;
    while(tree != NULL){
        parent = tree;
        if(strcmp(tree -> key,key)){
            tree = tree -> left;
        }
        else if(strcmp(key,tree -> key)){
            tree = tree -> right;
        }
        else{
            return;
        }
    }
    node = bstree_create(key, value);
        if (strcmp(parent->key,key))
            parent->left = node;
        else
            parent->right = node;
}

struct bstree *bstree_lookup(struct bstree *tree, char *key)
{
    while (tree != NULL) {
        if (strcmp(key,tree -> key) == 0)
            return tree;
        else if (strcmp(tree -> key,key))
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}


struct bstree *bstree_min(struct bstree *tree)
{
    if (tree == NULL)
        return NULL;
    struct bstree *l = tree;
    while (l -> left != NULL)
        l = l -> left;
    return l;
}


struct bstree *bstree_max(struct bstree *tree)
{
    if (tree == NULL)
        return NULL;
    struct bstree *r = tree;
    while (r -> right != NULL)
        r = r -> right;
    return r;
}




int main()
{
    struct bstree *tree = NULL;
    tree = bstree_create("zzzzzroma", 100);
    bstree_add(tree,"asha",20);
    // tree_print(tree);
    printf("%d\t%s\n",bstree_min(tree)->value,bstree_min(tree)->key);
    printf("%d\t%s\n",bstree_max(tree)->value,bstree_max(tree)->key);
    return 0;
}