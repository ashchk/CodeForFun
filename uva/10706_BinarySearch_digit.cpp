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
/*
//---------coinChange--DP faster----
long long table[30000+1];
long long coinChangecount(int m, int n )
{
memset(table, 0, sizeof(table));
table[0] = 1;

for(int i=0; i<m; i++)
for(int j=a[i]; j<=n; j++)
table[j] += table[j-a[i]];

return table[n];
}
//----coinChange- using recursion+dp------------
long long dp[6][30005];
long long coin_Change(int coinNumber, int reminder){//how many ways to count this coin

if(dp[coinNumber][reminder])
return dp[coinNumber][reminder];

if(reminder == 0){
dp[coinNumber][reminder] = 1;return dp[coinNumber][reminder];
}
if(coinNumber <0){
dp[coinNumber][reminder] = 0;return dp[coinNumber][reminder];
}
if(reminder<0){
dp[coinNumber][reminder] = 0;return dp[coinNumber][reminder];
}
if(coinNumber<=0 && reminder>0){
dp[coinNumber][reminder] = 0;return dp[coinNumber][reminder];
}

dp[coinNumber][reminder] = coin_Change(coinNumber, reminder - a[coinNumber-1])+ coin_Change(coinNumber-1, reminder);
return dp[coinNumber][reminder];
}
-------------------------------------------
//----------------- LDS+ LIS N^2----------------
for(i = n - 1; i >= 0; i--) {
for( j = i + 1; j < n; j++) {
if(a[i] > a[j] && ( lds[i] < (lds[j]+1)))
lds[i] = lds[j]+1;
}
}
for(i = n - 1; i >= 0; i--) {
for( j = i + 1; j < n; j++) {
if(a[i] < a[j] && ( lis[i] < (lis[j]+1))){
lis[i] = lis[j]+1;
}
}
}
vector<int>List; // LIS list
for(i = n-1; i >=0 && max; i--){
if(max == lis[i]){
List.push_back(a[i]);
max--;
}
}
//----binary search---------------------
int binarySearchLIS(int key,int size){
int low =0,high = size-1,mid,ret=100005,index=-1;
while(low<=high){
mid = (low+high)/2;
if(lis[mid] == key)
return -1;//already found
else if(lis[mid] > key){
if(ret>lis[mid]){
ret = lis[mid];
index = mid;
}
high=mid-1;//high index decreased as the number is already greater than mid
}
else if(lis[mid] < key){
low=mid+1; //key is bigger than the mid number so low index increased
}
}
return index;
}
//----------palindrome-------------
int isPalindrome(string str){
int i,n=str.size(),j,mid=str.size()/2;
for(i=0,j=n-1;i<mid;i++,j--)
if(str[i] != str[j])
return 0;
if(i==mid)
return 1;
return 0;
}
//---------------------binary search with extra condition----------------
pair<int,int>P[15];
int binary_search( int first, int last,int key)
{
while (last >= first)
{
// calculate the midpoint for roughly equal partition
int imid = (first + last)/2;
if(P[imid].first <= key && P[imid].second>= key)
return imid;

else if (P[imid].second < key)
first = imid + 1;
else
last = imid - 1;
}

return -1;// key was not found
}
//--------nlogn list------LIS-------------
int GetCeilIndex(int a[], int T[], int l, int r, int key) {
int m;

while( r - l > 1 ) {
m = l + (r - l)/2;
if( a[T[m]] >= key )
r = m;
else
l = m;
}

return r;
}
int LongestIncreasingSubsequence( int size) {
// Add boundary case, when array size is zero
// Depend on smart pointers

int *tailIndices = new int[size];
int *prevIndices = new int[size];
int len,j,i;

memset(tailIndices, 0, sizeof(tailIndices[0])*size);
memset(prevIndices, 0xFF, sizeof(prevIndices[0])*size);

tailIndices[0] = 0;
prevIndices[0] = -1;
len = 1; // it will always point to empty location
for( int i = 1; i < size; i++ ) {
if( a[i] < a[tailIndices[0]] ) {
// new smallest value
tailIndices[0] = i;
} else if( a[i] > a[tailIndices[len-1]] ) {
// a[i] wants to extend largest subsequence
prevIndices[i] = tailIndices[len-1];
tailIndices[len++] = i;
} else {
// a[i] wants to be a potential condidate of future subsequence
// It will replace ceil value in tailIndices
int pos = GetCeilIndex(a, tailIndices, -1, len-1, a[i]);

prevIndices[i] = tailIndices[pos-1];
tailIndices[pos] = i;
}
}
j=0;
for(i = tailIndices[len-1],j=0; i >= 0; i = prevIndices[i],j++ ){
lisCal[j] = a[i];
}
len = j;

delete[] tailIndices;
delete[] prevIndices;

return len;
}
---------Flood Fill-------------------
#define pii pair<int,int>
//int fx[]={1,-1,0,0,1,1,-1,-1};
//int fy[]={0,0,1,-1,1,-1,1,-1};
int fx[] = {1,-1,0,0}; //not in diagonal
int fy[] = {0,0,1,-1};
int cell[105][105];
int d[105][105],vis[105][105];
int row,col;
bool check(int tx,int ty)
{
if (tx>=0 && tx<row && ty>=0 && ty<col)
return true;
return false;
}
int bfs(int sx,int sy)
{
vis[sx][sy]=1;
int sum = 1;
queue<pii>q;
q.push(pii(sx,sy));
while(!q.empty())
{
pii top=q.front(); q.pop();
for(int k=0;k<4;k++)
{
int tx=top.first+fx[k];
int ty=top.second+fy[k];
if((check(tx,ty)) && (cell[tx][ty]==cell[sx][sy]|| cell[tx][ty]==1) && vis[tx][ty]==0)//
{
vis[tx][ty]=1;
sum++;
//d[tx][ty]=d[top.first][top.second]+1;
q.push(pii(tx,ty));
}
}
}
return sum;
}
*/

