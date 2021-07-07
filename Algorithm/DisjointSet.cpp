#include<bits/stdc++.h>
using namespace std;

/// Source Destination & cost of edge
struct Edge{///Edge
   int src, dest;
};

/// connected, undirected & weight graph
struct Graph{
    int V, E;

    Edge* edge;
};

///Create graph with V and E
Graph* createGraph(int v, int e)
{
    Graph* graph= new Graph;
    graph->V = v;
    graph->E = e;

    graph->edge = new Edge[graph->E * sizeof(Edge)];

    return graph;
}

int finding(int parent[ ], int i)
{
    if(parent[i] == -1)
        return i;
    return finding(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    parent[x] = y;
}

int isCycle(Graph* graph)
{
    int* parent = new int [graph->V * sizeof(int)];

    memset(parent, -1, sizeof(int) * graph->V);

    for(int i=0; i< graph->E; i++){
        int x = finding(parent, graph->edge[i].src);
        int y = finding(parent, graph->edge[i].dest);

        if(x == y) return 1;

        Union(parent, x, y);
    }
    return 0;
}

int main()
{
    int V=3, E=3;
    Graph* graph = createGraph(V,E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if (isCycle(graph))
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";

    return 0;
}

