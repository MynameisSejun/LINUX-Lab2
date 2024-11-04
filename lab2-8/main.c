#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    
    // 사용자로부터 행렬의 크기 입력 받기
    printf("행렬의 행과 열의 크기를 입력하세요 (예: 2 3): ");
    scanf("%d %d", &rows, &cols);

    // 메모리 동적 할당
    int **matrixA = (int **)malloc(rows * sizeof(int *));
    int **matrixB = (int **)malloc(rows * sizeof(int *));
    int **resultMatrix = (int **)malloc(rows * sizeof(int *));
    
    for (int i = 0; i < rows; i++) {
        matrixA[i] = (int *)malloc(cols * sizeof(int));
        matrixB[i] = (int *)malloc(cols * sizeof(int));
        resultMatrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // 첫 번째 행렬 입력
    printf("첫 번째 행렬의 요소를 입력하세요:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // 두 번째 행렬 입력
    printf("두 번째 행렬의 요소를 입력하세요:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // 행렬 더하기
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // 결과 행렬 출력
    printf("두 행렬의 합은 다음과 같습니다:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    // 동적으로 할당된 메모리 해제
    for (int i = 0; i < rows; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(resultMatrix[i]);
    }
    free(matrixA);
    free(matrixB);
    free(resultMatrix);

    return 0;
}
