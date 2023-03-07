#include <iostream>
#include <vector>

using namespace std;

// Hàm tạo ma trận Hadamard kích thước N*N
vector<vector<char>> hadamard(int n) {
    if (n == 0) {
        // Ma trận Hadamard kích thước 1*1
        return { {'o'} };
    }
    int N = 1 << n; // N = 2^n
    vector<vector<char>> result(N, vector<char>(N, '.')); // Tạo ma trận kích thước N*N ban đầu
    auto sub_hadamard = hadamard(n - 1); // Tạo ba ma trận Hadamard kích thước (N/2)*(N/2)
    // Gán các ma trận Hadamard vào ma trận kích thước N*N theo đặc điểm của ma trận Hadamard
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            result[i][j] = sub_hadamard[i][j];
            result[i][j + N / 2] = sub_hadamard[i][j];
            result[i + N / 2][j] = sub_hadamard[i][j];
            result[i + N / 2][j + N / 2] = sub_hadamard[i][j] == '.' ? 'o' : '.'; // Đảo ngược ma trận Hadamard ở góc phần tư phải dưới
        }
    }
    return result;
}

// Hàm in ma trận ra màn hình
void print_matrix(const vector<vector<char>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    auto result = hadamard(n);
    print_matrix(result);
    return 0;
}
