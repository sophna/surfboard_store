#include <iostream>
#include <string>
#include <iomanip> //should be included in order to use 'setfill'
#include <cassert>

const int HEADER_WIDTH = 58; //total lenght of the stream to output the program data
const int HEADER_WIDTH_LEFT_ALIGN = 53; //number of chars for banner including text
const int HEADER_WIDTH_RIGHT_ALIGN = 5; //numbers of chars for the banner to complete up to 70 chars
const float SMALL_BOARD_PRICE = 175.00; // assign value/price to the constant small corresponding for small size surf board
const float MEDIUM_BOARD_PRICE = 190.00; // assign value/price to the constant medium corresponding for medium size surf board
const float LARGE_BOARD_PRICE = 200.00; // assign value/price to the constant large corresponding for large size surf board
const float XXXS_BOARD_PRICE = 100.00; // assign value/price to the constant large corresponding for xxxs size surf board

using namespace std;

//declare function prototypes, they should be declared before function main
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXxxs);
void ShowUsage(void);
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXxxs);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXxxs);

int main(void) //function main
{
  char user_selection;

  int total_small_purchased=0; //declare initial number of small surf boards purchased as zero
  int total_medium_purchased=0; //declare initial number of medium surf boards purchased as zero
  int total_large_purchased=0; //declare initial number of lage surf boards purchased as zero
  int total_xxxs_purchased=0; //declare initial number of xxxs surf boards purchased as zero

  cout << setfill('*'); //use setfill to change the fill char to *
  cout << setw(HEADER_WIDTH) << "" << endl; //set the width of the line to 70 chars, output a null char to print the whole stream
  cout << setw(HEADER_WIDTH_LEFT_ALIGN) << "Welcome to my Johnny Utah's PointBreak Surf Shop" << setw(HEADER_WIDTH_RIGHT_ALIGN) << "" << endl; //message is 34 chars lenght, fill up to HEADER_WIDTH_LEFT_ALIGN chars and then up to HEADER_WIDTH_RIGHT_ALIGN chars after the message
  cout << setw(HEADER_WIDTH) << "" << endl << endl; //output the * in the third row
  
  cout << setprecision(2)<<fixed; //use setprecision(2) to use 2 decimal places, and 'fixed' to use fixed format to show all digits

  ShowUsage(); //call function to show how to use the program to the user

  while (true)
  {
    cin.clear(); //find out that is a good practice to flush the cin before user input in loop programs that continiously ask for user input
    cout << "Please enter selection: ";
    cin >> user_selection; //assign user input to variable user_selection

    switch (user_selection) //will determine what it will happen depending on user input
    {
      case 'c': //user enters lower case c
      case 'C': //user enters upper case c
        {
          DisplayPurchase(total_small_purchased,total_medium_purchased,total_large_purchased, total_xxxs_purchased);
          break;
        }
      case 'p': //user enters lower case p
      case 'P': //case user enters upper case p
        {
          MakePurchase(total_small_purchased,total_medium_purchased,total_large_purchased, total_xxxs_purchased);
          break;
        }
      case 'q': //user enters lower case q
      case 'Q': //user enters upper case q
        {
          cout << "Thank you" << endl; //display thank you
          return 0; //returning from main function finish the program
        }
      case 's': //user enters lower case s
      case 'S': //user enters uppper case s
        {
          ShowUsage();
          break;
        }
      case 't': //user enters lower case t
      case 'T': //user enters upper case t
       {
         DisplayTotal(total_small_purchased,total_medium_purchased,total_large_purchased, total_xxxs_purchased);
         break;
       }
      default:
      {
        //do nothing
      }
        
    }
  }



	return 0;
}
//define body of function DisplayPurchase
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXxxs)
{
  if(iTotalSmall > 0) //if a number other than zero is entered in small
  {
    cout << "The total number of smalls surfboards is " << iTotalSmall << endl;
  }

  if(iTotalMedium > 0) //if a number other than zero is entered in medium
  {
    cout << "The total number of medium surfboards is " << iTotalMedium << endl;
  }

  if(iTotalLarge > 0) //if a number other than zero is entered in large
  {
    cout << "The total number of large surfboards is " << iTotalLarge<< endl;
  }
  if(iTotalXxxs> 0) //if a number other than zero is entered in xxxs
  {
    cout << "The total number of xxxs surfboards is " << iTotalXxxs << endl;
  }

  if ( (iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0) && (iTotalXxxs == 0)) //if no purchases have been made
  {
    cout << "No purchases made yet" << endl;
  }

  cout << endl; //Add a new line after the output is printed from this function
}

