//Programmer: Joseph Klutenkamper
//Date:       9/8/2017
//Class:      CS1575
//Homework:   Hivemind
//Description:This program finds each value stored in a
//            dynamic aray larger than zero, then sotres it
//            in an array of type class(bots). The program the
//            traverses through the array calculating the distance
//            to each element larger than zero and determines if
//            there are two elements within the distence less than or
//            eqaul to it's value then the program counts this as an
//            unisolated member.
//-----------------------------------------------------------------------------
#include<iostream>
//included cmath for easier math functions
#include<cmath>
using namespace std;

//Class bots is meant to be a staple for any element that may be an isolated
//member thus it contains values that help deductively rule out what will and
//will not be an isolated member.
class bots
{
  //variables needed to help find the distance from one bot to another
  //on the dynamic array.
  private:
    short h_pos;
    short w_pos;
    short type;

  //Public getter and setter fucntions to manipulate the values of the private
  //variables.
  public:
    void set_h(short h_co){h_pos=h_co;}
    void set_w(short w_co){w_pos=w_co;}
    void set_type(short typea){type=typea;}
    short get_h(){return h_pos;}
    short get_w(){return w_pos;}
    short get_type(){return type;}
};
//End class decleration.


//Start of main function.
int main()
{

  //Stylistic choice
  cout << endl;

  //Constants used for refining traversal of dynamic array and keeping a
  //max number of bots
  const short MAX_BOTS             = 1000;
  const short NO_ROUNDS            = 0;
  const short NO_ROBOTS            = 0;
  const short COMMUNICATION_FACTOR = 2;

  //Local level variables that will be used throughout the main function
  short rounds;
  short roundcount;
  short robotcount;
  short isolated;

  //First user input to determine how many iterations this function will
  //preform.
  cin >> rounds;

  //Start of algorythmic iterations of dynamic array traversal and refining
  //Seacrh for isolated members
  while (rounds>NO_ROUNDS)
  {
    //local varaibles to this while loop.
    roundcount++;
    short height;
    short width;
    short **grid;

    //Decleration of array of class bots
    //and initialization.
    bots robots[MAX_BOTS];
    robotcount = NO_ROBOTS;

    //Input for array height and width.
    cin >> height;
    cin >> width;

    //Initialization of a dynamic array of short pointers.
    grid=new short* [height];

    //Start of dynamic array traversal with the outer shell being height.
    for(short k=0;k<height;k++)
    {
      //Initialization of the second dynamic dimension(width)
      grid[k]=new short[width];

      //Start of traversal to each element in the dynamic array.
      for(short i=0; i<width; i++ )
      {
        //Input for each element (must be short).
        cin >> grid[k][i];

        //Condiional stating that if the input for an element in the dynamic
        //array is not zero then initialize an element of bots with the input
        //value.
        if (grid[k][i]>0)
        {
          //Getter and setter functions for storing the location in the
          //dynamic array and the value of the element in the array of
          //class(bots).
          robots[robotcount].set_h(k);
          robots[robotcount].set_w(i);
          robots[robotcount].set_type(grid[k][i]);

          //Adds another to robot counter making it able to tie values to a
          //diferent element next iteration.
          robotcount++;
        }
        //end of if input is >0.

      }
      //end of inner element of dynamic array traversal

    }
    //end of outer element of dynamic array traversal.

//-----------------------SEARCH------------------
    //subtract from the robot count because the last iteration adds one that
    //doesnt actually have a value.
    robotcount--;

    //isolated is initialized as the number of all elements greater than
    //zero existing in the dynamic array and then slowly subtracted as we
    //deduce which are not isolated.
    isolated = robotcount+1;

    //This traversal takes the robots and compares locations to their value
    //to see if they are within distance from each other.
    for(short i=0;i<robotcount;i++)
    {
      //This is a local loop variable used to count the amount of robots
      //within the chosen robots range.
      short true_count=0;

      //This compares all the other robots to the 'i' robot.
      for(short c=0;c<robotcount;c++)
      {

          //---------------TEST TRASH-----------------------
          //float x_1=static_cast<float>(robots[i].get_h());
          //float x_2=static_cast<float>(robots[c].get_h());
          //float y_2=static_cast<float>(robots[c].get_w());
          //float y_1=static_cast<float>(robots[i].get_w());
          //float difx=((x_2-x_1)*(x_2-x_1));
          //float dify=((y_2-y_1)*(y_2-y_1));
          //float sqt=(sqrt(difx+dify));


           //I'm actually very proud of this one, so this is basically the
           //distance formula of the 'i' robot compared to all the other 'c'
           //robots and if it is less than or equal to the value of it's
           //position in the dynamic array then it is within the range.
           if((sqrt(static_cast<float>
             (pow((robots[c].get_h()-robots[i].get_h()),2)
             +pow((robots[c].get_w()-robots[i].get_w()),2)))
             <= static_cast<float>(robots[i].get_type()))
             && (sqrt(static_cast<float>
             (pow((robots[c].get_h()-robots[i].get_h()),2)
             +pow((robots[c].get_w()-robots[i].get_w()),2))))!=0)
           {
             //Adds to count that tells how many robots are in range.
             true_count++;

             //Conditional that sees if true count is equal to the
             //factor that determines if the robots communicate which is
             //2 at this moment
             if(true_count==COMMUNICATION_FACTOR)
             {
                isolated--;
             }
             //End of if robo range count equals 2.

           }
           //End of if another robot[c] is in the radius of 'i' robot

        }
        //End of each[c] of [i] for traversal.

      }
      //End of Each [i] traversal.

    //Start of the traversal to delete the Dynamic array.
    for(short k=0; k<height; k++)
    {
      //deletes the memory allocation for the inner dimension.
      delete [] grid[k];
    }

    //deletes the memory allocation for the outer dimension.
    delete[] grid;

    //cout that states how many isolated members are on each array.
    cout << "Hive mind "<<roundcount<<" has "<<isolated<<" isolated members\n";

    //subtract from rounds
    rounds--;

  }
  //End of while statement that catches input and delivers isolated member
  // and dimensional array output

  //Stylistic choice, having no spaces between output and input looks strange
  //in this case.
  cout << endl;


  //c u Space Cowboy
  return 0;

}

//Thanks!

//Last updated: 9/8/2017
//by:           Joseph Klutenkamper
