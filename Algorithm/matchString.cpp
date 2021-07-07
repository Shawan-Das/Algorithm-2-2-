#include <bits/stdc++.h>
using namespace std;
string text, match;
void finding()
{
    int n = text.size();
    int m = match.size();


    for (int i=0; i<=n-m; i++)
    {
        int j;
        for (j = 0; j<m; j++)
            if (text[i+j] != match[j]) break;


        if (j==m) cout << "Pattern occurs in index :" <<i<< endl;
    }
}

int main()
{
         getline(cin,text);
         getline(cin,match);

         finding();

    return 0;
}
