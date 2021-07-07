#include<bits/stdc++.h>
using namespace std;
int Array[100000];
int ax_Array[100000];

void mergArrays(int low,int mid,int high)
{
    int i=low, j=mid+1, k=low;

    while(i<=mid && j<=high)
        if(Array[i]<Array[j]) ax_Array[k++]=Array[i++];
              else            ax_Array[k++]=Array[j++];

    while(i<=mid)  ax_Array[k++]=Array[i++];

    while(j<=high) ax_Array[k++]=Array[j++];

    for(i=low;i<=high;i++) Array[i]=ax_Array[i];
}

void mergSort(int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergSort(low,mid);
        mergSort(mid+1,high);
        mergArrays(low,mid,high);
    }
    else return;
}

int main(){
    int n;
    cin>> n;
    for(int i=0;i<n;i++) cin>> Array[i];
    mergSort(0,n-1);

    for(int i=0;i<n;i++) cout<< Array[i]<<" ";

    return 0;
}

