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
int main()
{
	unsigned int n;
	while(scanf("%u",&n) && (n!=0))
	{
		unsigned int toAdd=1,a=0,b=0;
		bool as=true;
		while(n){
		if(n & 1)
		{
			if(as)a+=toAdd;
			else b+=toAdd;
			as=!as;
		}
		n/=2;
		toAdd*=2;
	  }
		printf("%u %u\n",a,b);
	}
}

