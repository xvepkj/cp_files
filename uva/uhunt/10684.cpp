#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  while(scanf("%d",&N),N){
    int sum=0,mx=0;
    int x;
    for(int i=0;i<N;i++){
      scanf("%d",&x);
      sum+=x;
      mx=max(mx,sum);
      if(sum<0)sum=0;
    }
    if(mx<=0)printf("Losing streak.\n");
    else printf("The maximum winning streak is %d.\n",mx);
  }
}
