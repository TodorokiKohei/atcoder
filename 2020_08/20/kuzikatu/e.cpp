#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a *= 100;
    b *= 100;
    set<int> wat, sug;
    for(int i = 0; i <= 30; i++){
        for(int j = 0; j <= 30; j++){
            int sum = a * i + b * j;
            if (sum != 0 && sum <= f) wat.insert(sum);
            else break;
        }
    }
    for(int i = 0; i <= 3000; i++){
        for(int j = 0; j <= 3000; j++){
            int sum = c * i + d * j;
            if (sum <= f) sug.insert(sum);
        }
    }

    double con = -1;
    int ansWat = 0, ansSug = 0;
    for(int w: wat){
        for(int s: sug){
            if (w + s > f) continue;
            if (s <= e * (w/100)){
                double c = ((double)100 * s) / (w + s);
                if (chmax(con, c)){
                    ansWat = w;
                    ansSug = s;
                }
            }
        }
    }
    printf("%d %d\n", ansWat+ansSug, ansSug);
    return 0;
}