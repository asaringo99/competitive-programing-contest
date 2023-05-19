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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

struct Point {
    ll x, y;
    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
ll cross(const Point &O, const Point &A, const Point &B){
    return (A.x - O.x) * (ll)(B.y - O.y) - (A.y - O.y) * (ll)(B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P){
    int n = P.size(), k = 0;
    vector<Point> H(2*n);

    // Sort points lexicographically
    sort(P.begin(), P.end());

    // Build lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}

int n, m;
ll C[202020];

int main(){
    // fast_io
    cin >> n >> m;
    vector<ll> B(n), S(n,0);
    rep(i,n) cin >> B[i];
    rep(i,m) cin >> C[i];
    vector<Point> vec ;
    sort(all(B));
    rep(i,B.size()){
        if(i > 0 && B[i] == B[i-1]) continue;
        vec.push_back(Point{i,B[i]*(n-i)});
    }
    vector<pair<ll,ll>> V;
    for(Point p: convex_hull(vec)) V.push_back({p.x, p.y});
    // for(Point p: convex_hull(vec)) cout << p.x << " " << p.y << endl;
    sort(all(V));
    vector<pair<ll,int>> K;
    rep(i,V.size()){
        auto [id, val] = V[i];
        if(i == V.size() - 1) {
            K.push_back({0,id});
            break;
        }
        auto [nid, nval] = V[i+1];
        if(nval < val) {
            K.push_back({0,id});
            break;
        }
        if(id == nid) continue;
        ll x = (nval - val) % (nid - id) == 0 ? (nval - val) / (nid - id) : (nval - val) / (nid - id) + 1;
        K.push_back({x,id});
    }
    sort(all(K));
    rep(i,m){
        ll c = C[i];
        auto it = upper_bound(K.begin(), K.end(), pair<ll,int>(c, n));
        it--;
        auto [val, id] = *it;
        cout << (B[id] + c) * (n - id) << " ";
    }
    cout << endl;
}