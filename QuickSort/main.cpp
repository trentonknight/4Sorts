#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>        
#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;
//maximum size of all arrays: 100000
const int MAX = 10;
//highest value allowed per random int in array: 30000
const int RAND = 300;

int callQuick(int list[]);
int quickSort(int [],int ,int );
int medianLeft(int [],int, int );
int exchange(int[],int,int);
int insertionSort(int[],int,int);

int main(){
   
  int *index;

  index = new(nothrow) int[MAX];
  if(!index){
    cout << "Allocation failure.\n" << endl;
  }
   
 
  for(int a = 0; a < 10; a++){
    index[a] = a * 10;
  } 

  callQuick(index);

  cin.get();

  delete [] index;

}

int callQuick(int list[]){
  quickSort(list,0,9);
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
