#include<bits/stdc++.h>
using namespace std;
int Array[100000];
int minimum;
void mergSort(int low, int high)
{
    if( low == high){
        if(minimum > Array[low])
              minimum = Array[low];
              return;
    }

    if(high - low == 1)
    {
        if(Array[low]<Array[high] && minimum>Array[low])
            minimum = Array[low];
        else if(minimum>Array[high])
            minimum = Array[high];
        return;
    }

        int mid=(low+high)/2;
        mergSort(low,mid);
        mergSort(mid+1,high);
}

int main(){
    int n;
    cin>> n;
    for(int i=0;i<n;i++) cin>> Array[i];
    minimum = Array[0];

    mergSort(0,n-1);

    cout<< minimum<<endl;

    return 0;
}


