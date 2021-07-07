#include<bits/stdc++.h>

using namespace std;
int Array[1000000]={0};
int isPrime1(int n)
{
    int i;
    for(i=2;i<n;i++)
        if (n%i==0) return 0;
    return 1;
}
int isPrime2(int n)
{
    for(int i=2;i<=n/2;i++)
       if(n%i==0) return 0;

       return 1;
}

int isPrime3(int n)
{

   for(int i=2; i<=sqrt(n); i++){
    if(Array[i]==0)
        for(int j=2*i; j<=n; j+=i)
        Array[j]=1;
   }
        for(int j=1; j<=n; j++)
       if(Array[j]==0) cout<<j<<" ";
     cout<<endl;
}




int main()
{
    int n;
    clock_t startTime, endTime;
    cin>>n;

    ///linear
   // cout<<"Linear:\n";
    startTime=clock();
    for(int i=1;i<=n;i++)
       if(isPrime1(i)) cout<<i<<" ";
    cout<<"\n";
    endTime=clock();
    cout<<endl<<"Time :"<<1000*(double)(endTime-startTime)<<endl;


    ///Sieve of Eratosthenes
   // cout<<endl<<"sieve of Eratosthenes: "<<endl;
    startTime=clock();
    for(int i=1;i<=n;i++)
       if(isPrime2(i)) cout<<i<<" ";
    cout<<"\n";
    endTime=clock();
    cout<<endl<<"Time :"<<1000*( double)(endTime-startTime)<<endl;

    /// SQRT
    startTime=clock();
    isPrime3(n);
    endTime=clock();
    cout<<endl<<"Time :"<<1000*( double)(endTime-startTime)<<endl;
    return 0;
}
