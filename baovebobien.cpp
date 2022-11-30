#include <iostream>
using namespace std;
#define MAX 100
int m, n;
int a[MAX][MAX];
int b[MAX][MAX];
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[i][j];
		}
	} // sao chép matrix a sang matrix b
	// từ giờ trở đi, ta chèn số bên matrix b, matrix a chỉ lấy để làm mốc
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				if (i > 0 && j > 0 && i < m - 1 && j < n - 1) {
					int x, y;

					x = i - 1;
					for (y = j - 1; y < j + 1; y++) {
						b[x][y] = 1;
					}

					y = j + 1;
					for (x = i - 1; x < i + 1; x++) {
						b[x][y] = 1;
					}

					x = i + 1;
					for (y = j + 1; y > j - 1; y--) {
						b[x][y] = 1;
					}

					y = j - 1;
					for (x = i + 1; x > i - 1; x--) {
						b[x][y] = 1;
					}
				}
				else {
					int x, y;

					x = i - 1;
					for (y = j - 1; y < j + 1; y++) {
						if (x >= 0 && x < m && y >= 0 && y < n)
							b[x][y] = 1;
					}

					y = j + 1;
					for (x = i - 1; x < i + 1; x++) {
						if (x >= 0 && x < m && y >= 0 && y < n)
							b[x][y] = 1;
					}

					x = i + 1;
					for (y = j + 1; y > j - 1; y--) {
						if (x >= 0 && x < m && y >= 0 && y < n)
							b[x][y] = 1;
					}

					y = j - 1;
					for (x = i + 1; x > i - 1; x--) {
						if (x >= 0 && x < m && y >= 0 && y < n)
							b[x][y] = 1;
					}
				}
			}
		}
	}
	// tính điểm
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum += b[i][j];
		}
	}
	cout << sum;
}
