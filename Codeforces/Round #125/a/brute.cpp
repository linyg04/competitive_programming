// Andrés Mejía
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

////////////// Prewritten code follows. Look down for solution. ////////////////
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
////////////////////////// Solution starts below. //////////////////////////////

int K, B, N, T;

bool works(int m) {
    if (m >= N) return true;
    
    long long power = 1;
    long long sum = 0;
    
    for (int i = 0; i < N - m; ++i) {
        sum += power * B;
        if (sum > T) return false;
        power *= K;
    }
    sum += power;
    if (sum > T) return false;
    assert(T >= sum);
    return true;
}

int main(){
    cin >> K >> B >> N >> T;
 
    long long z = 1;
    for (int i = 0; i < N; ++i) {
        z = K * z + B;
    }
    D(z);
    
    long long z2 = T;
    for (int i = 0; ; ++i) {
        if (z2 >= z) {
            cout << i << endl;
            break;
        }
        z2 = K * z2 + B;
    }
    D(z2);
    return 0;
}