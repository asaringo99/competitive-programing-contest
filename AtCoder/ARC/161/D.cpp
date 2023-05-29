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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    ll n, d;
    cin >> n >> d;
    ll maxedge = n * (n - 1) / 2;
    if(maxedge < d * n){
        cout << "No" << endl ;
        return;
    }
    ll k = n * d;
    vector<vector<int>> G(n);
    int phase = -1;
    while(k > 0){
        bool ok = false;
        rrep(p,1,n){
            if(k == 0){
                ok = true;
                break;
            }
            unordered_set<int> used;
            phase = p;
            rep(i,n){
                if(k == 0){
                    ok = true;
                    break;
                }
                if(used.count((i+p)%n)) continue;
                G[i].push_back((i+p)%n);
                used.insert((i+p)%n);
                k--;
            }
            if(ok) break;
        }
    }
    rrep(i,2,phase+1){
        ll val = i;
        val *= val - 1;
        val /= 2;
        val /= i;
        if(val >= d){
            cout << "No" << endl ;
            return;
        }
    }
    cout << "Yes" << endl ;
    rep(i,n){
        for(int u : G[i]) cout << i + 1 << " " << u + 1 << endl;
    }
}

int main(){
    fast_io
    solve();
}