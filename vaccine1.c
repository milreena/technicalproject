#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Structure to represent a user's information
struct User {
    char name[50];
    int age;
    char address[100];
    char aadhaarNumber[13]; // 12 digits + '\0' (null-terminator)
    char vaccineType[20];
    bool vaccinated;
};

const char filename[] = "vaccine_records.txt";

// Admin password (change this to a more secure method in a real system)
const char adminPassword[] = "admin123";

// Function to validate if a string contains only alphabetic characters
bool isAlphabetic(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') {
            return false;
        }
    }
    return true;
}

// Function to validate if a string contains only numeric characters
bool isNumeric(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to validate Aadhaar number
bool isValidAadhaar(const char* aadhaar) {
    int len = strlen(aadhaar);
    if (len != 12 || !isNumeric(aadhaar)) {
        return false;
    }
    return aadhaar[0] != '0' && aadhaar[0] != '1';
}

// Function to validate age
bool isValidAge(int age) {
    return age >= 0 && age <= 150;
}

// Function to create a new vaccine record
void createUser() {
    struct User user;

    while (true) {
        printf("Please enter your name: ");
        scanf(" %[^\n]s", user.name);

        if (!isAlphabetic(user.name)) {
            printf("Invalid name. Please enter a valid name with alphabetic characters only.\n");
        } else {
            break;
        }
    }

    while (true) {
        printf("Please enter your age: ");
        if (scanf("%d", &user.age) != 1 || !isValidAge(user.age)) {
            printf("Invalid age. Please enter a valid age between 0 and 150.\n");
            while (getchar() != '\n');  // Clear input buffer
        } else {
            break;
        }
    }

    printf("Please enter your address: ");
    scanf(" %[^\n]s", user.address);

    while (true) {
        printf("Please enter your Aadhaar number (12 digits): ");
        scanf(" %12s", user.aadhaarNumber);

        if (!isValidAadhaar(user.aadhaarNumber)) {
            printf("Invalid Aadhaar number. Please enter a valid 12-digit Aadhaar number that does not start with '0' or '1'.\n");
        } else {
            break;
        }
    }

    while (true) {
        printf("Please select a vaccine type (e.g., Pfizer, Moderna, J&J): ");
        scanf(" %19s", user.vaccineType);

        if (!isAlphabetic(user.vaccineType)) {
            printf("Invalid vaccine type. Please enter a valid vaccine type with alphabetic characters only.\n");
        } else {
            break;
        }
    }

    user.vaccinated = false;

    // Open the file in append mode
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Write the user's data to the file
    fprintf(file, "%s %d %s %s %s %d\n", user.name, user.age, user.address, user.aadhaarNumber, user.vaccineType, user.vaccinated);

    fclose(file);

    printf("Registration successful! Thank you for registering for the vaccine.\n");
}

// Function to read and display all vaccine records
void readRecords() {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    struct User user;

    printf("Vaccine Records:\n");
    printf("Name\tAge\tAddress\t\tAadhaar\t\tVaccine Type\tVaccinated\n");
    printf("--------------------------------------------------------------\n");

    while (fscanf(file, "%s %d %s %s %s %d", user.name, &user.age, user.address, user.aadhaarNumber, user.vaccineType, &user.vaccinated) != EOF) {
        printf("%s\t%d\t%s\t%s\t%s\t%d\n", user.name, user.age, user.address, user.aadhaarNumber, user.vaccineType, user.vaccinated ? "Yes" : "No");
    }

    fclose(file);
}

// Function to update the vaccine status
void updateUser() {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char searchAadhaar[13];
    printf("Enter your Aadhaar number: ");
    scanf(" %12s", searchAadhaar);

    struct User user;
    bool found = false;

    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening the file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%s %d %s %s %s %d", user.name, &user.age, user.address, user.aadhaarNumber, user.vaccineType, &user.vaccinated) != EOF) {
        if (strcmp(searchAadhaar, user.aadhaarNumber) == 0) {
            printf("Your vaccine status is currently %s.\n", user.vaccinated ? "Vaccinated" : "Not Vaccinated");
            printf("Change vaccine status (1 for vaccinated, 0 for not vaccinated): ");
            scanf("%d", &user.vaccinated);
            found = true;
        }
        fprintf(tempFile, "%s %d %s %s %s %d\n", user.name, user.age, user.address, user.aadhaarNumber, user.vaccineType, user.vaccinated);
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);

    if (!found) {
        printf("Aadhaar number not found in records.\n");
    } else {
        printf("Vaccine status updated successfully.\n");
    }
}

// Function to delete a vaccine record
void deleteUser() {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char searchAadhaar[13];
    printf("Enter your Aadhaar number to delete the record: ");
    scanf(" %12s", searchAadhaar);

    struct User user;
    bool found = false;

    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening the file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%s %d %s %s %s %d", user.name, &user.age, user.address, user.aadhaarNumber, user.vaccineType, &user.vaccinated) != EOF) {
        if (strcmp(searchAadhaar, user.aadhaarNumber) == 0) {
            printf("Your record has been deleted.\n");
            found = true;
        } else {
            fprintf(tempFile, "%s %d %s %s %s %d\n", user.name, user.age, user.address, user.aadhaarNumber, user.vaccineType, user.vaccinated);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);

    if (!found) {
        printf("Aadhaar number not found in records.\n");
    }
}

// Admin authentication
bool adminLogin() {
    char password[20];
    printf("Enter admin password: ");
    scanf(" %19s", password);

    return strcmp(password, adminPassword) == 0;
}

// Admin interface
void adminInterface() {
    if (!adminLogin()) {
        printf("Incorrect admin password. Access denied.\n");
        return;
    }

    int choice;
    while (true) {
        printf("\nAdmin Menu:\n");
        printf("1. View all vaccine records\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readRecords();
                break;
            case 2:
                printf("Exiting admin mode.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// User interface
void userInterface() {
    int choice;

    printf("Welcome to the Vaccine Registration System\n");

    while (true) {
        printf("\nUser Menu:\n");
        printf("1. Register for the vaccine\n");
        printf("2. Check vaccine status\n");
        printf("3. Delete your record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                updateUser();
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    int userType;

    printf("Vaccine Registration System\n");
    printf("Choose User Type:\n");
    printf("1. User\n");
    printf("2. Admin\n");
    printf("Enter your choice: ");
    scanf("%d", &userType);

    switch (userType) {
        case 1:
            userInterface();
            break;
        case 2:
            adminInterface();
            break;
        default:
            printf("Invalid user type. Exiting the system.\n");
    }

    return 0;
}
