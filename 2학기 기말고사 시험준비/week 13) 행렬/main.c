// 2차원 행렬 (2D Array practice)
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 난수 생성을 위한 헤더 파일
#define ROW 100 // 행렬의 최대 행 수
#define COL 100 // 행렬의 최대 열 수

int main() {
    int matrix[ROW][COL]; // 2차원 배열 선언
    int row, col; // 사용자로부터 입력받을 행(row)과 열(col)의 크기

    srand(time(NULL)); // 난수 초기화 (현재 시간을 기준으로 시드 설정)
    
    // 행(row)와 열(col)의 크기 입력받기
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);

    // 행렬에 랜덤 값을 채우기
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            matrix[i][j] = rand() % 1000; // 0~999 사이의 랜덤 값
    }

    // 행렬 출력
    printf("Generated Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            printf("[%3d] ", matrix[i][j]); // 각 요소를 3자리 정렬로 출력
        printf("\n"); // 각 행 출력 후 줄바꿈
    }

    return 0; // 프로그램 종료
}

