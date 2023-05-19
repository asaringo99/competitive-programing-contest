#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
vector<int> A ;
map<int,char> mp ;

void dfs(int dep){
    if(dep == n){
        for(int u : A) cout << mp[u] ;
        cout << endl ;
        return ;
    }
    for(int i = 0 ; i < 3 ; i++){
        A.push_back(i) ;
        dfs(dep+1) ;
        A.pop_back() ;
    }
}

int main(){
    cin >> n ;
    mp[0] = 'a' ;
    mp[1] = 'b' ;
    mp[2] = 'c' ;
    dfs(0) ;
}