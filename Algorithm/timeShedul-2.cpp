#include<bits/stdc++.h>
using namespace std;
struct Time
{
    int name;
    int Start;
    int End;
};
Time Array[1000];
void Sorting(int n)
{
    for(int i=0;i<n;i++)
       for(int j=0;j<n-i-1;j++)
         if(Array[j].End > Array[j+1].End)
            swap(Array[j+1],Array[j]);
}

void TimeSeter(int i, int n, int endTime)
{
    if(i>=n) return;
    else if(Array[i].Start>=endTime)
        {
            cout<<"Activity: "<<Array[i].name<<"  From: "<<Array[i].Start<<"  To: "<<Array[i].End<<endl;
            TimeSeter(i+1, n, Array[i].End);
            return;
        }
    else TimeSeter(i+1, n, endTime);
    return;
}


int main()
{
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>Array[i].name;
        cin>>Array[i].Start;
        cin>>Array[i].End;
    }
     Sorting(n);
     TimeSeter(0,n,-1);
     return 0;
}

