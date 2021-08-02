#include<bits/stdc++.h>
using namespace std;

struct student {
   int ID;
   string name;
   float credits,CGPA;

};
 struct student information[1000];
 struct student newArray[1000];
int n;


///--------------Insertion Sort--------------
void insertionSort(){

        for(int i=1;i<n;i++){

        if(information[i].credits > information[i-1].credits){

            for(int j=i;j>0;j--){
                if(information[j].credits > information[j-1].credits)
                swap(information[j],information[j-1]);

                else if(information[j].credits == information[j-1].credits && information[j].CGPA > information[j-1].CGPA)
                    swap(information[j],information[j-1]);

                else break;
            }

        }

    }

}
///---------------Insertion Sort End ------------------


///---------------Merge Sort ------------------------

         ///---------- Sorting Part----------
void mergArrays(int low,int mid,int high)
{
    int i=low, j=mid+1, k=low;

    while(i<=mid && j<=high){

        if(information[i].credits > information[j].credits){
            newArray[k++]=information[i++];
        }

        else if(information[i].credits == information[j].credits && information[i].CGPA > information[j].CGPA){
            newArray[k++]=information[i++];
        }

        else if(information[i].credits == information[j].credits && information[i].CGPA < information[j].CGPA){
            newArray[k++]=information[j++];
        }

        else newArray[k++]=information[j++];
    }


    while(i<=mid)  newArray[k++]=information[i++];

    while(j<=high) newArray[k++]=information[j++];

    for(i=low;i<=high;i++) information[i]=newArray[i];
}


           ///----- Dividing Part----------------
void mergSort(int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergSort(low,mid);
        mergSort(mid+1,high);
        mergArrays(low,mid,high);
    }
    else return;
}
///-----------------Merge Sort End--------------------------



///----------------Main Function--------------------------
int main()
{
    cin>>n;

    //cout<<"ID /t Name /t Total Credit CGPA"<<endl
    for(int i=0; i<n; i++){
            cout<<"ID : ";
            cin>>information[i].ID;
            cin.ignore();
            cout<<"Name : ";
            getline (cin, information[i].name);
            cout<<"Credits : ";
            cin>>information[i].credits;
            cout<<"CGPA: ";
            cin>>information[i].CGPA;
            cout<<endl;
    }

    cout<<" Insertion Sort: 1"<<endl<<" Merge Sort: 2"<<endl;
     cout<<"Option: "; int t; cin>>t;
    if(t==1) insertionSort();
    if(t==2) mergSort(0,n-1);


    for(int i=0; i<n; i++)
    {
        cout<<information[i].ID<<"  ";
        cout<<information[i].name<<"  ";
        cout<<information[i].credits<<"  ";
        cout<<information[i].CGPA<<endl;
    }

    return 0;
}
