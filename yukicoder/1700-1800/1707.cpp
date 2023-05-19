#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int t ;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> vec(n+1) ;
    vector<int> A(2*n) , S(2*n) ;
    rep(i,2*n) {
        S[i] = i % n + 1 ;
        cin >> A[i] ;
        vec[A[i]].push_back(i) ;
    }
    rrep(i,1,n+1) if(vec[i].size() != 2){
        cout << "No" << endl ;
        return ;
    }
    bool ok = true ;
    rep(i,2*n){
        if(S[i] != A[i]) ok = false ;
    }
    if(ok){
        cout << "Yes" << endl ;
        return ;
    }
    bool res = false ;
    rrep(i,1,n+1){
        bool check = true ;
        vector<int> V(2*n) ;
        int l = vec[i][0] , r = vec[i][1] ;
        int s = l + 1 , t = r - 1 ;
        int v = t - s + 1 ;
        rep(j,2*n){
            if(s <= j && j <= t) V[j] = A[2*s+v-1-j] ;
            else V[j] = A[j] ;
        }
        rep(j,2*n) if(V[j] != S[j]) check = false ;
        if(check) res = true ;
    }
    if(res) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}