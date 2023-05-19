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

ll n, L, R;

int main(){
    fast_io
    cin >> n >> L >> R;
    L--;
    vector<int> A(n);
    rep(i,n) A[i] = i + 1;
    ll p = 1;
    ll c = 0;
    while(L > c + n - p){
        c += n - p;
        p++;
    }
    ll q = p;
    while(c <= L){
        q++;
        c++;
    }
    while(c <= R && q <= n){
        swap(A[p-1], A[q-1]);
        q++;
        c++;
    }
    cout << c << endl;
    if(R - c <= 2 * n){
        while(c <= R){
            if(q == n + 1){
                p++;
                q = p + 1;
            }
            swap(A[p-1],A[q-1]);
            q++;
            c++;
        }
        rep(i,n) cout << A[i] << " "; cout << endl;
        return 0;
    }
    p++;
    q = p + 1;
    ll x = 1;
    ll d = 0;
    while(R > d + n - x){
        d += n - x;
        x++;
    }
    rep(i,n) cout << A[i] << " "; cout << endl;
    vector<int> B = A;
    cout << p << " " << x << endl;
    rep(i,n-p) {
        cout << p + i - 1 << " " << (n - (x-p+2) + i) % (n - p + 1) + p - 1 << endl;
        A[p+i-1] = B[(n - (x-p+2) + i) % (n - p + 1) + p - 1];
    }
    rep(i,n) cout << A[i] << " "; cout << endl;

    ll y = x;
    while(d <= R){
        y++;
        d++;
    }
}