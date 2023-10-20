#pragma once 

typedef struct bt_node
{
    int value;
    struct bt_node *left;
    struct bt_node *right;
} bt_node;

typedef struct bt_tree
{
    bt_node *root;
} bt_tree;

bt_node* BT_createNode(int value);

void BT_insertInOrder(bt_node *root, int value);
bt_node* BT_searchNode(bt_node *root, int value);
void BT_deleteNode(bt_node *node, int value);

void BT_displayPostfix(bt_node* node);
void BT_displayPrefix(bt_node* node);
void BT_displayInfix(bt_node* node);

int BT_heightOfTree(bt_node *root);
int BT_isTreeEmpty(bt_node *tree);
