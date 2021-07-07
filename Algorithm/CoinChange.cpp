#include<bits/stdc++.h>
using namespace std;
int Currency[20], counter=0;

int CoinChange(int i,int n, int coin)
{
     if(i>=n) return 0;
else if(coin==0) return 0;

    else if(Currency[i]<=coin){
        cout<<"Note "<<Currency[i]<<" :"<<coin/Currency[i]<<endl;
        counter+= coin/Currency[i];
        return coin%Currency[i] + CoinChange(i+1,n,coin%Currency[i]);
    }

    else CoinChange(i+1,n,coin);
}

int main()
{
    int n;  cin>>n;

    for(int i=0; i<n;i++)
        cin>>Currency[i];

    int coin; cin>>coin;

   CoinChange(0,n,coin);

   cout<<"\n\nTotal : "<<counter<<endl;
}
