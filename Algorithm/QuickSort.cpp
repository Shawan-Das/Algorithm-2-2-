#include<bits/stdc++.h>
using namespace std;
int Array[50];

void swaping(int i, int j) {
  int t = Array[i];
  Array[i] = Array[j];
  Array[j] = t;
}


int part(int low, int high){

  int mark = Array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++){
    if (Array[j] <= mark) {
      i++;
      swaping(i,j);
    }
  }
  swaping(i + 1, high);
  return (i + 1);
}


void quickSort(int low, int high) {
  if (low < high) {

    int f = part(low, high);
    quickSort(low, f - 1);
    quickSort(f + 1, high);
  }
}


int main() {
  int n;
  cout<<"Number of input: ";
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>Array[i];
  }

  quickSort(0,n - 1);

 for(int i=0; i<n;i++){
    cout<<Array[i]<<" ";
 }

  return 0;
}
