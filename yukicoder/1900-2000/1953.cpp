#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"

ll k ;
ll dp[101][2][202] ;

ll f(ll a){
    rep(i,30) rep(j,2) rep(x,202) dp[i][j][x] = 0 ;
    int n = to_string(a).size() ;
    vector<int> digit ;
    rep(i,n) digit.push_back(to_string(a)[i] - '0') ;
    dp[0][0][0] = 1 ;
    rep(i,n){
        // Leading 0 がある場合
        { 
            // Leading 0 では上から1桁目以降に処理を行う
            if(i > 0) rrep(x,1,10) {
                if(x == 4) dp[i+1][1][1]++ ;
                else if(x == 6) dp[i+1][1][1]++ ;
                else if(x == 8) dp[i+1][1][2]++ ;
                else if(x == 9) dp[i+1][1][1]++ ;
                else dp[i+1][1][0]++ ;
            }
        }
        // smaller が 0 の場合の処理
        {
            int xxxx , oooo ;
            // 次の桁を見る
            rep(x,101) {
                if(digit[i] == 0) dp[i+1][0][x+1] += dp[i][0][x] ;
                else if(digit[i] == 4) dp[i+1][0][x+1] += dp[i][0][x] ;
                else if(digit[i] == 6) dp[i+1][0][x+1] += dp[i][0][x] ;
                else if(digit[i] == 8) dp[i+1][0][x+2] += dp[i][0][x] ;
                else if(digit[i] == 9) dp[i+1][0][x+1] += dp[i][0][x] ;
                else dp[i+1][0][x] += dp[i][0][x] ;
            }

            // Leading 0 では上から0桁目に関しては次の桁の値は0としては行けない(03543のような値を作ってしまうため)
            // 1桁目以降は次の桁の値の候補として0~9までどれを入れても良い(1桁目が決まっていれば103843のようになる)
            int fir = 0 ;
            if(i == 0) fir = 1 ;
            rrep(x,fir,digit[i]) rep(y,101) {
                if(x == 0) dp[i+1][1][y+1] += dp[i][0][y] ;
                else if(x == 4) dp[i+1][1][y+1] += dp[i][0][y] ;
                else if(x == 6) dp[i+1][1][y+1] += dp[i][0][y] ;
                else if(x == 8) dp[i+1][1][y+2] += dp[i][0][y] ;
                else if(x == 9) dp[i+1][1][y+1] += dp[i][0][y] ;
                else dp[i+1][1][y] += dp[i][0][y] ;
            }
        }
        // smaller が 1 の場合の処理
        {
            int xxxx, oooo ;
            // smaller == trueの状態から遷移する
            // 自由に遷移して良いので問題によっては対称性を利用することも可能
            rep(x,10) rep(y,101){
                if(x == 0) dp[i+1][1][y+1] += dp[i][1][y] ;
                else if(x == 4) dp[i+1][1][y+1] += dp[i][1][y] ;
                else if(x == 6) dp[i+1][1][y+1] += dp[i][1][y] ;
                else if(x == 8) dp[i+1][1][y+2] += dp[i][1][y] ;
                else if(x == 9) dp[i+1][1][y+1] += dp[i][1][y] ;
                else dp[i+1][1][y] += dp[i][1][y] ;
            }
        }
    }
    ll res = 0 ;
    rep(i,101){
        res += dp[n][1][i] * i + dp[n][0][i] * i ;
    }
    return res ;
}

int main(){
    fast_input_output
    cin >> k ;
    ll lef = 0 , rig = 1e18 + 1 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        ll x = f(mid) ;
        if(x < k) lef = mid ;
        else rig = mid ;
    }
    if(f(rig) != k) cout << -1 << endl ;
    else cout << rig << endl ;
}