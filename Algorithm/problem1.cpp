#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
       cin>>t; getchar();

    string str1, str2;

    for(int i=1; i<=t; i++)
    {
        getline(cin,str1);
        getline(cin,str2);

        string str3= str1+str2;

        sort(str3.begin(),str3.end());

         for(int j=0; j<str1.size();j++)
                cout<<str3[j];

        cout<<endl;
    }

    return 0;
}
