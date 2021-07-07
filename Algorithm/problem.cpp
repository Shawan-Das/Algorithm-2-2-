#include<bits/stdc++.h>
using namespace std;

struct chips
{
    char name;
  int deadline, price;
};


bool compare(chips a, chips b)
{
    return (a.price > b.price);
}


int main()
{
    int n; cin>>n; chips Array[n];
    int profit=0;
    for(int i=0; i<n;i++)
    {
        cin>>Array[i].name;
        cin>>Array[i].deadline;
        cin>>Array[i].price;
    }

    sort(Array, Array+n,compare);

       int currentDay=1;
   for(int i=0; i<n; i++)
   {
       if(currentDay<=Array[i].deadline)
       {
           cout<<Array[i].name<<" ";
           profit+=Array[i].price;
           currentDay++;
       }
   }
  cout<<"\n"<<profit<<endl;
}
