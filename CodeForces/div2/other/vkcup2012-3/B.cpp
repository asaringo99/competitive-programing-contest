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
    if(S[0] == '.'){
        cout << "NO" << endl;
        return;
    }
    n = S.size();
    int cnt = 0;
    bool ok = false;
    vector<string> res;
    string T = "";
    rep(i,n){
        char u = S[i];
        if(i < n - 1 && S[i] == '.' && S[i+1] == '.'){
            cout << "NO" << endl;
            return;
        }
        if(i < n - 1 && S[i+1] == '.' && ok){
            res.push_back(T);
            cnt = 0;
            T = "";
            T += u;
            ok = false;
            continue;
        }
        if(i == n - 1 && !ok){
            cout << "NO" << endl;
            return;
        }
        if(u == '.'){
            if(i < n - 2 && S[i+2] == '.'){
                cout << "NO" << endl;
                return;
            }
            T += u;
            ok = true;
            cnt = 0;
            continue;
        }
        if(ok){
            T += u;
            cnt++;
            if(cnt == 3){
                res.push_back(T);
                cnt = 0;
                T = "";
                ok = false;
                continue;
            }
        }
        else{
            T += u;
            cnt++;
            if(cnt > 8){
                cout << "NO" << endl;
                return;
            }
        }
    }
    if(T.size() != 0) res.push_back(T);
    cout << "YES" << endl ;
    for(auto s: res) cout << s << endl;
}

int main(){
    fast_io
    solve();
}