#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long A[1000][1000];
int main() {
    int tst;
    scanf("%d",&tst);
    while(tst--)
    {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        {scanf("%d",&A[i][j]);
        A[i+n][j]=A[i][j+n]=A[i+n][j+n]=A[i][j];}
    for(int i=0;i<2*n;i++)
      for(int j=0;j<2*n;j++)
      {
        if(i>0)A[i][j]+=A[i-1][j];
        if(j>0)A[i][j]+=A[i][j-1];
        if(i>0 && j>0)A[i][j]-=A[i-1][j-1];
      }

    int mxy=-3e7;
    int sub;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)
      for(int k=i;k<2*n && k<i+n;k++)for(int l=j;l<2*n && l<n+j;l++)
      {
        sub=A[k][l];
        if(i>0)sub-=A[i-1][l];
        if(j>0)sub-=A[k][j-1];
        if(i>0 && j>0)sub+=A[i-1][j-1];
        mxy=max(mxy,sub);
      }

    printf("%d\n",mxy);
  }
}