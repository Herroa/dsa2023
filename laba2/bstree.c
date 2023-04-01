#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

void tree_print(struct bstree * tree) {
    if (tree == NULL){} 
    else {
        tree_print(tree->left);
        printf("%s \n", tree->key); 
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
        if(strcmp(tree -> key,key)>0){
            tree = tree -> left;
        }
        else if(strcmp(key,tree -> key)>0){
            tree = tree -> right;
        }
        else{
            return;
        }
    }
    node = bstree_create(key, value);
        if (strcmp(parent->key,key)>0)
            parent->left = node;
        else
            parent->right = node;
    // printf("file added %s\n",key);
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
    tree = bstree_create("zzz", 100);
    bstree_add(tree,"dfassafsha", 20);
    bstree_add(tree,"dfaadsfsdssafsha", 20);
    bstree_add(tree,"dfassadsaffsha", 20);
    // printf("%d\t%s\n",bstree_min(tree)->value,bstree_min(tree)->key);
    // printf("%d\t%s\n",bstree_max(tree)->value,bstree_max(tree)->key);
    FILE *file;
    if ((file = fopen("words.txt", "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    char **str = (char**)malloc(sizeof(char*));
    int n = 0;
    while (!feof(file))
    {
        str[n] = (char*)malloc(sizeof(char)* 256);
        fgets(str[n], 256, file);
        n++;
        str = (char**)realloc(str, sizeof(char*)*(n + 1));
    }
    fclose(file);
    for(int i = 0;i<100;i++)
        bstree_add(tree, str[i], 1);
    
    // tree_print(tree);
    return 0;
}