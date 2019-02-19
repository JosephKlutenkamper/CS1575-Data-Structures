


#ifndef TREENODE_H
#define TREENODE_H

#include "mybstree.h"

template <typename T>
class TreeNode
{
public:
   T m_data;
   TreeNode* m_right;
   TreeNode* m_left;
   
   TreeNode(T data)
   {
    this->m_data  = data;
    this->m_right = NULL;
    this->m_left  = NULL;
   
   }

   TreeNode(T data, TreeNode<T>* left, TreeNode<T>* right)
   {
     this->m_data = data;
     this->m_right = right;
     this->m_left=left;
            
   }
   
   void clearTree(TreeNode<T>* root)
   {
    if(root==NULL)
    { return; }

    clearTree(root->m_left);
    clearTree(root->m_right);
    delete root;
    root = NULL;    
   }

   TreeNode<T>* clone(const TreeNode<T>* cpy)
   {
    if(cpy == NULL)
    {
	return NULL;
    } 
    else{

      return new TreeNode<T>(cpy->m_data, clone(cpy->m_left), 
                                          clone(cpy->m_right));
    }

   }

   bool isLeaf()
   {
      if(!m_right && !m_left)
         return true;
      else 
         return false;
   }

   
};
#include "treenode.h"
#endif