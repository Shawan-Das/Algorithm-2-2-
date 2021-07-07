#include<bits/stdc++.h>
using namespace std;
int Currency[20], counter=0;


void CoinChange(int n,int coin)
{
    for(int i=0; i<n; i++)
    {
        if(coin==0) break;
        else if(Currency[i]<=coin){
            counter += coin/Currency[i];
            cout<<"Note "<<Currency[i]<<" :"<<coin/Currency[i]<<endl;
            coin = coin%Currency[i];
        }
    }

    cout<<"\n\nTotal : "<<counter<<endl;
}

int main()
{
    int n;  cin>>n;

    for(int i=0; i<n;i++)
        cin>>Currency[i];

    int coin; cin>>coin;

   CoinChange(n,coin);
}

