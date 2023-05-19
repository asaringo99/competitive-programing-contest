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

string S;

int main(){
    fast_io
    cin >> S;
    int n = S.size();
    int cnt = 0;
    string s = "";
    vector<string> T;
    rep(i,n){
        s += S[i];
        int k = S[i] - 'A';
        if(0 <= k && k < 26){
            cnt++;
            s.pop_back();
            s += (char)('a' + (S[i] - 'A'));
            if(cnt % 2 == 0){
                T.push_back(s);
                s = "";
            }
        }
    }
    sort(all(T));
    rep(i,T.size()) {
        rep(j, T[i].size()){
            if(j == 0) T[i][j] = (char)('A' + (T[i][j] - 'a'));
            if(j == T[i].size()-1) T[i][j] = (char)('A' + (T[i][j] - 'a'));
        }
    }
    for(string U : T) cout << U; cout << endl;
}