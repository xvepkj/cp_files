#include<cstdio>
#include <bits/stdc++.h> 
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
  int m;
  while(scanf("%d\n",&m)==1){
    char a[m][m];
    for(int i=0;i<m;i++)
        scanf("%s\n",a[i]);
    int maxx=-1;
    for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
        if(a[i][j]=='1'){ int min=INT_MAX;
          for(int k=0;k<m;k++)
          for(int l=0;l<m;l++)
            if(a[k][l]=='3' && abs(i-k)+abs(l-j)<min)min=abs(i-k)+abs(l-j);
          if(min>maxx)maxx=min;
    }
    printf("%d\n",maxx);
  }
}