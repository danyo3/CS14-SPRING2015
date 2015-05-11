//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Danny Diep <ddiep003>
// SID: 861146918
// Date: May 4, 2015
// Lab 4
//  ================== END ASSESSMENT HEADER ===============
// bst.h
#ifndef BST_H
#define BST_H
#define TEST

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;

#define nil 0
// #defie Value int // restore for testing
template <typename Value>
class BST {
    class Node 
    { //binary tree node
        public:
        Node* left;
        Node* right;
        Value value;
        bool selected;
        Node (const Value v = Value())
        :value(v), left(nil), right(nil)
        {}
        Value &content() {return value;}
        bool isInternal() {return left != nil && right != nil;}
        bool isExternal() {return left != nil || right != nil;}
        bool isLeaf() {return left == nil && right == nil;}
        int height()//DONE!/////////////////////////////////////////////////////////////////////////
        {
            //returns the height of the subtree rooted at this node
            //cout << value << '\t';
			//cout << "left: " << left << " right: " << right << endl;
			if(left == nil || right == nil)
			{
				return 0;
			}
			return 1 + max(left->height(), right->height());
        }
        int size()//DONE!/////////////////////////////////////////////////////////////////////////
        {
            //returns the size of the subtree rooted at this node
            if(this == nil)
            {
				return 0;
            }
			return 1 + this->left->size() + this->right->size();
        } // Node
        	
    	void minCover() //find the	smallest cover	of	the	tree such that root is	not	part of vertex	cover.
    	{
    	    if (this == nil)
    	    {
    	        return;
    	    }
    	    if (isLeaf())
    	    {
    	        return;
    	    }
    	    this-> left->minCover();
    	    this-> right->minCover();
    	    if(this->left != nil && this->left->selected == false || this->right != nil && this->right->selected == false)
            {
                selected = true;
                return;
            }
            if((this->left != nil && this->left->selected) || (this->right != nil && this->right->selected))
            {
                selected = false;
                return;
            }
            return;
    	}
    	void minCover(int& sz)
        {
            if(this == nil)
            {
                return;
            }
            if(isLeaf())
            {
                return;
            }
            left->minCover(sz);
            if(this->selected)
            {
                cout << value << " ";
                sz++;
            }
            right->minCover(sz);
        }
    };
    //const Node* nil; // later nil will point to a sentinel node
    Node* root;
    int count;
    public :
    int size()//DONE!/////////////////////////////////////////////////////////////////////////
    {
        //size of the overall tree
        if(root == nil)
        {
			return 1;
        }
		return 1 + root->left->size() + root->right->size();
    }
    bool empty(){return size() == 0;}
    void print_node(const Node* n)//DONE!/////////////////////////////////////////////////////////////////////////
    {
        //Print the node's value
        cout << n->value;
    }
    bool search(Value x)//DONE!/////////////////////////////////////////////////////////////////////////
    {
        //search for a Value in the bst and return true if it was found.
        if(root->value == x)
        {
			return true;
        }
        //recursive solution 
        // ? is the condition operator which will go to the left if root value is greater than x
        // goes left if true goes right if false
        //calls std search function
		return ( (root->value > x) ? root->left:root->right)->search(x);
    }
    void preorder()const //DONE!/////////////////////////////////////////////////////////////////////////
    {
        //Traverse and print the tree one Value per line in preorder
        preorder(root);
    }
        
    void preorder(Node* BR)const
	{
		if(BR == nil)
		{
		    return;
		}
		cout << BR->value << '\n';
		preorder(BR->left);
		preorder(BR->right);
	}
	void postorder()const//DONE!/////////////////////////////////////////////////////////////////////////
    {
        //Traverse and print the tree one value per line in postorder
        postorder(root);
    }
    
    void postorder(Node* BR) const
	{
		if(BR == nil)
		{
			return;
		}
		postorder(BR->left);
		postorder(BR->right);
		cout << BR->value << '\n';
	}
    void inorder()const//DONE!/////////////////////////////////////////////////////////////////////////
    {
        //Traverse and print thetree one Value per line inorder
        inorder(root);
    }
    void inorder(Node* BR)const
	{
		if(BR == nil)
		{
			return;
		}
		inorder(BR->left);
		cout << BR->value << '\n';
		inorder(BR->right);
	}
    
