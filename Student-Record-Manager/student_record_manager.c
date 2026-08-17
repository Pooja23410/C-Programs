#include <stdio.h>

struct Student
{
    int id;
    char name[50];
    int age;
    char department[50];
    float marks;
};

int main()
{
    struct Student s[100];

    int count = 0;
    int choice;
    int id;
    int i, j;
    int found;

    while (1)
    {
        printf("\n===== STUDENT RECORD MANAGER =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        /* Add Student */
        if (choice == 1)
        {
            if (count >= 100)
            {
                printf("Student limit reached!\n");
            }
            else
            {
                printf("Enter Student ID: ");
                scanf("%d", &s[count].id);

                printf("Enter Name: ");
                scanf(" %[^\n]", s[count].name);

                printf("Enter Age: ");
                scanf("%d", &s[count].age);

                printf("Enter Department: ");
                scanf(" %[^\n]", s[count].department);

                printf("Enter Marks: ");
                scanf("%f", &s[count].marks);

                count++;

                printf("\nStudent added successfully!\n");
            }
        }

        /* Display Students */
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("\nNo student records found!\n");
            }
            else
            {
                printf("\n===== STUDENT RECORDS =====\n");

                for (i = 0; i < count; i++)
                {
                    printf("\nStudent %d\n", i + 1);
                    printf("ID         : %d\n", s[i].id);
                    printf("Name       : %s\n", s[i].name);
                    printf("Age        : %d\n", s[i].age);
                    printf("Department : %s\n", s[i].department);
                    printf("Marks      : %.2f\n", s[i].marks);
                }
            }
        }

        /* Search Student */
        else if (choice == 3)
        {
            printf("\nEnter Student ID to search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (s[i].id == id)
                {
                    printf("\nStudent Found!\n");
                    printf("ID         : %d\n", s[i].id);
                    printf("Name       : %s\n", s[i].name);
                    printf("Age        : %d\n", s[i].age);
                    printf("Department : %s\n", s[i].department);
                    printf("Marks      : %.2f\n", s[i].marks);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("\nStudent not found!\n");
            }
        }

        /* Update Student */
        else if (choice == 4)
        {
            printf("\nEnter Student ID to update: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (s[i].id == id)
                {
                    printf("Enter New Name: ");
                    scanf(" %[^\n]", s[i].name);

                    printf("Enter New Age: ");
                    scanf("%d", &s[i].age);

                    printf("Enter New Department: ");
                    scanf(" %[^\n]", s[i].department);

                    printf("Enter New Marks: ");
                    scanf("%f", &s[i].marks);

                    printf("\nStudent updated successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("\nStudent not found!\n");
            }
        }

        /* Delete Student */
        else if (choice == 5)
        {
            printf("\nEnter Student ID to delete: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (s[i].id == id)
                {
                    for (j = i; j < count - 1; j++)
                    {
                        s[j] = s[j + 1];
                    }

                    count--;

                    printf("\nStudent deleted successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("\nStudent not found!\n");
            }
        }

        /* Exit */
        else if (choice == 6)
        {
            printf("\nExiting Student Record Manager...\n");
            break;
        }

        else
        {
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
