//#include <iostream>
//#include <list>
//#include <cstdlib>
//#include <math.h>
//#include <string.h>
//using namespace std;
//int set[100];
//int length = 0;
//class Edge {
//public:
//	int u;
//	int v;
//	int w;
//	Edge(int from, int to, int weight);
//	Edge();
//};
//Edge::Edge() {
//	u = -1;
//	v = -1;
//	w = -1;
//}
//Edge::Edge(int from, int to, int weight) {
//	u = from;
//	v = to;
//	w = weight;
//}
//Edge* edges;
//int compareEdge(const void* a, const void* b) {
//	Edge* e1 = (Edge*)a;
//	Edge* e2 = (Edge*)b;
//	return e1->w - e2->w;//sort in descending order
//}
//int find(int element) {
//	if (set[element] < 0)
//		return element;
//	return set[element] = find(set[element]);
//}
//void UnionSet(int r1, int r2) {
//	set[r1] += set[r2];
//	set[r2] = r1;
//}
//void Union(int element1, int element2,int weight) {
//	int root1 = find(element1);
//	int root2 = find(element2);
//	if (root1 == root2)
//		return;
//	length += weight;
//	if (set[root1] < set[root2]) {//root1 has more members
//		UnionSet(root1, root2);
//	}
//	else {
//		UnionSet(root2, root1);
//	}
//
//}
//
//int main() {
//	int n, m;
//	while (cin >> n) {
//		length = 0;
//		if (n == 0)
//			break;
//		cin >> m;
//		if (m == 0) {
//			cout << 0 << endl;
//			continue;
//		}
//		edges = new Edge[m+1];
//		memset(&set, -1, sizeof(int)*(n + 1));
//		for (int i = 0; i < m; i++) {
//			int u, v, w;
//			cin >> u >> v >> w;
//			Edge temp(u, v, w);
//			edges[i] = temp;
//		}
//		qsort(edges, m, sizeof(Edge), compareEdge);
//		for (int i = 0; i < m; i++) {
//			int u = edges[i].u;
//			int v = edges[i].v;
//			int w = edges[i].w;
//			Union(u, v,w);
//		}
//		cout << length<<endl;
//	}
//	return 0;
//}