class Casino2:public Casino1//inherting Casino1 to this class
{
    private:
    int bidamnt;
    int guess;
    int dice;
    char choice;
    int rating ;

    public:
    //cinstructor
    Casino2(string nm="",int ag=0,int amnt=0,string fName="", int bid=0,int gu=0,int di=0,char ch=0,int rate=0):Casino1(nm,ag,amnt,fName),bidamnt(bid),guess(gu),dice(di),choice(ch),rating(rate){}

    string crname=getName();
    int realAge=getAge();
    int cramount= getAmount();
 
   void calculate1()//taking input for bidding amount and comparing with the current amount
   {
     do
        {
            cout <<"\n\t\t\t---------------------Welcome "<<crname<<" Are You Ready To Play?------------------------"<<"\n\n";
            cout<<"Enter Bidding Amount: $";
            cin >> bidamnt;
            if(bidamnt > cramount)
                cout <<"You Can not Bid More Than Current Amount\n"
                       <<"\nRe-enter Amount: ";
        }
            while(bidamnt > cramount);
}

void calculate2()//taking guessing number as input from user 
{
  do
        {
            cout <<"\t\t\t\t\t\nGuess A Number Between 1 To 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber Sholud Be Between 1 To 10\n"
                    <<"\nGuess Numer Again: ";
        }while(guess <= 0 || guess > 10);
}

void calculate3()//calculating the winning amount or losing amount
{

  srand(time(0));       //srand() is used to initialise random number generators

  dice = rand()%10 + 1; //algorithm of which number the dice will generate

        if(dice == guess)
        {
            
            cout<<"\n\t\t\t\t\t\t\t\t\t\t ********"<<endl;
            cout<<  "\t\t\t\t\t\t\t\t\t\t** o  o **  "<<endl;
            cout<<  "\t\t\t\t\t\t\t\t\t\t**      **  "<<endl;
            cout<<  "\t\t\t\t\t\t\t\t\t\t**  O   **  "<<endl;
            cout<<  "\t\t\t\t\t\t\t\t\t\t ********  "<<endl;
            cout <<"\n\t\t\t\t\t\t\t\t\t Hurray You Won " << bidamnt * 10<<"$\n";

            cramount = cramount + bidamnt * 10;

        }

        else

         {   
            
            cout<<"\n\t\t\t\t\t\t\t\t\t\t ********"<<endl;
            cout<<  "\t\t\t\t\t\t\t\t\t\t** _  _ **  "<<endl;
            cout<<  "\t\t\t\t\t\t\t\t\t\t** :  : **  "<<endl;
            cout<<  "\t\t\t\t\t\t\t\t\t\t**  ~   **  "<<endl;
            cout<<  "\t\t\t\t\t\t\t\t\t\t ********  "<<endl; 
            cout << "\n\t\t\t\t   Opps! You couldnot win this time better luck next time "<<endl;

            cramount = cramount - bidamnt;

        }
}

void gameRating()// gameRating() for taking ratings from gamers

{
      cout<<"Rate our game out of five :"<<endl;
      cin>>rating;

  if (rating>=1&&rating<=5)

  {
    cout<<"Your rating is accepted.Thank you for your valuable rating." <<endl;
  }

  else
  {
    cout<<"Invalid Input!Try again"<<endl;
    exit(0);
  }
}


 void filewrite()// file writing operation
 {
     
     string fNameSave=getFileName();
     ofstream WriteFile;
     
     WriteFile.open(fNameSave,ios::app);

     if(!WriteFile)

     {
       cout<<"File cannot be opened"<<endl;
     }

     else
     {

       WriteFile <<endl<<"Player Name :"<<crname<<"\t\t"<<"Age :"<< realAge<<"\t\t"<<"Final Amount :"<< cramount <<"\t"<<"Rating: " << rating << " star" << endl;

     }
     WriteFile.close();

}

void print()
{
  cout <<endl<< "\nThe Winning Number Was: " << dice <<"\n";
  cout << "\n"<<crname<<", Your Remaining Amount Is " << cramount << "$\n";        
}

 void calculate() //calculate()function for calling other calculating functions and checking few conditions
 { 
   do
    {
      calculate1();  
      calculate2();
      calculate3();
      print();
       if(cramount == 0)
        {
            cout << "\nSorry You Don't Have Money To Play \n"; 
            break;  
        }
            cout << "\nYou Want To Play Again Press (y/n)? ";
            cin >> choice;
    }
    while(choice =='Y'|| choice=='y');

    cout<<"\n===============================================================================================\n";
    cout << "Thanks For Playing Game  Your Final Amount Is " << cramount << "$";
    cout<<"\n===============================================================================================\n";    
}
}; 