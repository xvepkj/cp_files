/*PKJ*/
// #define DEBUG_MODE
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
    #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
int INF=1e8;
int t,R,C,y,z;
char a[105][105];
int memo[105][105];
vii lis;
char x[105];
vii v;
int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
int floodfill(int r,int c,char c1,char c2){
	if(r<0 || r>=R || c<0 || c>=C)return 0;
	if(a[r][c]!=c1)return 0;
	lis.push_back(ii(r,c));
	int ans=1;
	a[r][c]=c2;
	for(int d=0;d<8;d++)
		ans+=floodfill(r+dr[d],c+dc[d],c1,c2);
	return ans;
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d\n",&t);
    while(t--){
    	R=0;
    	C=0;
    	v.clear();
    	while(gets(x)){
    		if(x[0]=='\0')break;
    		if(x[0]!='W' && x[0]!='L')
    			{sscanf(x,"%d %d",&y,&z);
				v.push_back(ii(y,z));				
    			}
    		else sscanf(x,"%s",a[R++]);
    	}
    	int i;
    	for(i=0;a[0][i]!='\0';i++);
    	C=i;
    	// for(int i=0;i<R;i++)
    	// 	for(int j=0;j<)
    	memset(memo,-1,sizeof memo);
    	for(int i=0;i<v.size();i++){
    		int tot;
    		lis.clear();
    		if(memo[v[i].first-1][v[i].second-1]==-1){
    		tot=floodfill(v[i].first-1,v[i].second-1,'W','.' );
    		for(int j=0;j<lis.size();j++)
    			memo[lis[j].first][lis[j].second]=tot;
    	}
    	else{tot=memo[v[i].first-1][v[i].second-1];}
    	printf("%d\n",tot);
    	}
    	if(t)printf("\n");
    }
}