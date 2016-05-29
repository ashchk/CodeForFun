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




bool mysort(pair<pair<long long,long long>,int> A , pair<pair<long long,long long>,int> B){

	if(A.first.first > B.first.first)
		return true;
	if(A.first.second > B.first.second)
		return true;
	return false;
}


/*
CF 354 div2 C
problem type : two pointers
for character 'a' search highest substring with atmost k, 'b' characters, O(n)
same for 'b' again.
could not solve the problem in contest, because of not understanding that
this n+n = 2n not n*n!!!
*/


int main() {
	//freopen ("d:/Codejam/coding_contest_creation.txt","r",stdin);
	//freopen ("d:/Codejam/output.txt","w",stdout);
	long long n,i,j,k,temp,m;
	long long x,y,z,sum,test_case,length;
	long long flag,min=1e9,index=0,ans,remain,check,r;
	
	string str="",str1;
	
	
	
	while(cin>>n>>k){
		cin>>str;
		j = 0;
		LL countK=0,mx=0;

		//check for 'a'
		for(i = 0;i < n; i++){//full string taverse 
			
			while(j<n && countK <k){ // sub string as long as b does not occur more than k times
				if(str[j] == 'b' ){
				countK++;
				}
				j++;

			}
			while(j<n && str[j] == 'a')//check if there are more 'a' after b is already k times
				j++;

			mx = std::max(mx,j-i);

			if(str[i] == 'b')
				countK--;
		}
		

		j = 0, countK=0;

		//check for 'b'
		for(i = 0;i < n; i++){//full string taverse 
			
			while(j<n && countK <k){ // sub string as long as a does not occur more than k times
				if(str[j] == 'a' ){
				countK++;
				}
				j++;

			}
			while(j<n && str[j] == 'b')//check if there are more 'b' after a is already k times
				j++;

			mx = std::max(mx,j-i);

			if(str[i] == 'a')
				countK--;
		}
		cout<<mx<<"\n";
	}


	
	return 0;
}