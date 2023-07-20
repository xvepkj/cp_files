#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
int move[4][2] = { { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 }};
int grid[100][100], sol[2];
int r, c, m, n, w;
void dfs(int i, int j) {

    grid[i][j] = 1;

    map<int, bool> taken;

    for (int k = 0; k < 4; k++) {

 

        int a = i + move[k][0] * m;

        int b = j + move[k][1] * n;

        if (0 <= a && a < r && 0 <= b && b < c && grid[a][b] != -1 && !taken[a * 100 + b]) {

            grid[i][j]++;

            taken[a * 100 + b] = true;

            if (grid[a][b] == 0)

                dfs(a, b);

        }



        a = i + move[k][0] * n;

        b = j + move[k][1] * m;

        if (0 <= a && a < r && 0 <= b && b < c && grid[a][b] != -1 && !taken[a * 100 + b]) {

            grid[i][j]++;

            taken[a * 100 + b] = true;

            if (grid[a][b] == 0)

                dfs(a, b);

        }

    }

    sol[grid[i][j] & 1]++;

}

 

int main() {

    int tt;

    cin >> tt;

    for (int t = 1; t <= tt; t++) {

        cin >> r >> c >> m >> n;

        memset(grid, 0, sizeof(grid));

        for (cin >> w; w; w--) {

            int a, b;

            cin >> a >> b;

            grid[a][b] = -1;

        }

        memset(sol, 0, sizeof(sol));

        if (grid[0][0] == 0)

            dfs(0, 0);

        printf("Case %d: %d %d\n", t, sol[1], sol[0]);

    }

    return 0;

}
