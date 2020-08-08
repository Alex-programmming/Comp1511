// Haoheng Duan
// z5248147
// 04/10/2019
// This program calculates the marks that a student got in an exam
 
#include <stdio.h>

int main(void) {
    int mark;
    int award;
    printf("Enter the total number of marks in the exam: ");
    scanf("%d", &mark);
    printf("Enter the number of marks the student was awarded: ");
    scanf("%d", &award);
    printf("The student scored ");
    printf("%.0lf%%", award * 100 / (mark * 1.0));
    printf(" in this exam.\n");
    
    return 0;
}
