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
int arr[203000];
int visited[1000000];
int main()
{
   int f,r;
   while(scanf("%d",&f),f){
    scanf("%d",&r);
    int fx[f];
    int rx[r];
    for(int i=0;i<f;i++)scanf("%d",&fx[i]);
    for(int i=0;i<r;i++)scanf("%d",&rx[i]);
    ll comb=f*r;
    double dr[comb];
    int k=0;
    for(int i=0;i<r;i++)
      for(int j=0;j<f;j++)
        {dr[k]=(double)rx[i]/(double)fx[j];k++;}
    sort(dr,dr+comb);
    double max=-1;
    double ans;
    for(int i=1;i<comb;i++)
      {ans=dr[i]/dr[i-1];
        if(ans>max)max=ans;}
    printf("%0.2f\n",max);
   }
}