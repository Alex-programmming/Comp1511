// Haoheng Duan
// z5248147
// 29/09/2019
#include <stdio.h>
int main(void) {
    int no1;
    int no2;
    int no3;
    int no4;
    int no5;
    int no6;
    int no7;
    int no8;
    int no9;
    int no10;
    int no11;
    int no12;
    int no13;
    int year;
    int month;
    int date;
    printf("Enter year: ");
    scanf("%d", &year);
    no1 = year % 19;
    no2 = year / 100;
    no3 = year % 100;
    no4 = no2 / 4;
    no5 = no2 % 4;
    no6 = (no2 + 8) / 25;
    no7 = (no2 - no6 + 1) / 3;
    no8 = (19 * no1 + no2 - no4 - no7 + 15) % 30;
    no9 = no3 / 4;
    no10 = no3 % 4;
    no11 = (32 + 2 * no5 + 2 * no9 - no8 - no10 ) % 7;
    no12 = (no1 + 11 * no8 + 22 * no11) / 451;
    month = (no8 + no11 - 7 * no12 + 114) / 31;
    no13 = (no8 + no11 - 7 * no12 + 114) % 31;
    date = no13 + 1;
    printf("Easter is ");
    if (month == 1) {
        printf("January");
    } else if (month == 2) {
        printf("Feburary");
    } else if (month == 3) {
        printf("March");
    } else if (month == 4) {
        printf("April");
    } else if (month == 5) {
        printf("May");
    } else if (month == 6) {
        printf("June");
    } else if (month == 7) {
        printf("July");
    } else if (month == 8) {
        printf("Auguest");
    } else if (month == 9) {
        printf("September");
    } else if (month == 10) {
        printf("October");
    } else if (month == 11) {
        printf("November");
    } else if (month == 12) {
        printf("December");
    } 
    printf(" %d in %d.\n", date, year);
    return 0;
}

