#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<bitset>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
/* ---------------------------------------------- */
#define DBGMODE
#ifdef DBGMODE
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif
const ll MX = ((ll)1 << 32) - 1;
int main() {
      int l;
      char s1[200];
      scanf("%d",&l);
      fgets(s1,10,stdin);
      int f=0;
      ll tott=0;
      int tot=0;
      ll x=1;
      stack<int> t;
      for(int i=0;i<l;i++)
      {	char s[100];
      	char a[20];
      	int n;
      	fgets(s,50,stdin);
      	if(sscanf(s,"%s %d",a, &n)==2)
      		{	if(x<=MX){
      			t.push(n);
      			x=x*n;
      			f++;}
      			else t.push(1);
      		}
      	if(s[0]=='a'){
      		tot+=x;tott+=x;}
      		if(s[0]=='e')
      			{if(f>0){f-=1;x=x/t.top();t.pop();}}
      	}
      	if(tott!=tot)printf("OVERFLOW!!!\n");
      	else printf("%d\n",tot);
}
