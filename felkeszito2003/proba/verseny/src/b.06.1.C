#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <cstdio>

using namespace std;


void main()
{
  string s;
	cout.precision(2);
  while (getline(cin, s) && s!="END") {
  	int i, cnt = 0;
  	map<char, unsigned> m;
  	for (i=0; i<s.length(); ++i) {
			++m[s[i]];
  	}
		multiset<unsigned> ms;
		map<char, unsigned>::iterator mit;
		for (mit=m.begin(); mit!=m.end(); ++mit) {
			ms.insert(mit->second);
		}
		while (ms.size()>=2) {
			int w;
			w = *(ms.begin());
			ms.erase(ms.begin());
			w += *(ms.begin());
			ms.erase(ms.begin());
			cnt += w;
			ms.insert(w);
		}
		printf("%d %d %.1lf\n", s.length() * 8, cnt, s.length()*8.0/cnt);
	
//cout << s.length()*8 << ' ' << cnt << ' ';
	//zut << s.length()*8.0/(cnt) << endl;
	}
}
