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

void solve(){
    int n, l, v, u;
    cin >> n >> l >> v >> u;
    vector<ll> A(3*n);
    rep(i,n) cin >> A[i];
    rep(i,n) A[i+n] = A[i]+2*l;
    rep(i,n) A[i+2*n] = A[i]+4*l;
    ld dist = (ld)l / (v + u);
    queue<int> queA, queB;
    rep(i,3*n){
        queA.push(i);
        queB.push(i);
    }
    int a = 0;
    int b = -1;
    ld ca = A[0], cb = A[0] + dist;
    ld ra = A[1] - A[0], rb = -1;
    int cnt = 0;
    rep(i,n){
        if(A[i] - A[0] > dist) break;
        queB.pop();
        b = i;
        rb = A[i+1] - A[0] - dist;
        cnt++;
    }
    cnt--;
    queA.pop();
    vector<ld> res(n+1);
    cout << dist << endl;
    while(1){
        // return;
        if(a == n) break;
        int na = queA.front();
        int nb = queB.front();
        ld dist_a = A[na] - ca;
        ld dist_b = A[nb] - cb;
        cout << ca << " " << cb << " " << cnt << endl;
        if(dist_a < dist_b){
            queA.pop();
            a = na;
            ca = A[a];
            cb += dist_a;
            res[cnt] += dist_a;
            cnt--;
        }
        else{
            queB.pop();
            b = nb;
            cb = A[b];
            ca += dist_b;
            res[cnt] += dist_b;
            cnt++;
        }
    }
    rep(i,n+1) cout << fixed << setprecision(25) << res[i] / (ld)2*l << endl;
}

int main(){
    // fast_io
    solve();
}