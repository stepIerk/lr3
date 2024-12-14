#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"

typedef struct course
{
    char name[20];
    Student members[200];
    float maxMark;
    int nomberOfMembers;
} Course;

Student *findMaxStud(Course *c);

void addStudent(Course *c, Student *s);
Student *findMaxStudentAtCourse(Course *c);
