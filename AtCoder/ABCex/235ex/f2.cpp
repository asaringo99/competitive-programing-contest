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

const int mod = 998244353 ;

string S ; // 入力されるめちゃでかい値
int k ;
ll dp[10101][2][1<<10] ; // i桁目にsmallerでkな値
ll ep[10101][2][1<<10] ; // i桁目にsmallerでkな値
bool C[10];

//---------------------------------------------------------------------------//
//                                 debug                                     //
//---------------------------------------------------------------------------//
// cout << "dp[" << i+1 << "][0][" << t << "] = " << dp[i+1][0][t] << endl ; //
// cout << "dp[" << i+1 << "][1][" << t << "] = " << dp[i+1][1][t] << endl ; //
//---------------------------------------------------------------------------//

int main(){
    cin >> S >> k ;
    int n = S.size() ;

    vector<int> digit ; // 各桁の値
    rep(i,n){
        // 各桁の値を入れていく
        digit.push_back(S[i] - '0') ;
    }

    rep(i,k){
        int c;
        cin >> c;
        C[c] = true;
    }

    // 初期化を忘れない
    dp[0][0][0] = 0 ;
    ep[0][0][0] = 1 ;
    int T = 0;
    rep(i,n){
        // Leading 0 がある場合
        { 
            // Leading 0 では上から1桁目以降に処理を行う
            if(i > 0) rrep(j,1,10) (dp[i+1][1][1<<j] += j) %= mod ;
            if(i > 0) rrep(j,1,10) (ep[i+1][1][1<<j] += 1) %= mod ;
        }
        // smaller が 0 の場合の処理
        {
            int c = digit[i];
            // 次の桁を見る
            (dp[i+1][0][T|1<<c] += dp[i][0][T] * 10 % mod + c) %= mod ;
            (ep[i+1][0][T|1<<c] += ep[i][0][T]) %= mod ;

            // Leading 0 では上から0桁目に関しては次の桁の値は0としては行けない(03543のような値を作ってしまうため)
            // 1桁目以降は次の桁の値の候補として0~9までどれを入れても良い(1桁目が決まっていれば103843のようになる)
            int fir = 0 ;
            if(i == 0) fir = 1 ;
            rrep(x,fir,digit[i]){
                (dp[i+1][1][T|1<<x] += dp[i][0][T] * 10 % mod + x) %= mod ;
                (ep[i+1][1][T|1<<x] += ep[i][0][T]) %= mod ;
            }

            T |= 1 << c;
        }
        // smaller が 1 の場合の処理
        {
            // smaller == trueの状態から遷移する
            // 自由に遷移して良いので問題によっては対称性を利用することも可能
            rep(S,1<<10) rep(j,10){
                if(ep[i][1][S] > 0) {
                    (dp[i+1][1][S|1<<j] += dp[i][1][S] * 10 % mod + j * ep[i][1][S] % mod) %= mod ;
                    (ep[i+1][1][S|1<<j] += ep[i][1][S]) %= mod ;
                }
            }
        }
    }

    ll res = 0;
    rep(S,1<<10){
        bool ok = true;
        rep(i,10) if(C[i]) if(!(S >> i & 1)) ok = false;
        if(ok) {
            // if(dp[n][0][S] + dp[n][1][S] > 0) cout << dp[n][0][S] << " " << dp[n][1][S] << endl;
            (res += dp[n][0][S] + dp[n][1][S]) %= mod;
        }
    }
    cout << res << endl ;
}