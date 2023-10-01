#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 5

struct student
{
    int id;
    char name[50];
    char courses[MAX_COURSES][20];
    int numCourses;
};

int main()
{
    int n, i, j, in, sid, found = 0, min_idx;
    char course[20], name[50];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student st[MAX_STUDENTS], temp;

    // TODO: Read details of the Student into the corresponding Student variables (using for loop)
    for (i = 0; i < n; i++)
    {
        printf("Enter Student ID: ");
        // Write corresponding scan statement here
        scanf("%d", &st[i].id);
        printf("Enter Name of the Student: ");
        // Write corresponding scan statement here
        scanf("%s", st[i].name);
        printf("Enter the number of courses registered for student %s (up to %d): ", st[i].name, MAX_COURSES);
        // Write corresponding scan statement here
        scanf("%d", &st[i].numCourses);
        printf("Enter the courses registered for student %s:\n", st[i].name);
        // Write corresponding scan statement here [NOTE that a student might be registered to multiple courses, so accomodate that also here]
        for (j = 0; j < st[i].numCourses; j++)
        {
            scanf("%s", st[i].courses[j]);
        }
    }   

    while (1)
    {
        printf("\nMENU\n1. Find students registered in a course\n2. Print students in alphabetical order\n3. Find a student by ID\n4. Exit\n");
        scanf("%d", &in);

        switch (in)
        {
        case 1:
            printf("Enter a course to search: ");
            scanf("%s", course);
            printf("The students registered in the course %s are:\n", course);
            // Write a loop here to check each student's course and print the student's name if the course matches.
            for (int i = 0; i < n; i++)
            {
                // Check each student's course and print the student's name if the course matches.
                // Print only student names (each on a new line).
                // Print format : printf("%s\n", student_name) (replace student_name with the respective variable in your program).
                for (int j = 0; j < st[i].numCourses; j++)
                {
                    if (strcmp(st[i].courses[j], course) == 0)
                    {
                        printf("%s\n", st[i].name);
                    }
                }
            }
            break;

        case 2:
            // Write sorting code here.
            for (int i = 0; i < n - 1; i++)
            {
                min_idx = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (strcmp(st[j].name, st[min_idx].name) < 0)
                    {
                        min_idx = j;
                    }
                }
                temp = st[i];
                st[i] = st[min_idx];
                st[min_idx] = temp;
            }
            printf("The students in alphabetical order are:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%s\n", st[i].name);
            }
            // Write a loop here to print all student's name.
            // Print only student names (each on a new line).

            break;

        case 3:
            printf("Enter a Student ID to search: ");
            scanf("%d", &sid);
            found = 0;
            // Write a loop here to find and print the student's information based on the entered ID.
            // On the first line, print the student name.
            // After that, print each course name on a seperate line, with the format printf("%s\n", course_name)
            // (replace course_name with the respective variable in your program).
            for (int i = 0; i < n; i++)
            {
                if (st[i].id == sid)
                {
                    printf("%s\n", st[i].name);
                    for (int j = 0; j < st[i].numCourses; j++)
                    {
                        printf("%s\n", st[i].courses[j]);
                    }
                    found = 1;
                    break;
                }
            }
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid input\n");
            break;
        }
    }
}
