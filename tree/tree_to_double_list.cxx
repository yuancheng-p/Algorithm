/* Build a binary tree
 * Ergodic a binary tree
 * Trun a binary tree into a double chain list.
 *
 * Mar 18 2014
 */
#include <iostream>
using namespace std;


struct Node
{
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }

    int value;
    Node *left;
    Node *right;
};


void addNode(Node *tree, int value)
{
    Node *currentNode = tree;
    Node *parrentNode = tree;
    while (NULL != currentNode)
    {
        parrentNode = currentNode;
        if (currentNode->value > value)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }
    currentNode = new Node(value);

    if (value < parrentNode->value)
    {
        parrentNode->left = currentNode;
    }
    else
    {
        parrentNode->right = currentNode;
    }
}


/* find max value node in a BSTree */
Node * findMaxNode(Node *tree)
{
    Node *node = tree;
    while (NULL != node->right)
    {
        node = node->right;
    }
    return node;
}


/* find min value node in a BSTree */
Node * findMinNode(Node *tree)
{
    if (NULL == tree)
    {
        return NULL;
    }

    Node *node = tree;
    while (NULL != node->left)
    {
        node = node->left;
    }
    return node;
}


/*
 * Key recursive function of the algorithm.
 */
void treeToDoubleList(Node *tree)
{
    // the pre-node and post-node of list for the current tree node.
    Node *pre = NULL;
    Node *post = NULL;
    if (NULL != tree->left)
    {
        treeToDoubleList(tree->left);
        pre = findMaxNode(tree->left);
        pre->right = tree;
    }

    if (NULL != tree->right)
    {
        treeToDoubleList(tree->right);
        post = findMinNode(tree->right);
        post->left = tree;
    }

    tree->left = pre;
    tree->right = post;
}


/* Just for printing and BSTree */
void ergodicTree(Node *node)
{
    if (NULL != node->left)
    {
        ergodicTree(node->left);
    }

    cout << node->value << ";  ";

    if (NULL != node->right)
    {
        ergodicTree(node->right);
    }
}


/* Just for printing the double list */
void ergodicList(Node *list)
{
    Node *node = list;
    cout << "- Ergodic from left to right:" << endl;
    while(NULL != node->right)
    {
        cout << node->value << ";  ";
        node = node->right;
    }

    cout << endl;
    cout << "- Ergodic from right to left:" << endl;
    while(NULL != node->left)
    {
        cout << node->value << ";  ";
        node = node->left;
    }
}


int main()
{
    /* init tree */
    Node *tree = new Node(10);
    addNode(tree, 8);
    addNode(tree, 6);
    addNode(tree, 9);
    addNode(tree, 14);
    addNode(tree, 12);
    addNode(tree, 16);

    cout << "The ordered BSTree:" << endl;
    ergodicTree(tree);
    cout << endl;

    treeToDoubleList(tree);

    /* find the header of the double list */
    Node *list = tree;
    while (NULL != list->left)
    {
        list = list->left;
    }
    cout << "The double list:" << endl;
    ergodicList(list);
    cout << endl;

    return 0;
}
