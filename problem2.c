// // Write a program that use a structure to hold information about movies, such as title,
// genre, director, release year, and rating. Write a program that allows users to add new
// movies, search for movies by genre, and display all movie details.
#include<stdio.h>
#include<string.h>
#define MAX_MOVIES 100
typedef struct
{
    char title[30];
    char genre[30];
    char director[30];
    int release_year;
    float rating;
}Movie;
void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full! Cannot add more movies.\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); // Clear the buffer
    fgets(movies[*count].title, sizeof(movies[*count].title), stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0';

    printf("Enter movie genre: ");
    fgets(movies[*count].genre, sizeof(movies[*count].genre), stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = '\0';

    printf("Enter movie director: ");
    fgets(movies[*count].director, sizeof(movies[*count].director), stdin);
    movies[*count].director[strcspn(movies[*count].director, "\n")] = '\0';

    printf("Enter release year: ");
    scanf("%d", &movies[*count].release_year);

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies in the list.\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].release_year);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("-------------------------\n");
    }
}

void searchByGenre(Movie movies[], int count, const char *genre) {
    int found = 0;
    printf("\n--- Movies in Genre: %s ---\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].genre, genre) == 0) {
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].release_year);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("-------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found in the genre '%s'.\n", genre);
    }
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;
    char genre[50];

    while (1) {
       
        printf("\n--- Movie Management System ---\n");
        printf("1. Add New Movie\n");
        printf("2. Display All Movies\n");
        printf("3. Search Movies by Genre\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;

            case 2:
                displayMovies(movies, count);
                break;

            case 3:
                printf("Enter genre to search: ");
                getchar(); 
                fgets(genre, sizeof(genre), stdin);
                genre[strcspn(genre, "\n")] = '\0';
                searchByGenre(movies, count, genre);
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}