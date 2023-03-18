
typedef struct bstree
{
    int value;
    char key[100];
    struct bstree *left;
    struct bstree *right;
    struct bstree *parent;
} node;

node *bstree_create(char *key, int value);
// void bstree_add(node *tree, char *key, int value);
// node *bstree_lookup(node *tree, char *key);
// node *bstree_delete(node *tree, char *key);
node *bstree_min(node *tree);
node *bstree_max(node *tree);