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

int callQuick(int list[]);
int quickSort(int [],int ,int );
int medianLeft(int [],int, int );
int exchange(int[],int,int);
int insertionSort(int[],int,int);

int main(){
   
  int array[10] = {79,4,7,9,11,345,12233,34,99,2};

  callQuick(array);

  cin.get();

}

int callQuick(int list[]){
  quickSort(list,0,MAX);
  return *list;
}
int quickSort(int list[],int left,int right){
  int pivot;
  int sortLeft;
  int sortRight;  

  if((right - left) > 0){
    medianLeft(list,left,right);
    pivot = list[left];
    sortLeft = left + 1;
    sortRight = right;
    while(list[sortLeft] <  list[sortRight]){
      sortLeft = sortLeft + 1;
    }
       while(list[sortRight] >= pivot){
	 sortRight = sortRight - 1;
       }
    exchange(list,sortLeft,sortRight);
    sortLeft = sortLeft + 1;
    sortRight = sortRight - 1;
  }///end if
  ///next phase
  list[left] = list[sortLeft - 1];
  list[sortLeft - 1] = pivot;
  if(left < sortRight){
    quickSort(list,left,sortRight - 1);
  }
  if(sortLeft < right){
    quickSort(list,sortLeft,right);
  }
  else{
    insertionSort(list,left,right);
  }
  return *list;
}
int medianLeft(int list[],int left, int right){
  int mid = 0;

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
int exchange(int list[],int back,int front){
  int temp;
  temp = list[back];
  list[back] = list[front];
  list[front] = temp;
  return *list;
}
int insertionSort(int list[],int left,int right){

  return *list;
}
