#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cout<<"Please Enter the number of cities: "; cin>>n;
    int m; cout<<"Please Enter the number of days  : "; cin>>m;
    int Array[n][m];

    for(int i=0; i<n; i++){
        cout<<"For city "<<i+1<<", Please enter the Temperature for "<<m<<" days :"<<endl;

       for(int j=0; j<m; j++){
         cout<<"Day "<<j+1<<" methane unit in ton: "; cin>>Array[i][j];
       }
    }


    for(int i=0; i<n; i++){
            double mean_value =0;
        for(int j=0; j<m; j++){
            mean_value+= (double)Array[i][j];
        }
      mean_value = mean_value/m;
      cout<<"City "<<i+1<<", Average methane is "<< mean_value<<endl;
      if(50<mean_value && mean_value<100) cout<<"City "<<i+1<<" is in danger"<<endl;
      if(100<=mean_value)                 cout<<"City "<<i+1<<" is not a liveable city"<<endl;
      if(20<mean_value && mean_value<=50)  cout<<"Methane emission must be reduced"<<endl;
      if(0<mean_value && mean_value<=20)  cout<<"Methane emission is in tolerate level"<<endl;
    }

    return 0;
}
