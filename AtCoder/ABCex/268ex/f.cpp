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

struct Fraction{
    ll a , b; // a / b を表す
    Fraction(int a_, int b_): a(a_), b(b_) {}

    bool operator< (const Fraction& x) const {
        return a * x.b > b * x.a ;
    }
    bool operator> (const Fraction& x) const {
        return b * x.a < a * x.b ;
    }
};

int n;

int main(){
    fast_io
    cin >> n;
    vector<pair<Fraction,int>> V;
    vector<string> S;
    rep(i,n){
        string s;
        cin >>s;
        S.push_back(s);
        ll val = 0, c = 0;
        for(char u : s){
            if(u == 'X') c++;
            else val += u - '0';
        }
        V.push_back({Fraction(c,val),i});
    }
    sort(all(V));
    string T = "";
    rep(i,n){
        auto[val, id] = V[i];
        T += S[id];
    }
    ll res = 0, cnt = 0;
    for(char u : T){
        if(u == 'X') cnt++;
        else{
            res += cnt * (u - '0');
        }
    }
    cout << res << endl;
}