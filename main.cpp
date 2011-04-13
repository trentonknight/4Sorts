#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>        
#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;
//maximum size of all arrays: 100000
const int MAX = 1000;
//highest value allowed per random int in array: 30000
const int RAND = 300;

typedef int (*fP)(int [],int,int);
void driverFunction();
int bubbleSort(int [],int,int);
int mergeSort(int [],int,int);
int callQuick(int []);
int quickSort(int [],int,int);
int medianLeft(int [],int,int);
int insertionSort(int [],int,int);
int exchange(int [],int,int);
void createArrays(int [],int []);
bool menuErrorCheck(char);
void pickSorts(char&,char&);
double doSort(int [],char);
double clockStop(double);
void verifyARRAY(int []);
string sortName(char);

int main(){
 
  driverFunction();

#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;
}
void driverFunction(){
  int repeat = 0;
  int avg = 0;
  char runOne = '\0';
  char runTwo = '\0';
  double timeONE = 0.0;
  double timeTWO = 0.0;
  //create empty arrays
  int list_I[MAX] = {0};
  int list_II[MAX] = {0};


  createArrays(list_I,list_II);
  //call pickSorts() to get a verify user choice
  pickSorts(runOne,runTwo);
  //call doSort which calls function pointers.
  cout << "Enter the number of times to repeat each sort (1 or more): " << endl;
  cin >> repeat;
  avg = repeat;

  while(repeat != 0){
    timeONE = doSort(list_I,runOne) + timeONE;
    timeTWO = doSort(list_II,runTwo) + timeTWO;
    repeat--;
    if(repeat != 0){
      createArrays(list_I,list_II);
    }
  }
  cout << "SORTING RESULTS" << endl;
  cout << "---------------" << endl;
  cout << sortName(runOne) << setw(5) << "  " << timeONE/avg
       << " clock ticks on average" << endl;
  cout << sortName(runTwo) << setw(5) << "  " << timeTWO/avg
       << " clock ticks on average" << endl;


#ifdef _WIN32
  system ("PAUSE");
#endif

  driverFunction();
}
int bubbleSort(int list[],int left,int right){
  bool ex = true;
  int index = 0;

  while(ex) 
    {
      ex = false;
      index++;

      for (int i = 0; i < MAX - index; i++) 
	{
	  if (list[i] > list[i + 1]) 
	    {
	      exchange(list,i,i + 1);
	      ex = true;
	    }
	}
    }
  return *list;
}
int exchange(int list[],int back,int front){
  int temp;
  temp = list[back];
  list[back] = list[front];
  list[front] = temp;
  return *list;
}
int mergeSort(int merge[],int left,int right){
  cout << "called mergesort.";
  return *merge;
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
void pickSorts(char& one,char& two){
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
    pickSorts(one,two);
  }
  check = menuErrorCheck(choice[1]);
  if(!check){
    choice.clear();
    pickSorts(one,two);
  }
  one = choice[0];
  two = choice[1];
}
double doSort(int list[],char sort){
  fP functionP;
  double timer = 0.0;

  switch(sort){
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
  timer = clock();
  *list = (*functionP)(list,0,MAX);
  clockStop(timer);
  verifyARRAY(list);

  return timer;
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
    exit(0);
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
void verifyARRAY(int list[]){
  bool ver = true;
  int invalid = 0;

  for(int a = 1; a < MAX -1; a++){
    if(list[a] < list[a - 1]){
      ver = false;
      invalid++;
    }
    if(list[a + 1] < list[a]){
      ver = false;
      invalid++;
    }
  }
  if(ver){
    cout << "Sort Validated." << endl;
  }
  else{
    cout << "WARNING!: " << invalid << " invalid matches." << endl;
  }
}
string sortName(char picked){

  string name;

  switch(picked){
  case 'M':
    name = "Merge Sort";
    break;
  case 'Q':
    name = "Quick Sort";
    break;
  case 'I':
    name = "Insertion Sort";
    break;
  case 'B':
    name = "Bubble Sort";
    break;
  default:
    cout << "Whoops! Character corrupted." << endl;
  }
  return name;

}
///quicksort functions below
int quickSort(int list[],int left,int right){
  int pivot;
  int sortLeft;
  int sortRight; 

  if((right - left) > 0){
    medianLeft(list,left,right);
    pivot = list[left];
    sortLeft = left + 1;
    sortRight = right;

    while(sortLeft <=  sortRight){
      while(list[sortLeft] < pivot){
	sortLeft++;
      }
      while(list[sortRight] >= pivot){
	sortRight--;
      }
      if(sortLeft <= sortRight)
	{
          exchange(list,left,right);
          sortLeft++;
          sortRight--;
	}
    }
  ///next phase
  list[left] = list[sortLeft - 1];
  list[sortLeft - 1] = pivot;
  if(left < sortRight){
    quickSort(list,left,sortRight - 1);
  }
  if(sortLeft < right){
    quickSort(list,sortLeft,right);
  }
 }///end if
  else{
    insertionSort(list,left,right);
  }
  return *list;
}
int medianLeft(int list[],int left, int right){
  int mid;

  mid = (left + right)/2;

  if(list[left] > list[mid]){
    exchange(list,left,mid);
  }
  if(list[left] > list[right]){
    exchange(list,left,right);
  }
  if(list[mid] > list[right]){
    exchange(list,mid,right);
  }
  exchange(list,left,mid);

  return *list;
}
int insertionSort(int list[],int first,int last){
  int current;
  int hold;
  int walker;

  for(current = first + 1; current <= last; current++){
    hold = list[current];
    walker = current - 1;
    while(walker >= first && hold < list[walker])
      {
	list[walker + 1] = list[walker];
	walker--;
      }
    list[walker + 1] = hold;
  }
  return *list;
}
