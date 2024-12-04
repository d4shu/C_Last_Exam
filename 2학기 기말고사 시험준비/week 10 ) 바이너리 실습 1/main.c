#include <stdio.h>
#define SIZE 100

void bin1() { 
    int main() { // 메인 함수 정의
        char input[SIZE];  // 사용자 입력을 저장할 배열
        FILE* fp = NULL;   // 파일 포인터 초기화

        // 바이너리 쓰기 모드로 파일 열기
        if ((fp = fopen("output.bin", "wb")) == NULL) {
            printf("error..."); // 파일 열기 실패 시 메시지 출력
            return 0;          // 함수 종료
        }

        gets(input); // 사용자로부터 문자열 입력 받기 (버퍼 오버플로우 위험 있음)
        
        // fputs(input, fp); // 일반 텍스트로 저장 (주석 처리됨)
        fwrite(input, strlen(input), 1, fp); // 문자열 데이터를 바이너리로 저장

        fclose(fp); // 파일 닫기
        return 0;   // 프로그램 종료
    }
} // 바이너리 실습 1

 
 
void bin1_2() { 
    int main() { // 메인 함수 정의
        char input[SIZE];  // 파일에서 읽은 데이터를 저장할 배열
        FILE* fp = NULL;   // 파일 포인터 초기화
        int i = 0;         // 인덱스 변수 초기화

        // 바이너리 읽기 모드로 파일 열기
        if ((fp = fopen("output.bin", "rb")) == NULL) {
            printf("error..."); // 파일 열기 실패 시 메시지 출력
            return 0;          // 함수 종료
        }

        // 파일에서 데이터를 한 글자씩 읽어 배열에 저장
        while (!feof(fp)) {
            fread(&input[i], sizeof(char), 1, fp); // 1바이트씩 읽어옴
            i++;
        }

        input[--i] = '\0'; // 마지막에 읽힌 추가 데이터를 제거하고 문자열 끝 지정
        puts(input);       // 읽어온 문자열 출력

        fclose(fp); // 파일 닫기
        return 0;   // 프로그램 종료
    }
}

