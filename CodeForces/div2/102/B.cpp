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
    bool neg = false;
    int s = 0;
    if(S[0] == '-') neg = true, s++;
    string R = "", F = "";
    bool f = false;
    int cnt = 0;
    rrep(i,s,S.size()){
        if(f) cnt++;
        if(cnt > 2) continue;
        if(S[i] == '.') {
            f = true;
            continue;
        }
        if(f) F += S[i];
        else R += S[i];
    }
    reverse(all(R));
    string res = "";
    int sum = 0;
    rep(i,R.size()){
        if(sum > 0 && sum % 3 == 0) res += ',';
        res += R[i];
        sum++;
    }
    res += '$';
    reverse(all(res));
    res += '.';
    rep(i,F.size()) res += F[i];
    if(F.size() <= 1) res += '0';
    if(F.size() <= 0) res += '0';
    if(neg) res = '(' + res + ')';
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}