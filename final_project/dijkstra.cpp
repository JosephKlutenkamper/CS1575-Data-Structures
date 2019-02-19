//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper
//Instructor: Morales
//Date:       12/14/2017
//Class:      CS 1575
//Program:    Final Project - Dr. Zoidberg's Day Out
//-----------------------------------------------------------------------------

#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "city.h"
#include <queue>
#include <list>
using namespace std;


int main()
{
  string cityname;
  string locname;
  string locname2;
  int numloc;
  int numcities;
  int hood;
  int numtrash;
  int weight;
  int count = 0;

  cin >> numcities;
  //cout << "Number of cities:"<< numcities << endl;
  while (numcities>0)
  {
    cin >> cityname;
    cin >> numloc;

    city vill(numloc,cityname);

    //cout << "Number of locations:"<< numloc << endl;
    while(numloc>0)
    {
      cin >> locname;
      cin >> numtrash;
      node parent(numtrash, locname);
      vill.placenode(numtrash, locname);

      cin >> hood;

      //cout << "number of hoods:"<< hood << endl;
      while (hood>0)
      {
        cin >> locname2;
        cin >> weight;
        //cout << "hood loop"<<endl;
        //cout << parent.getname() <<" is going into edge"<<endl;
        //cout << locname2 << " is going into edge"<<endl;
        //cout << weight   << " is going into edge"<<endl;
        edge ed;
        ed.setedge(parent, locname2, weight);
        vill.placefakeedge(ed);

        hood--;

      }
      //cout << "exited hood loop"<<endl;

      numloc--;
    }
    //vill.checkedges();
    //vill.display();
    vill.dijkstra();
    numcities --;
  }

  return 0;
}
