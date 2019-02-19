//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper
//Instructor: Morales
//Date:       12/14/2017
//Class:      CS 1575
//Program:    Final Project - Dr. Zoidberg's Day Out
//-----------------------------------------------------------------------------

//Class for city
#ifndef CITY_H
#define CITY_H
#include <iostream>
#include "stdlib.h"
#include <list>
#include <queue>
#include "string.h"
using namespace std;

class node
{
   private:
     int trash;
     string name;
     bool visit;

   public:
     node();
     node(int waste, string nam);
     int gettrash();
     string getname();
     void setname(string str){name = str; return;};
     bool visited();
     void setvisit(bool vis);

};

class edge
{
   private:


   public:
     string temp;
     node source;
     node target;
     int weight;
     edge();
     edge(const edge &e){source=e.source;target=e.target;weight=e.weight;return;}
     void setedge(node parent, const string &child, int cost);
     node  getsource();
     node  gettarget();
     void   settarget(node child);
     int    getweight();
     void   setweight(int set);
     string gettemp();
     void settemp(string str){temp=str;return;};


};

struct compair
{
    bool operator() (edge& ed1, edge& ed2)
    {
      if(ed1.getweight()==ed2.getweight())
      {
        return ed1.gettarget().gettrash() > ed2.gettarget().gettrash();
      }
      else
      {
        return ed1.getweight() < ed2.getweight();
      }
    }

};

class city
{
   private:
     int size;
     string nameofcity;
     node** adj;
     priority_queue<edge, vector<edge>, compair> que;
     vector<node> locations;
     vector<int> distances;
     edge temp;

   public:
     vector<edge> eds;
     city(int numnodes, string name);
     ~city();
     void placenode(int garbage, string name);
     void placedistance(int dist);
     void placeedge(edge ed);
     void placefakeedge(edge e);
     node getloc(unsigned int access);
     int  getdist(unsigned int access);
     void checkedges();
     void display();
     void dijkstra();
     string getname();


};

#include"city.cpp"
#endif
