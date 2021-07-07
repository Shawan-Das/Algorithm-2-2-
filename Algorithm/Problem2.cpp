#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int Array[n];
    int minimum;
    for(int i=0; i<n; i++) cin>>Array[i];

    int low=0, high= n-1;
    while(low<high)
    {
        int mid = (low+high)/2;

        if(Array[mid]< Array[mid-1] && Array[mid]>Array[mid+1]){
            minimum = Array[mid]; break;
        }
    else if(Array[mid+1]<Array[mid]){
           minimum =Array[mid+1]; break;
       }
    else if(Array[mid]<Array[high]) high = mid;
    else low =mid;
    }
    cout<<minimum<<endl;
}
