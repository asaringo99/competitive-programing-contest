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
#define endl "\n"

int n ;

P X[303030];
int L[303030], R[303030];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        L[i] = a;
        R[i] = b;
        X[i] = {a,b};
    }
    sort(L,L+n);
    sort(R,R+n);
    ll sum = 0;
    rrep(i,1,n) sum += (ll)i * L[i];
    rep(i,n-1) sum -= (ll)(n - 1 - i) * L[i];

    ll cl = 0, cr = n, in = 0;
    int l = 0, r = 0;
    ll res = 1e18;
    // cout << sum << endl;
    rep(x,10000007){
        bool ok = false;
        while(l < n && x >= L[l]){
            l++;
            cr--;
            in++;
            ok = true;
        }
        while(r < n && x >= R[r]){
            r++;
            cl++;
            in--;
            ok = true;
        }
        chmin(res,sum);;
        // cout << sum << " " << in << endl;
        sum -= cr * in;
        sum += cl * in;
    }
    cout << res << endl;
}