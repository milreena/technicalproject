#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int choice;

struct ReportData {
    char title[100];
    char content[1000];
};

struct Center {
    char centerName[100];
    int availableStock;
    char location[100];  // Add location field
    char contactPerson[100];  // Add contact person's name
    char contactNumber[15];  // Add contact person's number
    // Add any other center details you need
};

struct Appointment {
    char aadhaarNumber[20];
    char date[20];
    char time[10];
    int confirmed;
};

struct PersonalInformation {
    char name[100];
    char aadhaarNumber[20];
};

struct ContactDetails {
    char email[100];
    char phone[15];
};

struct MedicalHistory {
    char conditions[200];
    char medications[200];
};

struct PreferredCenter {
    char centerName[100];
};
// Main menu
int main() {
    struct PersonalInformation personalInfo;
    struct ContactDetails contactDetails;
    struct MedicalHistory medicalHistory;
    struct PreferredCenter preferredCenter;

    int choice;

    do {
        printf("\n1. Register\n");
        printf("2. Apointment\n");
        printf("3. admin dashboard\n");
         printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registrationForm(&personalInfo, &contactDetails, &medicalHistory, &preferredCenter);
                break;
            case 2:
                    

    do {
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2: {
                char date[20];
                printf("Enter date to view appointments (dd-mm-yyyy): ");
                scanf("%s", date);
                viewAppointmentsByDate(date);
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (1);
            case 3:
                 adminDashboard();
                 break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (1);

    return 0;
}




// Function to display registration form and gather personal information
void registrationForm() {

   struct PersonalInformation  personalInfo;
 struct ContactDetails contactDetails;
 struct MedicalHistory medicalHistory;
 struct PreferredCenter  preferredCenter;
    printf("Registration Form:\n");

    printf("1. Personal Information\n");
    printf("Name: ");
    scanf(" %s", personalInfo.name);
    printf("Aadhaar Number: ");
    scanf(" %s", personalInfo.aadhaarNumber);
   

    printf("\n2. Contact Details\n");
    printf("Email: ");
    scanf(" %[^\n]", contactDetails.email);
    printf("Phone: ");
    scanf(" %[^\n]", contactDetails.phone);

    printf("\n3. Medical History\n");
    printf("Existing Medical Conditions: ");
    scanf(" %[^\n]", medicalHistory.conditions);
    printf("Current Medications: ");
    scanf(" %[^\n]", medicalHistory.medications);

    printf("\n4. Preferred Vaccination Center\n");
    printf("Center Name: ");
    scanf(" %[^\n]", preferredCenter.centerName);
    
    FILE *file = fopen("registrations.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
     fprintf(file, "registered\nname:%s\n,Aadhar:%s\n",personalInfo.name, personalInfo.aadhaarNumber);

    fclose(file);

    printf("\nRegistration Successful!\n");
}

void scheduleAppointment() {
    struct Appointment appointment;

    printf("Enter your Aadhaar number: ");
    scanf("%s", appointment.aadhaarNumber);
    
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", appointment.date);

    printf("Enter time slot (hh:mm): ");
    scanf("%s", appointment.time);

    appointment.confirmed = 0; // Not confirmed initially

    // Save appointment data to file using file handling
    FILE *file = fopen("appointments.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "aadhar no.:%s\n,date:%s\n,time:%s\n,confirmed:%d\n",
            appointment.aadhaarNumber, appointment.date,
            appointment.time, appointment.confirmed);

    fclose(file);

    printf("Appointment scheduled successfully!\n");
}

// Function to display appointments for a given date
void viewAppointmentsByDate(const char *date) {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Appointments for %s:\n", date);

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char storedDate[20];
        sscanf(line, "%*[^|]|%[^|]", storedDate);
        if (strcmp(storedDate, date) == 0) {
            printf("%s", line);
        }
    }

    fclose(file);
}
void manageCenters() {
    int numCenters;
    printf("Enter the number of centers: ");
    scanf("%d", &numCenters);

    FILE *file = fopen("centers.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < numCenters; i++) {
        struct Center center;

        printf("Enter center details:\n");
        printf("Center Name: ");
        scanf("%s", center.centerName);

        printf("Available Stock: ");
        scanf("%d", &center.availableStock);

        // Collect and store other center details
        printf("Location: ");
        scanf("%s", center.location);

        printf("Contact Person: ");
        scanf("%s", center.contactPerson);

        printf("Contact Number: ");
        scanf("%s", center.contactNumber);

        // Write center details to the file
        fprintf(file, "%s %d %s %s %s\n",
                center.centerName, center.availableStock,
                center.location, center.contactPerson, center.contactNumber);
    }

    fclose(file);
    printf("Centers information updated.\n");
}
void monitorRegistrations() {
    FILE *file = fopen("registrations.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Registered People:\n");
    //printf("Name\tAadhaar Number\n");
    
    struct PersonalInformation personalInfo;
    while (fscanf(file, "%s %s", personalInfo.name, personalInfo.aadhaarNumber) != EOF) {
        printf("%s\t%s\n",  personalInfo.name,  personalInfo.aadhaarNumber);
    }

    fclose(file);
}
void viewStock() {
    FILE *file = fopen("centers.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Center\tAvailable Stock\n");
    char centerName[100];
    int stock;
    while (fscanf(file, "%s %d", centerName, &stock) != EOF) {
        printf("%s\t%d\n", centerName, stock);
    }

    fclose(file);
}

void generateGeneralReport(const char *reportTitle, const char *reportContent) {
    struct ReportData report;
    strcpy(report.title, reportTitle);
    strcpy(report.content, reportContent);

    // Generate a unique file name for the report
    char fileName[100];
    snprintf(fileName, sizeof(fileName), "report_%ld.txt", time(NULL));

    // Create and write the report to a file
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error creating report file!\n");
        return;
    }

    fprintf(file, "Report Title: %s\n\n", report.title);
    fprintf(file, "Report Content:\n%s\n", report.content);

    fclose(file);

    printf("Report generated successfully: %s\n", fileName);
}

void adminDashboard() {
    int choice;

    do {
        printf("Admin Dashboard\n");
        printf("1. Monitor Registrations\n");
        printf("2. View Stock\n");
        printf("3. Manage Centers\n");
        printf("4. Generate General Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                monitorRegistrations();
                break;
            case 2:
                viewStock();
                break;
            case 3:
                manageCenters();
                break;
            case 4:
                generateGeneralReport("Monthly Vaccination Data", "Total vaccinations: 1500\nVaccination centers: 5");

                break;
            case 5:
                printf("Exiting admin dashboard.\n");
                return;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (1);
}


