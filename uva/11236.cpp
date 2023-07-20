#include<cstdio>
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
int main()
{ ll s,p;
  for(int i=1;i+i+i+i<=2000;i++)
    for(int j=i;j+i+j+j<=2000;j++)
        for(int k=j;k+i+j+k<=2000;k++)
          {
            p=(ll)(i*j*k);
            s=i+j+k;
            if(p<=1000000)continue;
            if((s*1000000)%(p-10000000))continue;
            int l=(s*1000000)/(p-10000000);
            s+=l;
            if(s>2000 || l<k)continue;
            double x=i/100.00;
            double y=j/100.00;
            double z=k/100.00;
            double w=l/100.00;
            printf("%.2f %.2f %.2f %.2f\n",x,y,z,w);
          }      
}