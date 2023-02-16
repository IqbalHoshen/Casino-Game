class Casino1 : public FileOperation//inheriting FileOperation to this class
{
  private:
  string name;
  int age;
  int amount;
   
  public:
  //constructor
  Casino1(string nm="",int ag=0,int amnt=0,string fName=""):FileOperation(fName),name(nm),age(ag),amount(amnt){}
  
//using get methods for the private data members
 string getName()
 {
  cout <<"\n\t\t\t\t\t\t\t\t~~~~~~~Enter Player Name:"<<"~~~~~~~"<<endl<<"\t\t\t\t\t\t\t\t\t =>";
  getline(cin,name);
  return name;

 }

int getAge()
{
  cout <<"\n\t\t\t\t\t\t\t\t~~~~~~~Enter Player Age: "<<"~~~~~~~"<<endl<<"\t\t\t\t\t\t\t\t\t =>";
  cin>> age;
 
  if (age>=18)
  {
    cout<<"\nHurray!You are eligible for the game.Enjoy!"<<endl;
  }

  else
  {
    cout << "\nSorry!You are not eligible for this game :( Check out the game rules kindly"<<endl;
    rules();
    exit(0);  
  }

  return age; 
}


int getAmount()
{
  amount=100 ;
    cout <<"\nYour Initial Amount: $"<<amount;
  return amount;
}

//Using file handling for saving Player's Info

virtual void fileReadOperation()// File Reading Operation
{
     
     string fNameSave=getFileName();
      
      ifstream ReadFile;
      ReadFile.open(fNameSave,ios::in);
      if(!ReadFile)
      {
        cout<<"File could not be opened"<<endl;
      }

      else
      {
        string line;
        while(!ReadFile.eof())
      {
        getline(ReadFile,line);
        if(ReadFile.eof())break;
        cout <<line << endl;
      }

      }
      ReadFile.close();
      
    }

    

void print1()//print1() for decorating the front part of our game
{
   cout<<"\n\t===============================================================================================";
 cout<<"\n\t\t\t\t\t   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
 cout<<"\n\t\t\t\t\t CC          A  A      SS             III     NN N   NN   OO      OO    ";
 cout<<"\n\t\t\t\t\tCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
 cout<<"\n\t\t\t\t\t CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
 cout<<"\n\t\t\t\t\t   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
 cout<<"\n\t===============================================================================================\n";   
 }
 

void rules()// void rules() for creating the rules of the game

 {
   cout<<"\n===============================================================================================\n";
   cout << "\t\t\t\t\t\t\t\t\t\tGame Rules";
   cout<<"\n===============================================================================================";
   cout <<"\t\n1. Your age should be 18  or above 18";
   cout <<"\t\n2. Guessing Number should be in between 1 to 10";
   cout <<"\t\n3.The winning amount will be the ten times of your bidding amount";
   cout <<"\t\n4.Whereas the losing amount will be deducted from your initial amount or current amount";
   cout<<"\t\n5.You can rate our game out of five"<<endl;

    
   cout<<"\t\n===============================================================================================\n";
     
 }
 
};