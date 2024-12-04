#include <stdio.h>

void exec1() { // 파일 내용을 출력하는 함수
    int getLine(char* line) { // 한 줄을 입력받아 문자열에 저장하는 함수
        int ch;
        int i = 0;
        while ((ch = getchar()) != '\n') line[i++] = ch;
        line[i] = '\0'; // 문자열 끝에 NULL 문자 추가
        return i;       // 문자열 길이 반환
    }

    int main() { 
        char input[100];   // 파일에서 읽어온 데이터를 저장할 배열
        FILE* fp;          // 파일 포인터

        // 파일 "output.txt"를 읽기 모드로 열기
        if ((fp = fopen("output.txt", "r")) == NULL) {
            printf("error..."); // 파일 열기 실패 시 오류 메시지 출력
            return 0;          // 프로그램 종료
        }

        // 파일의 끝에 도달할 때까지 반복
        while (!feof(fp)) { /* feof: 파일 포인터가 파일의 끝인지 확인 */
            fgets(input, 100, fp); // 파일에서 최대 100자까지 읽어 배열에 저장
            printf("%s", input);   // 읽은 내용을 화면에 출력
        }

        fclose(fp); // 파일 닫기
        return 0;   // 프로그램 종료
    }
}



//텍스트 파일 복사 (src -> dest)
int getLine(char* line) { // 사용자 입력을 한 줄 받는 함수
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n') line[i++] = ch;
    line[i] = '\0'; // 문자열 끝에 NULL 문자 추가
    return i;       // 문자열 길이 반환
}

int main() { 
    char input[100];     // 데이터를 저장할 배열
    FILE* fp_src;        // 원본 파일 포인터
    FILE* fp_dest;       // 대상 파일 포인터

    // 원본 파일 "output.txt"를 읽기 모드로 열기
    if ((fp_src = fopen("output.txt", "r")) == NULL) {
        printf("error..."); // 파일 열기 실패 시 메시지 출력
        return 0;          // 프로그램 종료
    }

    // 대상 파일 "output2.txt"를 쓰기 모드로 열기
    if ((fp_dest = fopen("output2.txt", "w")) == NULL) {
        printf("error..."); // 파일 열기 실패 시 메시지 출력
        return 0;          // 프로그램 종료
    }

    // 원본 파일 내용을 읽어 대상 파일에 복사
    while (!feof(fp_src)) { 
        fgets(input, 100, fp_src); // 한 줄씩 읽기
        fputs(input, fp_dest);     // 읽은 내용을 대상 파일에 쓰기
    }

    fclose(fp_src); // 원본 파일 닫기
    fclose(fp_dest); // 대상 파일 닫기
    return 0;       // 프로그램 정상 종료
}

