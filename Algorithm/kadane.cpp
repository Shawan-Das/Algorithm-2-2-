#include<bits/stdc++.h>
using namespace std;
int Array[10000], maxSum=-100000;
int low=0, high;
int arraySum(int n)
{
    int cSum = 0, index;

    for(int i=0; i<n; i++)
    {
        cSum += Array[i];
        if(cSum < Array[i]){ cSum =Array[i]; index= i;}
        if(cSum > maxSum){ maxSum = cSum; high= i; low =index;}
    }
    return maxSum;
}

int main()
{
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>Array[i];

    int sum = arraySum(n);
    for(int i=low; i<=high; i++)
        cout<<Array[i]<<" ";
        cout<<"\nSum of maximum Sub Array :"<<sum<<endl;
    return 0;
}
/*
7
1 2 -3 -4 3 -1 -1
*/
