#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct student
{
    char name[20];
    double averageMark;
    double quantityOfMarks;
    int age;
} Student;

double changeMark(Student *s, int mark);
int isStudentExcellent(Student *s);

int howManyMarksToExcellent(Student *s); // функция просто по роиколу, было интересно сделать