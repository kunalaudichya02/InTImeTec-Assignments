#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int age;
} UserData;

//function to create a new user
void createNewUser() { 
    UserData user;
    int id, exists = 0;

    FILE *file = fopen("user_data.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open the file for reading\n");
        return;
    }

    printf("Please enter User ID: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF) {
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


    printf("Enter name: ");
    fgets(user.name, 100, stdin);
    for(int i=0; user.name[i] != '\0'; i++){
        if(user.name[i] == '\n'){
            user.name[i] == '\0';
            break;
        }
    }


    int validAge = 0;
    while(!validAge){
        printf("Enter Age: ");
        if(scanf("%d", &user.age) != 1){
            printf("Invalid input. Please enter a valid integer.\n");
            while(getchar()!= '\n');
        }
        else{
             if (user.age < 0) {
                 printf("Age cannot be negative. Please enter a valid age.\n");
           } else if (user.age > 120) {
                 printf("Age seems too high. Please enter a realistic age.\n");
           } else {
                 validAge = 1; 
           }
        }
    }



    fprintf(file, "%d\t%s\t%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("the user is successfully added\n");
}

//function to display all the users in the text file
void displayAllUsers() {
    FILE *file = fopen("user_data.txt", "r");
     if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    UserData user;
    int foundUser = 0;
    printf("\n--- User List ---\n");

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF) {
        foundUser = 1;
        printf("{\n");
        printf("    User ID: %d\n", user.id);
        printf("    Name: %s \n", user.name);
        printf("    Age: %d\n", user.age);
        printf("}\n");
    }

    if(!foundUser){
        printf("No user found  \n");
    }
    fclose(file);
}

//function to update users using their specific id
void updateUser() {
    int id, exists = 0;
    UserData user;
    FILE *file = fopen("user_data.txt", "r");
    FILE *temp_file = fopen("temp_file.txt", "w");

    if (file == NULL || temp_file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter User ID to modify: ");
    scanf("%d", &id);
    getchar();

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            exists = 1;
            printf("User ID found. Please enter the new details:\n");
            printf("Enter new name: ");
            fgets(user.name, 100, stdin);
             for(int i=0; user.name[i] != '\0'; i++){
                if(user.name[i] == '\n'){
                user.name[i] == '\0';
                break;
              }
              }

            int validAge=0;
            while(!validAge){
                printf("Enter new age: ");
                if(scanf("%d", &user.age) != 1){
                    printf("Invalid input. Please enter a valid integer.\n");
                    while(getchar()!= '\n');
                }
                 else
                {
                    if (user.age < 0) {
                        printf("Age cannot be negative. Please enter a valid age.\n");
                    } else if (user.age > 120) {
                        printf("Age seems too high. Please enter a realistic age.\n");
                    } else {
                        validAge = 1; 
                    }
                }
                }

        }
        fprintf(temp_file, "%d\t%s\t%d\n", user.id, user.name, user.age);
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

     if (file == NULL || temp_file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %[^\t\n] %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            exists = 1;
            continue;
        }
        fprintf(temp_file, "%d\t%s\t%d\n", user.id, user.name, user.age); 
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

    int choice=0;
    while (choice != 5) {
            printf("\n--- User Management Menu ---\n");
            printf("1. Add a New User\n");
            printf("2. View All Users\n");
            printf("3. Edit User Details\n");
            printf("4. Remove a User\n");
            printf("5. Exit\n");
            

        int validChoice=0;
        if(!validChoice){
            printf("Please enter your choice: ");
            if(scanf("%d", &choice) != 1){
                printf("Invalid input. Please enter a valid integer ");
                while(getchar()!= '\n');
                continue;
            }
            else{
                validChoice = 1;
            }
        }

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
