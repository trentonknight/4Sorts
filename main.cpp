#include <iostream>
#include <stdlib.h>
#include <ctime>        
#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;
//maximum size of all arrays: 100000
const int MAX = 1000;
//highest value allowed per random int in array: 30000
const int RAND = 300;

typedef int (*fP)(int []);
int bubbleSort(int []);
void createArrays(int [],int []);
bool menuErrorCheck(char);
string pickSorts();
void doSort(int [],int [],string);

int main(){
  //create empty arrays
  int list_I[MAX] = {0};
  int list_II[MAX] = {0};
  createArrays(list_I,list_II);
  doSort(list_I,list_II,pickSorts());
  
  



#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;
}

int bubbleSort(int list[]){
  bool exchange = true;
  int index = 0;
  int temp;

  while(exchange) 
    {
      exchange = false;
      index++;

      for (int i = 0; i < MAX - index; i++) 
	{
	  if (list[i] > list[i + 1]) 
	    {
	      temp = list[i];
	      list[i] = list[i + 1];
	      list[i + 1] = temp;
	      exchange = true;
	    }
	}
    }
  return *list;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    createArrays
///DESCRIPTION: inserts random int into arrays
///INPUT:
///Parameters: random int make
///OUTPUT:   
///Return Val: int *arrayOne and *arrayTwo filled with random int 
///CALLS TO:  randMAKE
///IMPLEMENTED BY: Jason Mansfield
///////////////////////////////////////////////////////////////////////////////////
void createArrays(int listOne[],int listTwo[]){
  srand(time(NULL));
  for(int a = 0; a <= MAX; a++){
    listOne[a] = rand() % RAND + 1;
    listTwo[a] = listOne[a];
  }
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    pickSorts
///DESCRIPTION:  retrieve user input to chooce two sort functions
///INPUT:
///Parameters: string choice[0] and choice[1] (NULL)
///OUTPUT:   
///Return Val: string choice[0] and choice[1] (with sorts selections)
///CALLS TO:  menuErrorCheck, pickSorts (if error function recurses)
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
string pickSorts(){
  bool check;
  string choice;
		
  cout << "\nChoose two sorts you wish to compare:\n"
       <<"\tB = Bubble sort\n"
       <<"\tI = Insertion sort\n"
       <<"\tM = Merge sort\n"
       <<"\tQ = Quick sort\n"
       <<"\tEE = Exit program"
       << endl;
  cout << "\nEnter two letter choices (or EE to exit): ";
  cin >> choice;
  check = menuErrorCheck(choice[0]);
  if(!check){
    choice.clear();
    pickSorts();
  }
  check = menuErrorCheck(choice[1]);
  if(!check){
    choice.clear();
    pickSorts();
  }
  return choice;
}
void doSort(int l_ONE[],int l_TWO[],string selSrts){
   fP functionP;

   functionP = &bubbleSort;
  *l_ONE = (*functionP)(l_ONE);

}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    menuErrorCheck
///DESCRIPTION: verifies user input for mistakes
///INPUT:
///Parameters: string inChoice[0] and inChoice[1]
///OUTPUT:   
///Return Val: true of false if user submitted valid choices
///Parameters: bool check
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
bool menuErrorCheck(char choice)
{ bool check = false;
  switch(choice){
  case 'M':
    check = true;
    break;
  case 'Q':
    check = true;
    break;
  case 'I':
    check = true;
    break;
  case 'B':
    check = true;
    break;
  case 'E':
    check = true;
    break;
  default:
    cout << "Whoops! Character not recognized:" << endl;
    check = false;
  }
  return check;

}
