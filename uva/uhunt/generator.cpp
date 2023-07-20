#include<cstdio>
#include<cmath>
#include<random>
#include<functional>
#include<chrono>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define INF 1000000000

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
minstd_rand0 generator (seed);  
int getrand(int a, int b) { return a + generator() % (b - a); }
int main(int argc, char** argv){
	int N = atoi(argv[1]);
	int a = atoi(argv[2]), b = atoi(argv[3]);
	printf("%d\n", N);
	for (int i = 0; i < N; i++) { printf("%d\n", getrand(a, b)); }
}
