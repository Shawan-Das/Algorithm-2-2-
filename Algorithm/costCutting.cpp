#include<bits/stdc++.h>
using namespace std;

int main()
{
    double paybleAmount, totalCreadit;
    cout<<"Enter Total Cost : ";    cin>>paybleAmount;
    cout<<"Total Course Credit :";  cin>>totalCreadit;

    double costePerCredit = paybleAmount/totalCreadit;

    cout<<"Enter 0 for Exit"<<endl;
    while(1)
    {
        double credit;
        cout<<"Enter Course Credit:"; cin>>credit;
        if(credit==0) break;
        double courseCost = credit*costePerCredit;
        cout<<"Course Cost: "<<courseCost<<endl;
        int totalClass = (((int)credit/2) + ((int)credit%2))*14;
        cout<<"Cost per Class: "<<(courseCost/totalClass)<<endl;
    }

    return 0;
}
