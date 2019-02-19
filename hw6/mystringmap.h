//Programmer: Joseph Klutenkamper
//Instructor: Morales
//Date:       11/17/2017
//class:      cs1575

#include <iostream>

using namespace std;

#ifndef MYSTRINGMAP_H
#define MYSTRINGMAP_H

#include "abstractstringmap.h"
#include "HashNode.h"

template< typename T>
class MyStringMap : public AbstractStringMap<T>
{



public:  

  //construction/destruction:

    MyStringMap();

    ~MyStringMap();
  //--
  
  //Accessor functions:
   int size() const;

   int max() const;

   bool isEmpty() const;

   const T& valueOf(const string& key) const throw (Oops);
  //--

  //Mutation functions:
   void clear();

   void insert(const string& key, const T& val);
   
   void remove(const string& k);
  //--

  //Output opperations
   void print() const;
  //--

private:

  int m_size;
  int m_max;
  string NOVAL;
  string TOVAL;
  HashNode<string,T> *HashTable;

  //doubles the size of the array
  void grow();

  //private insertion
  void hashInsert();

  //Removal 
  void hashRemove();

  //private member functions:
  int hash(const string &s) const ; 

  int probe(T key, T val);
  //--

};

#include "mystringmap.hpp"

#endif