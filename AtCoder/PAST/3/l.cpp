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
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int n, m;
queue<ll> que[101010];
set<pair<ll,ll>> F, S;
ll X[101010], Y[101010];

int main(){
    fast_io
    cin >> n;
    vector<vector<ll>> T(n);
    rep(i,n){
        X[i] = -1e18;
        Y[i] = -1e18;
    }
    rep(i,n){
        int k;
        cin >> k;
        vector<ll> A(k);
        rep(j,k) cin >> A[j], que[i].push(A[j]);
        T[i] = A;
    }
    rep(i,n){
        X[i] = que[i].front();
        F.insert({que[i].front(), i}); que[i].pop();
        if(que[i].empty()) continue;
        Y[i] = que[i].front();
        S.insert({que[i].front(), i}); que[i].pop();
    }
    cin >> m;
    vector<ll> res(m);
    rep(i,m){
        int a;
        cin >> a;
        if(a == 1){
            auto it = F.end(); it--;
            auto[val, id] = *it;
            F.erase(it);
            X[id] = Y[id];
            S.erase({Y[id], id});
            F.insert({X[id], id});
            Y[id] = -1e18;
            if(!que[id].empty()){
                Y[id] = que[id].front();
                S.insert({que[id].front(), id}); que[id].pop();
            }
            res[i] = val;
        }
        if(a == 2){
            auto it = F.end(); it--;
            auto[val, id] = *it;
            ll tmp = -1e18, jd = -1;
            auto jt = S.end();
            if(!S.empty()){
                jt--;
                tmp = (*jt).first;
                jd = (*jt).second;
            }
            if(val > tmp){
                F.erase(it);
                X[id] = Y[id];
                S.erase({Y[id], id});
                F.insert({X[id], id});
                Y[id] = -1e18;
                if(!que[id].empty()){
                    Y[id] = que[id].front();
                    S.insert({que[id].front(), id}); que[id].pop();
                }
                res[i] = val;
            }
            else{
                S.erase(jt);
                Y[jd] = -1e18;
                if(!que[jd].empty()){
                    Y[jd] = que[jd].front();
                    S.insert({que[jd].front(), jd}); que[jd].pop();
                }
                res[i] = tmp;
            }
        }
    }
    for(int u : res) cout << u << endl;
}