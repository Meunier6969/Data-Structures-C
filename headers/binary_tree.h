#pragma once

typedef struct bt_leaf
{
    int value;
    struct bt_leaf *left;
    struct bt_leaf *right;
} bt_leaf;

typedef struct bt_tree
{
    bt_leaf *root;
} bt_tree;

bt_leaf *createLeaf(int value);

void insertInOrder(bt_leaf *rootOfTree, int value);

int heightOfTree(bt_leaf *tree);
int isTreeEmpty(bt_tree tree);
