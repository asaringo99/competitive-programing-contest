#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

int n ;
int A[202020];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    ll s = 0;
    int k = -1;
    rep(i,n) if(A[i] * 2 >= A[n-1]) {
        k = i;
        break;
    }
    s = 2 * A[k];
    int mn = A[0], mx = A[n-1], res = mx;
    rep(i,2*n){
        auto it = upper_bound(A,A+n,s-mx-1);
        int id = it - A;
        cout << mn << " " << mx << " " << s << " " << id << endl;
        int a = A[id];
        if(i % 2 == 0) a = s - A[id];
        else a = A[id] - s;
        s = 2 * a - 2 * s;
        if(i % 2 == 0){
            mx = s - mn;
            mn = s - mx;
        }
        else{
            mx = mn - s;
            mn = mx - s;
        }
        
        chmax(res,mx);
    }
    cout << res << endl;
}