#include<bits/stdc++.h>
#include<string.h>
using namespace std;
long int d=256;
RabinKarp(string str1, string str2,long int q)
{
    int n= str1.size();
    int m= str2.size();
    int p=0, t=0;
   //long int  h=pow(d,m-1)%q;
      int h=1;
    for(int i=0; i<m-1; i++) h=(h*d)%q;
    cout<<"h- "<<h;
    for(int i=0; i<m; i++)
        {
            p = ((d*p) + str2[i])%q;
        t = ((d*t) + str1[i]) %q;
        }
     cout<<p<<"-"<<t<<endl;
int i,j;
    for(i=0; i<=n-m; i++){
         cout<<t<<endl;
        if(p==t){

           for(j=0; j<m; j++)
            if(str1[i+j] != str2[j]) break;

        if(j==m) cout<<"Pattern occurs in index : "<<i<<endl;

        }

            if(i<n-m)
                {
        t= (d*(t- str1[i]*h) + str1[i+m])%q;
        if(t<0) t+=q;
    }
}

}

int main()
{
    string str1, str2;
    getline(cin,str1);
    getline(cin,str2);
// cin>>str1; cin>>str2;
   // cout<<str1<<endl;
   // cout<<str2<<endl;
    long int q= 31;
     RabinKarp(str1,str2,q);

    return 0;
}

