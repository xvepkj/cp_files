#include <cstdio>
#include<iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif

int main () { 
  int t;
  scanf("%d",&t);
  while(t--){
   	int k;
   	char g1[6][6];
   	char g2[6][6];
   	scanf("%d",&k);
   	for(int i=0;i<6;i++)
   		scanf("%s",g1[i]);
   	for(int i=0;i<6;i++)
   		scanf("%s",g2[i]);
   	vector<vector<char>> v;
   	v.assign(6,vector<char>(0));
   	for(int i=0;i<5;i++)
   	{
   		set<char> l1;
   		set<char> l2;
   		for(int j=0;j<6;j++)
   			l1.insert(g1[j][i]);
   		for(int j=0;j<6;j++)
   			l2.insert(g2[j][i]);
   		for(auto it =l1.begin();it!=l1.end();it++)
   			if(l2.count(*it))v[i].push_back(*it);
   	}
   	int m=(v[0].size())*(v[1].size())*(v[2].size())*(v[3].size())*(v[4].size());
   	if(m<k)printf("NO\n");
   	else{
   		bool flg=false;
   		for(int i=0;i<5;i++)sort(v[i].begin(),v[i].end());
   		int u=0;
   		for(int i=0;i<v[0].size() && flg!=true;i++)
   			for(int j=0;j<v[1].size() && flg!=true;j++)
   				for(int b=0;b<v[2].size() && flg!=true;b++)
   					for(int n=0;n<v[3].size() && flg!=true;n++)
   						for(int h=0;h<v[4].size() && flg!=true;h++)
   							{u++;
   							if(u==k){printf("%c%c%c%c%c\n",v[0][i],v[1][j],v[2][b],v[3][n],v[4][h]);flg=true;}}
   	}
  }
}


