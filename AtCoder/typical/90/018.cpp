#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const double pi = 3.1415926535 ;

int q ;

int main(){
    double t , l , x , y ;
    cin >> t >> l >> x >> y >> q ;
    rep(i,q){
        double e ;
        cin >> e ;
        double theta = e / t * 2 * pi ;
        double u = cos(theta + pi / 2) * l / 2 , v = sin(theta + (double)3 * pi / 2) * l / 2 + l / 2 ;
        double dx = x * x , dy = (u - y) * (u - y) ;
        double dist = sqrt(dx + dy) ;
        cout << setprecision(15) << atan2(v,dist) * 360 / 2 / pi << endl ;
    }
}