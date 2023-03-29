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
        if(key < tree -> key){
            tree = tree -> left;
        }
        else if(key > tree -> key){
            tree = tree -> right;
        }
        else{
            return;
        }
    }
}

struct bstree *search(struct bstree * root, int value)
{
// Если дерево пусто или ключ корня равен искомому ключу, то возвращается указатель на корень
    if ((root == NULL) || (root -> value == value))
        return root;
// Поиск нужного узла
    if (value < root -> value)
        return search(root -> left, value);
    else return search(root -> right, value);
}

// Минимальный элемент дерева
struct bstree *bstree_min(struct bstree *root)
{
    struct bstree *l = root;
    while (l -> left != NULL)
        l = l -> left;
    return l;
}

// Максимальный элемент дерева
struct bstree *bstree_max(struct bstree *root)
{
    struct bstree *r = root;
    while (r -> right != NULL)
        r = r -> right;
    return r;
}




int main()
{
    struct bstree *tree = NULL;
    char init[4] = "Roma";
    int value = 10;
    tree = bstree_create(init, value);
    bstree_add(tree,3);
    tree_print(tree);
    printf("%d\n",bstree_min(tree)->value);
    printf("%d\n",bstree_max(tree)->value);
    return 0;
}