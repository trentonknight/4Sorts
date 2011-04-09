#include <iostream>
#include <stdlib.h>
#include <ctime>        
#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;
//maximum size of all arrays: 100000
const int MAX = 100;
//highest value allowed per random int in array: 30000
const int RAND = 100;

typedef int (*fP)(int []);
int bubbleSort(int []);
void createArrays(int [],int []);

int main(){
  fP functionP;
  
  int list_I[MAX] = {0};
  int list_II[MAX] = {0};
  createArrays(list_I,list_II);
  functionP = &bubbleSort;
  *list_II = (*functionP)(list_I);



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
