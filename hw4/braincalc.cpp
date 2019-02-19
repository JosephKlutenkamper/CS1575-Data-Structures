#include <iostream>
#include <cstdlib>
#include <sstream>
#include "LinkedStack.h"
using namespace std;

bool isOperator(string op)
{
  if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%")
    return true;
  else
    return false;
}

bool isBracket(string brkt)
{
  if (brkt == "{" || brkt == "[" || brkt == "("
      || brkt == ")" || brkt == "]" || brkt == "}")
   return true;
  else
    return false;
}

int main()
{
  LinkedStack<string> operatorStack;
  LinkedStack<int> operandStack;
  LinkedStack<string> bracketStack;

  int a;
  int rhs;
  int lhs;
  int total;
  string ins = " ";
  string s1;

  do
  {
    getline(cin, ins);
    istringstream inputstr(ins);
	
    while (inputstr >>s1)
	{		
       if(isOperator(s1) == false && isBracket(s1) == false)
       {
         a = atoi(s1.c_str());
         operandStack.push(a);
		 cout <<operandStack.top()<< " is going into operandStack\n";
       }

       else if(isOperator(s1) == true)
       {
         operatorStack.push(s1);
		 cout <<operatorStack.top()<<" is going into operator stack\n";
       }

       else if(isBracket(s1) == true)
       {
         if(s1 == "}" || s1 == "]" || s1 == ")")
		 {
		    if ((bracketStack.top() == "{" && s1=="}")||(bracketStack.top()=="("&&s1==")")||
		       (bracketStack.top() =="["&&s1=="]"))
		    {
			   if(operatorStack.top()=="+")
			   {
				   rhs=operandStack.top();
				   operandStack.pop();
				   lhs=operandStack.top();
				   operandStack.pop();
				   
				   total=lhs+rhs;
				   
				   operandStack.push(total);
				   operatorStack.pop();
			   }
			   else if(operatorStack.top()=="-")
			   {
				   rhs=operandStack.top();
				   operandStack.pop();
				   lhs=operandStack.top();
				   operandStack.pop();
				   
				   total = lhs-rhs;
				   
				   operandStack.push(total);
				   operatorStack.pop();
			   }
			   else if(operatorStack.top()=="*")
			   {
				   cout << operandStack.top();
				   rhs=operandStack.top();
				   operandStack.pop();
				   cout << endl;
				   cout << operandStack.top();
				   lhs=operandStack.top();
				   cout << endl;
				   operandStack.pop();
				   
				   total = lhs*rhs;
				   cout << total;
				   operandStack.push(total);
				   operatorStack.pop();
			   }
			   else if(operatorStack.top()=="/")
			   {
				   rhs=operandStack.top();
				   operandStack.pop();
				   lhs=operandStack.top();
				   operandStack.pop();
				   
				   total = lhs/rhs;
				   
				   operandStack.push(total);
				   operatorStack.pop();
			   }
			   else if(operatorStack.top()=="%")
			   {
				   rhs=operandStack.top();
				   operandStack.pop();
				   lhs=operandStack.top();
				   operandStack.pop();
				   
				   total = lhs%rhs;
				   
				   operandStack.push(total);
				   operatorStack.pop();
			   }
			   bracketStack.pop();
			   cout << operandStack.top();
			   cout << endl;
			   
		    }
			else
			{
			   cout << endl;
			   cout << "INVALID\n";
			   cout << bracketStack.top()<<" is on the top";
			   //cout <<endl;
			}
		 }
         else 
		 {	 
	   
            bracketStack.push(s1);
			cout << bracketStack.top()<< " is going into bracket stack\n";
		 }
		 
       }
	   else if(bracketStack.isEmpty())
	   {
		   cout << operandStack.top();
		   cout << endl;
		   operandStack.pop();
	   }
	   //cout << endl;
	   //cout<<bracketStack.top();
	   //cout <<endl;
    }
  }while(ins != "."); 


  return 0;
 }
