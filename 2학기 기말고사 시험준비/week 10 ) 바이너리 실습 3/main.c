#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 점(point)을 나타내는 구조체 정의
typedef struct point {
    int x; // x 좌표
    int y; // y 좌표
} POINT;

// 사용자로부터 점의 좌표를 입력받아 POINT 구조체를 생성하는 함수
POINT makePoint(void) {
    POINT p;
    // 사용자로부터 x와 y 값을 입력받음
    scanf("%d %d", &p.x, &p.y);
    return p; // 생성한 POINT 반환
}

// 랜덤한 좌표를 가지는 점들을 배열에 생성하는 함수
void makeRandomPoints(POINT p[], int size) {
    srand(time(NULL)); // 랜덤 시드 설정
    for (int i = 0; i < size; i++) {
        p[i].x = rand() % 100; // x 좌표를 0~99 사이의 값으로 생성
        p[i].y = rand() % 100; // y 좌표를 0~99 사이의 값으로 생성
    }
}

// 점 배열의 내용을 출력하는 함수
void printPoints(POINT p[], int size) {
    for (int i = 0; i < size; i++) {
        // 각 점의 x와 y 값을 출력
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
    }
}

// 점 배열을 바이너리 파일에 저장하는 함수
void saveFile(POINT p[], int size) {
    FILE* fp;
    fp = fopen("struct.bin", "wb"); // 바이너리 쓰기 모드로 파일 열기
    if (fp == NULL) exit(-1); // 파일 열기 실패 시 프로그램 종료
    fwrite(p, sizeof(POINT), size, fp); // 점 배열을 파일에 저장
    fclose(fp); // 파일 닫기
}

// 파일에서 점 배열을 읽어오는 함수
void loadFile(POINT p[], int size) {
    FILE* fp;
    fp = fopen("struct.bin", "rb"); // 바이너리 읽기 모드로 파일 열기
    if (fp == NULL) exit(-1); // 파일 열기 실패 시 프로그램 종료
    fread(p, sizeof(POINT), size, fp); // 점 배열을 파일에서 읽어오기
    fclose(fp); // 파일 닫기
}

// 메인 함수
int main() {
    POINT p[10]; // POINT 구조체 배열 선언 (크기 10)

    // 1. 파일에서 점 데이터를 읽어오기
    loadFile(p, 10);

    // 2. 점 배열에 랜덤 좌표 생성
    makeRandomPoints(p, 10);

    // 3. 생성된 점 배열 출력
    printPoints(p, 10);

    // 4. 점 배열을 파일에 저장
    saveFile(p, 10);

    return 0; // 프로그램 정상 종료
}

