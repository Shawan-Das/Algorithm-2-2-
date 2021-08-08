#include<bits/stdc++.h>
using namespace std;

int recursion(int ary[], int low, int high, int key)
{
    if(low<=high)
    {
        int mid = (low+high)/2;
        if(ary[mid]== key) return mid;
        else if( key > ary[mid]) return recursion(ary, mid+1, high, key);
            else return recursion(ary, low, mid-1, key);
    }
    else return -1;
}

void iterative(int ary[], int low, int high, int key)
{
    int flag=-1;
        while(low<=high)
    {
        int mid= (low+high)/2;
        if(ary[mid]==key)
        {
            cout<<key<<" is in position : "<<mid+1<<endl;
            flag =1; break;
        }
        else if(key>ary[mid]) low=mid+1;
        else high = mid-1;
        flag =-1;
    }
    if(flag == -1) cout<<"Number not found"<<endl;
}


int main()
{
    int n,key;
     cin>>n;
    int ary[n];
    for(int i=0; i<n; i++) cin>>ary[i];
    cin>>key;

       cout<<"Recursion: 1"<<endl<<"Iterative: 2"<<endl;
       int t; cin>>t;
       if(t==1){
            int flag = recursion(ary, 0, n, key);
            if( flag == -1) cout<<"Number not Found"<<endl;
            else cout<<key<<" is in position : "<<flag+1<<endl;
       }

       if(t==2) iterative(ary, 0, n, key);

       return 0;
}
