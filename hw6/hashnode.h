//Programmer: Joseph Klutenkamper
//Instructor: Morales
//Date:       11/17/2017
//class:      cs1575

#ifndef HASHNODE_H
#define HASHNODE_H

#include "mystringmap.h"

template <typename Key, typename T>
class HashNode 
{
  Key m_key;
  T   m_value;

public:
    HashNode(){}

    HashNode(Key key, T value)
    {
        m_key = key;
        m_value = value;
    }

    HashNode(const HashNode &cpy)
    {
        m_key = cpy.m_key;
        m_value = cpy.m_value;
    }

    Key key() 
    {
        return m_key;
    }

    void setKey(Key src)
    {
        m_key = src;
    }

    const T& value() const 
    {

        return m_value;
    }

    void setValue(T src)
    {
        m_value = src;
    }
};

#endif