//Programmer: Joseph Klutenkamper
//Date:       9/25/2017
//Class:      CS1575
//Hw:         2(Dungeon and clams)
//-----------------------------------------------------------------------------
//Program description:Program will attempt recursive techniques to find a
//                   :solution to a maze.
//-----------------------------------------------------------------------------
#include <iostream>
using namespace std;

bool move(int row, int col, char** maz);

int main()
{
  int cs;
  int rs;
  bool zoid=false;
  do {

  // Maze is a 2D array of characters
  char** maze;// Readin size of Maze

  // Readin size of Maze
  cin >> cs >> rs;
  cout << cs << " " << rs << endl;
  cin.ignore();    // to move read head to next line

  // Allocate Maze Array
  maze = new char*[rs];
  for(int k=0; k < rs; k++)
  {
    maze[k] = new char[cs];
  }


  // Read Maze Array
  // Notice that we are reading *Character by Character*
  // and after every row we need to read an extra character
  // to account for the 'end-of-line' character
  char dummy;
  for(int k=0; k < rs; k++)
  {
    for(int j=0; j < cs; j++)
    {
      cin.get(maze[k][j]);
    }
    cin.get(dummy);   // read end-of-line
  }

 //finding where zoidberg is to move him to solution
  for(int k=0; k < rs; k++)
  {
    for(int j=0; j < cs; j++)
    {
      if(maze[k][j]=='Z')
      {
        //find soltuion to maze
        zoid=move(k,j,maze);
      }
    }
  }

  // Print Maze Array if there is a solution
  if(zoid==true)
  {
    for(int k=0; k < rs; k++)
    {
      for(int j=0; j < cs; j++)
      {
        cout << maze[k][j];
      }
      cout << endl;   // read end-of-line
    }
  }
  cout << endl;

  // De-allocate Maze Array
  for(int k=0; k < rs; k++)
  {
    delete [] maze[k];
  }
  delete [] maze;

//end of while when there is no rows or cols for it to analize
}while((rs>0)&&(cs>0));

  return 0;
}


//fucntion that moves zoidberg
bool move(int row, int col, char** maz)
{

  if(maz[row][col]=='E')//if its the exit
  {
    return true;
  }

  //if there is not an open space and zoidberg isnt on top of himself
  if(maz[row][col]!=' '&&maz[row][col]!='Z')
  {
    return false;
  }

  //if the location is free or on zoidberg
  else if(maz[row][col]==' '||maz[row][col]=='Z')
  {
    //leave crumb
    maz[row][col]='.';
    if(move(row,col+1,maz)) //check north
    {
      return true;
    }
    if(move(row+1,col,maz))//check east
    {
      return true;
    }
    if(move(row,col-1,maz))//cheack south
    {
      return true;
    }
    if(move(row-1,col,maz))//check west
    {
      return true;
    }

    //delete breadcrumb
    maz[row][col]=' ';
    //no solution
    return false;

  }
}
