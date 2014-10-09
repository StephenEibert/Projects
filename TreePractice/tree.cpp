#include "tree.h"
using namespace std;

table::table (): root (NULL), head (NULL)
{}

table::table (const table & source)
{
    copy_table (root, source.root);
}

table::~table ()
{
    delete_all (root);
}

void table::display ()
{
    display (root);
}

void table::display_LLL ()
{
    display_LLL (head);
}

void table::copy_to_LLL ()
{
    copy_to_LLL (head, root);
}

void table::build ()
{
    build (root);
}

int table::insert (int to_add)
{
    insert (root, to_add);
}

int table::count_nodes ()
{
    count_nodes (root);
}

int table::display2children ()
{
    display2children (root);
}

int table::height ()
{
    height (root);
}

int table::inorder ()
{
    inorder (root);
}

int table::remove2ndlargest ()
{
    remove2ndlargest (root);
}
/*
void table::copy_table ()
{
    copy_table (root, source.root);
}
*/

//This function will copy what is in the BST into a LLL.
void table::copy_to_LLL (LLL_node * & result, node * source)
{
    if (!source)
    {
        result = NULL;
        return;
    }

    //copy_to_LLL (result->next, source->left);
    result = new LLL_node;
    result->data = source->data;
    copy_to_LLL (result->next, source->right);
    copy_to_LLL (result->next, source->left);

    return;
}

//Function to diplay what is in the LLL, seperate from the BST display function
void table::display_LLL (LLL_node * head)
{
    if (!head)
        return;
    cout << head->data <<endl;
    display_LLL (head->next);
    return;
}

void table::copy_table (node * & result, node * source)
{
    if (!source)
    {
        result = NULL;
        return;
    }

    result = new node;
    result->data = source->data;
    copy_table (source->left, result->left);
    copy_table (source->right, result->right);

    return;
}

void table::delete_all (node * & root)
{
    if (!root)
        return;
    delete_all (root->left);
    delete_all (root->right);
    delete root;
    root = NULL;
}

void table::display (node * root)
{
    if (!root)
        return;
    cout << root->data <<endl;
    cout <<"Right:" <<endl;
    display (root->right);
    cout <<"Left:" <<endl;
    display (root->left);
    return;
}

void table::build (node * & root)
{
    //A random int between 0-22 for the max size of the tree
    int max_size(rand() % 23);

    //For loop stepping through each of the elements of max_size
    for (int i=0; i<max_size; ++i)
    {
        //An int between 0-99 to populate data of the tree
        int to_add(rand() % 100);
        //Insert function, passing in root (by reference) as well as the random int
        insert (root, to_add);
    }
    return;
}

int table::insert (node * & root, int to_add)
{
    if (!root)
    {
        root = new node;
        root->data = to_add;
        root->right = root->left = NULL;
    }
    else if (to_add > root->data)
        insert (root->right, to_add);
    else if (to_add < root->data)
        insert (root->left, to_add);

    return 1;
}

int table::count_nodes (node * & root)
{
    if (!root)
        return 0;
    int value = count_nodes (root->left) + count_nodes (root->right) + 1;
    return value;
}

int table::display2children (node * & root)
{
    int value=0;
    if (!root)
        return 0;
    if (root->left && root->right)
    {
        cout << root->data <<"\t";
        ++value;
    }
    display2children (root->right);
    display2children (root->left);
    return value;
}

int table::height (node * & root)
{
    if (!root)
        return 0;
    if (height (root->left) > height (root->right))
        return height (root->left) + 1;
    else
        return height (root->right) + 1;
}

//This function returns roots inorder successor to the calling routine.
int table::inorder (node * & root)
{
    if (!root)
        return 0;
    if (!root->right && !root->left)
        return 0;
    if (root->left && !root->right)
    {
        node * current = root->left;
        while (current->right)
            current = current->right;
        return current->data;
    }
    else if (root->left && root->right)
    {
        node * current = root->left;
        while (current->right)
            current = current->right;
        return current->data;
    }
}

int table::remove2ndlargest (node * & root)
{
    if (!root)
        return 0;
    //if (!root->left && !root->right)
        //cout <<"Only 1 node in the tree!" <<endl;
    if (root->left && !root->right)
    {
        node * current = root->left;
        while (current->right)
            current = current->right;
        delete current;
        current = NULL;
        return 1;
    }
    return remove2ndlargest (root->right);
}
