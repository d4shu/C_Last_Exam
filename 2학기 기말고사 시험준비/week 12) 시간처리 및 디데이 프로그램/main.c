/******************************************************************************
입력한 날짜의 해당 요일을 출력해준다.
*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include "report.h"
#include "wday.h"

int main(int argc, char* argv[]){
    week2(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    //wday();
    
}  
