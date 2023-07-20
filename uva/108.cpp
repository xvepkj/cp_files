#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long A[1000][1000];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        {scanf("%d",&A[i][j]);
      if(i>0)A[i][j]+=A[i-1][j];}
    int mxy=0;
    int sub=0;
    for(int i=0;i<n;i++)for(int j=i;j<n;j++)
    {
      sub=0;
    for(int c=0;c<n;c++){
      sub+=A[j][c];
      if(i>0)sub-=A[i-1][c];
      if(sub<0)sub=0;
      mxy=max(mxy,sub);
    }}
    printf("%d\n",mxy);
}