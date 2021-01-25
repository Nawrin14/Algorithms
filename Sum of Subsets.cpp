#include<bits/stdc++.h>
using namespace std;
int v[10],v1[10];
int n,m;

void SumofSubset(int s,int k,int r){

    v1[k]=1;
    if(s+v[k]==m){
        cout<<endl;

        for(int j=1;j<=k;j++)
            cout<<v1[j]<<"\t";

        cout<<endl;
    }
    else if(s+v[k]+v[k+1]<=m)
        SumofSubset(s+v[k],k+1,r-v[k]);

    if((s+r-v[k]>=m)&&(s+v[k+1]<=m)){
       v1[k]=0;
       SumofSubset(s,k+1,r-v[k]);
    }

}

int main(){

    int sum=0,x,i=0;
    cout<<"Enter the number of integers: ";
    cin>>n;
    v[0]=0;
    cout<<"Enter the numbers: "<<endl;
    while(i<n){
        cin>>x;
        if(x<0)
            cout<<"\nEnter a positive number\n"<<endl;
        else{
            v[i+1]=x;
            sum+=x;
            i++;
        }
    }
    cout<<"\nEnter the sum: ";
    cin>>m;
    if(sum<m){
        cout<<endl<<"\nNo subset possible\n"<<endl;
        return 0;
    }

    cout<<"\nThe solution vectors are: \n";
    SumofSubset(0,1,sum);

}
