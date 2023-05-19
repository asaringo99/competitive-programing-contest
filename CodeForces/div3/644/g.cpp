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
typedef pair<int,int> P ;
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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> A(n,vector<int>(m,0));
    priority_queue<P,vector<P>,greater<P>> que;
    rep(i,n) que.push({0,i});
    rep(i,m){
        int cnt = b;
        while(cnt > 0){
            auto[c,row] = que.top(); que.pop();
            que.push({c+1,row});
            A[row][i] += 1;
            cnt--;
        }
    }
    rep(i,n){
        int cnt = 0;
        rep(j,m){
            if(A[i][j] > 1){
                cout << "NO" << endl;
                return;
            }
            cnt += A[i][j];
        }
        if(cnt != a){
            cout << "NO" << endl;
            return;
        }
    }
    rep(j,m){
        int cnt = 0;
        rep(i,n){
            if(A[i][j] > 1){
                cout << "NO" << endl;
                return;
            }
            cnt += A[i][j];
        }
        if(cnt != b){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    rep(i,n){
        rep(j,m) cout << A[i][j]; cout << endl;
    }
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}