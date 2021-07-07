#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
      cin>> n;   int ary[n];

    for(int i=0;i<n;i++) cin>> ary[i];

    for(int i=0;i<n;i++){
            int minimum=ary[i];
            int index=i;
        for(int j=i+1;j<n;j++){
            if(minimum>ary[j])
            {
                minimum=ary[j];
                 index = j;
            }
          }
          swap(ary[i],ary[index]);
       }
       for(int i=0;i<n;i++) cout<<ary[i]<<" ";

       return 0;
}
