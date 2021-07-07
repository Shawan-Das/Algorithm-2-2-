#include<bits/stdc++.h>
using namespace std;
int Array[100000], aray[100000];

void Merge(int low , int mid1, int mid2, int high)
{
    int i= low, j= mid1+1, k=mid2+1, index=low;

    while( i<=mid1 && j<=mid2 && k<=high)
        if(Array[i]< Array[j] && Array[i]< Array[k]) aray[index++]=Array[i++];
   else if(Array[j]< Array[i] && Array[j]< Array[k]) aray[index++]=Array[j++];
   else   aray[index++]=Array[k++];

    while(i<=mid1 && j<=mid2)
        if(Array[i]< Array[j]) aray[index++]=Array[i++];
        else  aray[index++]=Array[j++];

    while(i<=mid1 && k<=high)
        if(Array[i]< Array[k]) aray[index++]=Array[i++];
        else  aray[index++]=Array[k++];

    while(j<=mid2 && k<=high)
        if(Array[j]< Array[k]) aray[index++]=Array[j++];
        else  aray[index++]=Array[k++];

    while(i<=mid1) aray[index++]= Array[i++];
    while(j<=mid2) aray[index++]= Array[j++];
    while(k<=high) aray[index++]= Array[k++];

    for(int i=low; i<=high; i++)Array[i]=aray[i];

}

void devide(int low, int high)
{
     if(high-low == 1){
        if(Array[low]>Array[high])
            swap(Array[low],Array[high]);
        return;
     }
     else if(low==high) return;
     else if(low>high) return;

        int mid1 =low + (high-low)/3;
    int mid2 =low + (2*mid1);

    devide(low, mid1);
    devide(mid1+1, mid2);
    devide(mid2+1, high);
    Merge(low, mid1, mid2, high);

}
int main()
{
    int n; cin>>n;

    for(int i=0; i<n; i++) cin>> Array[i];
    devide(0,n-1);

    for(int i=0; i<n; i++) cout<< Array[i]<<" ";
}
