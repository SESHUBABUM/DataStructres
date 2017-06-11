// Example program
#include <iostream>
#include <string>
using namespace std;
class BinarySearcgTree
{
    struct node
    {
        int data;
        struct node *left;
        struct node *right;
    };
    struct node *root;
public:
    BinarySearcgTree()
    {
        root=nullptr;
    }
    void insert
    int search(int key)
    {
        struct node *temp=root;
        while( temp!=nullptr) 
        {
            if( root->data==key)
                return 1;
            else if(root->data > key )
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        return 0;
    }
};
int main()
{
 return 0;
}
