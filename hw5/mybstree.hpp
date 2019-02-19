



template <typename T>
const T& MyBSTree<T>::recursive_getMin( TreeNode<T>* t )const
{
   if ( t->m_left == NULL ) 
       return t->m_data;
   else 
       return recursive_getMin( t->m_left );
}

template <typename T>
const T& MyBSTree<T>::recursive_getMax(TreeNode<T>* t)const
{
   if (t->m_right==NULL)
   {
      return t->m_data;
   }
   
   else
   {
     return recursive_getMax(t->m_right);
   }
}

template<typename T>
int MyBSTree<T>::recursive_height(TreeNode<T>* t) const
{
  if(t == NULL)
    return 0;
  else
  {
    int leftMax  = 1;
    int rightMax = 1;

    if(t->m_left)
      leftMax =  1 + recursive_height(t->m_left); 

    if(t->m_right)
      rightMax =  1 + recursive_height(t->m_right);
    
    if(leftMax>= rightMax)
      return leftMax;
    else 
      return rightMax;
  }
}  

template <typename T>
void MyBSTree<T>:: prettyPrint(const TreeNode<T>* t, int pad)const
{
 string s(pad, ' ');
 if (t == NULL)
     cout << endl;
 else{
   prettyPrint(t->m_right, pad+4);
   cout << s << t->m_data << endl;
   prettyPrint(t->m_left, pad+4);
 }  
}

template <typename T>
TreeNode<T>* MyBSTree<T>:: clone(const TreeNode<T>* t)const
{
 if (t == NULL)
     return NULL;
 else
 {
     return new TreeNode<T>(t->m_data, clone(t->m_left),clone(t->m_right));
 }  
}

template<typename T>
void MyBSTree<T>::recursive_insert(TreeNode<T>*& t, T val) 
{
  //if source is null then create a new node and exit program
  if(t == NULL)
  {
    t = new TreeNode<T>(val);
    return;
  }

  //if data equals value then we are not inserting it
  //return and exit function
  if(t->m_data == val)
   return ;

  //checks to see if data is less than value passed
  //if so create a node on the right
  if(t->m_data < val)
  {
    if(t->m_right == NULL)
    {
      t->m_right = new TreeNode<T>(val);
      m_size++;
      return;
    }
    
    recursive_insert( t->m_right, val);
  }
  
  //checks to see if data is greater than value passed
  //if so create a node on the left
  if(t->m_data > val)
  {
    if(t->m_left == NULL)
    {
      
      t->m_left = new TreeNode<T>(val);
      m_size++;
      return;
    }
    
    recursive_insert( t->m_left, val);
  }


} 

template<typename T>
void MyBSTree<T>::recursive_print(TreeNode<T>* t, int val) const
{
  string s(val, ' ');
 
  if(t == NULL)
  {
    cout << endl;
  }
  else 
  {
    recursive_print(t->m_right, val+4);
    cout << s << t->m_data << endl;
    recursive_print(t->m_left, val+4);  
  }


}  

template<typename T>
void MyBSTree<T>::recursive_pre_order_print(TreeNode<T> *t) const
{
  cout << t->m_data << " ";
  if(t->m_left != NULL)
    recursive_pre_order_print(t->m_left);
  if(t->m_right !=NULL)
    recursive_pre_order_print(t->m_right);
}

template<typename T>
void MyBSTree<T>::recursive_post_order_print(TreeNode<T>* t) const
{
  if(t->m_left != NULL)
    recursive_post_order_print(t->m_left);
  if(t->m_right !=NULL)
    recursive_post_order_print(t->m_right);
   
  cout << t->m_data << " ";
  
}

template<typename T>
void MyBSTree<T>::recursive_remove(TreeNode<T>*& t, T val)
{
  if(t == NULL) //if BST is NULL don't perform the rest of the funciton
  return;

  if(val < t->m_data)
    recursive_remove(t->m_left,val);

  else if(val > t->m_data)
    recursive_remove(t->m_right,val);
  
  else
  {
    if(t->isLeaf())
    {
      delete t;
      t = NULL;
      m_size--;
      return;
    }
    else if(t->m_left == NULL||t->m_right == NULL)
    {
      TreeNode<T> *temp = t->m_right;
      if(temp == NULL)
        temp = t->m_left;
      delete t;
      t = temp;
      m_size--;
      return;
    }  
    else{
        t->m_data = recursive_getMin(t->m_left);
        recursive_remove(t->m_left, t->m_data );
    }
  }
}  


template<typename T>
void MyBSTree<T>::recursive_clear(TreeNode<T>*& t)
{
  if(t == NULL)
    return;

  recursive_clear(t->m_left);
  recursive_clear(t->m_right);
   
  delete t;

}

template<typename T>
MyBSTree<T>::MyBSTree()
{
 m_size = 0;
 this->m_root = NULL;
}


