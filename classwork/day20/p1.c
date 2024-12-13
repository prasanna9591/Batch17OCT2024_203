#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_LENGTH 100

// Structure to store book details
typedef struct 
{
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    char genre[MAX_LENGTH];
} Book;

// Comparator function for sorting by genre
int compare(const void *a, const void *b) 
{
    Book *bookA = (Book *)a;
    Book *bookB = (Book *)b;
    return strcmp(bookA->genre, bookB->genre);
}

int main() 
{
    int N, i;
    Book books[MAX_BOOKS];

    // Read the number of books
    scanf("%d", &N);
    getchar(); // Consume the newline character after the number

    // Read the book details
    for (i = 0; i < N; i++) 
    {
        scanf("%[^,],%[^,],%[^\n]", books[i].title, books[i].author, books[i].genre);
        getchar(); // Consume the newline character after each line
    }

    // Sort the books by genre
    qsort(books, N, sizeof(Book), compare);

    // Print the titles of the books in the sorted order
    for (i = 0; i < N; i++) 
    {
        printf("%s\n", books[i].title);
    }

    return 0;
}

