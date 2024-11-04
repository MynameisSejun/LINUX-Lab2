#include <iostream>
#include <vector>
using namespace std; // std 네임스페이스 사용
int main() {
    int rows, cols;
    // 사용자로부터 행렬의 크기 입력 받기
    cout << "행렬의 행과 열의 크기를 입력하세요: ";
    cin >> rows >> cols;
    // 행렬을 위한 벡터 정의
    vector<vector<int>> matrixA(rows, vector<int>(cols));
    vector<vector<int>> matrixB(rows, vector<int>(cols));
    vector<vector<int>> resultMatrix(rows, vector<int>(cols));
    // 첫 번째 행렬 입력
    cout << "첫 번째 행렬의 요소를 입력하세요:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }
    // 두 번째 행렬 입력
    cout << "두 번째 행렬의 요소를 입력하세요:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }
    // 행렬 더하기
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    // 결과 행렬 출력
    cout << "두 행렬의 합은 다음과 같습니다:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << resultMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
