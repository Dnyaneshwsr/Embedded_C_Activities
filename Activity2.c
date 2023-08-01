#include <stdio.h>
#include <string.h>

typedef struct Student
{
    char a[10];
    int b;
    double c;
} Student;

// Generic swap function
void generic_swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main()
{
    int i1 = 10, i2 = 20;
    float f1 = 1.6, f2 = 8.9;
    int a1[3] = {1, 2, 3}, a2[3] = {10, 20, 30};
    Student s1 = {"Adil", 42, 5.2}, s2 = {"Bilal", 9, 3};

    // Swap two integers
    printf("Before swapping: i1 = %d, i2 = %d\n", i1, i2);
    generic_swap(&i1, &i2, sizeof(int));
    printf("After swapping: i1 = %d, i2 = %d\n", i1, i2);

    // Swap two floats
    printf("Before swapping: f1 = %.2f, f2 = %.2f\n", f1, f2);
    generic_swap(&f1, &f2, sizeof(float));
    printf("After swapping: f1 = %.2f, f2 = %.2f\n", f1, f2);

    // Swap two integer arrays
    printf("Before swapping: a1 = {%d, %d, %d}, a2 = {%d, %d, %d}\n",
           a1[0], a1[1], a1[2], a2[0], a2[1], a2[2]);
    generic_swap(a1, a2, sizeof(a1));
    printf("After swapping: a1 = {%d, %d, %d}, a2 = {%d, %d, %d}\n",
           a1[0], a1[1], a1[2], a2[0], a2[1], a2[2]);

    // Swap two Student structs
    printf("Before swapping: s1.a = %s, s1.b = %d, s1.c = %.2f\n",
           s1.a, s1.b, s1.c);
    printf("Before swapping: s2.a = %s, s2.b = %d, s2.c = %.2f\n",
           s2.a, s2.b, s2.c);
    generic_swap(&s1, &s2, sizeof(Student));
    printf("After swapping: s1.a = %s, s1.b = %d, s1.c = %.2f\n",
           s1.a, s1.b, s1.c);
    printf("After swapping: s2.a = %s, s2.b = %d, s2.c = %.2f\n",
           s2.a, s2.b, s2.c);

    return 0;
}
