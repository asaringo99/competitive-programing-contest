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
    int n;
    string S;
    cin >> S;
    n = S.size();
    vector<int> A(26,0);
    for(char u : S) A[u-'a']++;
    string X = "", Y = "";
    bool ok = false;
    rep(i,26){
        if(ok) break;
        while(A[i] > 0){
            if(A[i] == 1) break;;
            X += (char)('a' + i);
            Y += (char)('a' + i);
            A[i] -= 2;
        }
    }
    int o = 1;
    rep(i,26){
        if(A[i] == 1){
            if(o) {
                X += (char)('a' + i);
                o ^= 1;
            }
            else{
                Y += (char)('a' + i);
                o ^= 1;
            }
        }
    }
    reverse(all(Y));
    X += Y;
    cout << X << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}