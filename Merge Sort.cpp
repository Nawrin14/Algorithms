#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void Merge(int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int L[n1],R[n2];
    for(int i=0; i<n1; i++)
        L[i]=v[low+i];
    for(int j=0; j<n2; j++)
        R[j]=v[mid+1+j];
    int i=0,j=0,k=low;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
            v[k++]=L[i++];
        else
            v[k++]=R[j++];
    }
    while(i<n1)
        v[k++]=L[i++];
    while(i<n2)
        v[k++]=R[j++];
}
void merge_sort(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        Merge(low,mid,high);
    }
}
int main()
{
    int n,x;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    printf("\nEnter %d numbers: \n",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    merge_sort(0,n-1);
    printf("\nAfter sorting: \n");
    for(int i=0; i<n; i++)
        printf("%d\t",v[i]);
    printf("\n");
}
