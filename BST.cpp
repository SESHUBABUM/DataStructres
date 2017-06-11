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
    void insert(int key)
    {
        root=_insert(root,key);
    }
    struct node* _insert(struct node *root, int key)
    {
        if(root==nullptr)
        {
            struct node* temp=new node;
            temp->data=key;
            temp->left=nullptr;
            temp->right=nullptr;
            return temp;
        }
        else if( root->data > key)
        {
            root->left=_insert(root->left, key);
        }
        else if( root->data < key)
        {
            root->right=_insert(root->right, key);
        }
        return root;
    }
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
