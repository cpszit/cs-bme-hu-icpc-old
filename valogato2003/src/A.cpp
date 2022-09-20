#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define FLT_EPSILON 1.192092896e-07F 

#define DEBUGPRINT(x) 
//#define DEBUGPRINT(x) x

class Vector 
{
public:
  float x,y;
	Vector(float _x=0, float _y=0) : x(_x), y(_y)  {};
	//! cross product operator
	float operator%(const Vector& v) {
		return (x*v.y)-(v.x*y);
	}

	Vector operator-(const Vector& v) const {
		return Vector(x-v.x, y-v.y);
	}

	Vector operator+(const Vector& v) const {
		return Vector(x+v.x, y+v.y);
	}
	Vector operator*(float s) const { return Vector(x*s, y*s); }
};

class Line
{
public:
	Vector A,B;

	Line() {};
	Line(const Vector& A1, const Vector& B1) : A(A1), B(B1) {};

	void swap() {
		Vector t=A;
		A=B;
		B=t;
	}
	
	
	void print(const char* s) {
//		printf("%s(%d, %d, %d, %d)\n", s, A.x, A.y, B.x, B.y);
	}

	//! Calculates the distance of the intersection on the line AB
	//! If the return value is <0 or >1, then the intersection is invalid
	bool intersect(const Line& l, float& f) {
		const Vector& C=l.A;
		const Vector& D=l.B;
		
		float n1=(A.y-C.y)*(D.x-C.x) - (A.x-C.x)*(D.y-C.y);
		float n2=(A.y-C.y)*(B.x-A.x) - (A.x-C.x)*(B.y-A.y);
		float d=(B.x-A.x)*(D.y-C.y) - (B.y-A.y)*(D.x-C.x);

		f=n1/d;
		return (!(fabsf(d)<FLT_EPSILON || n2/d < 0.0f ));
	}
};

class Polygon : public vector<Vector> {
public:
	Polygon() {};

	void FinishPolygon() {
		const Vector& v=front();
		if (&v) push_back(v);	// repeat the last vertex to ease clipping
	}


public:
	void Dump(const char* phase) {
		printf("%s\n", phase);
		for (int i=0; i<size(); i++) {
			printf("(%.2f, %.2f)\t", at(i).x, at(i).y);
		}
		printf("\n");
	}

	void Clip(const Vector& A, const Vector& B, const Vector& C) {
		DEBUGPRINT(Dump("Clip #1"));
		FinishPolygon(); Line L1(A, B); Clip(L1); DEBUGPRINT(Dump("Clip #2"));
		FinishPolygon(); Line L2(B, C); Clip(L2); DEBUGPRINT(Dump("Clip #3"));
		FinishPolygon(); Line L3(C, A); Clip(L3); DEBUGPRINT(Dump("Clip #4"));
	}

	const Vector& at(int i) { return this->operator[](i); }


	void Clip(const Line& R) {
		if (size()==0) return;

		Polygon q;
		vector<bool> inner;
		Line L;
		Vector R1 = R.B-R.A;
		for (int i=0; i<size(); i++) {
			const Vector& p=this->operator[](i);
			float c=R1 % (p-R.A);	
			bool isInner = (c>=0.0f);
			inner.push_back(isInner);
		}

		for (int i=0; i<size()-1; i++) {
			bool doInters=false;
			if (inner[i]) {
				const Vector& p=this->operator[](i);
				q.push_back(p);
				if (!inner[i+1]) {
					doInters=true;
					L.A=at(i);
					L.B=at(i+1);
				}
			} else if (inner[i+1]) {
				doInters=true;
				L.A=at(i+1);
				L.B=at(i);
			}

			if (doInters) {
				float i1;
				L.intersect(R, i1);
				Vector clippedNewPoint=L.A+(L.B-L.A)*i1;
				q.push_back(clippedNewPoint);
			}
		}

		clear();
		(*this)=q;
	}

	
};

	
class Intervall
{
public:
	Intervall() { was_init=false; }
	
	float m_min, m_max;
	bool was_init;

	void AddPoint(float f) {
		if (was_init) { 
			m_min = MIN(m_min, f);
			m_max = MAX(m_max, f);
		} else {
			was_init = true;
			m_min = m_max = f;
		}
		//printf("AddPoint(%.4f), min=%.4f, max=%.4f\n",f, m_min, m_max);
	}

	void print(const char* s) {
		printf("%s(%.4f  %.4f)\n", s, m_min, m_max);
	}


	void Reset() { was_init=false; }

	bool operator<(const Intervall& o) const {
		return (m_min<o.m_min);
	}

	void Clip(float _min, float _max) {
		m_min = MAX(m_min, _min);
		m_max = MIN(m_max, _max);
	}


};

void main()
{
//	freopen("E:/home/benedek/Projects/ACM2003/LocalContest/road/road.in", "r", stdin);
	Line road;
	Line view;

	vector<Intervall> interv;
	bool fakeRoad;


	int num_cases=0;
	while(true) {
		num_cases++;
		interv.clear();

		int numPolys;
		scanf("%d", &numPolys);

		if (numPolys==0) break;

		scanf("%f %f", &view.A.x, &view.A.y);
		scanf("%f %f %f %f", &road.A.x, &road.A.y, &road.B.x, &road.B.y);

		float orientation = (road.A-view.A)%(road.B-view.A);
		if (orientation<0.0f) road.swap();

		fakeRoad=(road.A.x==road.B.x && road.A.y==road.B.y);
		
		for (int i=0; i<numPolys; i++) {
			int numVertices;
			scanf("%d", &numVertices);

			Intervall ii;
			Polygon p;
			p.clear();

			Vector v;

			for (int j=0; j<numVertices; j++) {
				scanf("%f %f", &v.x, &v.y);
				p.push_back(v);
			}

			//clipping view triangle
			float r_last, r;
			p.Clip(view.A, road.A, road.B);
			for (int j=0; j<p.size(); j++) {
				view.B = p[j];
				road.intersect(view, r);
				if (j==0) r_last=r;
				else {
					ii.AddPoint(r_last);
					ii.AddPoint(r);
				  ii.Clip(0.0f, 1.0f);
				  interv.push_back(ii);
//					ii.print("NewSectiion");
					ii.Reset();
				}
			}
		}


		int numSafeSections=0;
		if (fakeRoad) {
			printf("Fake road!\n");
			numSafeSections=0;
		}
		else {
		sort(interv.begin(), interv.end());

		
		Intervall ii;

//		printf("num_cases=%d interv.size()=%d\n", num_cases, interv.size());

		if (interv.size()!=0) {
			ii=interv[0];
			numSafeSections=1;
		}
		
		for (int i=0; i<interv.size(); i++) {
			Intervall& s=interv[i];
			
			if (ii.m_max+FLT_EPSILON-s.m_min<0.0f) {
				if (num_cases==10) {
					DEBUGPRINT(
					printf("numSafeSections=%d ", numSafeSections);
					ii.print("ii");
					);
				}


				//disjunct section
				ii=s;
				numSafeSections++;
			} else {
				ii.AddPoint(s.m_max);
			}
		}

		if (num_cases==10) {
			DEBUGPRINT(
			printf("numSafeSections=%d ", numSafeSections);
			ii.print("ii");
			);
		}
		}

		printf("%d\n", numSafeSections);
	}
}


		


				


		
