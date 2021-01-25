#include<bits/stdc++.h>
using namespace std;
vector<int>node[100];
vector<bool>v;
queue<int> q;
void BFS(int x)
{
    q.push(x);
    v[x]=true;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout<<f<<"\t";
        for(int i=0; i<node[f].size(); i++)
        {
            int newNode=node[f][i];
            if(v[newNode]==false)
            {
                q.push(newNode);
                v[newNode]=true;
            }
        }
    }
}
int main()
{
    int node_no,edge_no,a,b,c;
    cout<<"\nEnter the number of nodes:";
    cin>>node_no;
    cout<<"\nEnter the number of edges:";
    cin>>edge_no;
    cout<<"\nEnter the adjacency list:\n";
    for(int i=1; i<=edge_no; i++)
    {
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    cout<<"\nNode adjacency list:"<<endl;
    for(int i=0; i<node_no; i++)
    {
        cout<<i<<"\t";
        for(int j=0; j<node[i].size(); j++)
        {
            cout<<node[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int i=0; i<node_no; i++)
        v.push_back(false);
    int start_node;
    cout<<"\nEnter the starting node:\n";
    cin>>start_node;
    cout<<"\nThe BFS traversal path is:\n";
    BFS(start_node);
}
