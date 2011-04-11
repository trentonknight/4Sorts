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
int mergeSort(int []);
int quickSort(int []);
int insertionSort(int []);
void createArrays(int [],int []);
bool menuErrorCheck(char);
string pickSorts();
void doSort(int [],int [],string);
double clockStop(double);

int main(){
  //create empty arrays
  int list_I[MAX] = {0};
  int list_II[MAX] = {0};
  createArrays(list_I,list_II);
  //call pickSorts() to get a verify user choice
  //call doSort which calls function pointers.
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
int mergeSort(int merge[]){
  cout << "called mergesort.";
  return *merge;
}
int quickSort(int quick[]){
  cout << "called quick.";
  return *quick;
}
int insertionSort(int insert[]){
  cout << "called insert.";
  return *insert;
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
  int lists = 0;
  double timer = 0.0;

  while(lists != 2){
    switch(selSrts[lists]){
    case 'M':
      cout << "Merge Sort ";
      functionP = &mergeSort;
      break;
    case 'Q':
      cout << "Quick Sort ";
      functionP = &quickSort;
      break;
    case 'I':
      cout << "Insertion Sort ";
      functionP = &insertionSort;
      break;
    case 'B':
      cout << "Bubble Sort ";
      functionP = &bubbleSort;
      break;
    default:
      cout << "Error! string was corrupted." << endl;
    }
    if(lists == 0){
      timer = clock();
      *l_ONE = (*functionP)(l_ONE);
      clockStop(timer);
    } 
    else{
      timer = clock();
      *l_TWO = (*functionP)(l_TWO);
       clockStop(timer);
    }
    lists++;
  }
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
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:   clockStop
///DESCRIPTION: displays time required to run sort 
///Parameters: clock() stop time
///OUTPUT:   
///Return Val: clock stop time minus start time giving total time of sort run
///CALLS TO: n/a
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
double clockStop(double start){
  double stop = clock();
  double time = ((double)(stop - start));
  cout.precision(7);
  cout << fixed << "time " << time << endl;
  return time;
}
