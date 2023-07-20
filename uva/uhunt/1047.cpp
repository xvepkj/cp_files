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
  myset.insert(50);
  for(int i=0;i<=20;i++){myset.insert(i);myset.insert(i*2);myset.insert(i*3);}
  for(set<int>::iterator it = myset.begin(); it != myset.end(); it++) 
        a.push_back(*it);
  while(true){
    scanf("%d",&x);
    if(x<=0){printf("END OF OUTPUT\n");break;}
    int perm=0;   
    int comb=0;
    memset(vis,false,sizeof(vis));
        for(int i=0;i<a.size();i++)
          for(int j=0;j<a.size();j++)
            for(int k=0;k<a.size();k++)
              if((x-a[i]-a[j]-a[k])==0){
                perm++;
                if(!vis[a[i]][a[j]][a[k]]){
                  vis[a[i]][a[j]][a[k]]=vis[a[i]][a[k]][a[j]]=true;
                  vis[a[j]][a[i]][a[k]]=vis[a[j]][a[k]][a[i]]=true;
                  vis[a[k]][a[j]][a[i]]=vis[a[k]][a[i]][a[j]]=true;
                  comb++;
                }
              }
      if(comb==0)printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",x);
      else{
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",x,comb);
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",x,perm);}
    printf("**********************************************************************\n");
  }
}