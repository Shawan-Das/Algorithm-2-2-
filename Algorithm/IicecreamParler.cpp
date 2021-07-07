#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int k=1; k<=t; k++)
    {
        int m; cin>>m;
        int n; cin>>n; int cost[n];
        int f =0;

        for(int c=0; c<n; c++) cin>>cost[c];

        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
        if(cost[i]+cost[j]== m){
            cout<<i+1<<"\t"<<j+1<<endl;
            f=1; break;
        }
    }
    return 0;
}
