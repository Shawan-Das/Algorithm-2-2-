#include<bits/stdc++.h>
using namespace std;

int numberSearch(int ary[], int low, int high, int key)
{
    if(low<=high)
    {
        int mid = (low+high)/2;
        if(ary[mid]== key) return mid;
        else if( key > ary[mid]) return numberSearch(ary, mid+1, high, key);
            else return numberSearch(ary, low, mid-1, key);
    }
    else return -1;
}


int main()
{
    int n,key;
     cin>>n;
    int ary[n];
    for(int i=0; i<n; i++) cin>>ary[i];
    cin>>key;

    int flag, low=0, high=n, mid;

    while(low<=high)
    {
        mid= (low+high)/2;
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

       int master = numberSearch(ary, 0, n, key);
       if( master == -1) cout<<"Number not Found"<<endl;
       else cout<<key<<" is in position : "<<master+1<<endl;

    return 0;
}
