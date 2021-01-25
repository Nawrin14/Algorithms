#include<bits/stdc++.h>
using namespace std;
vector<int>node[100];
vector<bool>v;
stack<int> s;
void DFS(int x)
{
    s.push(x);
    v[x]=true;
    cout<<x<<"\t";
    while(!s.empty())
    {
        int flag=0;
        int f=s.top();
        for(int i=0; i<node[f].size(); i++)
        {
            int newNode=node[f][i];
            if(v[newNode]==false)
            {
                flag=1;
                s.push(newNode);
                v[newNode]=true;
                cout<<newNode<<"\t";
                break;
            }
        }
        if(flag==0)
            s.pop();
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
    cout<<"\nEnter the starting node:\n";
    int start_node;
    cin>>start_node;
    cout<<"\nThe DFS traversal path is:\n";
    DFS(start_node);
}
