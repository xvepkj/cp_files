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
    int n;
    scanf("%d",&n);
    int a[n][n];
    int i;
    for(i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    int choice[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    int minimum = 10000000;
    do {
      int sum = 0;
      for (i = 0; i < n; i++) {
        sum += a[i][choice[i]];
      }
      minimum = min(sum, minimum);
    } while (next_permutation(choice, choice + n));

    printf("%d\n", minimum);
  }
}