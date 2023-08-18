#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int choice;

struct Profile {
    char name[50];
    char aadhaar[15];
    char appointment[50];
    char medicalReport[100];
};

struct VaccineInfo {
    int id;
    char name[50];
    char manufacturer[50];
    int dosesRequired;
};

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
    int isCancelled;
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
    struct VaccineInfo vaccine;

    int choice;

    do {
        printf("\n1. Register\n");
        printf("2. Apointment\n");
        printf("3. admin dashboard\n");
        printf("4. vaccine info\n");
        printf("5. manage appointment\n");
         printf("6. profile management\n");
          printf("7. Exit\n");
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
                vaccinemain();
                break;
            case 5:
                    manageappointment();
                    break;

            case 6:
                    profileMenu();
                    break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (1);

    return 0;
}

// registeration
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
    
     fprintf(file, "registered\nname:%s\n,Aadhar:%s\n,email:%s\n,phone:%s\n,condition:%s\n,medication:%s\n",personalInfo.name, personalInfo.aadhaarNumber,contactDetails.email,contactDetails.phone,medicalHistory.conditions,medicalHistory.medications);

    fclose(file);

    printf("\nRegistration Successful!\n");
}

//Appointment
void scheduleAppointment() {
    struct Appointment appointment;

    printf("Enter your Aadhaar number: ");
    scanf("%s", appointment.aadhaarNumber);
    
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", appointment.date);

    printf("Enter time slot (hh:mm): ");
    scanf("%s", appointment.time);

    appointment.confirmed = 0;
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


//dashboard
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

//vaccine info
void addVaccineInfo(FILE *file) {
    struct VaccineInfo vaccine;
    
    printf("Enter Vaccine ID: ");
    scanf("%d", &vaccine.id);
    printf("Enter Vaccine Name: ");
    scanf("%s", vaccine.name);
    printf("Enter Manufacturer: ");
    scanf("%s", vaccine.manufacturer);
    printf("Enter Doses Required: ");
    scanf("%d", &vaccine.dosesRequired);
    
    fseek(file, 0, SEEK_END);
    fwrite(&vaccine, sizeof(struct VaccineInfo), 1, file);
    
    printf("Vaccine information added successfully.\n");
}
void viewVaccineInfo(FILE *file) {
    struct VaccineInfo vaccine;
    
    printf("\nVaccine Information:\n");
    
    fseek(file, 0, SEEK_SET);
    
    while (fread(&vaccine, sizeof(struct VaccineInfo), 1, file)) {
        printf("ID: %d\n", vaccine.id);
        printf("Name: %s\n", vaccine.name);
        printf("Manufacturer: %s\n", vaccine.manufacturer);
        printf("Doses Required: %d\n", vaccine.dosesRequired);
        printf("---------------\n");
    }
}
void editVaccineInfo(FILE *file, int id) {
    struct VaccineInfo vaccine;
    
    fseek(file, 0, SEEK_SET);
    
    while (fread(&vaccine, sizeof(struct VaccineInfo), 1, file)) {
        if (vaccine.id == id) {
            printf("Enter updated Vaccine Name: ");
            scanf("%s", vaccine.name);
            printf("Enter updated Manufacturer: ");
            scanf("%s", vaccine.manufacturer);
            printf("Enter updated Doses Required: ");
            scanf("%d", &vaccine.dosesRequired);
            
            fseek(file, -sizeof(struct VaccineInfo), SEEK_CUR);
            fwrite(&vaccine, sizeof(struct VaccineInfo), 1, file);
            
            printf("Vaccine information updated successfully.\n");
            return;
        }
    }
    
    printf("Vaccine ID not found.\n");
}
void deleteVaccineInfo(FILE *file, int id) {
    struct VaccineInfo vaccine;
    FILE *tempFile = fopen("temp.txt", "w");
    
    fseek(file, 0, SEEK_SET);
    
    while (fread(&vaccine, sizeof(struct VaccineInfo), 1, file)) {
        if (vaccine.id != id) {
            fwrite(&vaccine, sizeof(struct VaccineInfo), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove("vaccine.txt");
    rename("temp.txt", "vaccine.txt");
    
    printf("Vaccine information deleted successfully.\n");
}
void vaccineMenu(FILE *file) {
    int choice, id;
    
    do {
        printf("\nAdmin Menu\n");
        printf("1. Add Vaccine Information\n");
        printf("2. View Vaccine Information\n");
        printf("3. Edit Vaccine Information\n");
        printf("4. Delete Vaccine Information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addVaccineInfo(file);
                break;
            case 2:
                viewVaccineInfo(file);
                break;
            case 3:
                printf("Enter Vaccine ID to edit: ");
                scanf("%d", &id);
                editVaccineInfo(file, id);
                break;
            case 4:
                printf("Enter Vaccine ID to delete: ");
                scanf("%d", &id);
                deleteVaccineInfo(file, id);
                break;
            case 5:
                printf("Exiting vaccine menu...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);
}
void vaccinemain() {
    FILE *file = fopen("vaccine.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    vaccineMenu(file);
    
    fclose(file);
    
}

//manage appointment
void viewAppointments(FILE *file) {
    struct Appointment appointment;

    printf("\nAppointments:\n");

    while (fread(&appointment, sizeof(struct Appointment), 1,file)) {
        if (!appointment.isCancelled) {
            printf("Aadhaar: %s\n", appointment.aadhaarNumber);
            printf("Date: %s\n", appointment.date);
            printf("Time: %s\n", appointment.time);
            printf("---------------\n");
        }
       
    }
}
void rescheduleAppointment(FILE *file, const char *aadhaar) {
    struct Appointment appointment;
    long pos;

    fseek(file, 0, SEEK_SET);

    while (fread(&appointment, sizeof(struct Appointment), 1, file)) {
        if (strcmp(appointment.aadhaarNumber, aadhaar) == 0 && !appointment.isCancelled) {
            pos = ftell(file) - sizeof(struct Appointment);
            break;
        }
    }

    if (pos != -1) {
        printf("Enter new date (dd-mm-yyyy): ");
        scanf("%s", appointment.date);
        printf("Enter new time (HH:MM): ");
        scanf("%s", appointment.time);

        fseek(file, pos, SEEK_SET);
        fwrite(&appointment, sizeof(struct Appointment), 1,file);

        printf("Appointment rescheduled successfully.\n");
    } else {
        printf("Appointment not found or already cancelled.\n");
    }
}
void cancelAppointment(FILE *file, const char *aadhaar) {
    struct Appointment appointment;
    long pos;

    fseek(file, 0, SEEK_SET);

    while (fread(&appointment, sizeof(struct Appointment), 1, file)) {
        if (strcmp(appointment.aadhaarNumber, aadhaar) == 0 && !appointment.isCancelled) {
            pos = ftell(file) - sizeof(struct Appointment);
            break;
        }
    }

    if (pos != -1) {
        appointment.isCancelled = 1;

        fseek(file, pos, SEEK_SET);
        fwrite(&appointment, sizeof(struct Appointment), 1, file);

        printf("Appointment cancelled successfully.\n");
    } else {
        printf("Appointment not found or already cancelled.\n");
    }
}
void sendReminder(FILE *file) {
    struct Appointment appointment;
    time_t currentTime;
    struct tm *currentTimeInfo;
    time(&currentTime);
    currentTimeInfo = localtime(&currentTime);

    printf("\nUpcoming Appointments:\n");

    while (fread(&appointment, sizeof(struct Appointment), 1, file)) {
        if (!appointment.isCancelled) {
            struct tm appointmentTimeInfo = {0};
            if (sscanf(appointment.time, "%d:%d", &appointmentTimeInfo.tm_hour, &appointmentTimeInfo.tm_min) == 2) {
                // Set today's date
                appointmentTimeInfo.tm_year = currentTimeInfo->tm_year;
                appointmentTimeInfo.tm_mon = currentTimeInfo->tm_mon;
                appointmentTimeInfo.tm_mday = currentTimeInfo->tm_mday;

                time_t appointmentTime = mktime(&appointmentTimeInfo);

                double difference = difftime(appointmentTime, currentTime);
                if (difference > 0 && difference <= 24 * 60 * 60) {
                    printf("Aadhaar: %s\n", appointment.aadhaarNumber);
                    printf("Date: %s\n", appointment.date);
                    printf("Time: %s\n", appointment.time);
                    printf("Reminder: Your appointment is scheduled within 24 hours.\n");
                    printf("---------------\n");
                }
            }
        }
    }
}
void manageMenu(FILE *file) {
    int choice;
    char aadhaar[15];

    do {
        printf("\nManage Appointments\n");
        printf("1. View Appointments\n");
        printf("2. Reschedule Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Send Reminders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewAppointments(file);
                break;
            case 2:
                printf("Enter Aadhaar number: ");
                scanf("%s", aadhaar);
                rescheduleAppointment(file, aadhaar);
                break;
            case 3:
                printf("Enter Aadhaar number: ");
                scanf("%s", aadhaar);
                cancelAppointment(file, aadhaar);
                break;
            case 4:
                sendmain();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
 void manageappointment() {
     struct Appointment appointment;
    FILE *file = fopen("appointments.txt", "r");

    if (file == NULL) {
        printf("Error opening appointments file.\n");
        return 1;
    }

        manageMenu(file);
     while(fscanf(file, "aadhar no.:%s\n,date:%s\n,time:%s\n,confirmed:%d\n",
            appointment.aadhaarNumber, appointment.date,
            appointment.time, appointment.confirmed) != EOF){
                printf(file, "aadhar no.:%s\n,date:%s\n,time:%s\n,confirmed:%d\n",
            appointment.aadhaarNumber, appointment.date,
            appointment.time, appointment.confirmed);
         }

    fclose(file);
    
}
void sendmain() {
    FILE *file = fopen("appointments.txt", "r");

    if (file == NULL) {
        printf("Error opening appointments file.\n");
        return 1;
    }

    sendReminder(file);

    fclose(file);
    
}

//profile mangement
void updateProfile(struct PersonalInfo *personalInfo) {
    printf("\nUpdating Profile Information\n");
    printf("Enter new name: ");
    scanf("%s", personalInfo->name);
    printf("Enter new Aadhaar number: ");
    scanf("%s", personalInfo->aadhaar);
    FILE *file = fopen("registrations.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    struct PersonalInfo personalInfo;
    long pos = -1;
    
    while (fread(&personalInfo, sizeof(struct PersonalInfo), 1, file)) {
        if (strcmp(personalInfo.aadhaar, personalInfo->aadhaar) == 0) {
            pos = ftell(file) - sizeof(struct PersonalInfo);
            break;
        }
    }
    
    if (pos != -1) {
        fseek(file, pos, SEEK_SET);
        fwrite(personalInfo, sizeof(struct PersonalInfo), 1, file);
        printf("Profile information updated successfully.\n");
    } else {
        printf("Profile not found.\n");
    }
    
    fclose(file);
}

void changeAppointment(struct Appointment *appointment) {
    printf("\nChanging Appointment\n");
    printf("Enter new date: ");
    scanf("%s", appointment->date);
    printf("Enter new time: ");
    scanf("%s", appointment->time);
    
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    struct Appointment appointment;
    long pos = -1;
    
    while (fread(&appointment, sizeof(struct Appointment), 1, file)) {
        if (strcmp(appointment.aadhaarNumber, appointment->aadhaarNumber) == 0) {
            pos = ftell(file) - sizeof(struct Appointment);
            break;
        }
    }
    
    if (pos != -1) {
        fseek(file, pos, SEEK_SET);
        fwrite(appointment, sizeof(struct Appointment), 1, file);
        printf("Appointment details changed successfully.\n");
    } else {
        printf("Appointment not found.\n");
    }
    
    fclose(file);
}
void updateMedicalReport(struct MedicalHistory *medicalhistory) {
    printf("\nUpdating Medical Report\n");
    printf("Enter new medical history: ");
    scanf("%s", medicalhistory->medicalHistory);
    printf("Enter new prescription: ");
    scanf("%s", medicalhistory->prescription);
    
    // Assuming 'file' is a global file pointer for the medical history database file
    FILE *file = fopen("medical_history.dat", "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    struct MedicalHistory medicalhistory;
    long pos = -1;
    
    while (fread(&medicalhistory, sizeof(struct MedicalHistory), 1, file)) {
        if (strcmp(medicalhistory.aadhaar, medicalhistory->aadhaar) == 0) {
            pos = ftell(file) - sizeof(struct MedicalHistory);
            break;
        }
    }
    
    if (pos != -1) {
        fseek(file, pos, SEEK_SET);
        fwrite(medicalhistory, sizeof(struct MedicalHistory), 1, file);
        printf("Medical report updated successfully.\n");
    } else {
        printf("Medical report not found.\n");
    }
    
    fclose(file);
}

void profileMenu() {
    struct PersonalInfo personalInfo;
    struct Appointment appointment;
    struct MedicalHistory medicalhistory;
    
    int choice;
    
    do {
        printf("\nMain Menu\n");
        printf("1. Update Profile Information\n");
        printf("2. Change Appointment\n");
        printf("3. Update Medical Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                updateProfile(&personalInfo);
                break;
            case 2:
                changeAppointment(&appointment);
                break;
            case 3:
                updateMedicalReport(&medicalhistory);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);
}
