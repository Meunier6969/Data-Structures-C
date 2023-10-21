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

bt_tree BT_exampleTree()
{
    bt_tree tree;
    tree.root = BT_createNode(5);
    BT_insertInOrder(tree.root, 3);
    BT_insertInOrder(tree.root, 7);
    BT_insertInOrder(tree.root, 2);
    BT_insertInOrder(tree.root, 4);
    BT_insertInOrder(tree.root, 6);
    BT_insertInOrder(tree.root, 8);
    BT_insertInOrder(tree.root, 1);
    BT_insertInOrder(tree.root, 9);
    return tree;
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
        
    return node;
}

bt_node* BT_deleteNode(bt_node *node, int value)
{
    if (node == NULL)
        return node;
        
    // Please do it for me 🙏
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

int BT_isTreeEmpty(bt_node *root)
{
    return (root == NULL);
}

int BT_heightOfTree(bt_node *node)
{
    if (node == NULL)
        return 0;
    
    return 1 + fmax(BT_heightOfTree(node->left), BT_heightOfTree(node->right));
}

int BT_balanceFactor(bt_node* node)
{
    return BT_heightOfTree(node->left) - BT_heightOfTree(node->right); 
}
