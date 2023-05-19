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
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;
string S ;
set<char> ST, st ;
set<char> mp ;

int main(){
    fast_input_output
    cin >> S ;
    bool a = false , b = false , c = false ;
    n = S.size() ;
    for(char u : a_z) st.insert(u) ;
    for(char u : A_Z) ST.insert(u) ;

    for(char u : S) mp.insert(u) ;
    for(char u : S) if(st.count(u) == 1) a = true ;
    for(char u : S) if(ST.count(u) == 1) b = true ;
    if((int)mp.size() == n) c = true ;
    if(a && b && c) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}