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
#if 0 
int GCD(int b, int a)
{
	if (a == 0)	return b;
	return GCD(a, b%a);
}
long long getLcm(long long a, long long b){
	long long c = a / gcd(a, b);
	return b*c;
}

long long a[100005];

bool myfunc(pair<int, int>a, pair<int, int>b){
	if (a.second<b.second)
		return true;
	return false;

}

int main()
{
	long long i, m, n, x, testCase = 0, j, k, y, flag, temp;
	long long  sum, max, number, min, p, q, reminder, index, minIndex, length, total, N;
	string str;
	int b[25], ti, di, mask;

	while (scanf("%lld", &N) == 1)
	{
		scanf("%lld", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		vector<int>X, result;
		max = 0;
		for (mask = 0; mask<(1 << n); mask++){
			sum = 0;
			X.clear();
			for (i = 0; i < n; i++){
				if (mask & (1 << i)){
					sum += a[i];
					X.push_back(a[i]);
				}
			}
			if (sum >= max && sum <= N){
				max = sum;
				result = X;
			}
		}

		for (i = 0; i < result.size(); i++)
			printf("%d ", result[i]);

		printf("sum:%lld\n", max);
	}
	return 0;
}
#endif