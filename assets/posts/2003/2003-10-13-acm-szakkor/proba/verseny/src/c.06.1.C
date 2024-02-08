#include <iostream>

using namespace std;

void main() {
	int n, h, ch, e, maxe=0;
	int f[25], df[25], tf[25], it[25], mit[25];
	int i, j, k, max;
	cin >> n;
	while (n!=0) {
		cin >> h;
		h*=12;
		for (i=0; i<n; ++i) {
			cin >> f[i];
		}
		for (i=0; i<n; ++i) {
			cin >> df[i];
		}
		for (i=0; i<n-1; ++i) {
			cin >> tf[i];
		}
		for (i=0; i<n; ++i) {
			ch = 0;
			for (j=0; j<i+1; ++j) {
				it[j] = 0;
			}
			for (j=0; j<i; ++j) {
				ch += tf[j];
			}
			e = 0;
		  for (; ch<h; ++ch) {
				max = 0;
				for (k=1; k<i+1; ++k) {
					if (f[max]-it[max]*df[max]<f[k]-it[k]*df[k]) {
						max = k;
					}
				}
				if (f[max]-it[max]*df[max]>0) {
					e += f[max]-it[max]*df[max];
					++it[max];
				}
				else {
					++it[0];
				}
			}
			
			if (e>maxe) {
				maxe = e;
				for (k=0; k<n; ++k) {
					mit[k] = k<i+1 ? it[k] : 0;
				}
			}
		}
		for (i=0; i<n; ++i) {
			cout << 5*mit[i] << (i<n-1 ? ", " : "\n");
		}
		cout << "Number of fish expected: " << maxe << endl;
		cin >> n;
	}
}
