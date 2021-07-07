#include<bits/stdc++.h>
using namespace std;
int Coins[]={1,2,5,10,20,50,100,500,1000}, temp[100];

int CoinChange(int note, int n)
{
    if(note==0) return 0;
    if(temp[note]!=-1) return temp[note];
    int minValue=INT_MAX;
    for(int i=0; i<n; i++){
        if(Coins[i]<=note)
        {
            int tempValue = 1 + CoinChange(note-Coins[i],n);

            if(tempValue<minValue)
            minValue = tempValue;
        }
        temp[note]= minValue;
    }
    return minValue;
}

int main()
{
    int n=9;
    int note; cin>>note;
for(int k=0; k<100; k++)temp[k]=-1;
    cout<<CoinChange(note,n);
    return 0;

}
