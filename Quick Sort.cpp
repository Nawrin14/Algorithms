#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int part(int low,int high)
{
    int pivot=v[high];
    int i=low;
    for(int j=low; j<high; j++)
    {
        if(v[j]<pivot)
        {
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[i],v[high]);
    return i;
}
void quick_sort(int low,int high)
{
    if(low<high)
    {
        int pivot=part(low,high);
        quick_sort(low,pivot-1);
        quick_sort(pivot+1,high);
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
    quick_sort(0,n-1);
    printf("\nAfter sorting: \n");
    for(int i=0; i<n; i++)
        printf("%d\t",v[i]);
    printf("\n");
}
