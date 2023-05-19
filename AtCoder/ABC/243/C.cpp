#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
string S ;
map<int,vector<int>> R , L ;
int X[202020] , Y[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    cin >> S ;
    rep(i,n){
        if(S[i] == 'L') L[Y[i]].push_back(X[i]) ;
        if(S[i] == 'R') R[Y[i]].push_back(X[i]) ;
    }
    for(auto it : L){
        sort(L[it.first].begin(),L[it.first].end()) ;
    }
    for(auto it : R){
        sort(R[it.first].begin(),R[it.first].end()) ;
    }
    bool ok = false ;
    for(auto it : R){
        int x = it.second[0] ;
        if(L[it.first].size() == 0) continue ;
        int y = L[it.first][L[it.first].size() - 1] ;
        if(x < y) ok = true ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}