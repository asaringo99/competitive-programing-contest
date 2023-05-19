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

ll n, K;
ll A[303030], S[303030];

int main(){
    fast_input_output
    cin >> n >> K ;
    ll maxval = 0, minval = 1e18;
    rep(i,n){
        ll a;
        cin >> a;
        A[i] = a;
        chmax(maxval,a);
        chmin(minval,a);
    }
    ll cnt = 0;
    rep(i,n){
        cnt += maxval - A[i];
    }
    if(cnt <= K){
        K -= cnt;
        K /= n;
        cout << maxval + K << endl;
    }
    else{
        ll res = 1;
        sort(A,A+n);
        rep(i,n) S[i+1] = S[i] + A[i];
        rrep(i,2,maxval+1){
            ll x = i ;
            int j = 0;
            ll sum = 0;
            while(true){
                auto it = upper_bound(A,A+n,x);
                int k = it - A;
                sum += x * (k - j) - (S[k] - S[j]);
                j = k;
                x += i;
                if(it == A+n) break;
            }
            if(sum <= K) res = i;
        }
        cout << res << endl;
    }
}