#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;

    for(int i=1; i<=t; i++){
        long long int n; cin>>n;
        int counter=0;
        for(int j=1; j<10; j++){
            for(long long int k=j; k<=n; k=(k*10)+j)
              counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}
