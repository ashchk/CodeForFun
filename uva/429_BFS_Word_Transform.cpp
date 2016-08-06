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
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

#define LL long long
#if 0
#define MOD 1000000007
#define MX 100010
#define pii pair<int,int>
int NODES;
int row,col;
int visited[205];
string S[205];
struct Node{
	string str;
	int cost;
	Node(string s,int x){
		str = s;
		cost = x;
	}
	Node(){
	}
};
int check(string a,string b){
	if(a.length() != b.length())
		return 0;
	int count =0;
	for(int i=0;i<a.length();i++){
		if(a[i]!= b[i]) 
			count++;

	}
	if(count==1)
		return 1;
	return 0;
}
int bfs(string a,string target){
	int i;
	memset(visited,0,sizeof visited);
	queue<Node>Q;
	Q.push(Node(a,0));

	while(!Q.empty()){
		Node temp =Q.front();
		Q.pop();
		if(temp.str == target)
			return temp.cost;
		for(i=0;i<NODES;i++){
			if(!visited[i]){
				if(check(temp.str,S[i]))
				{
					Q.push(Node(S[i],temp.cost+1));
					visited[i]=true;
				}
			}
		}

	}
	return 0;
}
int main()
{
	int test_cases=0,i,j,n,x=0,k,m,y=0;
	bool flag=false;

	string str,given_word,target_word;
	scanf("%d",&x);
	getchar (); getchar ();
	char input[105];
	while(x--){
		i=0;
		while ( gets (input) && strcmp (input, "*") ) {
			S [i] = input;
			i++;
		}

		NODES=i;
		if ( flag ) 
			printf ("\n"); 
		flag = true;


		while ( gets (input) && strlen (input) ) {
			char *pch;
			pch = strtok(input, " ");
			given_word = pch;
			pch = strtok (NULL, " ");
			target_word = pch;
			cout << given_word << " " << target_word;
			printf (" %d\n", bfs(given_word, target_word));
		}

	}

	return 0;
}
#endif