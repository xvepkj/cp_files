#include<cstdio>
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
int left[100006];
int right[100006];
int n,m;
int maxx=-1;
set<int> myset;
bool vis[65][65][65];
vector<int> a;
int x;
int main()
{ 
  int tst;
  scanf("%d",&tst);
  while(tst--){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int x;
    int dp[1005]={};
    dp[0]=1;
    for(int i=0;i<m;i++){
      scanf("%d",&x);
      for(int j=n-x;j>=0;j--)
        if(dp[j] && !dp[j+x])
          dp[j+x]=1;
    }
    if(dp[n])printf("YES\n");
    else printf("NO\n");
  }
}