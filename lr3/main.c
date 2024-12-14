#include "course.c"

int testFunctionChangeMark(int mark);
int testFunctionAddStudent(int qOfStudents);
int testFunctionIsStudentExcellent();
int testFunctionFindMaxStudentAtCourse(int qOfStudents);

int testCaseDraw(char *testName, char *funcAnswer, char *rightAnswer);

void testPositive();
void testNegative();

void extremeTest();

int main()
{
    testPositive();
    testNegative();
    extremeTest();
    return 0;
}

void writeBorderLine(char simbol)
{
    for (int i = 0; i < 50; i++)
    {
        printf("%c", simbol);
    }
    printf("\n");
}

void printTestClaster(int posTests, int qOfTests)
{
    writeBorderLine('*');
    printf("Total: %d passed tests\n", posTests);
    int percentOfPassedTests = (posTests * 100) / qOfTests;
    printf("Percent of passed tests: %d %%\n", percentOfPassedTests);
}

void testPositive()
{
    printf("\n");
    writeBorderLine('-');
    printf("Positive tests\n");
    int possitiveTests = 0;
    possitiveTests += testFunctionChangeMark(5);
    possitiveTests += testFunctionAddStudent(1);
    possitiveTests += testFunctionIsStudentExcellent();
    possitiveTests += testFunctionFindMaxStudentAtCourse(2);
    printTestClaster(possitiveTests, 4);
}

void testNegative()
{
    printf("\n");
    writeBorderLine('-');
    printf("Negative tests\n");
    int negativeTests = 0;
    negativeTests += testFunctionChangeMark(10);
    negativeTests += testFunctionFindMaxStudentAtCourse(0);
    printTestClaster(negativeTests, 2);
}

void extremeTest()
{
    printf("\n");
    writeBorderLine('-');
    printf("Extreme tests\n");
    int extremeTests = 0;
    extremeTests += testFunctionAddStudent(100);
    printTestClaster(extremeTests, 1);
}

int testFunctionChangeMark(int mark)
{
    Student stud = {"Stepan", 4, 2, 13};
    double averageMark = changeMark(&stud, mark);
    char *funcAnswer = malloc(sizeof(char) * 20);
    sprintf(funcAnswer, "%.2f", averageMark);
    char *rightAnswer = malloc(sizeof(char) * 20);
    double rightDouble;
    if (mark >= 2 && mark <= 5)
    {
        rightDouble = ((4.00 * 2.00) + mark) / (3.00);
    }
    else
    {
        rightDouble = -1;
    }
    sprintf(rightAnswer, "%.2f", rightDouble);
    return testCaseDraw("changeMark", funcAnswer, rightAnswer);
}

int testFunctionIsStudentExcellent()
{
    Student stud1 = {"Stepan", 5, 1, 13};
    int isExcellent = isStudentExcellent(&stud1);
    char *funcAnswer = malloc(sizeof(char) * 20);
    sprintf(funcAnswer, "%d", isExcellent);
    char *rightAnswer = "1";
    return testCaseDraw("isStudentExcellent", funcAnswer, rightAnswer);
}

int testFunctionAddStudent(int qOfStudents)
{
    Course course = {"C++", 0, 0, 0};
    for (int i = 0; i < qOfStudents; i++)
    {
        Student stud2 = {"Someone", 4, 2, i};
        addStudent(&course, &stud2);
    }
    char *funcAnswer = malloc(sizeof(char) * 20);
    sprintf(funcAnswer, "%d", course.nomberOfMembers);
    char *rightAnswer = malloc(sizeof(char) * 20);
    sprintf(rightAnswer, "%d", qOfStudents);
    return testCaseDraw("addStudent", funcAnswer, rightAnswer);
}

int testFunctionFindMaxStudentAtCourse(int qOfStudents)
{
    Course course1 = {"C++", 0, 0, 0};
    char *rightAnswer;
    if (qOfStudents > 1)
    {
        Student stud3 = {"Stepan", 5, 1, 13};
        Student stud4 = {"Petya", 2, 1, 13};
        addStudent(&course1, &stud3);
        addStudent(&course1, &stud4);
        rightAnswer = "Stepan";
    }
    else
    {
        rightAnswer = "(null)";
    }

    Student *max = findMaxStudentAtCourse(&course1);
    char *funcAnswer = malloc(sizeof(char) * 20);
    sprintf(funcAnswer, "%s", max->name);

    return testCaseDraw("findMaxStudentAtCourse", funcAnswer, rightAnswer);
}

int testCaseDraw(char *testName, char *funcAnswer, char *rightAnswer)
{
    writeBorderLine('-');
    printf("Test for %s function\n", testName);
    printf("Right answer: %s\n", rightAnswer);
    printf("Function answer: %s\n", funcAnswer);
    if (strcmp(rightAnswer, funcAnswer) == 0)
    {
        printf("test: PASSED\n");
        return 1;
    }
    printf("test: FAILED\n");
    return 0;
}
