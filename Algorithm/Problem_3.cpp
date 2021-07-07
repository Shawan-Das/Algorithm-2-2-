#include<bits/stdc++.h>
using namespace std;

void vowel(string str, int n){
    string str1; int j=0;
    for(int i=0; i<n; i++){
        cout<<str[i];
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        if(str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u' ||
           str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U')
           str1[j++]= str[i];
    }
    str1[j]== '\0';
    for(int i=0; i<j; i++){
        cout<<str1[i];
    }
    cout<<endl;

    return;
}

void strfun(string str){
    string str1;
    int n= str.size();
    int j=0;
    for(int i=0; i<n; i++){
        if(str[i]>='a' && str[i]<='z'  || str[i]>='A' && str[i]<='Z')
            str1[j++] = str[i];
    }
    //int m= str1.size();

    for(int i=0; i<j; i++){
        cout<<str1[i];
    }
    cout<<endl;
   vowel(str1,j);
   return;
}
int main()
{
    string str;
    cin>>str;
    strfun(str);
}
