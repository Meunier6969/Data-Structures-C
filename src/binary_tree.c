#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../headers/binary_tree.h"

bt_node *BT_createNode(int value)
{
    bt_node *newNode = (bt_node*) malloc(sizeof(bt_node));
    
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void BT_insertInOrder(bt_node *node, int value)
{
    if (node == NULL)
        return;

    if (value < node->value)
    {
        if (node->left == NULL)
        {
            bt_node* newNode = BT_createNode(value);
            node->left = newNode;
        }
        else
        {
            BT_insertInOrder(node->left, value);
        }
    }

    if (value >= node->value)
    {
        if (node->right == NULL)
        {
            bt_node* newNode = BT_createNode(value);
            node->right = newNode;
        }
        else
        {
            BT_insertInOrder(node->right, value);
        }
    }
}

bt_node* BT_searchNode(bt_node *node, int value)
{
    if (node == NULL)
        return NULL;

    if (value < node->value)
        return BT_searchNode(node->left, value);

    if (value > node->value)
        return BT_searchNode(node->right, value);
        
    if (value == node->value)
        return node;
}

void BT_deleteNode(bt_node *node, int value)
{
    if (node == NULL)
        return;
        
    // Soon™️
}

void BT_displayPostfix(bt_node* node)
{
    if (node == NULL)
        return;

    BT_displayPostfix(node->left);
    BT_displayPostfix(node->right);
    printf("%d ", node->value);
}

void BT_displayPrefix(bt_node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->value);
    BT_displayPrefix(node->left);
    BT_displayPrefix(node->right);
}

void BT_displayInfix(bt_node* node)
{
    if (node == NULL)
        return;

    BT_displayInfix(node->left);
    printf("%d ", node->value);
    BT_displayInfix(node->right);
}

int BT_heightOfTree(bt_node *root)
{
    if (root == NULL)
        return 0;
    
    return 1 + fmax(BT_heightOfTree(root->left), BT_heightOfTree(root->right));
}

int BT_isTreeEmpty(bt_node *tree)
{
    return (tree == NULL);
}
