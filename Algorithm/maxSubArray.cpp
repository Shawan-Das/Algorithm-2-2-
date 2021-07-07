#include<bits/stdc++.h>
using namespace std;
int aray[10000], sum1=-100000, sum2=-100000;
int Low =0, High =0;

int sumOfArray(int low, int mid, int high)
{
    int sm1 =0;
    for(int i=low; i<=mid; i++){
            sm1 += aray[i];
        if(sm1 >= sum1) sum1=sm1;
    }

    int sm2= 0;
    for(int i=mid+1; i<=high; i++){
            sm2 +=aray[i];
    if(sm2 >= sum2) sum2=sm2;
    }

    return max(max(sm1, sm2),sm1+sm2);
}

int subArray(int low, int high)
{
    if(low == high) return aray[low];

       int mid = (low+high)/2;

        subArray(low, mid);
        subArray(mid+1, high);
        return max(max(subArray(low, mid),subArray(mid+1, high)),sumOfArray(low, mid, high));
}

int main()
{
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>aray[i];

    int maxSum = subArray(0, n-1);
   // for(int i=Low; i<=High; i++) cout<<aray[i]<<" ";
    cout<<"\nSum = "<<maxSum<<endl;
    return 0;
}

/*
cout<<"Low ="<<low<<"\t"<<"High ="<<mid<<"\t"<<"Sum ="<<sm1<<endl;
    cout<<"Low ="<<mid+1<<"\t"<<"High ="<<high<<"\t"<<"Sum ="<<sm2<<endl;
    cout<<"Low ="<<low<<"\t"<<"High ="<<high<<"\t"<<"Sum ="<<sm1+sm2<<endl;
if(sm1>= sm2 && sm1>= sm1+sm2){ Low =low; High =mid; }
    else if(sm2>= sm1 && sm2>= sm1+sm2){ Low =mid+1; High =high;}
    else                            { Low =low; High =high; }
*/
