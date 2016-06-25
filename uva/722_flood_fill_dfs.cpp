#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
#include<sstream>
#include<list>
#include<math.h>
#include<map>
#include<set>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<fstream>
#include<vector>
#include<algorithm>
#include <queue>
#include<string>
#include<cstring>
#include <deque>
#include<stack>
using namespace std;

int vis[105][105] = {0};
int waterLand = 0;
int row,col;
int grid[105][105];

void dfsFloodFill(int x, int y){
	
	vis[x][y] =1;
	int tx,ty,i;
	waterLand++;
	for(i = 0 ;i < 4 ;i++){
	tx = dx[i] + x;
	ty = dy[i] + y;
		if(tx>=0 && tx<row && ty>=0 && ty<col && !vis[tx][ty] && !grid[tx][ty]){
			dfsFloodFill(tx,ty);
		}
	}
}
/*

UVA 722

Problem type : flood fill using dfs

very difficlt to take input !!!

*/

int main() {

	long long n,i,j,k,temp,m;
	long long x,y,z,sum,test_case,length;
	long long flag,min=1e9,index=0,ans,remain,r;

	string str="";
	sum =0;
	
	cin>>test_case;

	while(test_case--){
		scanf("%lld %lld\n",&x,&y);
		
		memset(vis, 0 ,sizeof vis);
		i = 0;
		char inp[105];
		while(gets(inp) && strlen(inp) > 0) {
			m = strlen(inp);
            for(j = 0 ;j < m; j++)
				grid[i][j] = inp[j] - '0';
            i++;
        }
		row = i;col =j;

		waterLand = 0 ;
		if(x && y && x<= row && y<=col && !grid[x-1][y-1])
		dfsFloodFill(x - 1, y - 1);
		
		printf("%d\n", waterLand);
		if(test_case) printf("\n");

	}
	return 0;
}