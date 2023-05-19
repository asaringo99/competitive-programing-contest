#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)


int n ;

double EPS = 1e-10 ;
// 二次元ベクトル構造体
struct vec
{
    double x , y ;
    vec(double x , double y) : x(x) , y(y) {}
    vec operator + (vec v) { return vec(add(x , v.x),add(y , v.y)) ;}
    vec operator - (vec v) { return vec(add(x ,-v.x),add(y ,-v.y)) ;}
    vec operator * (double d) { return vec(x * d , y * d) ;}
    double dot (vec v) { return add(x * v.x , y * v.y) ;}
    double det (vec v) { return add(x * v.y ,-y * v.x) ;}
    
    double add(double a , double b){
        if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0 ;
        return a + b ;
    }
};


int main(){
    cin >> n ;
    vec p(n,n+4) ;
    cout << p.x << " " << p.y << endl ;
}