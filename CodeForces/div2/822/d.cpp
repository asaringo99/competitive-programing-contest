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

void solve(int z){
    int n, k;
    cin >> n >> k;
    k--;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    {
        vector<P> L;
        ll val = A[k], lm = 0, rm = 0;
        for(int i = k - 1 ; i >= 0 ; i--){
            val += A[i];
            if(val < A[k]) chmin(lm,val);
            if(val - A[k] > rm) {
                rm = val - A[k];
                L.push_back({A[k]-lm,val - A[k]});
            }
        }
        val = A[k];
        int l = 0;
        ll d = 0, e = 0;
        bool ok = true;
        for(int i = k + 1 ; i < n ; i++){
            while(l < L.size()){
                auto[mv, p] = L[l];
                if(mv > A[k] + d) break;
                e = p;
                l++;
            }
            d += A[i];
            if(A[k] + d + e < 0) ok = false;
        }
        if(ok){
            cout << "YES" << endl;
            return;
        }
    }
    {
        vector<P> R;
        ll val = A[k], lm = 0, rm = 0;
        for(int i = k + 1 ; i < n ; i++){
            val += A[i];
            if(val < A[k]) chmin(lm,val);
            if(val - A[k] > rm) {
                rm = val - A[k];
                R.push_back({A[k]-lm,val - A[k]});
            }
        }
        val = A[k];
        int l = 0;
        ll d = 0, e = 0;
        bool ok = true;
        for(int i = k - 1 ; i >= 0 ; i--){
            while(l < R.size()){
                auto[mv, p] = R[l];
                if(mv > A[k] + d) break;
                e = p;
                l++;
            }
            d += A[i];
            if(A[k] + d + e < 0) ok = false;
        }
        if(ok){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve(i);
}