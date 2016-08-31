#include <iostream>
using namespace std;

//corner case
void rotate(int* mat, int m, int n){
	int hm = m / 2;
	int hn = n / 2;
	
	for(int i = 0; i <= hm; i ++){
		for(int j = 0; j <= hn; j ++){
			int tmp = mat[i][j];
			int dx = hm - i; // 0 - hm
			int dy = hn - j; // 0 - hn
			
			mat[i][j] = mat[hm + dy][hn - dx]; // hm-i, hn-j
			mat[hm + dy][hn - dx] = mat[hm + dx][hn + dy];
			mat[hm + dx][hn + dy] = mat[dy][hn + dx];
			mat[dy][hn + dx] = tmp;
		}
	}
}
int main() {
	// your code goes here
	int mat[][4] = {{1,2,3,4},
					{5,6,7,8},
					{9,10,11,12},
					{13,14,15,16}};
	return 0;
}
