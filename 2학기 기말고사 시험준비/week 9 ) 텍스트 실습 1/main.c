#include <stdio.h>

// 사용자가 입력한 한 줄의 문자열을 배열에 저장하는 함수
int getLine(char* line) {
    int ch;      // 입력된 문자를 저장할 변수
    int i = 0;   // 문자열 배열의 인덱스

    // 개행 문자가 입력될 때까지 반복하여 문자를 읽음
    while ((ch = getchar()) != '\n') 
        line[i++] = ch;

    line[i] = '\0'; // 문자열 끝에 NULL 문자 추가
    return i;       // 입력받은 문자열의 길이를 반환
}

int main() {
    char input[100]; // 사용자 입력을 저장할 배열
    FILE* fp;        // 파일 포인터

    // "output.txt" 파일을 쓰기 모드("w")로 열기
    if ((fp = fopen("output.txt", "w")) == NULL) {
        printf("error..."); // 파일 열기 실패 시 오류 메시지 출력
        return 0;          // 프로그램 종료
    }

    // 사용자로부터 5번 입력을 받아 파일에 기록
    for (int i = 0; i < 5; i++) {
        getLine(input);      // 사용자로부터 한 줄 입력받음
        fputs(input, fp);    // 입력받은 문자열을 파일에 씀
        fputs("\n", fp);     // 줄 바꿈 문자("\n")를 추가로 기록
    }

    fclose(fp); // 파일 닫기
    return 0;   // 프로그램 정상 종료
}
