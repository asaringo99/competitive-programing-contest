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

int main(){
    fast_io
    cin >> n;
    multiset<int> st;
    rep(i,n){
        int a;
        cin >> a;
        st.insert(a);
    }
    int a = -1, b = -1;
    rrep(i,1,n+1){
        if(st.count(i) == 2) a = i;
        if(st.count(i) == 0) b = i;
    }
    if(a == -1 && b == -1){
        cout << "Correct" << endl;
        return 0;
    }
    cout << a << " " << b << endl;
}