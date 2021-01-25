#include<bits/stdc++.h>
#define INF 999
using namespace std;

int v,src,cost[100][100],dist[100],parent[100];
bool visited[100];

int nearest_min()
{
    int minDist=INF,minNode=0;
    for(int i=0; i<v; i++)
    {
        if(visited[i]==false && dist[i]<minDist)
        {
            minDist=dist[i];
            minNode=i;
        }
    }

    return minNode;
}

void dijkstra()
{
    for(int i=0; i<v-1; i++)
    {
        int minimum = nearest_min();
        visited[minimum]=true;

        for(int j=0; j<v; j++)
        {
            if(cost[minimum][j]!=INF && dist[j]>dist[minimum]+cost[minimum][j])
            {
                dist[j]=dist[minimum]+cost[minimum][j];
                parent[j]=minimum;
            }
        }
    }
}

void print()
{

    cout<<endl<<"The shortest paths are - "<<endl;

    for(int i=0; i<v; i++)
    {
        cout<<i;

        int parentNode = parent[i];
        while(parentNode!=src)
        {
            cout<<"<-"<<parentNode;
            parentNode = parent[parentNode];
        }

        cout<<"\t\t\tCost - "<<dist[i];
        cout<<endl;
    }
}

int main()
{
    cout<<"Enter number of vertics - ";
    cin>>v;
    cout<<"Enter the adjacency matrix - "<<endl;
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            cin>>cost[i][j];
    }

    cout<<"Enter the source - ";
    cin>>src;

    for(int i=0; i<v; i++)
    {
        dist[i]=INF;
        parent[i]=i;
        visited[i]=false;
    }

    dist[src]=0;
    dijkstra();
    print();

}
