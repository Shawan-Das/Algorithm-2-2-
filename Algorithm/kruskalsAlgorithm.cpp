#include<bits/stdc++.h>
using namespace std;

/// Source Destination & cost of edge
struct Edge{///Edge
   int src, dest;
    int weight;
};
/// connected, undirected & weight graph
struct Graph{
    int V, E;

    Edge* edge;
};
///subset Union Finding
struct subset{
    int parent, height;///child- Tree_Rank
};

///Create graph with V and E
Graph* createGraph(int v, int e)
{
    Graph* graph= new Graph;
    graph->V = v;
    graph->E = e;

    graph->edge = new Edge[e];

    return graph;
}

///Function to find set of an element
int finding(subset subsets[], int i)
{
    if(subsets[i].parent != i)
        subsets[i].parent = finding(subsets, subsets[i].parent);

    return subsets[i].parent;
}

///Set union
void Union(subset subsets[], int x, int y)
{
    int xroot = finding(subsets, x);
    int yroot = finding(subsets, y);

    if(subsets[xroot].height < subsets[yroot].height)
       subsets[xroot].parent = yroot;

    else if(subsets[xroot].height > subsets[yroot].height)
        subsets[yroot].parent = xroot;

    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].height++;
    }
}

///Comparing Edges and QuickSorting
int Comparing(const void*a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

///Kruskal Algorithm
void Kruskal(Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e =0;
    int i=0;
    int minimumCost=0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), Comparing);

    subset* subsets = new subset[(V * sizeof(subset))];

    ///V subsets with single element
    for(int v=0; v<V; v++)
    {
        subsets[v].parent = v;
        subsets[v].height = 0;
    }


    while(e<V-1 && i<graph->E)
    {
        Edge nextEdge = graph->edge[i++];

        int x= finding(subsets, nextEdge.src);
        int y = finding(subsets,nextEdge.dest);

        if(x!=y)
        {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    cout<<"Constructed Edges: "<<endl;

    for(int i=0; i< e; i++)
    {
        cout<< result[i].src<<" - "<<result[i].dest<<" = " <<result[i].weight<<endl;
        minimumCost += result[i].weight;
    }

    cout<<"\n Minimum cost spanning Tree: "<<minimumCost<<endl;

}

int main()
{
    ///number of vertices V  number of edge E
    int V=4,E=5;// cin>>V;   cin>>E;
    Graph* graph = createGraph(V, E);

    graph->edge[0].src= 0;
    graph->edge[0].dest= 1;
    graph->edge[0].weight=10;

    graph->edge[1].src= 0;
    graph->edge[1].dest= 2;
    graph->edge[1].weight=6;

    graph->edge[2].src= 0;
    graph->edge[2].dest= 3;
    graph->edge[2].weight=5;

    graph->edge[3].src= 1;
    graph->edge[3].dest= 3;
    graph->edge[3].weight=15;

    graph->edge[4].src=2;
    graph->edge[4].dest=3;
    graph->edge[4].weight=4;

    Kruskal(graph);
}
