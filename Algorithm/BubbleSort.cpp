#include <bits/stdc++.h>
using namespace std;
int main()
{

                int n;
     cin>> n;   int ary[n];

  for(int i=0;i<n;i++) cin>> ary[i];

  for(int i=0;i<n;i++)
     for(int j=0;j<n-1-i;j++)
        if(ary[j]>ary[j+1])
           swap(ary[j+1],ary[j]);

  for(int i=0; i<n; i++)
     cout<< ary[i]<<" ";

  return 0;

}

