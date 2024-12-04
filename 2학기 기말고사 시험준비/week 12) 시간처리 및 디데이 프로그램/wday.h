/******************************************************************************
입력한 날짜의 해당 요일을 출력해준다.
*******************************************************************************/

#ifndef _WDAY_H
#define _WDAY_H

void wday(){
    time_t current;               // 현재 시간을 저장할 변수
    struct tm* timeinfo;          // 시간 정보를 구조체로 저장하는 포인터

    int year, month, day;         // 입력받을 연도, 월, 일
    char* WEEK[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"}; // 요일 배열

    printf("Enter YYYY MM DD : "); // 사용자로부터 날짜 입력받기
    scanf("%d %d %d", &year, &month, &day);

    current = time(NULL);         // 현재 시간을 가져옴
    timeinfo = localtime(&current); // 현재 시간을 `struct tm` 형식으로 변환

    // 입력받은 연도, 월, 일을 `struct tm` 구조체에 설정
    timeinfo->tm_year = year - 1900; // tm_year는 1900년을 기준으로 계산
    timeinfo->tm_mon = month - 1;   // tm_mon은 0부터 시작하므로 -1
    timeinfo->tm_mday = day;        // 입력받은 날짜 설정

    mktime(timeinfo);              // `mktime`을 호출해 `tm_wday`를 계산

    // 결과 출력
    printf("%d %d %d -> %s\n", year, month, day, WEEK[timeinfo->tm_wday]);

}
#endif