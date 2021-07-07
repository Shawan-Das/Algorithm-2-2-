#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src, dest, weight;
};
struct Graph{
    int V, E;
    struct Edge* edge;
};

void printArray(int distance[], int n)
{
    cout<<"Vertex Distance From Source"<<endl;

    for(int i=0; i<n; i++)
        cout<<i<<" \t\t "<<distance[i]<<endl;
}

void BellmanFord(struct Graph*graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int distance[V];

    for(int i=0; i<V; i++)
        distance[i]= INT_MAX;

    distance[src]=0;

    for(int i=0; i<V-1; i++){
        for(int j=0; j<E; j++){

        int u= graph->edge[j].src;
        int v= graph->edge[j].dest;
        int w= graph->edge[j].weight;

        if(distance[u]!= INT_MAX && distance[u]+w < distance[v])
           distance[v] = distance[u] + w;
        }
    }

    for(int j=0; j<E; j++){

        int u= graph->edge[j].src;
        int v= graph->edge[j].dest;
        int w= graph->edge[j].weight;

        if(distance[u]!= INT_MAX && distance[u]+w < distance[v]){
            cout<<"Negative cycle contains. No solution"<<endl;
            return;
        }
    }

    printArray(distance, V);
    return;
}
int main()
{
    int V, E, start;
    cout<<"Number of Vertex : "; cin>>V;
    cout<<"Number of Edges  : "; cin>>E;
    cout<<"Source           : "; cin>>start;

    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    for(int i=0; i<E; i++){
        int s; cin>>s;
        int d; cin>>d;
        int w; cin>>w;

        graph->edge[i].src    = s;
        graph->edge[i].dest   = d;
        graph->edge[i].weight = w;
    }

    BellmanFord(graph, start);
    return 0;
}
