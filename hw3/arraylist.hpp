//Programmer: Joseph Klutenkamper
//Instructor: Morales
//Date:       10/16/2017
#include "arrayList.h"
#ifndef ARRAYLIST_HPP_
#define ARRAYLIST_HPP_


//Definition: Increases size of storage array
//Postconditions: a new array of size m_max*2 is allocated,
//                and m_data is copied to it.
//                m_max is set to the size of this new storage array
template<typename T> void ArrayList<T>::grow(){

    //Adjusting max size
    int old_max = m_max;
    m_max = m_max * 2;
    if(m_max == 0)
      m_max = 1;

    //Setting pointers
    T *temp = m_data;
    m_data = new T [m_max];

    //filing new array with values from old array
    for(int i = 0;i < old_max; i++)
    {
       m_data[i] = temp[i];
    }

    delete[] temp;
   }

  // Purpose: Decreases size of storage array
  // Postconditions: a new array of size m_max/2 is allocated,
  //     and m_data is copied to it.
  //     m_max is set to the size of this new storage array
template<typename T> void ArrayList<T>::shrink(){

    //Adjust max size
    int old_max = m_max;
    m_max = m_max/2;
    if(m_max == 0)
     m_max = 1;

     //Setting up pointers for new array
    T *temp = m_data;
    m_data = new T [m_max];

    //filing new array with values from old array
    for(int i = 0;i < old_max; i++)
    {
       m_data[i] = temp[i];
    }

    delete[] temp;
  }

  // Purpose: Parameterized Constructor
  // Parameters:  s : the requested size of the list
  //              x : the initial values in the list
  // Postconditions:  the list is constructed as a list of 's' copies of 'x'
template<typename T> ArrayList<T>::ArrayList(int s, const T& x){
    m_data = new T [s];
    m_size = m_max = s;
    for(int i = 0; i < s; i++)
      m_data[i] = x;
  }


  // Purpose: Destructor
  // Postconditions: current size and maximum size set to 0,
  //                 data deallocated and set to NULL
template<typename T> ArrayList<T>::~ArrayList(){

    m_size = m_max = 0;
    delete[] m_data;
    m_data = NULL;
  }

  // Purpose: Operator=, performs a deep copy of 'rhs' into 'this' ArrayList
  // Parameters: rhs : ArrayList to be copied
  // Returns: *this
  // Postconditions: rhs == this
template<typename T> ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
  {
	if(this != &rhs)
	{
      m_size = rhs.m_size;
      m_max = rhs.m_max;

      delete []m_data;

      m_data = new T[m_max];

      for(int i = 0; i < rhs.m_max; i++)
      {
        m_data[i] = rhs.m_data[i];
      }
   }
    return (*this);
  }

  // Purpose: Copy Constructor
  // Parameters: cpy = ArrayList to be copied
  // Postconditions: current size, maximum size, and elements same as cpy
template<typename T> ArrayList<T>::ArrayList(const ArrayList<T>& cpy){
  /*  m_size = cpy.m_size;
    m_max  = cpy.m_max;
    m_data = cpy.m_data;
    for(int i = 0; i < m_max; i++)
    {
      m_data[i] = cpy.m_data[i];
    }*/
    m_data = NULL;
    *this = cpy;

  }

  // Purpose: Accessor function for the number of elements in the list
  // Returns: number of elements in the list
template<typename T> int ArrayList<T>::size() const{
    return m_size;
  }

  // Purpose: Accessor function for the first element of the list
  // Returns: the first element in the list
template<typename T> const T& ArrayList<T>::first() const{
     if(m_size >= 1)
     {
       return m_data[0];
	 }
	 std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.first()" ;
     std::cout << "  (List is empty)" << std::endl;
     return m_errobj;
  }

  // Purpose: return a read-and-write reference to the element at
  // the specified position
  // Parameters: i is 0-based index into the ArrayList
  // Returns: the element at position i in the ArrayList
template<typename T> T& ArrayList<T>::operator[](int i) {
  if(i >= m_size || i < 0 ){
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!![]";
    std::cout << "  (index out of bounds)" << std::endl;
    return m_errobj;
    }
    else{
    return m_data[i];
    }
  }

  // Purpose: return a read-only reference to the element at
  // the specified position
  // Parameters: i is 0-based index into the ArrayList
  // Returns: the element at position i in the ArrayList
