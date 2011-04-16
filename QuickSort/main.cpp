#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>        
#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;


int quickS(int array[],int front,int back);
int quickSort(int index[], int start, int stop);
int exchange(int list[],int back,int front);

int main(){

  int index[10] = {9,10,1,2,3,99,20,34,8,199};

  quickS(index,0,10);

  cin.get();

  return 0;
}

int quickS(int array[],int front,int back) 
{
  quickSort(array, front, back - 1);
  return *array;
}
int quickSort(int index[], int start, int stop)
{
  int front = start;                         
  int back = stop;
  int fwd = 0;
  int bwd = 0;                          

  if (stop - start >= 1)                   
    {
      int pivot = index[start];
      cout << "\nPivot: " << index[start] << endl << endl;      

      while (back > front)                  
	{
          for(int a = 0; a < 10; a++){
	    cout << "[" << index[a] << "]"; 
	  }
	  cout << endl;
	  while (index[front] <= pivot && front <= stop && back > front)
	    {  
	      front++;
              fwd++;
	    }
          cout << "Move forward -> " << fwd << " to " << index[front] << endl;
          fwd = 0;                                    
	  while (index[back] > pivot && back >= start && back >= front) {
	    back--;
            bwd++;
	  }
	  cout << "Move backwards -> " << bwd << " to " << index[back] << endl;
          bwd = 0;   
           for(int a = 0; a < 10; a++){
	    cout << "[" << index[a] << "]"; 
	  }
	  cout << endl;                                  
	  if (back > front){ 
            cout << "\nexchange " << index[front] << " for " << index[back] << endl << endl;                              
	    exchange(index, front, back);
	  }                   
	}
      exchange(index, start, back);                                                    
      quickSort(index, start, back - 1); 
      quickSort(index, back + 1, stop);   
    }
        
  return *index;
}
int exchange(int list[],int back,int front){
  int temp;
  temp = list[back];
  list[back] = list[front];
  list[front] = temp;
  return *list;
}
