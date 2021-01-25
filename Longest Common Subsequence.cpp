#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,m;
int a[50][50];

void LCS()
{

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0)
                a[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }

    if(a[n][m]==0)
    {
        cout<<endl<<"\nThere is no common subsequence\n"<<endl;
        exit(0);
    }

    cout<<endl<<"\nThe length of the longest common subsequence is: \n"<<a[n][m]<<endl;
}

print_LCS()
{

    int lcs_len=a[n][m];
    char lcs[lcs_len+1];
    lcs[lcs_len]='\0';
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs[lcs_len-1]=s1[i-1];
            i--;
            j--;
            lcs_len--;

            if(lcs_len==0)
                break;
        }
        else if(a[i-1][j]>a[i][j-1])
            i--;
        else
            j--;
    }
    cout<<"\nThe longest common subsequence is: \n"<<lcs<<endl;
}

int main()
{
    cout<<"\nEnter 1st string: ";
    cin>>s1;
    cout<<"\nEnter 2nd string: ";
    cin>>s2;
    n=s1.length();
    m=s2.length();

    LCS();
    print_LCS();
}
