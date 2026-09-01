#include <stdio.h>

struct Book
{
    int id;
    char title[100];
    char author[50];
    int year;
    int available;
};

int main()
{
    struct Book books[100];

    int count = 0;
    int choice;
    int id;
    int i, j;
    int found;

    while (1)
    {
        printf("\n===== E-LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Update Book\n");
        printf("7. Delete Book\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        /* Add Book */
        if (choice == 1)
        {
            if (count >= 100)
            {
                printf("\nLibrary storage is full!\n");
            }
            else
            {
                printf("\nEnter Book ID: ");
                scanf("%d", &books[count].id);

                printf("Enter Book Title: ");
                scanf(" %[^\n]", books[count].title);

                printf("Enter Author Name: ");
                scanf(" %[^\n]", books[count].author);

                printf("Enter Publication Year: ");
                scanf("%d", &books[count].year);

                books[count].available = 1;

                count++;

                printf("\nBook added successfully!\n");
            }
        }

        /* Display Books */
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("\nNo books available in the library!\n");
            }
            else
            {
                printf("\n===== LIBRARY BOOKS =====\n");

                for (i = 0; i < count; i++)
                {
                    printf("\nBook %d\n", i + 1);
                    printf("ID        : %d\n", books[i].id);
                    printf("Title     : %s\n", books[i].title);
                    printf("Author    : %s\n", books[i].author);
                    printf("Year      : %d\n", books[i].year);

                    if (books[i].available == 1)
                    {
                        printf("Status    : Available\n");
                    }
                    else
                    {
                        printf("Status    : Borrowed\n");
                    }
                }
            }
        }

        /* Search Book */
        else if (choice == 3)
        {
            printf("\nEnter Book ID to search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    printf("\nBook Found!\n");
                    printf("-----------------------------\n");
                    printf("ID        : %d\n", books[i].id);
                    printf("Title     : %s\n", books[i].title);
                    printf("Author    : %s\n", books[i].author);
                    printf("Year      : %d\n", books[i].year);

                    if (books[i].available == 1)
                    {
                        printf("Status    : Available\n");
                    }
                    else
                    {
                        printf("Status    : Borrowed\n");
                    }

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("\nBook not found!\n");
            }
        }

        /* Borrow Book */
        else if (choice == 4)
        {
            printf("\nEnter Book ID to borrow: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    found = 1;

                    if (books[i].available == 1)
                    {
                        books[i].available = 0;
                        printf("\nBook borrowed successfully!\n");
                    }
                    else
                    {
                        printf("\nBook is already borrowed!\n");
                    }

                    break;
                }
            }

            if (found == 0)
            {
                printf("\nBook not found!\n");
            }
        }

        /* Return Book */
        else if (choice == 5)
        {
            printf("\nEnter Book ID to return: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    found = 1;

                    if (books[i].available == 0)
                    {
                        books[i].available = 1;
                        printf("\nBook returned successfully!\n");
                    }
                    else
                    {
                        printf("\nBook is already available!\n");
                    }

                    break;
                }
            }

            if (found == 0)
            {
                printf("\nBook not found!\n");
            }
        }

        /* Update Book */
        else if (choice == 6)
        {
            printf("\nEnter Book ID to update: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    printf("\nEnter New Book Title: ");
                    scanf(" %[^\n]", books[i].title);

                    printf("Enter New Author Name: ");
                    scanf(" %[^\n]", books[i].author);

                    printf("Enter New Publication Year: ");
                    scanf("%d", &books[i].year);

                    printf("\nBook updated successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("\nBook not found!\n");
            }
        }

        /* Delete Book */
        else if (choice == 7)
        {
            printf("\nEnter Book ID to delete: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    for (j = i; j < count - 1; j++)
                    {
                        books[j] = books[j + 1];
                    }

                    count--;

                    printf("\nBook deleted successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("\nBook not found!\n");
            }
        }

        /* Exit */
        else if (choice == 8)
        {
            printf("\nExiting E-Library Management System...\n");
            break;
        }

        else
        {
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
