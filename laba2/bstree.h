
struct bstree
{
    int value;
    char *key;
    struct bstree *left;
    struct bstree *right;
    struct bstree *parent;
};


struct bstree *bstree_create(char *key, int value);
void bstree_add(struct bstree *tree, char *key, int value);
struct bstree *bstree_lookup(struct bstree *tree, char *key);
struct bstree *bstree_delete(struct bstree *tree, char *key);
struct bstree *bstree_min(struct bstree *tree, int *deep_pointer);
struct bstree *bstree_max(struct bstree *tree);