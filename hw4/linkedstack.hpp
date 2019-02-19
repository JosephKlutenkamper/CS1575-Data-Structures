#include <iostream>
#include "LinkedStack.h"
using namespace std;
#ifndef LINKEDSTACK_HPP_
#define LINKEDSTACK_HPP_
template <typename T>
LinkedStack<T>::LinkedStack()
{
  m_head = NULL;
  m_size = 0;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
  clear();
}

template <typename T>
const LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rhs)
{
   if(this != &rhs)
    {
      clear();

      Node<T>* ptr, * last = NULL;
      for(ptr = rhs.m_head; ptr != NULL; ptr = ptr->m_next)
      {
        Node<T>* tempNode = new Node<T>(ptr->m_data, m_head);

        if(last == NULL)
          m_head = tempNode;
        else
          last->m_next = tempNode;

        last = tempNode;
      }

      m_size = rhs.m_size;
    }
      return *this;
}
template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& rhs)
{
  m_head = NULL;

  Node<T>* ptr, * last = NULL;
  for(ptr = rhs.m_head; ptr != NULL; ptr = ptr->m_next)
  {
    Node<T>* tempNode = new Node<T>(ptr->m_data, m_head);

    if(last == NULL)
      m_head = tempNode;
    else
      last->m_next = tempNode;

    last = tempNode;
  }


  m_size = rhs.m_size;
}

template <typename T>
bool LinkedStack<T>::isEmpty() const
{
  if (m_head == NULL)
    return true;
  else
    return false;
}

template <typename T>
const T& LinkedStack<T>:: top() const throw ( Oops )
{
  try
  {
	  if(!isEmpty())
	  {
		  return m_head->m_data;
	  }
  }
  catch(const Oops)
  {
	 throw new Oops("Error"); 
  }
  return m_head->m_data;
}

template <typename T>
void LinkedStack<T>::push(const T& x)
{
  if(m_head != NULL)
  {
    Node<T>* tempNode = new Node<T>(x,m_head);
	m_head = tempNode;
  }
  else
  {

	Node<T>* tempNode = m_head;
    m_head = new Node<T>(x,tempNode);
  }
  m_size++;

}

template <typename T>
void LinkedStack<T>::pop()
{
  if(m_head->m_next != NULL)
  {
  
    Node<T>* tempNode = m_head->m_next;
    delete m_head;
	m_head = tempNode;
    m_size--;
	return;
  }
  return;
}

template <typename T>
void LinkedStack<T>::clear()
{
  while(isEmpty() == false)
  {
    pop();
  }

 return;

}

#endif