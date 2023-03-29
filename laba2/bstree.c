#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

void tree_print(struct bstree * tree) {
    if (tree == NULL){} 
          // ничего не делать
    else {
        tree_print(tree->left);     // печатаем левое поддерево (меньшие числа)
        printf("%d \n", tree->value); // печатаем корень
        tree_print(tree->right);     // печатаем правое поддерево (большие числа)
    }
}

struct bstree *bstree_create(char *key, int value)
{
    struct bstree *tmp = malloc(sizeof(struct bstree));
    if(tmp != NULL){
        tmp -> key = key;
        tmp -> value = value;
        tmp -> parent = NULL;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    return tmp;
}

void bstree_add(struct bstree *tree, char *key)
{
    if(tree == NULL){
        return;
    }
    struct bstree *parent;
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

// Минимальный элемент дерева
struct bstree *bstree_min(struct bstree *tree)
{
    struct bstree *l = tree;
    while (l -> left != NULL)
        l = l -> left;
    return l;
}

// Максимальный элемент дерева
struct bstree *bstree_max(struct bstree *tree)
{
    struct bstree *r = tree;
    while (r -> right != NULL)
        r = r -> right;
    return r;
}




int main()
{
    struct bstree *tree = NULL;
    tree = bstree_create("roma", 10);
    bstree_add(tree,"pasha");
    tree_print(tree);
    printf("%d\n",bstree_min(tree)->value);
    printf("%d\n",bstree_max(tree)->value);
    return 0;
}