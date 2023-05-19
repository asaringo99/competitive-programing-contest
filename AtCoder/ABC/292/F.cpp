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

ld EPS = 1e-15 ;
const ld PI = 3.14159265358979 ;
const ld theta120 = 2 * PI / 3;
const ld theta240 = 4 * PI / 3;

// a > 0 : +1
// a < 0 : -1
// a = 0 :  0
int sgn(ld a){
    if(a < -EPS) return -1 ;
    if(a > EPS)  return 1 ;
    return 0 ;
}
// ld型の足し算は怖い
ld add(ld a , ld b){
    if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0 ;
    return a + b ;
}
// ld型の == は怖い
inline bool equal(ld a , ld b){
    return fabs(a - b) < EPS ;
}

// 二次元ベクトル構造体
struct Point{
    ld x , y ;
    Point(ld x , ld y) : x(x) , y(y) {}
    Point operator + (Point v) { return Point(add(x , v.x),add(y , v.y)) ;}
    Point operator - (Point v) { return Point(add(x ,-v.x),add(y ,-v.y)) ;}
    Point operator * (ld d) { return Point(x * d , y * d) ;}
    Point operator / (ld d) { return Point(x / d , y / d) ;}
    Point& operator += (Point v) { x = add(x , v.x) ; y = add(y , v.y) ; return *this ; }
    Point& operator -= (Point v) { x = add(x ,-v.x) ; y = add(y ,-v.y) ; return *this ; }
    Point& operator *= (ld d) { x *= d ; y *= d ; return *this ; }
    Point& operator /= (ld d) { x /= d ; y /= d ; return *this ; }
    bool operator == (Point v) { return equal(x,v.x) && equal(y,v.y) ; }
    bool operator != (Point v) { return !equal(x,v.x) || !equal(y,v.y) ; }
    bool operator < (Point v){
        if(sgn(x - v.x) != 0) return sgn(x - v.x) < 0 ;
        else return sgn(y - v.y) < 0 ;
    }
    // 内積演算
    ld dot (Point v) { return add(x * v.x , y * v.y) ;}
    // 外積演算
    ld cross (Point v) { return add(x * v.y ,-y * v.x) ;}
    // 回転
    Point rotate(ld theta){ return Point(add(x * cos(theta) , -y * sin(theta)) , add(x * sin(theta) , y * cos(theta))) ; }
    // ベクトルの長さ
    ld length(){ return sqrt(add(x * x , y * y)) ; }
    // ベクトルの長さの二乗
    ld lengthSquare(){ return add(x * x , y * y) ; }
    // ベクトルの正規化
    Point normalized(){ return Point(x / length() , y / length()) ; }
    // ベクトルとベクトルの距離
    ld distanceFrom(Point vec){ return sqrt(add((vec.x - x) * (vec.x - x) , (vec.y - y) * (vec.y - y))) ; }
    // 点かどうか
    bool isZero(){ return x == 0.0 && y == 0.0 ; }
    // 偏角演算
    ld argument (Point v){
        Point u(x,y) ;
        if(u.cross(v) > 0) return acos(u.dot(v) / u.length() / v.length()) ;
        else return 2 * PI - acos(u.dot(v) / u.length() / v.length()) ;
    }
    // 出力
    void console(){ cout << setprecision(15) << x << " " << setprecision(15) << y << endl ; }
};

int n ;
using PP = pair<ld,P> ;

ll a, b;

bool f(ld v){
    ld x = a, y = v;
    Point p(x, y);
    Point q = p + p.rotate(theta120);
    if(0 <= q.x && q.x <= a && 0 <= q.y && q.y <= b) return true;
    return false;
    // Point r = q + p.rotate(theta240);
}

int main(){
    fast_io
    cin >> a >> b;
    if(a > b) swap(a,b);
    ld res = a;
    int cnt = 0;
    ld lef = 0, rig = b;
    while(cnt < 10000){
        ld mid = (lef + rig) / 2;
        if(f(mid)) lef = mid;
        else rig = mid;
        cnt++;
    }
    ld ans = sqrt(a * a + lef * lef);
    chmax(ans,res);
    cout << fixed << setprecision(25) << ans << endl;
}