    Value & operator[] (int n)
    {
        //returns reference to the value field of the nth node
        if (n >= size())
        {
            cout << "Error: Now printing root value \n";
            
            return root ->value;
        }
        return ophelper(n, root)->value;
        
    }
    
    Node* ophelper(int &n, Node* BR)
	{

		if (BR == nil)
		{
			return nil;
		}
		ophelper(n, BR->left);
		if(n==0)
		{
			return BR;
		}
		n--;
		ophelper(n, BR->right);
		return BR;
	}
	
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//LAB5 BEGINS HERE//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	    
	    
	

    void displayMinCover()
    {
        int size = 0;
            
        root->left->minCover();
        root->right->minCover();
        root->left->minCover(size);
        root->right->minCover(size);
        cout << endl;
        cout << size << endl;
    }
	
//----------------------------------------------------------------------------
//-----------------------------Exercise 2-------------------------------------
        void findSumPath(int sum){//list stores values
                int total = 0;
                int arr[1000];
                int j = 0;
                findPath(root, sum, arr, total, j);
            }
        
        void findPath(Node* n, int sum, int path[], int total, int i)
        {
            if(n == nil) return;

            path[i] = n->value;
            i++;
            
            if(n->left == nil && n->right == nil)
            {
                total = 0;

                for(int l = 0; l < i; l++)
                {
                    total = total + path[l];
                }
                
                if(total == sum)
                {
                    stack<int> answer;
                    for(int l = 0; l < i; l++)
                    {
                        answer.push(path[l]);
                    }
                    while(!answer.empty())
                    {
                        cout << answer.top() << " ";
                        answer.pop();
                    }
                    cout << endl;
                }
            }
            else
            {
                findPath(n->right, sum, path, total, i);
                findPath(n->left, sum, path, total, i);
            }
        }
//----------------------------------------------------------------------------
//-----------------------------Exercise 3-------------------------------------
        void vertSum(int hd, map<int,int>& m)
        {//helper
                int temp = 0;
                int sum = 0;
                verticalSum(root, hd, m, temp, sum);
                cout << m[hd];
        }
            
        void verticalSum(Node* n, int hd, map<int,int>& m, int temp, int &tot)
        {
            if(n == nil) return;
            if(hd == temp)
            {
                tot = tot + n->value;
                m[hd] = tot;
            }
                
            verticalSum(n->right, hd, m, temp + 1, tot);
            verticalSum(n->left, hd, m, temp - 1, tot);
        }
//----------------------------------------------------------------------------
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//END OF LAB 5//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BST() : count(0), root(nil){}
    void insert(Value X) {root = insert(X,root);}
    Node* insert(Value X, Node *T) 
    {
        //the normal binary tree insertion procedure
        if (T == nil){
            T = new Node(X); // the only place T gets updated
        } else if (X <T->value ){
            T->left = insert(X, T->left);
        }else if (X > T->value){
            T->right = insert(X, T->right);
        }else {
            T->value = X;
        }
        return T;
        
    }
    void remove( Value X ) { root = remove( X, root ); }
    Node* remove( Value X, Node*& T ) 
    {
        // The normal binary-tree removal procedure ...
        // Weiss’s code is faster but way more intricate.
        if ( T != nil ) {
            if ( X > T->value ) {
                T->right = remove( X, T->right );
            } else if ( X < T->value ) {
                T->left = remove( X, T->left );
            } else { // X == T->value
            if ( T->right != nil ) {
            Node* x = T->right;
            while ( x->left != nil ) x = x->left;
            T->value = x->value; // successor’s value
            T->right = remove( T->value, T->right );
            } else if ( T->left != nil ) {
                 Node* x = T->left;
                while ( x->right != nil ) x = x->right;
                T->value = x->value; // predecessor’s value
                T->left = remove( T->value, T->left );
                } else { // *T is external
                    delete T;
                    T = nil; // the only updating of T
                }
            }
        }
        // later, rebalancing code will be installed here
        return T;
    }
    void okay( ) { okay( root ); }
    void okay( Node* T ) 
    {
        // diagnostic code can be installed here
        return;
    }
};

#endif
