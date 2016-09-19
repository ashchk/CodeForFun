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
#define SQR(x) ((x)*(x))

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
#define MOD 1000000007
#define inf MOD
#define MX 1e9
#define pii pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define EPS 1e-7
template <class T> inline T gcd(T a, T b){ if (b == 0)return a; return gcd(b, a%b); }//gcd
int GCD(int b, int a)
{
	if (a == 0)	return b;
	return GCD(a, b%a);
}
long long getLcm(long long a, long long b){
	long long c = a / gcd(a, b);
	return b*c;
}

bool mysort(int a, int b){
	if (a > b)
		return true;
	return false;
}

void swap(char *x, char *y){
	char temp = *x;
	*x = *y;
	*y = temp;
}

void permute(int l, int r, char *str){
	if (l == r){
		printf("%s\n", str);
		return;
	}
	for (int i = l; i <= r; i++){
		swap(str[i], str[l]);
		permute(l + 1, r, str);
		swap(str[i], str[l]);
	}
}

string words[1005], query[1005];
int t, word, length;
void recfun(string q, int index, string str,int w){
	if (index == length){
		cout << str << "\n";
		return;
	}
	if (q[index] == '0'){
		for (int x = 0; x <= 9; x++){
			char ch = x + '0';
			recfun(q, index + 1, str+ch, w);
		}
	}
	else{
		for (int j = 0; j < word; j++){
			//str += words[j];
			recfun(q, index + 1, str + words[j], w + 1);
		}
		//if(w < word)	
	}
}
//628 recursion
/*
UVA 628 password
Problem type : recursion
for recursion dont assign anything, rather send it in the function
*/
int main() {
	LL n, i, j, k, result = 0, temp, m;
	LL x, y, z, sum, test_case, ans, len;
	
	string str,tempStr,str1[15];

	int q;
	while (cin>>word){
		for (i = 0; i < word; i++)
			cin >> words[i];
		
		cin >> q;
		while (q--){
			cin >> tempStr;
			cout << "--\n";
			length = tempStr.size();
			
			recfun(tempStr, 0, "", 0);
			
		}
	}
	return 0;
}