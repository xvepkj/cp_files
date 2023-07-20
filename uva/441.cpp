#include<cstdio>
#include<cmath>
#include<random>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<utility>
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
int left[100006];
int right[100006];
int n,m;
int maxx=-1;
vector<vi> adj;
int main()
{
  int k;
  int cnt=0;
  while(scanf("%d",&k),k){
    if(cnt)printf("\n");
    cnt++;
    int l[k];
    for(int i=0;i<k;i++)scanf("%d",&l[i]);
    for(int a=0;a<k-5;a++)
      for(int b=a+1;b<k-4;b++)
        for(int c=b+1;c<k-3;c++)
          for(int d=c+1;d<k-2;d++)
            for(int e=d+1;e<k-1;e++)
              for(int f=e+1;f<k;f++)
                printf("%d %d %d %d %d %d\n",l[a],l[b],l[c],l[d],l[e],l[f]);
  }
}