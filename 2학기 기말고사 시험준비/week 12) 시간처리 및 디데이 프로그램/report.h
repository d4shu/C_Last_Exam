#ifndef REPORT_H
#define REPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void week2(int year, int month, int day) {
    time_t current;
    struct tm* timeinfo;

    current = time(NULL); // 현재 시간 가져오기
    timeinfo = localtime(&current); // 현재 시간을 tm 구조체로 변환

    // 입력받은 날짜를 tm 구조체에 설정
    timeinfo->tm_year = year - 1900; // tm_year는 1900년 기준
    timeinfo->tm_mon = month - 1;    // tm_mon은 0부터 시작
    timeinfo->tm_mday = day;

    mktime(timeinfo); // 설정한 날짜의 요일과 timestamp 계산

    // 오늘과의 차이 계산
    double diff = difftime(mktime(timeinfo), current); // 두 timestamp의 차이 계산
    int dayDiff = diff / (60 * 60 * 24); // 초 단위 차이를 일(day)로 변환

    // 결과 출력
    if (dayDiff > 0) {
        printf("%d %d %d -> 오늘로부터 %d일 후 입니다.\n", year, month, day, dayDiff);
    } else if (dayDiff < 0) {
        printf("%d %d %d -> 오늘로부터 %d일 전 입니다.\n", year, month, day, dayDiff);
    } else {
        printf("오늘입니다 !\n");
    }
}


#endif