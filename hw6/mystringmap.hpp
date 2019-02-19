//Programmer: Joseph Klutenkamper
//Instructor: Morales
//Date:       11/17/2017
//class:      cs1575

template< typename T>
MyStringMap<T>::MyStringMap()
{
    m_size    = 0;
    m_max     = 8;
    NOVAL     = "empty";
    TOVAL     = "TOVAL";
    HashTable = new HashNode<string,T>[m_max];

    for(int k = 0; k < m_max; k++)
    {
        HashTable[k].setKey(NOVAL);    
    }
}

template< typename T>
MyStringMap<T>::~MyStringMap()
{
   m_size = 0;
   delete[] HashTable;
}

template< typename T>
int MyStringMap<T>::size() const 
{
    return m_size;
}

template< typename T>
int MyStringMap<T>::max() const 
{
    return m_max;
}

template< typename T>
bool MyStringMap<T>::isEmpty() const 
{
    if (m_size == 0)
    {
     return true;
    }
    else
    { 
     return false;
    }

}

template< typename T>
const T& MyStringMap<T>::valueOf(const string& key) const throw(Oops) 
{
    int ind = hash(key);
    if(HashTable[ind].key() != NOVAL && HashTable[ind].key() 
        != TOVAL && HashTable[ind].key() == key)
    {
        return HashTable[ind].value();    
    }
    else
    {
       throw Oops("Key Not Found!!");
    }       
}

template<typename T>
void MyStringMap<T>::clear() 
{
    m_size = 0;
    m_max = 8;
}

template< typename T>
void MyStringMap<T>::insert(const string& key, const T& val)
{

    int home;
    int ind = home = hash(key);
    int step = 1;
    if(m_size >= ((m_max/3)*2))
    {
        grow();
    }

    while(HashTable[ind].key() != NOVAL && HashTable[ind].key() != TOVAL)
    {
        ind = (home + step) % m_max;
        step++;
    }
    m_size++;
    HashTable[ind].setValue(val);
    HashTable[ind].setKey(key);
}

template< typename T>    
void MyStringMap<T>::remove(const string& k) 
{
    int home;
    int pos = home = hash(k);
    int step = 1;
    while(k != HashTable[pos].key() && HashTable[pos].key() != NOVAL)
    {
        pos = (home + step) % m_max;
        step++;
    }
    if(k == HashTable[pos].key())
    {
        HashTable[pos].setKey(TOVAL);
        m_size--;
    } 
}
 
template<typename T>
void MyStringMap<T>::print() const 
{
    for(int i = 0; i< m_max; i++)
    {
        if(HashTable[i].key() != NOVAL && HashTable[i].key() != TOVAL)
        {
            cout << "< " << HashTable[i].key() << ", " << HashTable[i].value() 
                 << " > " << endl;
        }

    }

}

template< typename T>
void MyStringMap<T>::grow()
{
    m_max *= 2;
    int pos ;
    int home = 0;
    int step = 1;
    HashNode<string,T> *tempHash = HashTable;
    HashTable = new HashNode<string,T>[m_max];

    for(int i = 0; i < m_max; i++)
    {
        HashTable[i].setKey(NOVAL);
    }

    for(int i =0; i < m_max/2 ; i++)
    {
        step = 1;

        if(tempHash[i].key() != NOVAL && tempHash[i].key() != TOVAL)
        {
            pos = home = hash(tempHash[i].key());
 
            while(HashTable[pos].key() != NOVAL && HashTable[pos].key() != TOVAL)
            {
                pos = (home + step) % m_max;
                step++;
            }

            HashTable[pos].setValue(tempHash[i].value());
            HashTable[pos].setKey(tempHash[i].key());
        }
    }
    delete[] tempHash;
}

template< typename T>
int MyStringMap<T>::hash(const string &s) const 
{
    int total = 0;
    for(int i = s.length()/2; i < s.length(); i++)
    {
        total += (int)((s[i]>>3)^0xA5);
    }
    return (total/2 +1) % m_max;
}

template< typename T>
int MyStringMap<T>::probe(T key, T val)
{
  return val;      
}