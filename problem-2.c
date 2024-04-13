//problem: Write a program in c that will accepts the student names and scores and sort them based on their scores.

#include <stdio.h>

typedef struct {
    char name[50];
    int score;
} Student;

void swap(Student* xp, Student* yp)
{
    Student temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Student arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].score < arr[j + 1].score) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printStudents(Student arr[], int size)
{
    printf("+----------------------+-------+\n");
    printf("|       Name           | Score |\n");
    printf("+----------------------+-------+\n");
    for (int i = 0; i < size; i++) {
        printf("| %-20s | %-5d |\n", arr[i].name, arr[i].score);
    }
    printf("+----------------------+-------+\n");
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter score of student %d: ", i + 1);
        scanf("%d", &students[i].score);
    }

    printf("\nStudents before sorting:\n");
    printStudents(students, n);

    bubbleSort(students, n);

    printf("\nStudents after sorting by score (descending order):\n");
    printStudents(students, n);

    return 0;
}
