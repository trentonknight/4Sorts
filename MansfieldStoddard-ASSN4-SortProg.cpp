/////////////////////////////////////////////////////////////////////////
///CODE FILENAME: MansfieldStoddard-ASSN4-SortProg.cpp
///DESCRIPTION:   Program tests the speed of four different sort techniques.
///  DATE:     26 APRIL 11
///  DESIGNER:	Jason N Mansfield
///  FUNCTIONS:   driverFunction(), bubbleSort(), mergeSort(),quickS()
///               quickSort(), insertionSort(), exchange(), createArrays()
///               menuErrorCheck(), pickSorts(), doSort(), clockStop(),
///               verifyARRAY(), sortName()
////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>        
#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;
//maximum size of all arrays: 100000
const int MAX = 100000;
//highest value allowed per random int in array: 30000
const int RAND = 30000;

typedef int (*fP)(int [],int,int);
void driverFunction();
int bubbleSort(int [],int,int);
int mergeSort(int [],int,int);
int quickS(int [],int,int);
int quickSort(int [],int,int);
int insertionSort(int [],int,int);
int exchange(int [],int,int);
void createArrays(int [],int []);
bool menuErrorCheck(char);
void pickSorts(char&,char&);
double doSort(int [],char);
double clockStop(double);
void verifyARRAY(int []);
string sortName(char);

///////////////////////////////////////////////////////////////////////////
///  FUNCTION: main()
///  DESCRIPTION:   simple calls driver function.
///  CALLS TO:  List of programmer-written functions called (names only)
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
int main(){
 
  driverFunction();

#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION: driverfunction()
///  DESCRIPTION:  the driverfunction handles creating of lists followed by 
///                cycling them through functions which verify user input,
///                select sort methods, perform selected sorts, timing of sorts,
///                creating new random lists and selection from user of times in which 
///                to run.
///  CALLS TO: createArrays(), pickSorts(), soSort(), driverFunction()
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:  bubbleSort()
///  DESCRIPTION:  simple bubble sort function
///  INPUT:
///  	Parameters: list[], int left, right.
///                 random int in list[].
///  OUTPUT:   
///  	Return Val: list[]
///  	Parameters: returns list[] sorted.
///  CALLS TO: exchange()
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////
///  FUNCTION: exchange()
///  DESCRIPTION:  exchanges selected int's in array
///  INPUT:
///  	Parameters: list[], int back, int front
///                 front is an index in list as is back.
///  OUTPUT:   
///  	Return Val: *list 
///  	Parameters: list now has two int swapped.
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
int exchange(int list[],int back,int front){
  int temp;
  temp = list[back];
  list[back] = list[front];
  list[front] = temp;
  return *list;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	mergeSort()
///  DESCRIPTION:  merges and then sorts list
///  INPUT:
///  	Parameters: list merge[] and int index selections left and right
///  OUTPUT:   
///  	Return Val: sorted list merge[]
///  CALLS TO:  mergeSort(), exchange()
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
int mergeSort(int merge[],int left,int right){
  cout << "called mergesort.";
  return *merge;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    createArrays()
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
///Parameters: string choice
///OUTPUT:   
///Return Val: string choice
///CALLS TO:  menuErrorCheck, pickSorts
///IMPLEMENTED BY: Mansfield
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
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	doSort()
///  DESCRIPTION:  Calls functions with function pointer and runs a variety
///                of sorts.
///  INPUT:
///  	Parameters: unsorted list[], char sort (user selection)
///  OUTPUT:   
///  	Return Val: returns timer which contains the run time of sorting
///                 method.
///  	Parameters: double timer
///  CALLS TO:  mergeSort(), quickS(),insertionSort(), bubbleSort(), clockStop(),
///             verifyARRAY().
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
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
    functionP = &quickS;
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
///Parameters: string choice
///OUTPUT:   
///Return Val: true of false if user submitted valid choice
///Parameters: bool check
///IMPLEMENTED BY: Jason Mansfield
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
///IMPLEMENTED BY: Jason Mansfield
///////////////////////////////////////////////////////////////////////////////////
double clockStop(double start){
  double stop = clock();
  double time = ((double)(stop - start));
  cout.precision(7);
  cout << fixed << "time " << time << endl;
  return time;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION: verifyARRAY()
///  DESCRIPTION:   verifies that indexes above the below indexes is larger throughout
///                 entire array; Otherwise a Warning message is given.
///  INPUT:
///  	Parameters: sorted list[]
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////
///  FUNCTION: sortName()
///  DESCRIPTION:  recieves user selected char and creates string named
///                after choosen sort method.
///  INPUT:
///  	Parameters: char picked
///  OUTPUT:   
///  	Return Val: string name
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	quickS()
///  DESCRIPTION:  decrements length of array to be read from. This avoids 
///                the quicksort from attempting to read past allocated memory. 
///  INPUT:
///  	Parameters: list array[] and indexes front and back.
///  OUTPUT:   
///  	Return Val: returns sorted array *array
///  CALLS TO:  quickSort()
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
int quickS(int array[],int front,int back) 
{
  quickSort(array, front, back - 1);
  return *array;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:	quickSort()
///  DESCRIPTION:   quickSort breaks the list up via pivot points and partitions
///                 the array for a divide and conquer approach.
///  INPUT:
///  	Parameters: list index[] with current index in the front of
///                 partition start while stop is the end of the partition.
///  OUTPUT:   
///  	Return Val: return sorted list index[] or recurse for furthur partitioning
///                 and exchanges.
///  CALLS TO:  exchange(), quickSort()
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
int quickSort(int index[], int start, int stop)
{
  int front = start;                         
  int back = stop;                          

  if (stop - start >= 1)                   
    {
      int pivot = index[start];       

      while (back > front)                  
	{
	  while (index[front] <= pivot && front <= stop && back > front)  
	    front++;                                    
	  while (index[back] > pivot && back >= start && back >= front) 
	    back--;                                     
	  if (back > front)                                    
	    exchange(index, front, back);                   
	}
      exchange(index, start, back);                                                    
      quickSort(index, start, back - 1); 
      quickSort(index, back + 1, stop);   
    }
        
  return *index;
}
///////////////////////////////////////////////////////////////////////////
///  FUNCTION:  insertionSort()
///  DESCRIPTION:  a basic insertion sort algorithm which takes list and sorts
///                it from less than to greatest.
///  INPUT:
///  	Parameters: int array list[] and index first and last.
///  OUTPUT:   
///  	Return Val: sorted int array list[]
///  IMPLEMENTED BY: Jason Mansfield
//////////////////////////////////////////////////////////////////////////
int insertionSort(int list[],int first,int last){
  int current;
  int hold;
  int walker;

  for(current = first + 1; current <= (last -1); current++){
    hold = list[current];
    walker = current - 1;
    while(walker >= first && hold < list[walker])
      {
        exchange(list,walker,walker + 1);
	walker--;
      }
    list[walker + 1] = hold;
  }
  return *list;
}
