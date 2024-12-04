/******************************************************************************
동적할당 실습 #3 - 동적할당 활용하기
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// POINT 구조체 정의
typedef struct point {
    int x; // x 좌표
    int y; // y 좌표
} POINT;

// 메뉴 입력 함수
int inputMenu(void) {
    int input;
    // 사용자에게 메뉴 선택 요청
    printf("메뉴입력(1. 구조체 만들기, 2. 구조체 출력하기, -1. 종료) : ");
    scanf("%d", &input);
    return input; // 사용자가 입력한 메뉴 번호 반환
}

// 새로운 POINT 구조체를 동적 할당하고 초기화
POINT* makePoint(void) {
    POINT* p = (POINT*)malloc(sizeof(POINT)); // POINT 구조체 크기만큼 메모리 할당
    if (p == NULL) { // 메모리 할당 실패 시 오류 처리
        printf("메모리 할당 실패\n");
        exit(1);
    }
    p->x = rand() % 100; // x 값 랜덤 초기화
    p->y = rand() % 100; // y 값 랜덤 초기화
    return p; // 생성된 POINT 구조체의 주소 반환
}

// POINT 배열 출력
void printPoint(POINT* p[], int size) {
    for (int i = 0; i < size; i++) 
        printf("x : %d, y : %d\n", p[i]->x, p[i]->y); // 각 POINT의 x, y 값 출력
}

// POINT 배열 메모리 해제
void freePoints(POINT* p[], int size) {
    for (int i = 0; i < size; i++)
        free(p[i]); // 각 POINT의 메모리 해제
}

int main() {
    int menu; // 메뉴 번호 저장 변수
    int count = 0; // 현재 생성된 POINT 개수
    POINT* points[100]; // POINT 포인터 배열 (최대 100개의 POINT 저장 가능)
    
    // 메뉴 루프
    do {
        menu = inputMenu(); // 메뉴 입력 받기
        if (menu == 1) {
            // 구조체 만들기
            points[count] = makePoint(); // 새로운 POINT 생성
            count++; // POINT 개수 증가
            printf("잘 만들었습니다.\n");
        } else if (menu == 2) {
            // 구조체 출력
            printPoint(points, count); // 생성된 POINT 모두 출력
        } else if (menu == -1) {
            // 프로그램 종료
            printf("프로그램을 종료합니다.\n");
            freePoints(points, count); // 모든 POINT 메모리 해제
        }
    } while (menu > 0); // 메뉴가 양수인 동안 반복
    
    return 0; // 프로그램 정상 종료
}
