#include "student.c"

void addStudent(Course *c, Student *s)
{
    c->members[c->nomberOfMembers++] = *s;
    Student *max = findMaxStud(c);
    c->maxMark = max->averageMark;
}

Student *findMaxStudentAtCourse(Course *c)
{
    if (c->nomberOfMembers == 0)
    {
        return NULL;
    }
    Student *max = findMaxStud(c);
    return max;
}

Student *findMaxStud(Course *c)
{
    Student *max = &c->members[0];
    for (int i = 1; i < c->nomberOfMembers; i++)
    {
        if (max->averageMark < c->members[i].averageMark)
        {
            max = &c->members[i];
        }
    }
    return max;
}