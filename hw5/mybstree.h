
#include <iostream>
using namespace std;

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"
#include "treenode.h"

template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
   TreeNode<T>* m_root;
   int m_size;

   const T& recursive_getMin(TreeNode<T>* t)const;

   const T& recursive_getMax(TreeNode<T>* t)const;  

   int recursive_height(TreeNode<T>* t)const;

   void prettyPrint(const TreeNode<T>* t, int pad)const;
   
   TreeNode<T>* clone(const TreeNode<T>* t)const;

   void recursive_insert(TreeNode<T>*& t, T val);

   void recursive_print(TreeNode<T>* t, int val)const;
   
   void recursive_pre_order_print(TreeNode<T>* t)const;

   void recursive_post_order_print(TreeNode<T>* t)const;

   void recursive_remove(TreeNode<T>*& t, T val);

   void recursive_clear(TreeNode<T>*& t);
   

public:
    
    //Constructors, destructors and copys
    MyBSTree();

    MyBSTree(T val);

    MyBSTree(MyBSTree& cpy);

    ~MyBSTree();

    const MyBSTree<T>& operator= (const MyBSTree<T>& rhs); 

 /*** ---- Accessor Operations ---- */

// Purpose: Accessor function for the number of elements in the tree
// Returns: number of elements in the tree 
int size() const;

// Purpose: Checks if a tree is empty
// Returns: 'true' if the tree is empty
//     'false' otherwise  
bool isEmpty() const;

// Purpose: Returns the height of the tree
// Returns: height the tree 
int height() const;


// Purpose: returns the maximum element in the Tree
// Returns: a const reference to the maximum element
// Exception: if the tree is empty, THROW a 'Oops' object with an error message!!!
const T& getMax() const throw (Oops);

// Purpose: returns the minimum element in the Tree
// Returns: a const reference to the minimum element
// Exception: if the tree is empty, THROW a 'Oops' object with an error message!!!
const T& getMin() const throw (Oops);

// Purpose: finds an element in the Tree
// Parameters: x is the element to be found 
// Returns: 
//     If the tree contains x then  
//         return N, the level of the node containing x
//         (the root is considered level 1)
//     If The tree does not contains x then  
//         return -N, where N is the level of the tree reached in the search
//     REPEAT: The root of the tree is considered level 1. 
int find(const T& x) const;


  
/*** ---- Mutator Operations ---- */

// Purpose: Clears the Tree
// Postconditions: an empty Tree
void clear();

// Purpose: Inserts an element into a tree
// Parameters: x is value to be added to the tree
// Postconditions: The tree now contains x
//     if the tree already contains x, ignore insertion
void insert(const T& x);

// Purpose: Removes an element from the tree
// Parameters: x, the element to remove
// Postconditions: the tree does not contains x
void remove(const T& x);
        
   
/*** ---- Output Operations ---- */

// Purpose: Prints the Tree in Pre-Order    
void printPreOrder() const;

// Purpose: Prints the Tree in Pre-Order    
void printPostOrder() const; 


// Purpose: Prints the Tree In-Order with formatting
//     each level indented 4 spaces, one element per line    
void print() const;

};

#include "mybstree.hpp"
#endif