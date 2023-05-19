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

int n, k;
string S;

int main(){
    // fast_io
    cin >> n >> k >> S;
    if(k == n){
        int res = 0;
        rrep(i,1,n){
            if(S[i] == 'X' && S[i-1] == 'X') res++;
        }
        cout << res << endl;
        return 0;
    }
    int sm = 0;
    rep(i,n){
        if(S[i] == 'X') sm++;
    }
    if(sm < k){
        k -= sm;
        vector<bool> B(n,false);
        vector<int> R;
        int res = n - 1;
        rep(i,n){
            if(B[i]) continue;
            if(S[i] == 'X') continue;
            int p = i;
            rrep(j,i,n){
                if(S[j] == 'X') break;
                B[j] = true;
                p = j;
            }
            if(i == 0 || p == n - 1){
                int c = p - i + 1;
                if(i == 0 && p == n - 1) c--;
                if(k - c < 0){
                    res -= k;
                    k = 0;
                }
                else{
                    res -= c;
                    k -= c;
                }
            }
            else R.push_back(p-i+1);
        }
        // for(int u : R) cout << u << " "; cout << endl;
        sort(all(R),greater<int>());
        for(int r : R){
            // cout << r << " " << k << " " << res << endl;
            if(k == 0) continue;
            if(k - r < 0){
                res -= k + 1;
                k = 0;
            }
            else{
                res -= r + 1;
                k -= r;
            }
        }
        chmax(res,0);
        cout << res << endl;
        return 0;
    }
    else{
        vector<bool> B(n,false);
        vector<int> R, D;
        int res = 0;
        rrep(i,1,n){
            if(S[i] == 'Y' && S[i-1] == 'Y') res++;
        }
        rep(i,n){
            if(B[i]) continue;
            if(S[i] == 'Y') continue;
            int p = i;
            rrep(j,i,n){
                if(S[j] == 'Y') break;
                B[j] = true;
                p = j;
            }
            if(i == 0 || p == n - 1){
                int c = p - i + 1;
                D.push_back(c);
            }
            else R.push_back(p-i+1);
        }
        sort(all(R));
        for(int r : R){
            if(k - r < 0){
                res += k;
                k = 0;
            }
            else{
                res += r + 1;
                k -= r;
            }
        }
        res += k;
        cout << res << endl;
        return 0;
    }
}