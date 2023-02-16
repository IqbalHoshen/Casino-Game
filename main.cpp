#include <iostream>
#include <string>//header file for string type input
#include <cstdlib>//for using srand() and rand function()
#include <fstream>//header file for file handling


using namespace std;
#include "file.h"//including the user defined header files
#include "part1.h"
#include "part2.h"

int main()//main function

{
  char selection;
  string nm;
  int amnt;
 
 Casino1 obj1;//creating object for Casino1 class
 obj1.setFileName("Save_Player_Info_File.txt"); //calling setFileName function using obj1
 obj1.print1();

 Casino2 obj2;
 obj2.setFileName("Save_Player_Info_File.txt");//calling setFileName function using obj2

 cout<<endl<<"\t\t\t\t\t\t\t\t\t 1 - Start playing";//Menubar
 cout<<endl<<"\t\t\t\t\t\t\t\t\t 2 - Game Rules";
 cout<<endl<<"\t\t\t\t\t\t\t\t\t 3 - Player Information";
 cout<<endl<<"\t\t\t\t\t\t\t\t\t 4 - Exit\n";

 cout<<endl<<"Enter selection: ";

 cin>>selection;

 switch(selection)
  {

   case '1':  
   obj2.calculate();
   obj2.gameRating();
   obj2.filewrite();
   break;

   case'2':
   obj2.rules();
   break;

   case '3':
   obj2.fileReadOperation(); //Derived class of fileReadOperation() overrides Base class
   break;

   case'4':
   cout<<endl<<"Exited";
   break;
    
   default: cout<<endl<<"Invalid selection";

  }
   return 0;
    
}




