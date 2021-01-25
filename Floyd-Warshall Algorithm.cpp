#include<bits/stdc++.h>
#define INF 999
using namespace std;
int dist[100][100],v;

void print_matrix(){

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
}

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

        for(int i=0; i<v; i++){
            if(dist[i][i]<0){
                cout<<endl<<"The graph contains negative cycle"<<endl;
                return;
            }
        }

        cout<<endl<<"For k = "<<k+1<<endl;
        print_matrix();
    }
    cout<<endl<<"The all pair shortest distance matrix is: "<<endl;
    print_matrix();
}

int main()
{

    cout<<"Enter number of vertices: ";
    cin>>v;
    cout<<endl<<"Enter the edge weights: "<<endl<<endl;

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cin>>dist[i][j];
        }
    }

    Floyd_Warshall();

}

