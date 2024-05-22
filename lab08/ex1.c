#include <stdio.h>
#include "student.h"
int askCourseIndex(course courses[], int num) {
    printf("course id: ");
    int cid;
    scanf("%d", &cid);
    int i = searchCourse(courses, num, cid);
    return i;
}
int main() {
    int i;
    course a = {215, "csc215", {}, 0};
    course b = {212, "csc212", {}, 0};
    course c = {281, "csc281", {}, 0};
    course courses[3] = {a, b, c};
    do
    {
        printf("1: add student\n");
        printf("2: remove student\n");
        printf("3: display students\n");
        printf("4: display student schedule\n");
        printf("5: find the course with the most students\n");
        printf("6: exit\n");
        printf("enter your choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
        {
            int index = askCourseIndex(courses, 3);
            if (index == -1)
            {
                printf("no course with that id\n");
            }
            else {              
                student s;
                printf("id: ");
                scanf("%d", &(s.id));
                printf("name: ");
                scanf("%s", s.name);
                printf("gpa: ");
                scanf("%f", &(s.GPA));
                addStudentToCourse(s, courses + index);
            }
            break;
        }
        case 2:
        {
            int index = askCourseIndex(courses, 3);
            if (index == -1)
            {
                printf("no course with that id\n");
            }
            else {
                printf("student id: ");
                int id;
                scanf("%d", &id);
                withdrawStudent(courses + index, id);
            }
            break;
        }
        case 3:
            int index = askCourseIndex(courses, 3);
            if (index == -1)
            {
                printf("no course with that id\n");
            }
            else {
                displayStudentsInCourse(courses[index]);
            }
            break;
        case 4:
            printf("id: ");
            int sid;
            scanf("%d", &sid);
            displaySchedule(courses, 3, sid);
            break;
        case 5:
            course m = findCourseWithMostStudents(courses, 3);
            printf("course with the most students: %s number: %d, has %d students\n\n", m.title, m.course_number, m.num_students);
            break;
        case 6:
            printf("goodbye\n");
            break;
        default:
            printf("unknown option\n");
            break;
        }
    } while (i != 6);
    return 0;
}