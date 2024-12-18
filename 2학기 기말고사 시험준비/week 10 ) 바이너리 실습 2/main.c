/******************************************************************************
 바이너리파일 배열데이터 읽고 쓰기
*******************************************************************************/

#include <stdio.h>

int main() {
    int array[100];          // 정수형 배열 선언 (크기 100)
    FILE* fp;                // 파일 포인터 선언
    int i = 0;               // 배열 인덱스 초기화

    // "array.bin" 파일을 바이너리 읽기 모드로 열기
    fp = fopen("array.bin", "rb");
    if (fp == NULL) return -1; // 파일 열기에 실패하면 프로그램 종료

    // 주석 처리된 부분: 파일에서 하나씩 읽는 방식
    /*
    while(fread(&array[i++], sizeof(int), 1, fp)); 
    i--; // 마지막 증가된 인덱스를 감소시킴
    for(int j=0; j<i; j++) printf("%d ", array[j]); // 읽은 값을 출력
    */

    // 파일에서 최대 100개의 정수를 한 번에 읽기
    fread(array, sizeof(int), 100, fp);

    // 배열의 값을 출력
    for (int i = 0; i < 100; i++) 
        printf("%d ", array[i]);

    fclose(fp); // 파일 닫기
    return 0;   // 프로그램 정상 종료
}


