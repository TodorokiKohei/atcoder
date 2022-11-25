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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll sumA = 0, sumB = 0, bCnt = 0, aCnt = 0;
    rep(i,n){
        sumA += a[i];
        sumB += b[i];
        if (a[i] > b[i]) bCnt += a[i] - b[i];
        else if (a[i] < b[i]) aCnt += ceil(((double)b[i]- a[i]) / 2);
    } 
    printf("%lld\n%lld\n%lld\n%lld\n%lld\n", sumA, sumB, sumB - sumA,bCnt, aCnt);
    if (sumA > sumB){
        cout << "No" << endl;
    }
    else if (sumB - sumA >= bCnt && sumB - sumA >= aCnt){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}