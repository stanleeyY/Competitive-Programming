//#include <iostream>
//#include <list>
//#include <limits.h>//for int_max
//using namespace std;
//
//int main() {
//	int arr[51][51];
//	int n, m;
//	while (cin >> n >> m) {
//		if (n == 0 && m == 0)
//			break;
//		bool flag = true;
//		for (int i = 1; i <= n; i++) {
//			if (!flag) {
//				cin.ignore(INT_MAX, '\n');// Need to do this because you have to clear the buffer for the next input.
//				//Don't do cin.ignore(INT_MAX), that would clear buffer till EOF and other inputs will be skipped.
//				continue;
//			}
//			for (int j = 1; j <= m; j++) {
//				cin >> arr[i][j];
//				if (arr[i][j] == 1) {
//					if (i == 1 || i == n || j == 1 || j == m) {
//						flag = false;
//						cin.ignore(INT_MAX, '\n');
//						break;
//					}
//				}
//			}
//			
//		}
//		if (flag)
//			cout << 4 << endl;
//		else
//			cout << 2 << endl;
//
//	}
//	return 0;
//}