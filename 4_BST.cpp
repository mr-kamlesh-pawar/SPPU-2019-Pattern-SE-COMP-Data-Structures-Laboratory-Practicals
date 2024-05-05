// Beginning with an empty binary search tree, Construct binary search tree by
// inserting the values in the order given. After constructing a binary tree -
//i. Insert new node, 
// ii. Find number of nodes in longest path from root, 
// iii. Minimum data value found in the tree, 
// iv. Change a tree so that the roles of the left and right pointers are swapped at every node, 
// v. Search a value

#include<iostream>
using namespace std;
struct node
{
    int data;
    node *L;
    node *R;
};
node *root,*temp;
int count,key;

class bst
{
    public:
    void create();
    void insert(node*,node*);
    void disin(node*);
    void dispre(node*);
    void dispost(node*);
    void search(node*,int);
    int height(node*);
    void mirror(node*);
    void min(node*);
    bst()
    {
      root=NULL;
      count=0;
    }
};

void bst::create()
{
    char ans;
    do
    {
        temp=new node;
        cout<<"Enter the data : "; 
        cin>>temp->data;
        temp->L=NULL;
        temp->R=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else
            insert(root,temp);
        cout<<"Do you want to insert more value : "<<endl; cin>>ans;
        count++;
        cout<<endl;
    }while(ans=='y');
    cout<<"The Total no.of nodes are:"<<count;
} 
void bst::insert(node *root,node* temp) 
{ 
    if(temp->data>root->data)
    {
        if(root->R==NULL)
        {
            root->R=temp;
        }
        else
            insert(root->R,temp);
    }
    else
    {
        if(root->L==NULL)
        {
            root->L=temp;
        }
        else
            insert(root->L,temp);
    }
}

void bst::disin(node *root)
{
    if(root!=NULL)
    {
        disin(root->L);
        cout<<root->data<<"\t"; 
        disin(root->R);
        count++;
    }
}

void bst::dispre(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"\t"; 
        dispre(root->L);
        dispre(root->R);
    }
}

void bst::dispost(node *root)
{
    if(root!=NULL)
    {
        dispost(root->L);
        dispost(root->R);
        cout<<root->data<<"\t";
    }
}

void bst::search(node * root,int key)
{
    int flag=0;
    cout<<"\nEnter your key : "<<endl; 
    cin>>key;
    temp=root;
    while(temp!=NULL)
    {
        if(key==temp->data)
        {
            cout<<"           KEY FOUND           \n"; 
            flag=1; 
            break;  
        } 
        node *parent=temp; 
        if(key>parent->data)
        {
            temp=temp->R;
        }
        else
        {
            temp=temp->L;
        }
    }
    if(flag==0)
    {
        cout<<"            KEY NOT FOUND              "<<endl; 
    
    } 
} 
int bst::height(node *root) 
{ 
    int hl,hr; 
    if(root==NULL)
    { 
        return 0; 
        
    } 
    else if(root->L==NULL && root->R==NULL)
    {
        return 1;
    }
    cout<<endl; 
    hr=1+height(root->R);
    hl=1+height(root->L);
    if(hr>hl)
    {
        return(hr);
    }
    else
    {
        return(hl);
    }   
}

void bst::min(node *root)
{
    temp=root;
    cout<<endl; 
    while(temp->L!=NULL)
    {
        temp=temp->L;
    }
    cout<<temp->data;
}

void bst::mirror(node *root)
{
    temp=root;
    if(root!=NULL)
    {
        mirror(root->L);
        mirror(root->R);
        temp=root->L;
        root->L=root->R;
        root->R=temp;
    }
}

int main()
{
    bst t;
    int ch;
    char ans;
    do
    {
        cout<<"\n1) Insert new node 2)number of nodes in longest path 3) minimum 4) mirror 5) search 6) inorder 7) preorder 8) postorder"<<endl; cin>>ch;
        switch(ch)
        {
            case 1:
                t.create();
                break;
            case 2:
                cout<<"\n Number of nodes in longest path:"<<t.height(root);
                break;
            case 3:
                cout<<"\nThe min element is:";
                t.min(root);
                break;
            case 4:
                t.mirror(root);
                cout<<"\nThe mirror of tree is: ";
                t.disin(root);
                break;
            case 5:
                t.search(root,key);
                break;
            case 6:
                cout<<"\n***************INORDER**************"<<endl;
                t.disin(root);
                break;
            case 7:
                cout<<"\n***************PREORDER**************"<<endl;
                t.dispre(root);
                break;
            case 8:
                cout<<"\n*******************POSTORDER**************"<<endl;
                t.dispost(root);
            break;
        }
        cout<<"\nDo you want to continue : "; cin>>ans;
    }while(ans=='y');
    return 0;
}



/* 

#include<iostream>
#include<stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class BST
{
private:
    node *root;

public:
    BST()
    {
        root = NULL;
    }

    void insert(int key)
    {
        node *newNode = new node;
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        node *current = root;
        node *parent = NULL;

        while (true)
        {
            parent = current;
            if (key < current->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newNode;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }

    int longestPath()
    {
        return height(root) - 1;
    }

    int findMin()
    {
        node *current = root;
        while (current->left != NULL)
            current = current->left;
        return current->data;
    }

    void mirror()
    {
        mirrorHelper(root);
    }

    void search(int key)
    {
        if (searchHelper(root, key))
            cout << "Key found!" << endl;
        else
            cout << "Key not found!" << endl;
    }

    void displayInorder()
    {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder()
    {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder()
    {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }

private:
    int height(node *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
        }
    }

    void mirrorHelper(node *root)
    {
        if (root == NULL)
            return;
        else
        {
            mirrorHelper(root->left);
            mirrorHelper(root->right);
            swap(root->left, root->right);
        }
    }

   bool searchHelper(node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return searchHelper(root->left, key);
    return searchHelper(root->right, key);
}

    void inorder(node *root)
    {
        stack<node *> s;
        node *current = root;

        while (true)
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }

            if (s.empty())
                break;

            current = s.top();
            s.pop();

            cout << current->data << " ";

            current = current->right;
        }
    }

    void preorder(node *root)
    {
        stack<node *> s;
        if (root != NULL)
            s.push(root);

        while (!s.empty())
        {
            node *temp = s.top();
            s.pop();
            cout << temp->data << " ";

            if (temp->right != NULL)
                s.push(temp->right);

            if (temp->left != NULL)
                s.push(temp->left);
        }
    }

    void postorder(node *root)
    {
        if (root == NULL)
            return;

        stack<node *> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            node *current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }

        while (!s2.empty())
        {
            node *current = s2.top();
            s2.pop();
            cout << current->data << " ";
        }
    }
};

int main()
{
    BST tree;
    char choice;
    int key;

    do
    {
        cout << "Enter value to insert: ";
        cin >> key;
        tree.insert(key);
        cout << "Do you want to insert more nodes? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Number of nodes in longest path from root: " << tree.longestPath() << endl;
    cout << "Minimum data value found in the tree: " << tree.findMin() << endl;

    cout << "Mirror of the tree (roles of left and right pointers swapped): ";
    tree.mirror();
    tree.displayInorder(); // Displaying inorder to see the mirrored tree
    cout << endl;

    cout << "Enter value to search: ";
    cin >> key;
    tree.search(key);

    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();

    return 0;
}




 */