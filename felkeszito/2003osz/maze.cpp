#include <iostream>
#include <hash_map>
#include <vector>
#include <queue>
#include <stdio.h>
#include <asm/types.h>
using namespace std;

typedef __u64 myKey;

class myData
{
public:
	bool visited;
	vector<myKey> edges;
	myData() { visited=false; }
	myData(const myData& o) {visited=o.visited;edges=o.edges;}
	myData& operator=(const myData& o) {
		visited=o.visited;edges=o.edges; 
		return (*this);	}
};
myKey makeKey(const char* s)
{
	myKey k=0;
	for (const char* c=s; *c; c++) if (*c!=' ') k=k*10+(*c-'0');
	return k;
}

int main(int argc, char* argv[])
{
	typedef hash_map<myKey, myData> HM;
	HM hm;
	HM::iterator hm_iterator;
	int maze_num=0;
	//for the sake of this example only. Standard input should be used
	FILE* f=fopen("maze.in", "rt");
	while (f) {

		hm.clear();

		int dimension;
		fscanf(f, "%d\n", &dimension);
		if (dimension==0) break;

		maze_num++;

		char buff[2000];
		myKey n1, n2;
		myKey startnode, endnode;

		bool first=true;
		fgets(buff, sizeof(buff), f);
		while (buff[0]!='-') {
			buff[dimension*2-1]=0;	//separate the coordinates
			buff[dimension*4-1]=0;	//properly terminate the string
			n1=makeKey(buff);
			n2=makeKey(&buff[dimension*2]);

			if (first) {
				startnode=n1;
				endnode=n2;
				first=false;
			} else {
				hm_iterator = hm.find(n1);

				if (hm_iterator!=hm.end()) {
					hm_iterator->second.edges.push_back(n2);
				} else {
					hm[n1].edges.push_back(n2);
				}

				hm_iterator = hm.find(n2);
				if (hm_iterator!=hm.end()) {
					hm_iterator->second.edges.push_back(n1);
				} else {
					hm[n2].edges.push_back(n1);
				}
			}
			fgets(buff, sizeof(buff), f);
		}

		if (!first) {
			queue<myKey> Q;
			Q.push(startnode);

			//Mark the start node visited
			hm_iterator = hm.find(startnode);
			if (hm_iterator!=hm.end()) {
				hm_iterator->second.visited=true;
			}

			bool travelled = false;
			while (!Q.empty() && !travelled) {
				myKey& s=Q.front();
				myData& node=hm[s];

				//visit all the edges
				for (unsigned int i=0; i<node.edges.size(); i++) {
					myKey target=node.edges[i];

					if (endnode==target) {
						travelled=true;
						break;
					}

					hm_iterator = hm.find(target);
					if (hm_iterator != hm.end()) {
						if (!hm_iterator->second.visited) {
							hm_iterator->second.visited=true;
							Q.push(target);
						}
					}
				}

				Q.pop();
			}

			printf("Maze #%d %s be travelled\n", maze_num,(travelled?"can":"cannot"));
		}
	}
	
	if (f) fclose(f);

	return 0;
}