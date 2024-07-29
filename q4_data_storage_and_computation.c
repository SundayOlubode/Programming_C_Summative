#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 100
#define MAX_STUDENTS 100

/**
 * struct Student - Structure to represent a student
 * @full_name: The student's full name
 * @grade_C: Grade for Programming in C
 * @grade_MAD: Grade for Mobile Application Development
 * @grade_Comm: Grade for Communications
 */
typedef struct Student
{
    char full_name[MAX_NAME_LEN];
    int grade_C;
    int grade_MAD;
    int grade_Comm;
} Student;

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    int n, i;
    Student students[MAX_STUDENTS];
    FILE *file;

    printf("Enter the number of students (between 6 and 99): ");
    scanf("%d", &n);

    if (n <= 5 || n >= 100)
    {
        printf("Invalid number of students. Program will exit.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter full name of student %d: ", i + 1);
        getchar(); // Consume newline character left by previous scanf
        fgets(students[i].full_name, MAX_NAME_LEN, stdin);

        printf("Enter grade for Programming in C: ");
        scanf("%d", &students[i].grade_C);

        printf("Enter grade for Mobile Application Development: ");
        scanf("%d", &students[i].grade_MAD);

        printf("Enter grade for Communications: ");
        scanf("%d", &students[i].grade_Comm);
    }

    file = fopen("students_grades.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(file, "%s %d %d %d\n",
                students[i].full_name,
                students[i].grade_C,
                students[i].grade_MAD,
                students[i].grade_Comm);
    }

    fclose(file);
    printf("Student grades have been recorded successfully.\n");

    return 0;
}

