// 로또 번호 생성 및 중복 제거 실습

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 로또 번호 정보를 담을 구조체 정의
typedef struct _lotto {
    int number[6]; // 로또 번호 6개
    int bonus;     // 보너스 번호
    int NO;        // 고유 식별 번호
} LOTTO;

// 로또 초기화 함수
void initLotto(LOTTO* l) {
    for (int i = 0; i < 6; i++) 
        l->number[i] = 0;  // 번호를 0으로 초기화
    l->bonus = 0;         // 보너스 번호 초기화
    l->NO = 0;            // 식별 번호 초기화
}

// 중복 체크 함수
// 이미 뽑힌 번호들과 비교하여 중복 여부 반환
int dup(LOTTO l, int num, int n) {
    for (int i = 0; i <= n; i++) {
        if (l.number[i] == num) 
            return 1; // 중복 발생
    }
    return 0; // 중복 없음
}

// 자동 로또 번호 생성 함수
LOTTO createAuto(int NO) {
    LOTTO l;
    int num;
    initLotto(&l); // 로또 초기화
    l.NO = NO;     // 고유 번호 설정
    
    for (int i = 0; i < 6; i++) {
        num = rand() % 45 + 1; // 1~45 범위의 난수 생성
        if (i == 0) 
            l.number[i] = num; // 첫 번째 번호는 바로 저장
        else if (i > 0 && !dup(l, num, i - 1)) 
            l.number[i] = num; // 중복이 없으면 저장
        else {
            i--; // 중복 발생 시 반복 시도
            printf("중복발생.. 다시 뽑으세요..\n");
        }
    }
    return l;
}

// 수동 로또 번호 생성 함수
LOTTO createManual(int NO) {
    LOTTO l;
    int num;
    initLotto(&l); // 로또 초기화
    l.NO = NO;     // 고유 번호 설정
    
    for (int i = 0; i < 6; i++) {
        printf("input number #%d : ", i + 1); // 번호 입력 요청
        scanf("%d", &num);
        if (i == 0) 
            l.number[i] = num; // 첫 번째 번호는 바로 저장
        else if (i > 0 && !dup(l, num, i - 1)) 
            l.number[i] = num; // 중복이 없으면 저장
        else {
            i--; // 중복 발생 시 다시 입력 요청
            printf("중복발생.. 다시 입력하세요..\n");
        }
    }
    return l;
}

// 로또 번호 출력 함수
void printLotto(LOTTO l) {
    printf("#%d lotto number : %2d, %2d, %2d, %2d, %2d, %2d\n", 
           l.NO, 
           l.number[0], l.number[1], l.number[2], 
           l.number[3], l.number[4], l.number[5]);
    printf("BONUS : %d\n", l.bonus);
}

// 프로그램 실행
int main() {
    LOTTO l;              // 로또 구조체 변수 선언
    srand(time(NULL));    // 난수 시드 초기화
    l = createAuto(20240911); // 자동으로 로또 번호 생성
    printLotto(l);        // 생성된 로또 번호 출력
    
    return 0; // 프로그램 정상 종료
}
