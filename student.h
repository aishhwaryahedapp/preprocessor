#ifndef STUDENT_H
#define STUDENT_H

#define PASS_MARK 40
#define MAX_MARK 100

struct student
{
int rollno;
char name[20];
float marks;
};

void display_result(struct student s); 
#endif

