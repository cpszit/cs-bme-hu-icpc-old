#include <iostream>
#include <cstring>

using namespace std;


void main() {
	int cnt, cntit;
	cin >> cnt;
	for (cntit=0; cntit<cnt; ++cntit) {
		int f[1000], g[1000], h[1000];
		int df, dg, dh;
		int i, j;
    bool b;
		cin >> df;
		for (i=0; i<df; ++i) {
			cin >> f[df-i-1];
		}
		cin >> dg;
		for (i=0; i<dg; ++i) {
			cin >> g[dg-i-1];
		}
		cin >> dh;
		for (i=0; i<dh; ++i) {
			cin >> h[dh-i-1];
		}
    int r[2000];
    memset(r, 0, sizeof(r));
    for (i=0; i<df; ++i) {
      if (f[i]!=0) {
        for (j=0; j<dg; ++j) {
          r[i+j] += f[i]*g[j];
          if (r[i+j]==2) {
            r[i+j] = 0;
          } 
        }
      }
    }
    for (i=df+dg-1; i>=dh; --i) {
      if (r[i-1]!=0) {
        for (j=0; j<dh; ++j) {
          r[i-dh+j]+=h[j];
          if (r[i-dh+j]==2) {
            r[i-dh+j] = 0;
          }
        }
      }
    }
    b = false;
    for (i=dh; i>0; --i) {
      if (r[i-1]==1 && !b) {
        b = true;
        cout << i << ' ' << r[i-1];
      }
      else if (b) {
        cout << ' ' << r[i-1];
      }
    }
    if (!b) {
      cout << 0;
    }
    cout << endl;
	}
}