template<typename T> const T& ArrayList<T>::operator[](int i) const{
    if(i >= m_size || i < 0 ){
      std::cout << "!-- ERROR : PANIC in ARRAYLIST!![]";
      std::cout << "  (index out of bounds)" << std::endl;
      return m_errobj;
    }
    else{
    return m_data[i];
    }
  }

  // Purpose: finds an element in the ArrayList
  // Parameters: 'x' is value to be found in the ArrayList
  // Returns: the position of the first occurrance of 'x' in the list,
  //          or -1  if 'x' is not found.
  template<typename T> int ArrayList<T>::find(const T& x) const{
    for(int i = 0 ;i < m_size;i++)
    {
      if(m_data[i] == x)
        return i;
    }
    return -1;
  }

//Defintion: Clears the ArrayList
//Postconditions: current size and maximum size set to 0,
//                 elements are deallocated and data is set to NULL
  template<typename T> void ArrayList<T>::clear(){
    m_size = m_max = 0;
    delete [] m_data;
    m_data =  NULL;
  }

// Definition: puts the value x at the end of an ArrayList
// Parameters: x is value to be added to ArrayList
// Postconditions: current size is incremented by 1
//     If max size is reached, the storage wrray is grown.
 template<typename T> void ArrayList<T>::insert_back(const T& x){
  if(m_size == m_max){
    grow();
    m_data[m_size] = x;
    m_size++;
  }
  else if(m_size != m_max){
    m_data[m_size] = x;
    m_size++;
  }
 }

//Definition: puts the value x at the position i in the  ArrayList
//Parameters: x is value to be added to ArrayList
//             i is the position to insert x at
//Postconditions: current size is incremented by 1
//     If max size is reached, the storage array is grown().
 template<typename T> void ArrayList<T>::insert(const T& x, int i){
    T temp;

    if(i >= m_max || i < 0)
    {
      std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()";
      std::cout << "  (index out of bounds)" << std::endl;

    }
  //First situtation where it equals max
    else if(i == m_max-1)
    {
      grow();
      for(int j= m_max-1; j > i ; j--)
      {
        temp = m_data[j-1];
        m_data[j] = m_data[j-1];
        m_data[j-1] = temp;
      }
      m_data[i] = x;
      m_size++;
    }

    else
    {
      for(int j= m_max-1; j > i ; j--)
      {
        temp = m_data[j-1];
        m_data[j] = m_data[j-1];
        m_data[j-1] = temp;
      }
      m_data[i] = x;
      m_size++;
      //Size of array reached the max
      if(m_size == m_max)
        grow();
    }
  }

// Purpose: Removes the element at index i in the array
// Parameters: i, the index of the element to remove
// Postconditions: if the size of the list is greater than 0
//                 size is decremented by one.
//                 if the size of the list less than 1/4 the max size,
//                 the storage array is shrunk.
  template<typename T> void ArrayList<T>::remove(int i){
    T temp;
    //Out of bounds error
    if(i >= m_max || i < 0)
    {
      std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()";
      std::cout << "  (index out of bounds)" << std::endl;
    }
    else{
      for(int j = i; j < m_max-1; j++)
      {
        temp = m_data[j+1];
        m_data[j] = m_data[j+1];
        m_data[j+1] = temp;
      }
      m_size--;
    }
  }

//Definition: swaps two elements of the array
//Parameters: i, k, two positions on the Arraylist
//Postconditions: the elements at positions i and k swap positions
  template<typename T> void ArrayList<T>::swap(int i, int k){
    int posI, posK;
    T temp;
    if( i > m_max || i < 0 || k > m_max || k < 0)
    {
      std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()";
      std::cout << "  (index out of bounds)" << std::endl;
    }
    else{
      for(int j = 0; j < m_max; j++)
      {
        if( j == i)
          posI = j;
        if(j == k)
          posK = j;
      }
      temp = m_data[posI];
      m_data[posI] = m_data[posK];
      m_data[posK] = temp;
    }
  }

//Definition: Appends two lists
//Parameters: alist, a list to appended to the end of 'this' list
//Postconditions: current size is incremented by size of alist
//                 the elements of alist are appended to the elements of 'this'
 template<typename T> void ArrayList<T>::append(const ArrayList<T>& alist){
   for(int i = 0; i < alist.m_size;i++)
   {
     insert_back(alist.m_data[i]);
   }
   return;
 }

//Definition: Removes duplicates
//Postconditions: all duplicate elements are removed from the list.
 template<typename T> void ArrayList<T>::purge(){
   for(int i = 0; i < m_size; i++){
     for(int j = i+1; j < m_size;){
       if(m_data[i] == m_data[j])
       {
         for(int l = j; l < m_size; l++)
          m_data[l] = m_data[l+1];

          m_size--;
       }
       else
         j++;
     }
   }
 }



#endif
