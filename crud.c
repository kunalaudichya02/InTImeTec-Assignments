#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char first_name[100];
    char last_name[100];
    int age;
} UserData;

//function to create a new user
void createNewUser() { 
    UserData user;
    int id, exists = 0;

    FILE *file = fopen("user_data.txt", "r");

    printf("Please enter User ID: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %d", &user.id, user.first_name, user.last_name, &user.age) != EOF) {
        if (user.id == id) {
            exists = 1;
            printf("User ID already taken. Please try another one\n");
            break;
        }
    }

    if (exists) {
        fclose(file);
        return;
    }
    fclose(file);

    file = fopen("user_data.txt", "a");
    if (file == NULL) {
        printf("Unable to open the file\n");
        return;
    }

    user.id = id;
    getchar(); 


    printf("Enter First Name: ");
    fgets(user.first_name, 100, stdin);
    user.first_name[strcspn(user.first_name, "\n")] = '\0';

    printf("Enter Last Name: ");
    fgets(user.last_name, 100, stdin);
    user.last_name[strcspn(user.last_name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &user.age);



    fprintf(file, "%d %s %s %d\n", user.id, user.first_name, user.last_name, user.age);
    fclose(file);
    printf("the user is successfully added\n");
}

//function to display all the users in the text file
void displayAllUsers() {
    FILE *file = fopen("user_data.txt", "r");
    UserData user;

    printf("\n--- User List ---\n");

    while (fscanf(file, "%d %s %s %d", &user.id, user.first_name, user.last_name, &user.age) != EOF) {
        printf("{\n");
        printf("    User ID: %d\n", user.id);
        printf("    Name: %s %s\n", user.first_name, user.last_name);
        printf("    Age: %d\n", user.age);
        printf("}\n");
    }

    fclose(file);
}

//function to update users using their specific id
void updateUser() {
    int id, exists = 0;
    UserData user;
    FILE *file = fopen("user_data.txt", "r");
    FILE *temp_file = fopen("temp_file.txt", "w");

    printf("Enter User ID to modify: ");
    scanf("%d", &id);
    getchar();

    while (fscanf(file, "%d %s %s %d", &user.id, user.first_name, user.last_name, &user.age) != EOF) {
        if (user.id == id) {
            exists = 1;
            printf("Enter new First Name: ");
            fgets(user.first_name, 100, stdin);
            user.first_name[strcspn(user.first_name, "\n")] = '\0';

            printf("Enter new Last Name: ");
            fgets(user.last_name, 100, stdin);
            user.last_name[strcspn(user.last_name, "\n")] = '\0';

            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp_file, "%d %s %s %d\n", user.id, user.first_name, user.last_name, user.age);
    }

    fclose(file);
    fclose(temp_file);

    if (exists) {
        remove("user_data.txt");
        rename("temp_file.txt", "user_data.txt");
        printf("User updated successfully.\n");
    } else {
        remove("temp_file.txt");
        printf("No user exists with ID %d.\n", id);
    }
}

//function to remove user using their specific id
void removeUser() {
    int id, exists = 0;
    UserData user;
    FILE *file = fopen("user_data.txt", "r");
    FILE *temp_file = fopen("temp_file.txt", "w");

    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %d", &user.id, user.first_name, user.last_name, &user.age) != EOF) {
        if (user.id == id) {
            exists = 1;
            continue;
        }
        fprintf(temp_file, "%d %s %s %d\n", user.id, user.first_name, user.last_name, user.age); 
    }

    fclose(file);
    fclose(temp_file);

    if (exists) {
        remove("user_data.txt");
        rename("temp_file.txt", "user_data.txt");
        printf("User successfully deleted.\n");
    } else {
        remove("temp_file.txt");
        printf("No user exists with ID %d.\n", id);
    }
}

int main() {
    FILE *file = fopen("user_data.txt", "r");
    if (file == NULL) {
        file = fopen("user_data.txt", "a");
        printf("File created successfully.\n");
    }
    fclose(file);

    int choice;

  

    while (choice != 5) {

            printf("\n--- User Management Menu ---\n");
            printf("1. Add a New User\n");
            printf("2. View All Users\n");
            printf("3. Edit User Details\n");
            printf("4. Remove a User\n");
            printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createNewUser();
                break;
            case 2:
                displayAllUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                removeUser();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
