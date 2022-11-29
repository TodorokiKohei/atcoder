#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    ll a, b;
    cin >> a >> b;
    if (a <= b) {
        printf("%.10f\n", double(a));
        return 0;
    }
    ll mx = floor(double(a) / double(b));
    ll left = 0, right = mx;
    while(right - left > 2) {
        ll line1 = left + (right - left) / 3;
        ll line2 = right - (right - left) / 3;
        double t1 = (a / sqrt(left+1)) + left * b;
        double t2 = (a / sqrt(line1+1)) + line1 * b;
        double t3 = (a / sqrt(line2+1)) + line2 * b;
        double t4 = (a / sqrt(right+1)) + right * b;
        if (t2 < t3 && t3 < t4) right = line2;
        else if (t1 > t2 && t2 > t3) left = line1;
        else {
            left = line1;
            right = line2;
        }
    }
    double ans = min((a / sqrt(left+1)) + left*b, a / sqrt(right+1) + right*b);
    ans = min(ans, (a / sqrt(left+2)) + (left+1)*b);
    printf("%.10f\n", ans);
    return 0;
}