#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

void tree_print(node * tree) {
    if (tree == NULL){} 
          // ничего не делать
    else {
        tree_print(tree->left);     // печатаем левое поддерево (меньшие числа)
        printf("%d \n", tree->value); // печатаем корень
        tree_print(tree->right);     // печатаем правое поддерево (большие числа)
    }
}

node *bstree_create(char *key, int value)
{
    node *tmp = malloc(sizeof(node));
    if(tmp != NULL){
        tmp -> key = key;
        tmp -> value = value;
        tmp -> parent = NULL;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    return tmp;
}

node *add(node *root, int value)
{
    node *root2 = root, *root3 = NULL;
// Выделение памяти под узел дерева
    node *tmp = malloc(sizeof(node));
// Присваивание значения ключу
    tmp -> value = value;
/* Поиск нужной позиции для вставки (руководствуемся правилом 
вставки элементов, см. начало статьи, пункт 3) */
    while (root2 != NULL)
    {
        root3 = root2;
        if (value < root2 -> value)
            root2 = root2 -> left;
        else
            root2 = root2 -> right;
    }
/* Присваивание указателю на родителя значения указателя root3 
(указатель root3 был найден выше) */
    tmp -> parent = root3;
// Присваивание указателю на левое и правое поддерево значения NULL
    tmp -> left = NULL;
    tmp -> right = NULL;
/* Вставляем узел в дерево (руководствуемся правилом
вставки элементов, см. начало статьи, пункт 3) */
    if (value < root3 -> value) root3 -> left = tmp;
    else root3 -> right = tmp;
    return root;
}

node *search(node * root, int value)
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
node *bstree_min(node *root)
{
    node *l = root;
    while (l -> left != NULL)
        l = l -> left;
    return l;
}

// Максимальный элемент дерева
node *bstree_max(node *root)
{
    node *r = root;
    while (r -> right != NULL)
        r = r -> right;
    return r;
}




int main()
{
    node *tree = NULL;
    char init[4] = "Roma";
    int value = 10;
    tree = bstree_create(init, value);
    add(tree,3);
    add(tree,100);
    add(tree,320);
    add(tree,10034);
    tree_print(tree);
    printf("%d\n",bstree_min(tree)->value);
    printf("%d\n",bstree_max(tree)->value);
    return 0;
}