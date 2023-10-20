#include <stdlib.h>
#include <math.h>

#include "../headers/binary_tree.h"

bt_leaf *createLeaf(int value)
{
    bt_leaf *newLeaf = (bt_leaf*) malloc(sizeof(bt_leaf)); // animal crossing real ??????
    
    newLeaf->value = value;
    newLeaf->left = NULL;
    newLeaf->right = NULL;

    return newLeaf;
}

int heightOfTree(bt_leaf *rootOfTree)
{
    if (rootOfTree == NULL)
        return 0;
    
    return 1 + fmax(heightOfTree(rootOfTree->left), heightOfTree(rootOfTree->right));
}

int isTreeEmpty(bt_tree tree)
{
    return (tree.root == NULL);
}