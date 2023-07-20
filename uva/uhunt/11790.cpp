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
const int N=100010;
ll f[N];
int a[1000000];
int b[1000000];
int x[1000000];
int y[1000000];
int main(){
    int t;
    scanf("%d",&t);
    for(int e=1;e<=t;e++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        for(int i = n - 1; i >= 0; i--) {
            x[i]=b[i];
            for(int j = i + 1; j < n; j++) {
                if(a[i] < a[j]) {
                    x[i] = max(x[j] + b[i], x[i]);
                }
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            y[i] = b[i];
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j]) {
                    y[i] = max(y[j] + b[i], y[i]);
                }
            }
        }
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++)ans1=max(ans1,x[i]);
        for(int i=0;i<n;i++)ans2=max(ans2,y[i]);
        if(ans1>=ans2)printf("Case %d. Increasing (%d). Decreasing (%d).\n",e,ans1,ans2);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n",e,ans2,ans1);
    }
}

