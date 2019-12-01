//Bowlby, David COSC 1437-58001
//Dr_T Nov-1-2019

/*
	Input Validation with Ref Functions 
	A cleaner way to do input validation
	Validating input, an essential process.
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
	Keeping Dr. McMillan from breaking my code, defend against "dark side of the force",
	and/or legitimate user error. 
	//Try and Catch blocks are used in error checking
	Teacher: Dr. Tyson McMillan 
*/
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
using namespace std;

class Candidate
{
    private:
      string firstName;
      string lastName;
      string partyAff;
      bool leadStatus;
      int currentVotes;
    
    public:
      //Default Constructor set to 0 ******
      Candidate() {firstName = "", lastName ="", partyAff = "", leadStatus = false, currentVotes = 0;}
      
      void setfirstName (string fN) { firstName = fN;}
      string getfirstName () const { return firstName;}

      void setlastName (string lN) { lastName = lN;}
      string getlastName () const { return lastName;}

      void setpartyAff (string pA) { partyAff = pA;}
      string getpartyAff () const { return partyAff;}

      void setleadStatus (bool lS);
      bool getleadStatus () const { return leadStatus;}

      void setcurrentVotes (int cV) { currentVotes = cV;}
      int getcurrentVotes () const { return currentVotes;}
};

class Scoreboard
{
  private:
    Candidate c1;// Allow access to class Candiate
    Candidate c2;// Allow access to class Candidate
  
  public:
    Scoreboard()
    {
      c1.setfirstName(" ");
      c1.setlastName(" ");
      c1.setpartyAff(" ");
      c1.setcurrentVotes(0);
      
      c2.setfirstName(" ");
      c2.setlastName(" ");
      c2.setpartyAff(" ");
      c2.setcurrentVotes(0);
      
    }

    void setc1(Candidate can1) { c1 = can1;}
    Candidate getc1() const { return c1;}
    
    void setc2(Candidate can2) { c2 = can2;}
    Candidate getc2() const { return c2;}

    //***********Update Candidate Info ***********

    void setfirstName()//Canidate 1
    {
      string newfirstName = "";
      cout << "\nWhat is the new First Name: " << endl;
      cin >> newfirstName;
      c1.setfirstName(newfirstName);
    }

    void setfirstName2()//Candidate 2
    {
      string newfirstName = "";
      cout << "\nWhat is the new First Name: " << endl;
      cin >> newfirstName;
      c2.setfirstName(newfirstName);
    }

    void setlastName()//Candidate 1
    {
      string newlastName = "";
      cout << "\nWhat is the new Last Name: " << endl;
      cin >> newlastName;
      c1.setlastName(newlastName);
    }

    void setlastName2()//Candidate 2
    {
      string newlastName = "";
      cout << "\nWhat is the new Last Name: " << endl;
      cin >> newlastName;
      c2.setlastName(newlastName);
    }

    void setpartyAff()//Candidate 1
    {
      string newpartyAff = "";
      cout << "\nWhat is your New Party Affliation: " << endl;
      getline(cin, newpartyAff);
      c1.setpartyAff(newpartyAff);
    }

    void setpartyAff2()//Candidate 2
    {
      string newpartyAff = "";
      cout << "\nWhat is your New Party Affliation: " << endl;
      getline(cin, newpartyAff);
      c2.setpartyAff(newpartyAff); 
    }

    void setcurrentVotes()
    {
      int newVotes = 0;
      cout << "\nWhat is the Current Vote Count: " << endl;
      cin >> newVotes;
      c1.setcurrentVotes(newVotes);
    }

    void setcurrentVotes2()
    {
      int newVotes = 0;
      cout << "\nWhat is the Current Vote Count: " << endl;
      cin >> newVotes;
      c2.setcurrentVotes(newVotes);
    }

    //?? NOT SURE HOW TO SET THIS UP TO AUTO UPDATE
    //BASED ON CURRENT VOTE COUNT......
    /*bool setleadStatus() 
    {
      if(c1.getcurrentVotes() > c2.getcurrentVotes())
      {
        return ("WINNING");
      }
      else
      {
        return ("LOSING");
      }
    }*/

    //****************Candidate Menus****************
    
    void menuCandidate1()//Candidate 1 Menu
      {
        int selection = 0;
        cout << "\nWhat would you like to update: " << endl;
        cout << "1.)First Name" << endl;
        cout << "2.)Last Name" << endl;
        cout << "3.)Party Affiliation" << endl;
        cout << "4.)Vote Count" << endl;
        cin >> selection;
        if(selection == 1)
        {
          setfirstName();
        }
        else if(selection == 2)
        {
          setlastName();
        }
        else if (selection == 3)
        {
          setpartyAff();
        }
        else if (selection == 4)
        {
          setcurrentVotes();
        }

        //Clear Screen Refresh
        cout << "\033[2J\033[1;1H";
      }

      void menuCandidate2()//Candidate 2 Menu
      {
        int selection = 0;
        cout << "\nWhat would you like to update: " << endl;
        cout << "1.)First Name" << endl;
        cout << "2.)Last Name" << endl;
        cout << "3.)Party Affiliation" << endl;
        cout << "4.)Vote Count" << endl;
        cin >> selection;
        if(selection == 1)
        {
          setfirstName2();
        }
        else if(selection == 2)
        {
          setlastName2();
        }
        else if (selection == 3)
        {
          setpartyAff2();
        }
        else if (selection == 4)
        {
          setcurrentVotes2();
        }

        //Clear Screen Refresh
        cout << "\033[2J\033[1;1H";
      }
      void displayInfo()
      {
        cout << "*********Candidate 1**********" << endl;
        cout<< "\nFirst Name: " << c1.getfirstName() << endl;
        cout<< "\nLast Name: " << c1.getlastName() << endl;
        cout<< "\nParty Affiliate: " << c1.getpartyAff() << endl;
        cout<< "\nTotal Votes: " << c1.getcurrentVotes() << endl;
        cout << "\nStatus: " << c1.getleadStatus() << endl;
         
      }

      void displayInfo2()
      {
        cout << "**********Candidate 2**********" << endl;
        cout<< "\nFirst Name: " << c2.getfirstName() << endl;
        cout<< "\nLast Name: " << c2.getlastName() << endl;
        cout<< "\nParty Affiliate: " << c2.getpartyAff() << endl;
        cout<< "\nTotal Votes: " << c2.getcurrentVotes() << endl;
        cout << "\nStatus: " << c2.getleadStatus() << endl;
      }
      

      void updateMenu()
      {
        int selection = 3;
        
          
          cout << "\nWhich Candidate would you like to UPDATE: " << endl;
          cout << "\n1.) Candidate 1" << endl;
          cout << "2.) Candiate 2" << endl;
          cout << "3.) Exit program" << endl;
          cin >> selection;
          if(selection == 1)
          {
            menuCandidate1();
          }
          else if (selection == 2)
          {
            menuCandidate2();
          }
          else if (selection == 3)
          {
            cout << "\nHave a Nice Day!!!!" << endl;
          }
        
      }

      void displayBoard()
      {
        cout << "\n********************VOTING DISPLAY******************"<< endl;
        
      }

    


};

int main()
{
  Scoreboard s;
  int selection = 0;
  
  do 
  {
    s.displayBoard();
    s.displayInfo();
    s.displayInfo2();
    s.updateMenu();
  
  }while (selection != 3);
        
    
  
  return 0;
}
