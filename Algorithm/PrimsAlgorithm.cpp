#include<bits/stdc++.h>
using namespace std;
int V;
int graph[100][100];
int minKey(int key[], bool mstSet[])
{
    int minimum = INT_MAX;
    int min_index;

    for(int v=0; v<V; v++)
        if(mstSet[v] ==  false && key[v]< minimum){
            minimum = key[v];
            min_index = v;
        }


    return min_index;
}

void printMST(int parent[])
{
    cout<<"Edge \t Weight"<<endl;

    for(int i=1; i<V; i++)
        cout<<parent[i]<<" - "<<i<<" \t "<<graph[i][parent[i]]<<endl;
}

void primMST()
{
    int parent [V];
    int key[V];
    bool mstSet[V];

    for(int i=0; i<V; i++){
        key[i] = INT_MAX;
        mstSet[i]= false;
    }

    key[0]= 0; parent[0] = -1;

    for(int c =0; c<V-1; c++)
    {
        int u= minKey(key,mstSet);

        mstSet[u] = true;

        for(int v=0; v<V; v++)
            if(graph[u][v] && mstSet[v]== false && graph[u][v]<key[v]){
                parent[v] = u;
                key[v]= graph[u][v];
            }
    }

    printMST(parent);
}

int main()
{
     cin>>V;
   // int graph[V][V];
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
          cin>>graph[i][j];

          primMST();
          return 0;
}
