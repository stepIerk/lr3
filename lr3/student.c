#include "course.h"

double changeMark(Student *s, int mark)
{
    if (mark <= 5 && mark >= 2)
    {
        s->averageMark = ((s->averageMark * s->quantityOfMarks) + mark) / (s->quantityOfMarks + 1);
        s->quantityOfMarks++;
        return s->averageMark;
    }
    return (-1);
}

int isStudentExcellent(Student *s)
{
    if (s->averageMark >= 4.61)
    {
        return 1;
    }
    return 0;
}

int howManyMarksToExcellent(Student *s)
{
    int i = 0;
    int qOfMarks = s->quantityOfMarks;
    double possibleMark = s->averageMark;
    while (possibleMark < 4.61)
    {
        possibleMark = (possibleMark * qOfMarks + 5) / (qOfMarks + 1);
        qOfMarks++;
        i++;
    }
    return i;
}