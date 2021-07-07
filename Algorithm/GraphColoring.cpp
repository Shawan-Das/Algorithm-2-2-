#include<bits/stdc++.h>
using namespace std;
int N;
int m;
int ans[100]={0};
int Graph[100][100]={0};
int colour[10]={0};
bool isSafe(int colourIndex, int colour)
{
  for(int j=0; j<N; j++)
  {
    if(Graph[colourIndex][j]==1 && colour==ans[j])
    {
        return false;
    }
  }
  return true;
}
int graphColour(int colourIndex)
{
    for(int i=1; i<=m; i++){

       if(isSafe(colourIndex,i)){
          ans[colourIndex]=i;

          if(colourIndex+1<N)
            graphColour(colourIndex+1);

          else
            for(int i=0; i<N; i++)
                cout<<ans[i];

            cout<<endl;
       }
    }
}
int main()
{
    cout<<"Colour :";
    cin>>m;
    for(int i=0; i<m; i++)
        cin>>colour[i];

        cout<<"Connection: ";
        cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>Graph[i][j];


    graphColour(0);


}

