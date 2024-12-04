#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// POINT 구조체 정의
typedef struct point {
    int x; // x 좌표
    int y; // y 좌표
} POINT;

// 사용자가 입력한 좌표를 POINT로 생성
POINT makePoint(void) {
    POINT p;
    scanf("%d %d", &p.x, &p.y); // 사용자로부터 x, y 좌표 입력받음
    return p;                  // POINT 반환
}

// 랜덤 좌표를 가지는 POINT 배열 생성
void makeRandomPoints(POINT p[], int size) {
    srand(time(NULL)); // 랜덤 시드 설정
    for (int i = 0; i < size; i++) {
        p[i].x = rand() % 100; // x 좌표를 0~99 사이의 랜덤 값으로 설정
        p[i].y = rand() % 100; // y 좌표를 0~99 사이의 랜덤 값으로 설정
    }
}

// POINT 배열 출력
void printPoints(POINT p[], int size) {
    for (int i = 0; i < size; i++)
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
}

// POINT 배열을 바이너리 파일에 저장
void saveFile(POINT p[], int size) {
    FILE* fp;
    fp = fopen("struct.bin", "wb"); // 바이너리 쓰기 모드로 파일 열기
    if (fp == NULL) exit(-1);      // 파일 열기 실패 시 프로그램 종료
    fwrite(p, sizeof(POINT), size, fp); // 배열 내용을 파일에 저장
    fclose(fp); // 파일 닫기
}

// 바이너리 파일에서 POINT 배열 읽기
void loadFile(POINT p[], int size) {
    FILE* fp;
    fp = fopen("struct.bin", "rb"); // 바이너리 읽기 모드로 파일 열기
    if (fp == NULL) exit(-1);       // 파일 열기 실패 시 프로그램 종료
    fread(p, sizeof(POINT), size, fp); // 파일에서 데이터를 읽어 배열에 저장
    fclose(fp); // 파일 닫기
}

int main() {
    FILE* fp;         // 파일 포인터
    POINT p[10];      // POINT 배열
    POINT p2;         // 특정 POINT 저장을 위한 변수
    int pi;           // 파일 위치 정보를 저장할 변수

    // 바이너리 파일에서 POINT 배열 읽기
    loadFile(p, 10);
    printPoints(p, 10); // 읽은 POINT 배열 출력

    // 바이너리 파일 다시 열기
    fp = fopen("struct.bin", "rb");
    if (fp == NULL) exit(-1); // 파일 열기 실패 시 프로그램 종료

    // 파일의 네 번째 POINT로 이동
    fseek(fp, sizeof(POINT) * 3, SEEK_SET); // 파일 시작 기준으로 4번째 POINT 위치로 이동
    pi = ftell(fp); // 현재 파일 위치 저장
    printf("pi = %d\n", pi); // 파일 위치 출력

    fread(&p2, sizeof(POINT), 1, fp); // 네 번째 POINT 읽기
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y); // 읽은 POINT 출력

    // 파일의 끝에서 두 번째 POINT로 이동
    fseek(fp, sizeof(POINT) * -2, SEEK_END); // 파일 끝에서 두 번째 POINT 위치로 이동
    printf("pi = %d\n", ftell(fp)); // 현재 파일 위치 출력

    fread(&p2, sizeof(POINT), 1, fp); // 해당 POINT 읽기
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y); // 읽은 POINT 출력

    // 파일의 끝으로 이동
    fseek(fp, 0, SEEK_END); // 파일 끝으로 이동
    printf("size = %ld\n", ftell(fp)); // 파일 크기 출력

    fclose(fp); // 파일 닫기
    return 0;
}
