#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

template <class T>
class node
{
	public:
		T data;
 		node<T> *left;
		node<T> *right;
};

template <class T>
class BSTree
{
	public:
		BSTree();
		void printIn();
		void printPre();
		void printPost();
		void insert_node(T value);
		void delete_node(T value);
		void findNode(T value);
	private:
		node<T> *root;
		void print_preorder(node<T> *ptr);
                void print_inorder(node<T> *ptr);
                void print_postorder(node<T> *ptr);
		void freenode(node<T> *p);
		node<T> *find_node(node<T> *ptr, T value);
		node<T> *find_parent(node<T> *ptr, T value, int *pos);
};

template <class T>
BSTree<T>::BSTree()
{
	root = NULL;
}

template <class T>
void BSTree<T>::printPre(){
	print_preorder(root);
	cout << endl;
}

template <class T>
void BSTree<T>::printIn(){
	print_inorder(root);
	cout << endl;
}

template <class T>
void BSTree<T>::printPost(){
	print_postorder(root);
	cout << endl;
}

template <class T>
void BSTree<T>::print_inorder(node<T> *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        cout << ptr->data << " ";
        print_inorder(ptr->right);
    }
}

template <class T>
void BSTree<T>::print_preorder(node<T> *ptr)
{
    if(ptr != NULL)
    {
        cout << ptr->data << " ";
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}

template <class T>
void BSTree<T>::print_postorder(node<T> *ptr)
{
    if(ptr != NULL)
    {
        print_postorder(ptr->left);
        print_postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

template <class T>
void BSTree<T>::freenode (node<T> *p)
{
	delete p;
}

template <class T>
void BSTree<T>::insert_node (T value)
{ 
	node<T> *new_node;
	node<T> *current;
	node<T> *parent;

	new_node = new node<T>;
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if ( root == NULL )
	{
		root = new_node;
	}
	else
	{
		current = root;
		while(current != NULL){
			parent = current;
			if ( current->data > value )
				current = current->left;
			else
				current = current->right;
		}
		if(parent->data > value)
			parent->left = new_node;
		else
			parent->right = new_node;
	}
}

template <class T>
void BSTree<T>::delete_node(T value)
{
	node<T> *parent;
	node<T> *ptr;
	node<T> *next;
	int pos;

	parent = find_parent(root, value, &pos);
	parent = find_parent(root, value, &pos);
        if(parent != NULL)
        {
                switch(pos)
                {
                        case -1:
                                ptr = parent->left;
                                break;
                        case 1:
                                ptr = parent->right;
                                break;
                        case 0:
                                ptr = parent;
                                break;
                }
                if(ptr->left == NULL)
                {
                        if(parent == ptr)
                                root = root->right;
                        else
                        {
                                if( pos == 1 )
                                {

                                        parent->right = ptr->right;
                                }
                                else
                                {

                                        parent->left = ptr->right;
                                }
                        }
                        freenode(ptr);
                }
		else if(ptr->right == NULL)
                {
                        if(parent != ptr)
                        {
                                if( pos == 1 )
                                {

                                        parent->right = ptr->left;
                                }
                                else
                                {

                                        parent->left = ptr->left;
                                }
                        }
                        else
                                root = root->left;
                        freenode(ptr);
                }
		else
                {
                        parent = ptr;
                        next = ptr->left;
                        if (next->right!=NULL){
                                while(next->right != NULL)
                                {
                                        parent = next;
                                        next = next->right;
                                }
                                parent->right = next->left;
                        }
                        else {
                                parent->left = next ->left;
                        }
                        ptr->data = next->data;
                        freenode(next);
                }
        }
}

template <class T>
node<T> *BSTree<T>::find_parent(node<T> *ptr, T value, int *pos)
{
	node<T> *parent;
	parent = ptr;
	*pos = 0;
	while ( ptr != NULL ) { 
		if ( ptr->data == value )
			return parent;
		else {
			if (ptr->data > value) {
				*pos = -1;
				ptr = ptr->left;
			}
			else {
				*pos = 1;
				ptr = ptr->right;
			}
		}
	}
	return NULL;
}

template <class T>
node<T> *BSTree<T>::find_node(node<T> *ptr, T value){
        while(ptr!=NULL){
                if (ptr->data==value){
                        return ptr;
                }
                else {
                        if (ptr->data>value){
                                ptr=ptr->left;
                        }
                        else{
                                ptr=ptr->right;
                        }
                }
        }
        return NULL;
}

template <class T>
void BSTree<T>::findNode(T val){
        node<T>* ptr;
        ptr=find_node(root, val);
        if (ptr!=NULL)
                cout << "Yes\n";
        else
                cout << "No\n";
}

template <class T>
void run(){
	char key;
	T value;
	BSTree<T> b;
	while(1)
	{
		cin >> key;
		switch(key)
		{
			case 'i':
				cin >> value;
				b.insert_node(value);
				break;
			case 'd':
				cin >> value;
				b.delete_node(value);
				break;
			case 'f':
				cin >> value;
				b.findNode(value);
				break;
			case 'l':
				b.printIn();
				break;
			case 'm':
				b.printPre();
				break;
			case 'n':
				b.printPost();
				break;
			case 'q':
				exit(0);
		}
	}
}
	

int main()
{	
	int t;
	cin >> t;
	if (t==1) {
		cout << "<Integer BST>\n";
		run<int>();
	}
	else if (t==2) {
		cout << "<Double BST>\n";
		run<double>();
	}
	else if (t==3) {
		cout << "<Char BST>\n";
		run<char>();
	}
	else if (t==4) {
		cout << "<String BST>\n";
		run<string>();
	}
	return 0;
}
