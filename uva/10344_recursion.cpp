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


#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
long long GCDFast(long long a,long long b){   while(b)b^=a^=b^=a%=b;  return a;   }
#define SET(a) memset(a,-1,sizeof(a))
#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define MX 100010
#define pii pair<int,int>
#define LL long long
// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};
/*
UVA 10344
Problem type : recursion
next_permutation need to be done myself later
*/
long long a[200005];
bool check = false;
int cnt =0;
void recCheck(int number, int index){
	if(check) return;
	if(index == 5){
		cnt++;
		if(number  == 23)
			check= true;

		return;
	}
	recCheck(number+ a[index], index+1);
	recCheck(number- a[index], index+1);
	recCheck(number* a[index], index+1);
	return;
}

int main() {
	//freopen ("d:/Codejam/coding_contest_creation.txt","r",stdin);
	//freopen ("d:/Codejam/output.txt","w",stdout);
	long long n,i,j,k,temp,m;
	long long x,y,z,sum,test_case,length;
	long long flag,min=1e9,index=0,ans,remain,r;

	string str="",str1;
	sum =0;

	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]){
		if(a[0]==0 && a[1]==0 && a[2] == 0 && a[3] == 0 && a[4] == 0)
			break;
		check = false;
		sort(a,a+5);
		do {
			recCheck(a[0], 1);
			if(check) 
				break;

		} while(next_permutation(a , a + 5));


		//cout<<"rec called "<<cnt<<"\n";
		if(check)
			cout<<"Possible\n";
		else
			cout<<"Impossible\n";
	}



	return 0;
}