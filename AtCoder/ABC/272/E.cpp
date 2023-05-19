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

int n, m ;

ll A[202020];
vector<int> B[202020];
set<int> st[202020];

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,n) cin >> A[i];
    rep(i,n){
        int k = A[i] / (i + 1);
        if(k < 0){
            k = -k;
            if(A[i] % (i + 1) != 0) k++;
        }
        else{
            k = 1;
        }
        int x = A[i] + k * (i + 1);
        while(x <= n && k <= m){
            if(st[k].count(x)) {
                x += (i + 1);
                k++;
                continue;
            }
            st[k].insert(x);
            B[k].push_back(x);
            x += (i + 1);
            k++;
        }
    }
    rep(i,n+1) sort(B[i].begin(),B[i].end());
    rrep(i,1,m+1){
        bool ok = false;
        rep(j,B[i].size()){
            if(j != B[i][j]){
                cout << j << endl;
                ok = true;
                break;
            }
        }
        if(!ok) cout << B[i].size() << endl;
    }
}