template<typename T>
MyBSTree<T>::MyBSTree(T val)
{
 m_size = 0;
 this->m_root->m_data = val;
 this->m_root->m_right = NULL;
 this->m_root->m_left = NULL;
}


template<typename T>
MyBSTree<T>::MyBSTree(MyBSTree<T> &cpy)
{
  this->m_root = this->m_root->clone(cpy.m_root);
}


template<typename T>
MyBSTree<T>::~MyBSTree()
{
   recursive_clear(this->m_root);
}

template<typename T>
const MyBSTree<T>&  MyBSTree<T>::operator= (const MyBSTree<T>& t)
{
  if(this != &t){
    recursive_clear(this->m_root);
    this->m_root = this->m_root->clone(t.m_root);
  }
  return *this;
}

 /*** ---- Accessor Operations ---- */

// Purpose: Accessor function for the number of elements in the tree
// Returns: number of elements in the tree 
template<typename T>
int MyBSTree<T>::size() const 
{
  if (this->m_root == NULL)
   return 0;
  else
   return m_size;
}

// Purpose: Checks if a tree is empty
// Returns: 'true' if the tree is empty
//     'false' otherwise  
template<typename T>
bool MyBSTree<T>::isEmpty() const 
{
 if(this->m_root == NULL)
    return true;
 else 
   return false;  
}

// Purpose: Returns the height of the tree
// Returns: height the tree 
template<typename T>
int MyBSTree<T>::height() const 
{
   return recursive_height(this->m_root);
}


// Purpose: returns the maximum element in the Tree
// Returns: a const reference to the maximum element
// Exception: if the tree is empty, THROW a 'Oops' object with an error message!!!
template<typename T>
const T& MyBSTree<T>::getMax() const throw (Oops) 
{

  if(this->m_root != NULL)
   return recursive_getMax(this->m_root);   
 else
 {
   throw Oops("OOPS! : Tree is Empty!!");
 }
  
}

// Purpose: returns the minimum element in the Tree
// Returns: a const reference to the minimum element
// Exception: if the tree is empty, THROW a 'Oops' object with an error message!!!
template<typename T>
const T& MyBSTree<T>::getMin() const throw (Oops) 
{
  if(this->m_root != NULL)
    return recursive_getMin(this->m_root);      
 else
 {
   throw Oops("OOPS! : Tree is Empty!!"); 
 }
}

// Purpose: finds an element in the Tree
// Parameters: x is the element to be found 
// Returns: 
//     If the tree contains x then  
//         return N, the level of the node containing x
//         (the root is considered level 1)
//     If The tree does not contains x then  
//         return -N, where N is the level of the tree reached in the search
//     REPEAT: The root of the tree is considered level 1. 
template<typename T>
int MyBSTree<T>::find(const T& x) const 
{
 int depth = 0;
 
 TreeNode<T>* temp = m_root;
 if(temp != NULL)
   depth = 1;
 while(temp != NULL && temp->m_data != x)
 {
   if(x > temp->m_data)
     temp = temp-> m_right;
   else if(x < temp->m_data)
   temp = temp->m_left;
   depth++;
 }
 if(temp == NULL)
   return -(depth);
 else
   return depth;  
  
}


 
/*** ---- Mutator Operations ---- */

// Purpose: Clears the Tree
// Postconditions: an empty Tree
template<typename T>
void MyBSTree<T>::clear() 
{
  recursive_clear(this->m_root);
}

// Purpose: Inserts an element into a tree
// Parameters: x is value to be added to the tree
// Postconditions: The tree now contains x
//     if the tree already contains x, ignore insertion
template<typename T>
void MyBSTree<T>::insert(const T& x) 
{
  if(this->m_root == NULL)
  {
    this->m_root=new TreeNode<T>(x);
    m_size++;
    return;
  }
  else 
   recursive_insert(this->m_root, x);
}

// Purpose: Removes an element from the tree
// Parameters: x, the element to remove
// Postconditions: the tree does not contains x
template<typename T>
void MyBSTree<T>::remove(const T& x) 
{
  recursive_remove(this->m_root,x);
}
       
  
/*** ---- Output Operations ----*/

// Purpose: Prints the Tree in Pre-Order 
template<typename T>   
void MyBSTree<T>::printPreOrder() const 
{
   if(this->m_root)
     recursive_pre_order_print(this->m_root);
   else 
     return;
}

// Purpose: Prints the Tree in Pre-Order   
template<typename T> 
void MyBSTree<T>::printPostOrder() const 
{
   if(this->m_root)
     recursive_post_order_print(this->m_root);
   else 
     return;
} 


// Purpose: Prints the Tree In-Order with formatting
//     each level indented 4 spaces, one element per line   
template<typename T> 
void MyBSTree<T>::print() const 
{
 if(this->m_root != NULL)
   recursive_print(this->m_root,0);
 else 
   return;
}