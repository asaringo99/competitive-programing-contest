#include <bits/stdc++.h>
using namespace std ;
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
string a , b , c ;
set<char> st ;
vector<char> vec ;
bool used[10] ;
ll x = -1 , y = -1 , z = -1 ;
map<char,int> mp ;

void dfs(int v){
    if(v == n){
        ll s = 0 , t = 0 , r = 0 ;
        if(mp[a[0]] == 0 || mp[b[0]] == 0 || mp[c[0]] == 0) return ;
        for(char u : a) s *= 10 , s += mp[u] ;
        for(char u : b) t *= 10 , t += mp[u] ;
        for(char u : c) r *= 10 , r += mp[u] ;
        if(s + t == r) x = s , y = t , z = r ;
        return ;
    }
    for(int i = 0 ; i <= 9 ; i++){
        if(used[i]) continue ;
        used[i] = true ;
        mp[vec[v]] = i ;
        dfs(v+1) ;
        used[i] = false ;
    }
}

int main(){
    cin >> a >> b >> c ;
    for(char u : a) st.insert(u) ;
    for(char u : b) st.insert(u) ;
    for(char u : c) st.insert(u) ;
    n = st.size() ;
    if(n > 10){
        cout << "UNSOLVABLE" << endl ;
        return 0 ;
    }
    for(char u : st) vec.push_back(u) ;
    dfs(0) ;
    if(x == -1) cout << "UNSOLVABLE" << endl ;
    else cout << x << endl << y << endl << z << endl ;
}