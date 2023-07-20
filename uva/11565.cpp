#include<cstdio>
#include<iostream>
#include<cmath>
#include<random>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<utility>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 
typedef vector<int> vi;
#define INF 1000000000
int main()
{ bool sol=false;
  int A,B,C;
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d",&A,&B,&C);
    for(int x=-B;x<=B;x++)
      {if(x && B%x)continue;
      for(int y=x+1;y<=B;y++)
        {if(y && B%y)continue;
          int z=A-x-y;
          if(x*x + y*y+ z*z==C)
            {sol=true;printf("%d %d %d\n",x,y,z);}}}
          if(!sol)printf("No solution.\n");
  }  
}