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

const int mod = 998244353 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

string S ;
int n , m ;
int C[10] ;
ll dp[10101][2][2020] ; // i桁目にsmallerでkな値
ll ep[10101][2][2020] ;

int main(){
    fast_input_output
    cin >> S >> m ;
    n = S.size() ;
    rep(i,m) cin >> C[i] ;

    vector<int> digit ; // 各桁の値
    rep(i,n){
        // 各桁の値を入れていく
        digit.push_back(S[i] - '0') ;
    }

    // 初期化を忘れない
    dp[0][0][0] = 1 ;
    int T = 0 ;
    rep(i,n){
        // Leading 0 がある場合
        { 
            // Leading 0 では上から1桁目以降に処理を行う
            if(i > 0) {
                rrep(x,1,10) {
                    dp[i+1][1][1 << x] += 1 ;
                    ep[i+1][1][1 << x] += x ;
                }
            }
        }
        // smaller が 0 の場合の処理
        {
            // 次の桁を見る
            (dp[i+1][0][T|1<<digit[i]] += dp[i][0][T]) %= mod ;
            (ep[i+1][0][T|1<<digit[i]] += ep[i][0][T] * 10 + digit[i]) %= mod ;

            // Leading 0 では上から0桁目に関しては次の桁の値は0としては行けない(03543のような値を作ってしまうため)
            // 1桁目以降は次の桁の値の候補として0~9までどれを入れても良い(1桁目が決まっていれば103843のようになる)
            int fir = 0 ;
            if(i == 0) fir = 1 ;
            rrep(x,fir,digit[i]){
                (dp[i+1][1][T|1<<x] += dp[i][0][T]) %= mod ;
                (ep[i+1][1][T|1<<x] += ep[i][0][T] * 10 + x) %= mod ;
            }
            T |= 1 << digit[i] ;
        }
        // smaller が 1 の場合の処理
        {
            // smaller == trueの状態から遷移する
            // 自由に遷移して良いので問題によっては対称性を利用することも可能
            rrep(G,1,1<<10) {
                rep(j,10) {
                    (dp[i+1][1][G|1<<j] += dp[i][1][G]) %= mod ;
                    (ep[i+1][1][G|1<<j] += ep[i][1][G] * 10 + j * dp[i][1][G]) %= mod ;
                }
            }
        }
    }
    ll res = 0 ;
    rrep(G,1,1<<10){
        bool ok = true ;
        rep(i,m) if(!(G >> C[i] & 1)) ok = false ;
        if(ok) {
            (res += ep[n][0][G] + ep[n][1][G]) %= mod ;
        }
    }
    cout << res << endl ;
}