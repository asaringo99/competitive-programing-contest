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
    int n, a, b;
    cin >> n >> a >> b;
    if(b == 0){
        if(a == 0){
            rep(i,n) cout << 1 << " "; cout << endl;
            return;
        }
        if(n - a == 1){
            cout << -1 << endl;
            return;
        }
        int N = n;
        n -= a + 2;
        // int s = 1;
        int k = 1;
        vector<int> vec = {1};
        while(a >= 0){
            vec.push_back(k);
            k++;
            // s++;
            a--;
        }
        // if(s > N){
        //     cout << -1 << endl;
        //     return;
        // }
        for(int u : vec) cout << u << " ";
        rep(i,n) cout << 1 << " "; cout << endl;
        return;
    }
    int sum = 1;
    rep(i,b + 1){
        cout << sum << " ";
        sum *= 2;
    }
    sum /= 2;

    rep(i,a) {
        sum++;
        cout << sum << " ";
    }
    rep(i,n-a-b-1) cout << 1 << " "; cout << endl;
}

int main(){
    fast_io
    solve();
}