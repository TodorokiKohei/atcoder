#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define  all(x) (x).begin(),(x).end()
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    set<int> st;
    rep(i, 1<<n){
        vector<int> use(n);
        rep(j,n) if (i>>j & 1) use[j] = 1;
        int sum = 0;
        rep(j,n) if (use[j]) sum+=a[j];
        st.insert(sum);
    }

    int q;
    cin >> q;
    rep(i,q){
        int m;
        cin >> m;
        if (st.find(m) == st.end()) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}