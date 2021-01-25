#include<bits/stdc++.h>
using namespace std;
vector<int>v;
vector<int>v1;
vector<int>v2;
void counting_sort(int n)
{
    int Max=*max_element(v.begin(),v.end());
    for(int i=0; i<=Max; i++)
        v1.push_back(0);

    for(int i=0; i<n; i++)
        v2.push_back(0);
    for(int j=0; j<n; j++)
        v1[v[j]]++;
    for(int k=1; k<=Max; k++)
        v1[k]+=v1[k-1];
    for(int l=n-1; l>=0; l--)
    {
        v2[v1[v[l]]-1]=v[l];
        v1[v[l]]--;
    }
    for(int i=0; i<n; i++)
        v[i]=v2[i];
}
int main()
{
    int n,x;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter %d numbers: \n",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    counting_sort(n);
    printf("\nAfter sorting:\n");
    for(int i=0; i<n; i++)
        printf("%d\t",v[i]);
    printf("\n");
}
