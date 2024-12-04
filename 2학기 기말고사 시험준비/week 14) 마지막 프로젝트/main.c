#include <stdio.h>
#include <string.h>
#include <math.h>
#define WORD    16 // 16비트 길이의 2진수를 처리하기 위한 상수 정의

// 문자열로 입력된 2진수를 WORD 크기의 2진수 배열로 변환
void getBinary(char bin[], char str[], int n) {
    int len = strlen(str); // 입력된 문자열의 길이
    int i;

    // 입력된 문자열 앞에 0을 추가하여 WORD 크기의 배열을 채움
    for (i = 0; i < n - len; i++) {
        bin[i] = '0';
    }

    // 입력된 문자열의 값을 복사
    for (int j = 0; j < len; j++) {
        bin[i++] = str[j];
    }
    bin[i] = '\0'; // 문자열 종료 문자 추가
}

// 2진수의 2의 보수(complement2) 계산
void complemnet2(char bin[], int n) {
    // 모든 비트를 반전
    for (int i = 0; i < n; i++) {
        if (bin[i] == '0') {
            bin[i] = '1';
        } else {
            bin[i] = '0';
        }
    }

    // 1을 더하여 2의 보수를 계산
    for (int i = n - 1; i >= 0; i--) {
        if (bin[i] == '0') {
            bin[i] = '1';
            break; // 캐리 없이 계산 완료
        } else {
            bin[i] = '0'; // 캐리 발생
        }
    }
}

// 2진수를 10진수 정수로 변환
int bin2dec(char bin[], int n) {
    int num = 0;

    // 각 자리 비트를 확인하며 10진수로 변환
    for (int i = 0; i < n; i++) {
        num = num * 2 + (bin[i] - '0'); // 각 비트를 더하며 계산
    }
    return num;
}

// 메인 함수
int main() {
    char input1[100]; // 첫 번째 2진수 입력
    char input2[100]; // 두 번째 2진수 입력
    char op[10]; // 연산자 입력

    char binary1[WORD + 1] = {0}; // 첫 번째 2진수를 저장할 배열
    char binary2[WORD + 1] = {0}; // 두 번째 2진수를 저장할 배열

    int result; // 계산 결과
    int num1, num2; // 10진수 변환된 두 숫자

    printf("<<<<<input>>>>>>\n");
    gets(input1); // 첫 번째 2진수 문자열 입력
    gets(op); // 연산자 입력
    gets(input2); // 두 번째 2진수 문자열 입력

    // 입력된 문자열을 16비트 2진수로 변환
    getBinary(binary1, input1, WORD);
    getBinary(binary2, input2, WORD);

    // 2진수를 10진수로 변환
    num1 = bin2dec(binary1, WORD);
    num2 = bin2dec(binary2, WORD);

    // 연산자에 따라 계산 수행
    switch(op[0]) {
        case '+' : result = num1 + num2; break;
        case '-' : result = num1 - num2; break;
        case '*' : result = num1 * num2; break;
        case '/' : result = num1 / num2; break;
        case '%' : result = num1 % num2; break;
        default : printf("bad op...\n"); break; // 잘못된 연산자 처리
    }

    // 결과 출력
    printf("%s(%d) %c %s(%d) = %d\n", binary1, num1, op[0], binary2, num2, result);

    return 0;
}
