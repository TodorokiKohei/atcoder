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
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    rep(i,n){
        int a;
        cin >> a;
        pq.push(a);
    }
    int i = 0;
    double last;
    while(i < k){
        int x = pq.top(); pq.pop();
        if (i != k-1){
            if (x % 2 == 0){
                pq.push(x/2.0);
                pq.push(x/2.0);
            }else{
                pq.push(x/2.0);
                pq.push((x/2.0)+1.0);
            }
        }else{
            last = x / 2.0;
        }
        i++;
    }
    printf("%d\n", max(pq.top(), (int)ceil(last)));
    return 0;
}