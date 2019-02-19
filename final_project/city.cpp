//-----------------------------------------------------------------------------
//Programmer: Joseph Klutenkamper
//Instructor: Morales
//Date:       12/14/2017
//Class:      CS 1575
//Program:    Final Project - Dr. Zoidberg's Day Out
//-----------------------------------------------------------------------------

#include <iostream>
using namespace std;


//node functions
node :: node()
{
  trash = 0;
  visit=false;
  return;
}

node :: node(int waste, string nam)
{
  trash = waste;
  name = nam;
  visit = false;
  return;
}

bool node :: visited()
{
  return visit;
}

int node :: gettrash()
{
  return trash;
}

string node :: getname()
{
  return name;
}

void node :: setvisit(bool vis)
{
  visit=vis;
  return;
}




//edge functions
edge :: edge()
{
  //int weight=0;
  //temp ="wha";
  return;
}
void edge :: setedge(node parent, const string &child, int cost)
{
  source = parent;
  target.setname(child);
  temp = target.getname();
  //cout << "temp changed:" << temp <<endl;
  //cout << "from child:" << child <<endl;
  weight = cost;
  return;
}

node edge :: getsource()
{
  return source;
}

node edge :: gettarget()
{
  return target;
}

void edge :: settarget(node child)
{
  target = child;
}

int edge :: getweight()
{
  return weight;
}

string edge :: gettemp()
{
  return temp;
}

void edge :: setweight(int set)
{
  weight = set;
  return;
}




//city functions

city :: city(int numnodes, string name)
{
  nameofcity=name;
  size=numnodes;
  adj = new node*[numnodes];
  for(int i = 0; i < numnodes; i++)
  {
      adj[i] = new node[numnodes];
  }

  return;
}

city :: ~city()
{
  for (int i = 0; i < size; i++)
  {
    delete[] adj[i];
  }

   delete[] adj;

   return;
}

void city :: placenode(int garbage, string name)
{
  node temp(garbage, name);
  distances.push_back(99999999);
  locations.push_back(temp);
  return;
}

void city :: placedistance(int dist)
{
  distances.push_back(dist);
  return;
}

void city :: placeedge(edge ed)
{
  que.push(ed);
  return;
}

void city :: placefakeedge(edge e)
{
  // cout << "temp recieved in vector:" << e.temp<<endl;
  // cout << "Parent recieved in vector:"<< e.source.getname()<<endl;
  // cout << "weight recieved in vector:"<< e.weight<<endl;
   eds.push_back(e);
   eds.back().temp=eds.back().target.getname();
  // cout << "temp pushed in vector:" << eds.back().temp<<endl;
  // cout << "Parent recieved in vector:"<< eds.back().source.getname()<<endl;
  // cout << "weight recieved in vector:"<< eds.back().weight<<endl;
  // cout << "maybe" <<eds.back().target.getname()<<endl;
   return;
}

node city :: getloc(unsigned int access)
{
  if(access <= distances.size())
  {
    return locations[access];
  }
  else
  {
    return locations[0];
  }
}

int city :: getdist(unsigned int access)
{
  if(access <= distances.size())
  {
    return distances[access];
  }
  else
  {
    return distances[0];
  }
}

void city :: checkedges()
{
  unsigned int i = 0;
  unsigned int b = 0;
  while (i<eds.size())
  {

    while (b<locations.size())
    {

      if(eds[i].gettemp()==locations[b].getname())
      {

        eds[i].settarget(locations[b]);
      }
      b++;
    }
    i++;
  }
}

void city :: display()
{
  cout << eds[0].gettemp();
  cout << "start of display" <<endl;
  unsigned int i = 0;
  cout << "size of edges vector:" << eds.size() << endl;
  unsigned int b = 0;
  cout << "size of locations vector:" << locations.size() << endl;
  while (i<eds.size())
  {
    cout << endl;
    cout << "edge["<<i<<"]"<<"contains:"<<endl;
    cout << "weight:" << eds[i].getweight() << endl;
    cout << "source:" << eds[i].getsource().getname() << endl;
    cout << "temp/target:"   << eds[i].gettemp() <<endl;
    cout << endl;

    i++;
  }

  while(b<locations.size())
  {
    cout << endl;
    cout << "locations[" << b << "]"<<"contains:" << endl;
    cout << "name:"  << locations[b].getname() << endl;
    cout << "trash:" << locations[b].gettrash() << endl;
    cout << endl;
    b++;
  }
}

void city :: dijkstra()
{
  string end   = "hospital";
  string start = "airport";
  int cost=0;
  int treats=0;
  unsigned int i = 0;

  //cout << "locations size:" << locations.size()<<endl;
  //cout << "hello" <<endl;
  //cout << "edges size:" << eds.size() << end;

  while(locations[i].getname()!=end)
  {
    for(int p=0;p<eds.size();p++)
    {
      if(eds[p].getsource().getname()==locations[i].getname())
      {
        que.push(eds[p]);
        for(int l=0;l<locations.size();l++)
        {
          if(eds[p].gettarget().getname()==locations[l].getname()
             &&!locations[l].visited())
          {
               if(distances[l]>eds[p].getweight())
               {
                 distances[l]=eds[p].getweight();
               }
           }
        }
      }
    }

  temp=que.top();
  que.pop();
  locations[i].setvisit(true);

  for(int k = 0; k < locations.size(); k++)
  {
    if(locations[k].getname() == temp.gettarget().getname()
     && !locations[k].visited())
    {
        for(int g = 0; g < eds.size();g++)
        {
            if(eds[g].getsource().getname() == temp.gettarget().getname())
            {
                que.push(eds[g]);
                for(int l = 0; l < locations.size(); l++)
                {
                   if((eds[g].gettarget().getname() == locations[l].getname())
                       && !locations[l].visited())
                   {
                      if(distances[l] > (eds[k].getweight()))
                      {
                         distances[l] = eds[k].getweight();
                         eds[g].setweight(distances[l]);
                      }

                    }
                }
            }
          }
          i=k;
      }
    }
    cost+=distances[i];
    treats+=locations[i].gettrash();
  }
  cout <<":"<< getname()<<","<< cost << " tokens, " << treats
       << " snacks." << endl;
}

string city :: getname()
{
  return nameofcity;
}
