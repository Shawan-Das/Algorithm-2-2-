#include<bits/stdc++.h>
using namespace std;
int graph[100][100], V;
int minDistance(int distance[], bool sptSet[])
{
    int minimum= INT_MAX, minIndex;

    for(int v=0; v<V; v++){
        if((sptSet[v] == false) && (distance[v] <= minimum)){
            minimum = distance[v];
            minIndex = v;
        }
    }

       return minIndex;
}

void printSolution(int distance[ ])
{
    cout<<"Vertex \t\t Distance From Source\n"<<endl;

    for(int i=0; i<V; i++)
        cout<<i<<" \t\t "<<distance[i]<<endl;
}

void dijkstra(int src)
{
    int distance[V];  bool sptSet[V];

    for(int i=0; i<V; i++){
        distance[i]= INT_MAX;
        sptSet[i] = false;
    }

    distance[src]= 0;
    for(int c=0; c<V-1; c++){

        int u = minDistance(distance, sptSet);

        sptSet[u] = true;

        for(int v=0; v<V; v++){
            if( !sptSet[v] && graph[u][v] && (distance[u] != INT_MAX) &&
                (distance[u] + graph[u][v] < distance[v]) )
                    distance[v] = distance[u] + graph[u][v];
        }
    }
       printSolution(distance);
}

int main()
{
    int src;
    cin>>V; cin>>src;

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
           cin>>graph[i][j];

    dijkstra(src);

    return 0;
}
