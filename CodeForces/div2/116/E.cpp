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
    string S, T;
    cin >> S >> T;
    int n = S.size();
    int m = T.size();
    vector<int> A(26,0);
    rep(i,n) A[S[i]-'a']++;
    string res = "-1";
    int s = -1, g = -1;
    char f = '-';
    bool ok = true;
    rep(i,m){
        char c = T[i];
        rrep(x,c-'a'+1,26) {
            if(A[x] > 0){
                s = i;
                f = (char)('a' + x);
                break;
            }
        }
        if(A[c-'a'] == 0) {
            ok = false;
            break;
        }
        g = i + 1;
        A[c-'a']--;
    }
    if(ok && S.size() != T.size()){
        cout << T;
        rep(i,26) rep(j,A[i]) cout << (char)('a' + i);
        cout << endl;
        return;
    }
    if(s != -1){
        rrep(i,s,g) A[T[i]-'a']++;
        rep(i,s) cout << T[i];
        cout << f;
        A[f-'a']--;
        rep(i,26) rep(j,A[i]) cout << (char)('a' + i);
        cout << endl;
        return;
    }
    cout << -1 << endl;
}

int main(){
    fast_io
    solve();
}