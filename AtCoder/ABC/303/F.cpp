#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef __int128_t sll;
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
#define all(a) a.begin(), a.end()
#define endl "\n"

ll n, h;
vector<ll> T, D;

bool f(ll x){
    priority_queue<ll> que;
    priority_queue<pair<ll,ll>> Q;
    rep(i,n){
        if(T[i] > x) que.push(D[i]);
        else Q.push({T[i]*D[i], T[i]});
    }
    que.push(1);
    Q.push({0,1});
    ll sum = 0;
    while(x > 0){
        while(!Q.empty()){
            auto[val, lim] = Q.top();
            if(lim <= x) break;
            Q.pop();
            que.push(val/lim);
        }
        auto[v, lim] = Q.top();
        ll u = que.top();
        ll valid = v / u + (v % u != 0);
        chmax(valid,lim);
        ld flflflflflf = 0;
        if(lim <= valid && valid <= x){
            flflflflflf += (ld)(valid + x) * (x - valid + 1) / 2 * u;
            flflflflflf += (ld)(valid - lim) * v;
        }
        else flflflflflf += (ld)(x - lim + 1) * v;
        if(flflflflflf + sum >= h) return true;
        ll add = 0;
        if(lim <= valid && valid <= x){
            add += (valid + x) * (x - valid + 1) / 2 * u;
            add += (valid - lim) * v;
        }
        else add += (x - lim + 1) * v;
        sum += (ll)add;
        x = lim - 1;
        Q.pop();
        que.push(v/lim);
    }
    return false;
}

int main(){
    fast_io
    cin >> n >> h;
    T = vector<ll>(n);
    D = vector<ll>(n);
    rep(i,n) cin >> T[i] >> D[i];
    ll lef = 0, rig = 2e18;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2;
        if(f(mid)) rig = mid;
        else lef = mid;
    }
    cout << rig << endl;
}