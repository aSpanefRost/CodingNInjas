// Angry Children
// Send Feedback
// Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
// Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
// unfairness=0;
// for(i=0;i<n;i++)
// for(j=0;j<n;j++)
//     unfairness+=abs(xi-xj)
// abs(x) denotes absolute value of x.
// Input Format
// The first line contains an integer N.
// The second line contains an integer K.
// N lines follow each integer containing the candy in the ith packet.
// Output Format
// A single integer which will be minimum unfairness.
// Constraints
// 2<=N<=10^5

// 2<=K<=N

// 0<= number of candies in each packet <=10^9
// Sample Input
// 7
// 3
// 10
// 100
// 300
// 200
// 1000
// 20
// 30
// Sample Output
// 40
// Explanation
// Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <numeric>
#include <complex>
#include <string>
#include <ctime>
#include <queue>

/*
// C++ 11 stuff

#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <array>

#define tup(name, pos) get<(pos)>(name)
#define A1(type, size) array <type, size>
#define A2(type, s1, s2) A1(A1(type, s2), s1)
#define A3(type, s1, s2, s3) A1(A2(type, s2, s3), s1)

//*/


using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pnt;


#define FI(i,a) for (int i=0; i<(a); ++i)
#define FOR(i,s,e) for (int i=(s); i<(e); ++i)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define V(t) vector < t >
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):(-(a)))
#define ALL(a) a.begin(),a.end()

#define dout(a) cerr << a << endl
#define sout(a) cerr << a << "  "
#define lbl cerr << "debug_label" << endl;

const double pi = 3.14159265358979323846264338327950288419716939937511;
const double eps = 1e-9;

//*
char ch_ch_ch[1<<20];
inline string gs() {scanf("%s",ch_ch_ch); return string(ch_ch_ch);}
inline string gl() {gets(ch_ch_ch); return string(ch_ch_ch);}
inline int gi() {int x; scanf("%d",&x); return x;}
//*/

const int inf = 1000000000;

// code starts here

int n;
V(int) a;
V(LL) sum;

void solution() {


    n = gi();
    int K = gi();
    FI(i,n) a.pb(gi());
    sort(ALL(a));
    sum.resize(n);
    LL res = inf*1ll*inf;
    sum[0] = a[0];
    FOR(i,1,n) sum[i] = a[i] + sum[i-1];
    LL cur = 0;
    FOR(i,1,K) cur += a[i]*1ll*i - sum[i-1];
    res = cur;
    if (K > 1) FOR(i,K,n) {
        cur += (K-1)*1ll*a[i] - (sum[i-1] - sum[i-K]);
        cur -= -(K-1)*1ll*a[i-K]  + (sum[i-1] - sum[i-K]);
        res = min(res,cur);
    }

    cout << res << endl;


}


// code ends here

int main(int argc, char** argv) {

#ifdef IGEL_ACM
    freopen("in.txt","r",stdin);
    //freopen("out.txt", "w", stdout);
    clock_t beg_time = clock();
#else
    //freopen(argv[1],"r",stdin);
    //freopen("painting.in", "r", stdin);
    //freopen("painting.out", "w", stdout);

#endif

    solution();

#ifdef IGEL_ACM
    fprintf(stderr,"*** Time: %.3lf ***\n",1.0*(clock()-beg_time)/CLOCKS_PER_SEC);
#endif

    return 0;
}
