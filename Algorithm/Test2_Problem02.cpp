#include<bits/stdc++.h>
using namespace std;
int length[100], table[100000];
int solve(int n, int remainLength)
{
    table[remainLength+1];
    table[0]=0;

    for(int i=1; i<=remainLength; i++){
        for(int j=0; j<n; j++){
            if(length[j]<=i){
                int temp = table[i-length[j]];

                if( temp != 100000 && temp+1 < table[i])
                    table[i] = temp+1;
            }
        }
    }

    if(table[remainLength] == 100000) return -1;

    return table[remainLength];
}

int main()
{
    cout<<"Problem-02\n";
    int n;  cin>>n;
    for(int i=0; i<n; i++) cin>>length[i];
    int totalLength; cin>>totalLength;

    for(int i=1; i<=totalLength;i++) table[i]= 100000;

    cout<<(solve(n,totalLength));
}
