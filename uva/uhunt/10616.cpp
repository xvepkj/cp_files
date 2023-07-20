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
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; 
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
int a[100000];
int N,Q,D,M;
int memo[300][30][15];
int dp(int i, int sum, int c)
{
    if(c == M && sum == 0)
        return 1;
    if(c == M && sum != 0)
        return 0;
    if(i == N)
        return 0;
    if(memo[i][sum][c] != -1)
        return memo[i][sum][c];

    memo[i][sum][c] = dp(i+1, sum%D, c) + dp(i+1, (sum+a[i])%D, c+1);

    return memo[i][sum][c];
}
int main(){
    int t=0;
    while(scanf("%d %d",&N,&Q)){
        t++;
        if(!(N+Q))break;
        for(int i=0;i<N;i++)scanf("%d",&a[i]);
            printf("SET %d:\n",t);
        for(int i=1;i<=Q;i++){
            memset(memo,-1,sizeof memo);
            scanf("%d %d",&D,&M);
            int y=dp(0,0,0);
            printf("QUERY %d: %d\n",i,y);
        }
    }
}

