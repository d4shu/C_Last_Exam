#include <stdio.h>

// 사용자 입력을 한 줄 받아 문자열에 저장하는 함수
int getLine(char* line) {
    int ch;  // 문자를 저장할 변수
    int i = 0; // 문자열 인덱스
    while ((ch = getchar()) != '\n') // 개행 문자를 만날 때까지 반복
        line[i++] = ch; // 입력된 문자 저장
    line[i] = '\0'; // 문자열 끝에 NULL 문자 추가
    return i; // 문자열의 길이 반환
}

int main() {
    char input[100];     // 문자열 데이터를 저장할 배열
    int num1, num2;      // 정수 데이터를 저장할 변수
    FILE* fp_src;        // 원본 파일 포인터
    FILE* fp_dest;       // 대상 파일 포인터

    // 원본 파일 "output.txt"를 읽기 모드로 열기
    if ((fp_src = fopen("output.txt", "r")) == NULL) {
        printf("error..."); // 파일 열기 실패 시 메시지 출력
        return 0;          // 프로그램 종료
    }

    // 대상 파일 "output3.txt"를 쓰기 모드로 열기
    if ((fp_dest = fopen("output3.txt", "w")) == NULL) {
        printf("error..."); // 파일 열기 실패 시 메시지 출력
        return 0;          // 프로그램 종료
    }

    // 원본 파일에서 데이터를 읽고 대상 파일로 복사
    while (!feof(fp_src)) {
        // 원본 파일에서 문자열과 두 개의 정수를 읽음
        fscanf(fp_src, "%s %d %d\n", input, &num1, &num2);
        // 대상 파일에 읽은 데이터를 동일한 형식으로 씀
        fprintf(fp_dest, "%s %d %d\n", input, num1, num2);
    }

    // 파일 닫기
    fclose(fp_src);
    fclose(fp_dest);

    return 0; // 프로그램 정상 종료
}
