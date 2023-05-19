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

int n;

ll dp[30][10][2];
ll C[20][20];
ll table[20][10][10];

int main(){
    fast_io
    cin >> n;
    vector<ll> A(n);
    vector<string> S(n);
    rep(i,n) cin >> A[i];
    rep(i,n) S[i] = to_string(A[i]);
    rep(i,n){
        string s = S[i];
        reverse(all(s));
        s += '0';
        rep(j,s.size()-1){
            int a = s[j] - '0';
            int b = s[j+1] - '0';
            table[j][a][b]++;
        }
        // s.pop_back();
        rep(j,s.size()){
            int a = s[j] - '0';
            C[j][a]++;
        }
    }

    ll res = 0;

    rep(i,10) rep(a,10) rep(b,10){
        ll c = C[0][i];
        ll t = table[0][a][b];
        // if(t > 0 && c > 0) cout << i << " " << a << " " << b << endl;
        res += c * t * ((i + a) % 10);
        if((i + a) > 9) dp[1][b][1] += c * t;
        else dp[1][b][0] += c * t;
    }
    // cout << res << endl;
    // cout << dp[1][9][1] << endl;
    // cout << dp[1][9][0] << endl;
    // cout << dp[1][5][0] << endl;
    // cout << dp[1][5][1] << endl;
    // cout << dp[1][2][0] << endl;
    // cout << dp[1][2][1] << endl;
    rrep(i,1,20){
        rep(x,10){
            ll c = C[i][x];
            rep(a,10){ //i桁目の値
                rep(b,10){ //次の値
                    ll t = table[i][a][b];

                    // 1
                    if(x + a + 1 > 9){
                        dp[i+1][b][1] += c * t * dp[i][a][1];
                        // if(c > 0 && t > 0 && dp[i][a][1] > 0) cout << i << " " << a << " " << c * t * ((x + a + 1) % 10) << " " << res << endl;
                        res += c * t * dp[i][a][1] * ((x + a + 1) % 10);
                        // if(c > 0 && t > 0 && dp[i][a][1] > 0) cout << i << " " << a << " " << c * t * ((x + a + 1) % 10) << " " << res << endl;
                    }
                    else{
                        dp[i+1][b][0] += c * t * dp[i][a][1];
                        res += c * t * dp[i][a][1] * ((x + a + 1) % 10);
                    }

                    // 0
                    if(x + a > 9){
                        dp[i+1][b][1] += c * t * dp[i][a][0];
                        res += c * t * dp[i][a][0] * ((x + a) % 10);
                        // if(dp[i][a][0] > 0) cout << dp[i][a][0] << endl;
                    }
                    else{
                        dp[i+1][b][0] += c * t * dp[i][a][0];
                        res += c * t * dp[i][a][0] * ((x + a) % 10);
                        // if(dp[i][a][0] > 0) cout << dp[i][a][0] << endl;
                    }
                }
            }
        }
    }
    cout << res << endl;
    // cout << dp[1][2][1] << endl;
}