/* //prime generate
#define N 1000000
bool prime_number[N];
long long prime_generator(long long n)
{
long long i = 0 , x = 0,j = 0,limit;

prime_number[0] = false;
prime_number[1] = false;
for(i = 2 ; i<= n ; i++)
prime_number[i] = true;
limit = (long long)sqrt((double)n);
for(x = 2 ; x <=  limit;x++)
{
if(prime_number[x] == true)
{
for(i = 4 ; i <= n ;i++)
if(prime_number[i] == true & i != x)
if(i % x == 0)
prime_number[i] = false;
}
}
x = 0;
for(i = 2 ; i<= n ; i++)
if(prime_number[i])
x++;//number of primes
return x;
}*/

/*
int visited[505];
int level[505];
vector<int>tree[505];


/*int dfs(int current_vertex,int source_vertex){
int ret = 0;
for(int i = 0 ;i <tree[current_vertex].size();i++){
int new_index = tree[current_vertex][i]; //x =  new index

if( new_index != source_vertex){

int y = dfs(new_index,current_vertex); // vertex = previous/source index

if(y == 0 && problem_road[current_vertex][i] == 1)
result.push_back(new_index);

ret+=max(problem_road[current_vertex][i],y);
}
}
return ret;
}
void DFS(int u, int l){
visited[u] = 1;
level[u] = l;
for (int i = 0; i < tree[u].size(); i++){
int x = tree[u][i];
if (!visited[x])
DFS(x, l + 1);
}

}

*/
bool mysort(int a, int b){
	if (a > b)
		return true;
	return false;
}
typedef struct {
	double x, y;
} Point;

vector<Point> P;

double distance2D(Point a, Point b)
{
	return sqrt(SQR(a.x - b.x) + SQR(a.y - b.y));
}

long long dp[100005],a[100005];

int digitCount(LL number){
	int count = 0;
	while (number){
		number /= 10;
		count++;
	}
	return count;
}

int mybinary_search(int l, int h, int searchKey){
	LL low = l, high = h,mid;

	while (low < high){
		mid = (low + high) / 2;
		if (a[mid] == searchKey)
			return mid;
		else if (a[mid] < searchKey)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

/*
UVA 10706 number sequence
Problem type : binary search for searching what is the nth digit
use binary search and dp for finding a specific digit in a big number of string array
*/

int main() {
	//freopen ("d:/Codejam/coding_contest_creation.txt","r",stdin);
	//freopen ("d:/Codejam/output.txt","w",stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);

	LL n, i, j, k, result = 0, temp, m;
	LL x, y, z, sum, test_case, length, ans,len;

	string str = "", st = "";
	
	char ch[]="abcd",C[10];
	LL low, high, mid,t;
	dp[0] = 0; a[0] = 0;
	for (i = 1; ; i++){
		dp[i] = dp[i - 1] + digitCount(i);//calculate digit till that number ex. 69 digits for 12 numbers
		a[i] = a[i - 1] + dp[i]; //total digit till now a[] = 1,3,6,10,15,21...
		if (a[i] >= 2147483647)
			break;
	}
	int totalIndex = i;
	while (cin >> y)
	{
		while (y--){
			cin >> n;
			int part = mybinary_search(1, totalIndex, n),cnt; //search which part the target input belongs to
			if (part == 1){
				cout << part<<"\n";
				continue;
			}
			
			while (a[part] < n)
				part++;//if partition is one step smaller
			
			sum = a[part-1];
			
			bool flag = 0;
			for (i = 1; i <= part; i++){//calculate string size for target index
				if (flag) break;
				m = i;
				cnt = 0;
				str = "";
				while (m){ //digit calcualtion for each number
					str += m % 10 + '0';
					m /= 10;
					cnt++;
				}
				if (sum + cnt >= n){ // found target digit :)
					int remain = n - sum;
					for (j = str.size() - 1; j >= 0; j--){
						if (remain==1){
							flag = 1;
							cout << str[j] << "\n";
							break;
						}
						else
							remain--;
					}
				}
				else
					sum += cnt;
			}
		}
		
	}
	return 0;
}