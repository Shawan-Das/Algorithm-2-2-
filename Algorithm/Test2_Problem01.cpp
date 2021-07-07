#include<bits/stdc++.h>
using namespace std;
int length[100], memory[100]={0};
int counter =0;
int solve(int remainLength,int index, int n)
{
    if(remainLength == 0) return counter=counter+1;

   // else if(memory[remainLength]!=0) return counter+=memory[remainLength];

    else if(index == n) return counter;

    else if(remainLength<length[index]) return counter;

    else if(remainLength - length[index]<0) solve(remainLength, 0, n);

        memory[remainLength]= solve(remainLength-length[index], index, n) +
                              solve(remainLength, index+1, n);
        //return counter += 1;
}

int main()
{
    cout<<"Problem-01\n";
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>length[i];

    int totalLength; cin>>totalLength;

    cout<<solve(totalLength,0,n);
    return 0;
}
