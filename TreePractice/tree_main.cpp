#include "tree.h"
#include <time.h>

using namespace std;

int main ()
{
    srand(time(NULL));
    table tree;

    int inorder_value=0;
    int height_value=0;
    int count_value=0;
    int child_value=0;
    tree.build ();

    cout <<"Your BST:" <<endl;
    tree.display ();

    count_value = tree.count_nodes ();
    cout <<"Your BST had " <<count_value <<" nodes in it." <<endl;

    child_value = tree.display2children ();
    cout <<"\n" <<child_value <<" nodes were found with two children." <<endl;

    height_value = tree.height ();
    cout <<"Your tree head a height of " <<height_value <<endl;

    inorder_value = tree.inorder ();
    cout <<"The inorder successor returned was: " <<inorder_value <<endl;
    //tree.copy_table ();
    //cout <<"Your BST after it has been copied:" <<endl;
    
    /*
    tree.copy_to_LLL ();

    cout <<"Your LLL, copied from the BST:" <<endl;
    tree.display_LLL ();
    */

    return 0;
}
