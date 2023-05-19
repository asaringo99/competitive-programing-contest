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

ll n, m;
ld s ;
ll A[5050], S[5050];

int main(){
    fast_input_output
    cin >> n >> m >> s ;
    rep(i,n) cin >> A[i], S[i+1] = S[i] + A[i];
    ld res = 0;
    rrep(i,1,n+1){
        ld sum = 0;
        if(s > m * i){
            sum = (ld)(S[n] - S[n-i]) * m;
            ll t = s - i * m;
            rrep(j,i+1,n){
                int k = j - i;
                if(t > m * k) {
                    if(j != n - 1){
                        ld val = sum+m*(S[n-i]-S[n-j])+min(t-k*m,m)*A[n-j-1];
                        chmax(res,val);
                    }
                }
                else{
                    chmax(res,sum+(ld)(S[n-i]-S[n-j])*(ld)t/k);
                }
            }
        }
        else{
            sum = (ld)(S[n] - S[n-i]) * s / i;
            chmax(res,sum);
        }
    }
    cout << fixed << setprecision(25) << res << endl;
}