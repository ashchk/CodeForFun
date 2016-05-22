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

long long GCD(long long b, long long a)
{
	if(a == 0)
		return b;
	return GCD(a, b%a);
}
long long getLCM(long long a,long long b){
	long long c=a/GCD(a,b);
	return b*c;
}
/*
//number to string conversion
stringstream ss;
ss << number;
str1= ss.str();
*/
#define pii pair<int,int>


/*
CF 353 div2 D
problem type : BST, find root
number just larger than input (x) , using upperbound

if it's root already exists and it does not have left child

or either x is the biggest number/ the root already has a left child 10,5,4,6(for 6)
*/

int main() {
	//freopen ("d:/Codejam/coding_contest_creation.txt","r",stdin);
	//freopen ("d:/Codejam/output.txt","w",stdout);
	long long n,i,j,k,temp,m;
	long long x,y,z,sum,test_case,length;
	long long flag,min=1e9,index=0,ans,remain,check,r,a,b,c,d;

	string str="",str1;
	
	//BST problem
	while(cin>>n){
		map<long long ,LL>left,right;
		set<long long>Numbers;
		cin>>x;
		
		Numbers.insert(x);
		
		for(i = 1;i<n ;i++){
			cin>>x;
			auto it = Numbers.upper_bound(x);//number just larger than x

			if(it != Numbers.end() && left.count(*it)==0 ){
				left[*it] = x;//it's root already exists and it does not have left child
				ans = *it;
			}else{
			it--; //either x is the biggest number
			right [*it] = x; //or the root already has a left child 10,5,4,6(for 6)
			ans = *it;
			}
			Numbers.insert(x);
			cout<<ans<<" ";
		}
		cout<<"\n";
	}

	
	return 0;
}