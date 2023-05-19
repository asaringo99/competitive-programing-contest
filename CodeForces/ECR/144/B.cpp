#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n, m;
    string S, T;
    cin >> S >> T;
    n = S.size();
    m = T.size();
    if(S == T){
        cout << "YES" << endl;
        cout << S << endl;
        return;
    }
    if(S[0] == T[0]){
        cout << "YES" << endl;
        cout << S[0] << "*" << endl;
        return;
    }
    if(S[n-1] == T[m-1]){
        cout << "YES" << endl;
        cout << "*" << S[n-1] << endl;
        return;
    }
    rep(i,n-1){
        string X = "";
        X += S[i];
        X += S[i+1];
        rep(j,m-1){
            string Y = "";
            Y += T[j];
            Y += T[j+1];
            if(X == Y){
                cout << "YES" << endl;
                cout << "*" << X << "*" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}