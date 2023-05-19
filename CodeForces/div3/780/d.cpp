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

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    int lef = 0, rig = 0;
    int pls = 1;
    int l = 0, r = n, cnt = 0, res = 0, al = 0, ar = n;
    while(rig < n){
        while(rig < n && A[rig] == 0){
            rig++;
            lef++;
            l++;
            r--;
        }
        while(rig < n && A[rig] != 0){
            if(abs(A[rig]) == 2) cnt++;
            if(A[rig] < 0) pls ^= 1;
            r--;
            if(pls){
                if(res < cnt){
                    res = cnt;
                    al = l;
                    ar = r;
                }
            }
            rig++;
        }
        while(lef < rig){
            if(abs(A[lef]) == 2) cnt--;
            if(A[lef] < 0) pls ^= 1;
            l++;
            if(pls){
                if(res < cnt){
                    res = cnt;
                    al = l;
                    ar = r;
                }
            }
            lef++;
        }
    }
    cout << al << " " << ar << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}