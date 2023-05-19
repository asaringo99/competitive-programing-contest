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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

ll n, k ;
ll A[101010], B[101010];

bool f(ll x){
    ll K = k;
    ll X = x, rem = 0;
    rep(i,n){
        X -= (i > 0 ? A[i] - A[i-1] : A[i]);
        rem -= (i > 0 ? A[i] - A[i-1] : A[i]);
        if(rem < 0) rem = 0;
        ll a;
        if(B[i] > rem){
            a = B[i] - rem;
            rem = 0;
        }
        else{
            a = 0;
            rem -= B[i];
        }
        ll cnt;
        if(a == 0) continue;
        else if(X <= 0) return false;
        else if(a % X == 0){
            cnt = a / X;
            K -= cnt;
        }
        else{
            cnt = a / X + 1;
            K -= cnt;
            rem = X - a % X;
        }
    }
    return K >= 0;
}

int main(){
    cin >> n >> k;
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    ll lef = 0, rig = 3e18;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2;
        if(f(mid)) rig = mid;
        else lef = mid;
    }
    cout << rig << endl;
}