#include <iostream>
#include <string.h>

#ifdef _WIN32 
#include <windows.h>
#endif

using namespace std;

const int TEN = 10;

int bubbleSort(int sortME[TEN]);
void printList(int listP[TEN]);

int main(){
 
  int number;

  cout << "ENTER LOWEST NUMBER OF TEN: " << endl; 
  cin >> number;

  int list[TEN] = {number + 9,number + 2, number + 8, number + 3, number + 7,
		   number + 4,number + 6,number + 5,number + 10, number + 1};
  //before sort
  cout << "Original Array: " << endl;
  printList(list);
  bubbleSort(list);
  //after sort
  cout << "Final Sorted Array: " << endl;
  printList(list);

#ifdef _WIN32 
  system ("PAUSE");
#endif
  return 0;

  return 0;
}
int bubbleSort(int sortME[TEN]){
  bool notSorted = false;
  int current = 0, index = 1, swap = 0;
  int tail = 9, pass = 1;

  while(current <= tail && !notSorted){
    index = tail;
    notSorted = true;
    while(index > current){
      if(sortME[index] < sortME[index -1]){
        notSorted = false;
        cout << "list[" << index << "] < list[" << index - 1 << "]" << endl;  
        cout << sortME[index] << " <-swapped-int-> "<< sortME[index - 1] << endl;
        swap = sortME[index -1];
        sortME[index - 1] = sortME[index];
        sortME[index] = swap;
        cout << "After Pass: " << pass++ << endl;
        printList(sortME); 
      }
      index--;
    }
    current++;
  }
  return *sortME;
}
void printList(int listP[TEN]){
 
  for(int a = 0; a < 10; a++){
  
    cout << "["<< listP[a] << "]";
  }
  cout << endl << endl;
}
