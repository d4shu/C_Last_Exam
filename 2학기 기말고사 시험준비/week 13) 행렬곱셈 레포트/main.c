#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 100 // 행렬의 최대 행 수
#define COL 100 // 행렬의 최대 열 수

// 2차원 배열에 랜덤 값을 입력하는 함수
void input2DArray(int array[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            array[i][j] = rand() % 1000; // 0 ~ 999 범위의 랜덤 값
    }
}

// 2차원 배열을 출력하는 함수
void print2DArray(int array[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            printf("[%8d] ", array[i][j]); // 정렬된 형식으로 출력
        printf("\n");
    }
}

// 행렬 덧셈 함수
void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            target[i][j] = s1[i][j] + s2[i][j]; // 같은 위치의 원소를 더함
    }
}

// 행렬 뺄셈 함수
void subMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            target[i][j] = s1[i][j] - s2[i][j]; // 같은 위치의 원소를 뺌
    }
}

// 행렬 곱셈 함수
void multiMatrix(int m1[][100], int m2[][100], int result[][100], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) { // 첫 번째 행렬의 행
        for (int j = 0; j < col2; j++) { // 두 번째 행렬의 열
            result[i][j] = 0; // 초기화
            for (int k = 0; k < col1; k++) { // 첫 번째 행렬의 열 또는 두 번째 행렬의 행
                result[i][j] += m1[i][k] * m2[k][j]; // 곱셈 후 누적
            }
        }
    }
}

// 메인 함수
int main() {
    int matrix1[ROW][COL]; // 첫 번째 행렬
    int matrix2[ROW][COL]; // 두 번째 행렬
    int result[ROW][COL];  // 결과 행렬
    
    int row1, col1, row2, col2;
    srand(time(NULL)); // 난수 초기화
    
    // 첫 번째 행렬 크기 입력
    printf("Input matrix 1 row & col: ");
    scanf("%d %d", &row1, &col1);
    // 두 번째 행렬 크기 입력
    printf("Input matrix 2 row & col: ");
    scanf("%d %d", &row2, &col2);

    // 행렬 곱셈 가능 여부 확인
    if (col1 == row2) {
        printf("Matrix multiplication possible.\n");
        
        // 두 행렬에 랜덤 값 입력
        input2DArray(matrix1, row1, col1);
        input2DArray(matrix2, row2, col2);

        // 입력된 행렬 출력
        printf("Matrix 1:\n");
        print2DArray(matrix1, row1, col1);
        printf("Matrix 2:\n");
        print2DArray(matrix2, row2, col2);

        // 행렬 곱셈 수행
        multiMatrix(matrix1, matrix2, result, row1, col1, col2);

        // 결과 행렬 출력
        printf("Result:\n");
        print2DArray(result, row1, col2);
    } else {
        // 곱셈 불가능 메시지 출력
        printf("Matrix multiplication not possible. Please input valid dimensions.\n");
    }

    return 0;
}
