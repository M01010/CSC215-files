#include <stdio.h>
#include "student.h"
void displayCourse(course c) {
    printf("course: %s, number: %d\n", c.title, c.course_number);
}
void displayStudent(student s) {
    printf("name: %s, id: %d, GPA: %f\n", s.name, s.id, s.GPA);
}
void addStudentToCourse(student s, course *c) {
    if (c->num_students >= MAX_STUDENTS)
    {
        printf("students full, couldnt add");
        return;
    }
    c->students[c->num_students] = s;
    c->num_students++;
}
void withdrawStudent(course *c, int studentId) {
    int i = 0;
    for (i = 0; i < c->num_students; i++)
    {
        if (c->students[i].id == studentId)
        {
            c->students[i] = c->students[c->num_students - 1];
            c->num_students--;
            return;
        }
    }
}
void displayStudentsInCourse(course c) {
    printf("students in course %s:\n", c.title);
    int i = 0;
    for (i = 0; i < c.num_students; i++)
    {
        displayStudent(c.students[i]);
    }
    printf("\n");
}
void displaySchedule(course courses[], int numCourses, int studentId) {
    printf("schedule of student with id: %d\n", studentId);
    int i = 0;
    for (i = 0; i < numCourses; i++)
    {
        int j;
        for (j = 0; j < courses[i].num_students; j++)
        {
            if (courses[i].students[j].id == studentId)
            {
                displayCourse(courses[i]);
            }   
        }
    }
}
course findCourseWithMostStudents(course courses[], int numCourses) {
    int i = 0;
    int max_index = 0;
    for (i = 1; i < numCourses; i++)
    {
        if (courses[i].num_students > courses[max_index].num_students)
        {
            max_index = i;
        }
        
    }
    return courses[max_index];
}
int searchCourse(course courses[], int num, int id) {
    int i;
    for (i = 0; i < num; i++)
    {
        if (courses[i].course_number == id)
        {
            return i;
        }
    }
    return -1;
}
