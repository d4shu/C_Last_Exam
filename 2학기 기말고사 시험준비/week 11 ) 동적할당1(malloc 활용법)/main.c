/******************************************************************************
malloc 활용방법 .1
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> // 동적 메모리 할당 및 난수 생성에 필요한 헤더

int main()
{
    char* pChar; // `char` 형 포인터
    int* pInt;   // `int` 형 포인터
    int count;   // 동적으로 할당할 `int` 배열의 크기

    // 사용자로부터 동적 배열의 크기 입력
    scanf("%d", &count);

    // `count` 개의 정수를 저장할 수 있는 동적 메모리 할당
    pInt = (int*)malloc(count * sizeof(int));
    // 할당된 메모리 주소가 `pInt`에 저장됨

    // 배열의 각 원소를 0~99 사이의 난수로 초기화
    for (int i = 0; i < count; i++)
        pInt[i] = rand() % 100; // `rand()`는 난수 생성 함수

    // 초기화된 배열의 원소 출력
    for (int i = 0; i < count; i++)
        printf("%d ", pInt[i]);
    printf("\n"); // 줄 바꿈

    // `pChar` 포인터에 `pInt`의 주소를 캐스팅
    pChar = (char*)pInt; 
    // 메모리를 `char` 단위로 접근 가능해짐

    // 입력 버퍼 정리 (`getchar`로 개행 문자 제거)
    while (getchar() != '\n');

    // 사용자로부터 문자열 입력받아 동적 메모리에 저장
    gets(pChar); // 사용자가 입력한 문자열을 `pChar`가 가리키는 메모리에 저장
    // **주의:** `gets`는 버퍼 오버플로우의 위험이 있어 `fgets` 사용을 권장

    // 저장된 문자열 출력
    puts(pChar); 

    // 동적 메모리 해제
    free(pInt);

    return 0;
}
