#include <iostream>
using namespace std;

class BTreeNode
{
	friend class BSTree;
	private:
	    int data;
	    BTreeNode *left;
	    BTreeNode *right;
};
typedef class BTreeNode node;

class BSTree
{
	public:
		BSTree();
		void printIn();
		void printPre();
		void printPost();
		void insert_node(int value);
		void delete_node(int value);
		void findNode(int value);
	private:
		node* root;
		void print_preorder(node *ptr);
		void print_inorder(node *ptr);
		void print_postorder(node *ptr);
		node *find_node(node *ptr, int value);
		node *find_parent(node *ptr, int value, int *pos);
};

BSTree::BSTree(){
	root = NULL;
}

void BSTree::printPre(){
	print_preorder(root);
	cout << endl;
}

void BSTree::printIn(){
	print_inorder(root);
	cout << endl;
}

void BSTree::printPost(){
	print_postorder(root);
	cout << endl;
}

void BSTree::findNode(int val){
	node* ptr;
	ptr=find_node(root, val);
	if (ptr!=NULL)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	node *ptr;
	BSTree *b;
	int i, n, val;
	cin >> n;
	b = new BSTree[n];
	for (i=0; i<n; ++i){
		while(1){
			cin >> val;
			if (val!=-1)
				b[i].insert_node(val);
			else
				break;
		}
	}
	cout << "In-order:" << endl;
	for (i=0; i<n; ++i){
		b[i].printIn();
	}
	cout << "Pre-order:" << endl;
	for (i=0; i<n; ++i){
		b[i].printPre();
	}
	cout << "Post-order:" << endl;
	for (i=0; i<n; ++i){
		b[i].printPost();
	}
	cin >> val;
	cout << "Delete " << val << endl;
	for (i=0; i<n; ++i){
		b[i].delete_node(val);
		b[i].printIn();
	}
	cin >> val;
	cout << "Find " << val << endl;
	for (i=0; i<n; ++i){
		b[i].findNode(val);
	}
}

node *BSTree::find_node(node *ptr, int value){
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

node *BSTree::find_parent(node *ptr, int value, int *pos)
{
	node *parent;
	parent = ptr;
	*pos = 0;
	while(ptr != NULL)	
	{
		if(ptr->data == value)
			return parent;
		else
		{
			parent = ptr;
			if(ptr->data > value)
			{
				*pos = -1;
				ptr = ptr->left;
			}
			else
			{
				*pos = 1;
				ptr = ptr->right;
			}
		}
	}
	return NULL;
}

void BSTree::delete_node(int value)
{
	node *parent;
	node *ptr;
	node *next;
	int pos;

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
			delete ptr;
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
			delete ptr;
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
			
			delete next;	
		}
	}
}

void BSTree::insert_node(int value)
{
    node *new_node;
    node *current;
    node *parent;

    new_node = new node;
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL)
    {
        root = new_node; //return new_node;
    }
    else
    {
        current = root;
        while(current != NULL)
        {
            parent = current;
            if(current->data > value)
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

void BSTree::print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        cout << ptr->data << " "; //printf("%d ", ptr->data);
        print_inorder(ptr->right);
    }
}
 
void BSTree::print_preorder(node *ptr)
{
    if(ptr != NULL)
    {
        cout << ptr->data << " "; //printf("%d ", ptr->data);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}
 
void BSTree::print_postorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_postorder(ptr->left);
        print_postorder(ptr->right);
        cout << ptr->data << " "; //printf("%d ", ptr->data);
    }
}

