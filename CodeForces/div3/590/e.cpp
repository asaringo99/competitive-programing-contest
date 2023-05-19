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


int n, m;
ll  A[202020], S[202020];
ll V[202020];

void solve(){
    cin >> n >> m;
    ll sum = 0;
    rep(i,m) cin >> A[i];
    rep(i,m-1) {
        sum += abs(A[i]-A[i+1]);
        int mn = min(A[i],A[i+1]);
        int mx = max(A[i],A[i+1]);
        S[mn]++;
        S[mx+1]--;
    }
    rep(i,n){
        if(i == 0){
            V[A[i]] += (A[i+1] - 1) - abs(A[i] - A[i+1]);
            if(A[i] > A[i+1]) V[A[i]]++;
        }
        else if(i == n - 1){

        }
        else{

        }
    }
    int s = 0;
    rep(i,202020){
        s += S[i];
        S[i] = s;
    }
    cout << sum << " ";
    rrep(i,1,n){
        ll s = sum;
        s += abs(A[0] - A[i]);
        if(i != 0) s -= abs(A[i] - A[i-1]);
        if(i != n - 1) s -= abs(A[i] - A[i+1]);
        if(0 < i && i < n - 1) s += abs(A[i-1]-A[i+1]);
        cout << s << " ";
    }
    cout << endl;
}

int main(){
    fast_input_output
    solve();
}