//a function to show the user how to use the program.
void ShowUsage(void)
{
  cout << "To show program usage 'S'" << endl;
  cout << "To purchase a surfboard press 'P'" << endl;
  cout << "To display current purchases press 'C'" << endl;
  cout << "To display tolal amount due press 'T'" << endl; //the output in the requirements showed the word tolal 
  cout << "To quit the program press 'Q'" << endl << endl; //add an extra new line at the end of this sentence
}
        
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXxxs)
{
  int quantity;
  char surfboard_type;
  cout << "Please enter the quanity and type (X=extra small, S=small, M=medium, L=Large, of surfboards you would like to purchase:";
   
  if (cin >> quantity) //cin returns true in case a number was entered, if an invalid input it will return false
  {
     //do nothing
  }
  else
  {
    assert(0); //according to c++ reference, passing a zero to the assert function will stop program execution
  }

  cin >> surfboard_type;

  if( (surfboard_type == 's') || (surfboard_type == 'S'))
  {
    iTotalSmall = iTotalSmall + quantity; // increase by the number of purchased boards, we are modifyng by reference parameter.
  }

  if( (surfboard_type == 'm') || (surfboard_type == 'M'))
  {
    iTotalMedium = iTotalMedium + quantity; // increase by the number of purchased boards, we are modifyng by reference parameter.
  }

  if( (surfboard_type == 'l') || (surfboard_type == 'L'))
  {
    iTotalLarge = iTotalLarge + quantity; // increase by the number of purchased boards, we are modifyng by reference parameter.
  }
  if( (surfboard_type == 'x') || (surfboard_type == 'X'))
  {
    iTotalXxxs = iTotalXxxs + quantity; // increase by the number of purchased boards, we are modifyng by reference parameter.
  }

  cout << endl; //Add a new line after the output is printed from this function
}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXxxs)
{
  float amountDue=0;
  if(iTotalSmall > 0) //if total small is greater than zero
  {
    cout << "The total number of smalls surfboards is " << iTotalSmall << " at a total of " << '$' << (iTotalSmall*SMALL_BOARD_PRICE) << endl;
    amountDue = amountDue+(iTotalSmall*SMALL_BOARD_PRICE);
  }

  if(iTotalMedium > 0) //if total medium is greater than zero
  {
    cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of " << '$' << (iTotalMedium*MEDIUM_BOARD_PRICE) << endl;
    amountDue = amountDue+(iTotalMedium*MEDIUM_BOARD_PRICE);
  }

  if(iTotalLarge > 0) //if total large is greater than zero
  {
    cout << "The total number of large surfboards is " << iTotalLarge << " at a total of " << '$' << (iTotalLarge*LARGE_BOARD_PRICE) << endl;
    amountDue = amountDue+(iTotalLarge*LARGE_BOARD_PRICE);
  }
  if(iTotalXxxs > 0) //if total xxxs is greater than zero
  {
    cout << "The total number of extra small surfboards is " << iTotalXxxs << " at a total of " << '$' << (iTotalXxxs*XXXS_BOARD_PRICE) << endl;
    amountDue = amountDue+(iTotalXxxs*XXXS_BOARD_PRICE);
  }
  
  if ( (iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0) && (iTotalXxxs == 0))
  {
    cout << "No purchases made yet" << endl; 
  }

  if (amountDue > 0.0)
  {
    cout << "Amount due: " << '$' << amountDue << endl; 
  }

  cout << endl; //Add a new line after the output is printed from this function
}