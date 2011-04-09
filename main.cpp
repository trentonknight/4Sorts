#include <iostream>        
#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;
const int MAX = 25;

typedef int (*fP)(int []);
int bubbleSort(int []);

int main(){

  
  fP functionP;
  
  int test[MAX] = {1,2,4,5,6,7,8,6,4,4,3,2,9,88,44,33};
   
  functionP = &bubbleSort;
  
  *test = (*functionP)(test);



#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;
}
int bubbleSort(int sortME[]){
bool notSorted = false;
  int current = 0, index = 1, swap = 0;
  int tail = 9;

  while(current <= tail && !notSorted){
    index = tail;
    notSorted = true;
    while(index > current){
      if(sortME[index] < sortME[index -1]){
        notSorted = false;
        swap = sortME[index -1];
        sortME[index - 1] = sortME[index];
        sortME[index] = swap;
      }
      index--;
    }
    current++;
  }
  return *sortME;
}
