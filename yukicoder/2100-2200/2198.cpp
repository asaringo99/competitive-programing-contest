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
#define all(a) a.begin(), a.end()
#define endl "\n"

ll m;

vector<tuple<ll,ll,ll>> vec;

int main(){
    fast_input_output
    cin >> m;
    if(m == 0){
        cout << "thisisthechinchin" << endl;
        return 0;
    }

    ll k;
    for(ll i = 1; i * i * i <= m; i++){
        k = i;
    }
    k++;
    ll x = k, y = k, z = k, val = k * k * k;
    rep(i,100000){
        while(x > 1){
            if(val - y * z >= m){
                val -= k * k;
                x--;
            }
            else break;
        }
        // cout << x << " " << y << " " << z << " " << val << endl;
        while(y > 1){
            if(val - x * z >= m){
                val -= x * z;
                y--;
            }
            else break;
        }
        // cout << x << " " << y << " " << z << " " << val << endl;
        while(z > 1){
            if(val - x * y >= m){
                val -= x * y;
                z--;
            }
            else break;
        }
    }
    // cout << x << " " << y << " " << z << " " << val << endl;
    string res = "";
    rep(i,x) res += 'c';
    rep(i,y) res += 'o';
    rep(i,z) res += 'n';

    rep(i,y-1){
        if(val - x >= m){
            val -= x;
            swap(res[x+y-i],res[x+y-i-1]);
        }
        else break;
    }

    rep(i,x-1){
        if(val - 1 >= m){
            val -= x;
            swap(res[x-i],res[x-i-1]);
        }
        else break;
    }

    cout << res << endl;

    vector<vector<ll>> dp(res.size()+1,vector<ll>(4,0));
    dp[0][0] = 1;
    rep(i,res.size()){
        if(res[i] == 'c') dp[i+1][1] += dp[i][0];
        if(res[i] == 'o') dp[i+1][2] += dp[i][1];
        if(res[i] == 'n') dp[i+1][3] += dp[i][2];
        rep(j,4) dp[i+1][j] += dp[i][j];
    }
    // cout << dp[res.size()][3] << endl;
}