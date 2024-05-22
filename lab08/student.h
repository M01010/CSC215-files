#define MAX_STUDENTS 50
typedef struct
{
    int id;
    char name[50];
    float GPA;
} student;
typedef struct
{
    int course_number;
    char title[50];
    student students[MAX_STUDENTS];
    int num_students;
} course;
void displayCourse(course c);
void addStudentToCourse(student s, course *c);
void withdrawStudent(course *c, int studentId);
void displayStudentsInCourse(course c);
void displaySchedule(course courses[], int numCourses, int studentId);
course findCourseWithMostStudents(course courses[], int numCourses);
int searchCourse(course courses[], int num, int id);
