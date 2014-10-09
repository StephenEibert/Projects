#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

//BST node with right and left pointers
struct node
{
    int data;
    node * left;
    node * right;
};

//Node of a linear linked list for copying the BST into
struct LLL_node
{
    int data;
    LLL_node * next;
};

//Table class for the BST
class table
{
    public:
        table ();
        table (const table & source);
        ~table ();
        void display ();
        void display_LLL ();
        void build ();
        int insert (int to_add);
        void copy_to_LLL ();
        void copy_table ();
        int count_nodes ();
        int display2children ();
        int height ();
        int inorder ();
        int remove2ndlargest ();
    protected:
        void display_LLL (LLL_node * head);
        void copy_to_LLL (LLL_node * & result, node * source);  //Copy from the BST into a LLL
        void copy_table (node * & result, node * source);
        void delete_all (node * & root);
        void display (node * root);
        void build (node * & root);
        int insert (node * & root, int to_add);
        int count_nodes (node * & root);
        int display2children (node * & root);
        int height (node * & root);
        int inorder (node * & root);
        int remove2ndlargest (node * & root);
        node * root;
        LLL_node * head;    //Head pointer for the LLL
};
