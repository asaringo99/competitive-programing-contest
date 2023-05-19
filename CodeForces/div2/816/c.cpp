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

int z ;
ll n, m;

ll f(ll l, ll r){
    ll sl = n - l, sr = n - r;
    return l * (n - r - 1) + l * (r - l + 1) + (n - r - 1) * (r - l + 1) + (r - l + 2) * (r - l + 1) / 2;
}

void solve(){
    cin >> n >> m;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    ll sum = 0;
    rep(i,n){
        ll k = i;
        rrep(j,i,n){
            if(A[i] != A[j]) break;
            i = j;
        }
        ll l = n - k, r = n - i;
        sum += f(k,i);
    }
    rep(i,m){
        ll a, x;
        cin >> a >> x;
        a--;
        if(A[a] == x){
            cout << sum << endl;
            continue;
        }
        if(a > 0 && A[a] != A[a-1] && A[a-1] == x) sum -= a * (n - a);
        if(a > 0 && A[a] == A[a-1] && A[a-1] != x) sum += a * (n - a);
        if(a < n - 1 && A[a] != A[a+1] && A[a+1] == x) sum -= (a + 1) * (n - a - 1);
        if(a < n - 1 && A[a] == A[a+1] && A[a+1] != x) sum += (a + 1) * (n - a - 1);
        A[a] = x;
        cout << sum << endl;
    }
}

int main(){
    fast_input_output
    solve();
}