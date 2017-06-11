// Example program
#include <iostream>
#include <string>
using namespace std;
class BinarySearchTree
{
	struct node
	{
		int data;
		struct node *left;
		struct node *right;
	};
	struct node *root;
public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	void insert(int key)
	{
		root = _insert(root, key);
	}
	void inorder()
	{
		struct node *temp = root;
		_inorder(temp);
	}
	void _inorder(struct node *temp)
	{
		if (temp == nullptr) return;
		_inorder(temp->left);
		cout << temp->data << endl;
		_inorder(temp->right);
	}
	struct node* _insert(struct node *temp, int key)
	{
		if (temp == nullptr)
		{
			struct node* temp1 = new struct node;
			temp1->data = key;
			temp1->left = nullptr;
			temp1->right = nullptr;
			return temp1;
		}
		else if (temp->data > key)
		{
			temp->left = _insert(temp->left, key);
		}
		else if (temp->data < key)
		{
			temp->right = _insert(temp->right, key);
		}
		return temp;
	}
	int search(int key)
	{
		struct node *temp = root;
		while (temp != nullptr)
		{
			if (temp->data == key)
				return 1;
			else if (temp->data > key)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		return 0;
	}
};
int main()
{
	BinarySearchTree bst;
	bst.insert(23);
	bst.insert(32);
	bst.insert(2);
	bst.insert(3);
	bst.insert(233);
	cout << bst.search(233) << endl;
	cout << bst.search(233) << endl;
	cout << bst.search(2303) << endl;
	return 0;
}
