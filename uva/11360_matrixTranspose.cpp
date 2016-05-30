#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
#include <queue>
#include<string>
#include<cstring>
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
#include<stack>
using namespace std;
int GCDFast(int a, int b){ while (b)b ^= a ^= b ^= a %= b;  return a; }
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
#define MOD 1000000007
#define MX 100010
#define pii pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
template <class T> inline T gcd(T a, T b){ if (b == 0)return a; return gcd(b, a%b); }//gcd

/*
UVA 11360 matrix_transpose
Problem type : 2D array manipulation
matrix transpose is done using swap
*/


int main()
{
	long long i, m, n, x, testCase = 0, j, k, y, flag, temp,r,c;
	long long  sum, max = 0, number, min, p, q, reminder, index, answer, length, total;
	string str, input[15], secondPattern[15], tempString[15];
	cin >> testCase;

	while (testCase--){
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> input[i];
		
		cin >> m;
		while (m--){
			cin >> str;
			if (str[0] == 'i'){
				for (r = 0; r < n; r++)
					for (c = 0; c < n; c++){
						x = (input[r][c] - '0' + 1)%10;
						input[r][c] = x + '0';
					}
			}else if (str[0] == 'd'){
				for (r = 0; r < n; r++)
					for (c = 0; c < n; c++){
						x = (input[r][c] - '0' - 1+10) % 10;
						input[r][c] = x + '0';
					}
			}else if (str[0] == 't'){//tranpose
				for (r = 0; r < n; r++)
					for (c = r+1; c < n; c++){ //  change row into column and column into row
						char ch = input[r][c];
						input[r][c] = input[c][r];//just swap
						input[c][r] = ch;
					}
			}else if(str[0] == 'r'){
				cin >> x >> y; //change row x and y
				x--, y--;
				str = "";
				for (c = 0; c < n; c++){
					str += input[x][c];
					input[x][c] = input[y][c];
				}
				input[y] = str;
			}else{
				cin >> x >> y;	//change col x and y
				x--; y--;
				str = "";
				for (r = 0; r < n; r++){
					str += input[r][x];
					input[r][x] = input[r][y];
				}
				for (r = 0; r < n; r++){
					input[r][y] = str[r];
				}
				
			}
		}
		printf("Case #%d\n", ++max);
		for (r = 0; r < n; r++)
				cout << input[r] << "\n";
		
		cout <<"\n";
	}
	return 0;
}

