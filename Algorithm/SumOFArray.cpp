#include<bits/stdc++.h>
using namespace std;

int ArraySum(int Array[],int low, int high)
{
    if(low == high) return Array[low];
    else if(high-low==1) return Array[low]+Array[high];
    else{
        int mid = (low+high)/2;
        return ArraySum(Array,low, mid)+ ArraySum(Array,mid+1,high);
    }
}

int main()
{
    int n;  cin>>n; int Array[n];
    for(int i=0; i<n; i++) cin>> Array[i];


    cout<<"Sum of Array: "<<ArraySum(Array,0,n-1);

    return 0;
}
