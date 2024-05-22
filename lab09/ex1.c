#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM_OF_STUDENTS 3
struct Student
{
    int Id;
    char Name[50];
    float GPA;
};

void save()
{
    struct Student students[MAX_NUM_OF_STUDENTS];
    FILE *fp;
    int i;
    fp = fopen("students.dat", "wb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    printf("Enter the details: \n");
    for (i = 0; i < MAX_NUM_OF_STUDENTS; i++)
    {
        printf("Enter student ID or -1 to exit: ");
        scanf("%d", &students[i].Id);
        if (students[i].Id == -1)
            break;
        printf("Enter student name: ");
        scanf("%s", students[i].Name);
        printf("Enter student GPA: ");
        scanf("%f", &students[i].GPA);
        fwrite(&students[i], sizeof(students[i]), 1, fp);
        printf("-------------------------\n");
    }
    fclose(fp);
    return;
}
void read()
{
    struct Student student;
    FILE *fp;
    fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    printf("The details of the students are: \n");
    while (fread(&student, sizeof(student), 1, fp) >= 1)
    {
        printf("ID: %d, Name: %s, GPA: %.2f\n",
               student.Id, student.Name, student.GPA);
    }
    return;
}
int main()
{
    read();
    return 0;
}