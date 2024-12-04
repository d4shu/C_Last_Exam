// 동적할당 실습 #3 - 동적할당 활용하기

#include <stdio.h>
#include <stdlib.h>

// 구조체 정의: POINT는 x와 y 좌표를 저장
typedef struct point {
    int x;
    int y;
} POINT;

// 메뉴를 출력하고 사용자로부터 선택을 입력받음
int inputMenu(void) {
    int input;
    printf("1. 만들기, 2. 출력하기, 3. 클리어, 4. 파일저장, 5. 파일로드, -1. 종료 : ");
    scanf("%d", &input);
    return input;
}

// 새로운 POINT 구조체를 동적으로 생성하고 좌표를 랜덤하게 초기화
POINT* makePoint(void) {
    POINT* p = (POINT*)malloc(sizeof(POINT));
    if (!p) { // 메모리 할당 실패 처리
        printf("메모리 할당 실패\n");
        exit(1);
    }
    p->x = rand() % 100;
    p->y = rand() % 100;
    return p;
}

// POINT 배열을 출력
void printPoint(POINT* p[], int size) {
    for (int i = 0; i < size; i++)
        printf("x:%d, y:%d\n", p[i]->x, p[i]->y);
}

// POINT 배열의 메모리를 해제
void freePoints(POINT* p[], int size) {
    for (int i = 0; i < size; i++)
        free(p[i]);
}

// POINT 배열을 파일에 저장
int saveFile(POINT* p[], int count) {
    FILE* fp;
    fp = fopen("points.bin", "ab"); // 기존 데이터에 추가 (append binary)
    if (fp == NULL) return 0; // 파일 열기 실패 시 0 반환
    for (int i = 0; i < count; i++)
        fwrite(p[i], sizeof(POINT), 1, fp); // POINT 구조체를 파일에 저장
    fclose(fp);
    return 1; // 저장 성공
}

// 파일에서 POINT 배열을 읽어옴
int loadFile(POINT* p[], int max) {
    FILE* fp;
    int fSize, fCount;
    fp = fopen("points.bin", "rb"); // 파일 읽기 모드로 열기
    if (fp == NULL) return 0; // 파일 열기 실패 시 0 반환
    
    fseek(fp, 0, SEEK_END); // 파일 끝으로 이동
    fSize = ftell(fp); // 파일 크기 계산
    fCount = fSize / sizeof(POINT); // POINT 개수 계산
    rewind(fp); // 파일 포인터를 다시 처음으로 이동
    
    for (int i = 0; i < fCount; i++) {
        if (i == max) break; // 최대 저장 가능한 크기를 초과하면 중단
        p[i] = (POINT*)malloc(sizeof(POINT));
        fread(p[i], sizeof(POINT), 1, fp); // POINT 데이터를 파일에서 읽어옴
    }
    fclose(fp);
    return fCount; // 읽어온 POINT 개수 반환
}

int main() {
    int menu; // 사용자 메뉴 선택
    int count = 0; // POINT 개수
    POINT* points[100]; // 최대 100개의 POINT를 저장할 배열

    do {
        menu = inputMenu(); // 메뉴 입력
        switch (menu) {
            case 1: // 새로운 POINT 생성
                points[count] = makePoint();
                count++;
                break;
            case 2: // POINT 출력
                printPoint(points, count);
                break;
            case 3: // 화면 지우기
                system("clear"); // Windows에서는 system("cls")
                break;
            case 4: // POINT 파일에 저장
                if (!saveFile(points, count)) 
                    printf("file open error...\n");
                else 
                    printf("file writing success...\n");
                break;
            case 5: // 파일에서 POINT 로드
                count = loadFile(points, 100);
                break;
            case -1: // 프로그램 종료
                freePoints(points, count); // 동적으로 할당된 메모리 해제
                printf("프로그램을 종료합니다.\n");
                break;
        }
    } while (menu > 0); // 메뉴가 양수일 때 계속 실행

    return 0;
}
