#include<bits/stdc++.h>
#define INF 999
using namespace std;
int v, graph[100][100],dist[100][100], parent[100], min_edge[100];
bool inserted[100];

void Floyd_Warshall()
{

    for(int k=0; k<v; k++)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(dist[i][j]==INF)
            {
                cout<<endl<<"The graph is not connected"<<endl;
                exit(0);
            }
        }
    }
}

int get_min_edge()
{

    int Min=INF, min_vertices;

    for(int i=0; i<v; i++)
    {
        if(inserted[i]==false && min_edge[i]<Min)
        {
            Min=min_edge[i];
            min_vertices=i;
        }
    }

    return min_vertices;

}

void printMST()
{

    cout<<endl<<"Edges\tWeight"<<endl;

    for(int i=1; i<v; i++)
        cout<<parent[i]<<"->"<<i<<"\t"<<graph[i][parent[i]]<<endl;

}

void Prims()
{
    for(int i=0; i<v; i++)
    {
        min_edge[i]=INF;
        inserted[i]=false;
    }

    min_edge[0]=0;
    parent[0]=-INF;

    for(int n=0; n<v-1; n++)
    {
        int u = get_min_edge();
        inserted[u]=true;

        for(int V=0; V<v; V++)
        {
            if(graph[u][V]!=INF && inserted[V]==false && min_edge[V]>graph[u][V])
            {
                min_edge[V]=graph[u][V];
                parent[V]=u;
            }
        }
    }

    printMST();
}

int main()
{

    cout<<"\nEnter number of vertices: ";
    cin>>v;
    cout<<"\nEnter the edge weights: "<<endl;
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cin>>graph[i][j];
            if(i==j)
                graph[i][j]=0;
            dist[i][j]=graph[i][j];
        }
    }
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(graph[i][j]!=graph[j][i])
            {
                cout<<endl<<"The graph is not directed"<<endl;
                exit(0);
            }
        }
    }

    Floyd_Warshall();
    Prims();
}
