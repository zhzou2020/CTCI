#include <iostream>
#include "memory.h"
#define MAX 100
using namespace std;

void find_conn(const int* g, int m, int n);
void dfs(const int* g, int x, int y, int m, int n);

int v[MAX][MAX];

void find_conn(const int* g, int m, int n){
	
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			if(g[i * n + j] && ! v[i][j]){
				cout << "连通区域:" << endl;
				dfs(g, i, j, m, n);
			}
		}
	}
}

void dfs(const int* g, int x, int y, int m, int n){
	v[x][y] = 1;
	cout << x << "," << y << endl;
	
	if(x + 1 < m && g[(x + 1) * n + y] && ! v[x + 1][y])
		dfs(g, x + 1, y, m, n);
	if(x - 1 >= 0 && g[(x - 1) * n + y] && ! v[x - 1][y])
		dfs(g, x - 1, y, m, n);
	if(y + 1 < n && g[x * n + y + 1] && ! v[x][y + 1])
		dfs(g, x, y + 1, m, n);
	if(y - 1 >= 0 && g[x * n + y - 1] && ! v[x][y - 1])
		dfs(g, x, y - 1, m, n);
}

int main(){
	memset(v, 0, sizeof(v));
	
	int g[][5] = {{0, 1, 0, 0, 0},
					{1, 1, 1, 0, 0},
					{0, 0, 0, 1, 0},
					{0, 1, 0, 0, 1},
					{0, 1, 1, 0, 1}};

	find_conn((int*) g, 5, 5);
	
	return 0;
}
