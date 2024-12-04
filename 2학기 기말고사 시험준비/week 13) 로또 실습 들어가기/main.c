/******************************************************************************
로또게임 만들기
*******************************************************************************/

//로또실습 들어가기

#include <stdio.h>

// 로또 번호와 관련된 정보를 저장할 구조체 정의
typedef struct _lotto {
    int number[6]; // 로또 번호 6개 저장
    int bonus;     // 보너스 번호 저장
    int NO;        // 로또 번호 식별자 (예: 고유 번호)
} LOTTO;

// LOTTO 구조체 초기화 함수
void initLotto(LOTTO* l) {
    for (int i = 0; i < 6; i++) 
        l->number[i] = 0; // 모든 번호를 0으로 초기화
    l->bonus = 0;         // 보너스 번호를 0으로 초기화
    l->NO = 0;            // 식별 번호 초기화 (필요시 설정)
}

// 사용자 입력을 받아 로또 번호를 수동으로 생성하는 함수
LOTTO createManual(int NO) {
    LOTTO l;              // 로또 구조체 생성
    int num;              // 사용자가 입력할 번호 변수
    initLotto(&l);        // 생성된 구조체 초기화
    l.NO = NO;            // 로또 번호 식별자 설정
    
    for (int i = 0; i < 6; i++) {
        printf("input number #%d : ", i + 1); // 번호 입력 요청
        scanf("%d", &num);                   // 사용자로부터 번호 입력받기
        l.number[i] = num;                   // 입력받은 번호를 저장
    }
    return l;            // 생성된 로또 구조체 반환
}

// 로또 번호와 보너스 번호를 출력하는 함수
void printLotto(LOTTO l) {
    printf("#%d lotto number : %2d, %2d, %2d, %2d, %2d, %2d\n",
        l.NO, l.number[0], l.number[1], l.number[2], l.number[3], l.number[4], l.number[5]); // 로또 번호 식별자 출력       
    printf("BONUS : %d\n", l.bonus); // 보너스 번호 출력
}

int main() {
    LOTTO l;              // 로또 구조체 변수 선언
    
    l = createManual(20240911); // 특정 번호로 수동 로또 생성
    printLotto(l);              // 생성된 로또 번호 출력
    
    return 0;                   // 프로그램 정상 종료
}


