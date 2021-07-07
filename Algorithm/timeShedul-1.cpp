#include<bits/stdc++.h>
using namespace std;

struct Time
{
    int name;
    int Start;
    int End;
};
Time Array[1000];

void TimeSeter(int n)
{
    for(int i=0;i<n;i++)
       for(int j=0;j<n-i-1;j++)
         if(Array[j].End > Array[j+1].End)
            swap(Array[j+1],Array[j]);

    cout<<"Activity: "<<Array[0].name<<"  From: "<<Array[0].Start<<"  To: "<<Array[0].End<<endl;

    int endTime= Array[0].End;

    for(int i=1; i<n; i++)
    {
        if(Array[i].Start>=endTime)
        {
            cout<<"Activity: "<<Array[i].name<<"  From: "<<Array[i].Start<<"  To: "<<Array[i].End<<endl;
            endTime = Array[i].End;
        }
    }
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

     TimeSeter(n);
}
