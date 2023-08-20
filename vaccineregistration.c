#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct PersonalInfo {
    char name[50];
    char aadhaar[15];
    char dateOfBirth[15];
    char gender[10];
};
struct ContactDetails {
    char email[50];
    char phone[15];
    char emergencyContact[50];
    char emergencyPhone[15];
    char address[100];
};
struct MedicalHistory {
    char medicalHistory[200];
    char prescription[200];
    char allergies[100];
    char currentMedications[200];
};
struct PreferredCenter {
    char centerName[50];
    char address[100];
    char city[50];
    char state[50];
    char zipcode[10];
};
struct Appointment {
    char aadhaar[15];
    char date[15];
    char time[10];
    char centerName[50]; // Adding the center name field
};
struct Vaccine {
    char name[50];
    char manufacturer[50];
    char type[20];
    int dosesRequired;
};
struct VaccineStock {
    char vaccineName[50];
    int quantity;
};//components
void customerMenu();
void adminMenu();
void registrationForm();
void appointmentScheduling();
void dashboard();
void vaccineInformation();
void manageAppointments();
void profileManagement();
int main() { //mainmenue
    int role;
    printf("Welcome to the Vaccine Registration System!\n");
    printf("Please select your role:\n");
    printf("1. Customer\n");
    printf("2. Admin\n");
    printf("Enter your choice: ");
    scanf("%d", &role);
    if (role == 1) {
        customerMenu();
    } else if (role == 2) {
        adminMenu();
    } else {
        printf("Invalid role selection.\n");
    }
    return 0;
}
void customerMenu() {
    int choice;
    do {
        printf("\nCustomer Menu\n");
        printf("1. Registration Form\n");
        printf("2. Appointment Scheduling\n");
        printf("3. Dashboard\n");
        printf("4. Profile Management\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registrationForm();
                break;
            case 2:
                appointmentScheduling();
                break;
            case 3:
                dashboard();
                break;
            case 4:
                profileManagement();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
void adminMenu() {
    int choice;
    do {
        printf("\nAdmin Menu\n");
        printf("1. Manage Vaccine Information\n");
        printf("2. Manage Appointments\n");
        printf("3. Add Vaccine Stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                vaccineInformation();
                break;
            case 2:
                manageAppointments();
                break;
            case 3:
                addStock();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
void registrationForm() { 
    struct PersonalInfo Person;
    struct ContactDetails Contact;
    struct MedicalHistory History;
    struct PreferredCenter Center;
    printf("\nRegistration Form\n");
    printf("Enter Name: ");
    scanf("%s", Person.name);
    printf("Enter Aadhaar Number: ");
    scanf("%s", Person.aadhaar);
    printf("Enter Date of Birth (YYYY-MM-DD): ");
    scanf("%s", Person.dateOfBirth);
    printf("Enter Gender: ");
    scanf("%s", Person.gender);
    printf("Enter Email: ");
    scanf("%s", Contact.email);
    printf("Enter Phone Number: ");
    scanf("%s", Contact.phone);
    printf("Enter Emergency Contact: ");
    scanf("%s", Contact.emergencyContact);
    printf("Enter Emergency Phone: ");
    scanf("%s", Contact.emergencyPhone);
    printf("Enter Address: ");
    scanf("%s", Contact.address);
    printf("Enter Medical History: ");
    scanf("%s", History.medicalHistory);
    printf("Enter Prescription: ");
    scanf("%s", History.prescription);
    printf("Enter Allergies: ");
    scanf("%s", History.allergies);
    printf("Enter Current Medications: ");
    scanf("%s", History.currentMedications);
    printf("Enter Preferred Center Name: ");
    scanf("%s", Center.centerName);
    printf("Enter Address of Preferred Center: ");
    scanf("%s", Center.address);
    printf("Enter City of Preferred Center: ");
    scanf("%s", Center.city);
    printf("Enter State of Preferred Center: ");
    scanf("%s", Center.state);
    printf("Enter Zipcode of Preferred Center: ");
    scanf("%s", Center.zipcode);
    FILE *file = fopen("registration.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "\n\n\nName: %s\n", Person.name);
    fprintf(file, "Aadhaar Number: %s\n", Person.aadhaar);
    fprintf(file, "Date of Birth: %s\n", Person.dateOfBirth);
    fprintf(file, "Gender: %s\n", Person.gender);
    fprintf(file, "Email: %s\n", Contact.email);
    fprintf(file, "Phone Number: %s\n", Contact.phone);
    fprintf(file, "Emergency Contact: %s\n", Contact.emergencyContact);
    fprintf(file, "Emergency Phone: %s\n", Contact.emergencyPhone);
    fprintf(file, "Address: %s\n", Contact.address);
    fprintf(file, "Medical History: %s\n", History.medicalHistory);
    fprintf(file, "Prescription: %s\n", History.prescription);
    fprintf(file, "Allergies: %s\n", History.allergies);
    fprintf(file, "Current Medications: %s\n", History.currentMedications);
    fprintf(file, "Preferred Center Name: %s\n", Center.centerName);
    fprintf(file, "Address of Preferred Center: %s\n", Center.address);
    fprintf(file, "City of Preferred Center: %s\n", Center.city);
    fprintf(file, "State of Preferred Center: %s\n", Center.state);
    fprintf(file, "Zipcode of Preferred Center: %s\n", Center.zipcode);
    printf("---------------------------\n");
    fclose(file);
    printf("Registration completed successfully.\n");
    
}
void appointmentScheduling() { 
    printf("\nAppointment Scheduling\n");
    struct Appointment newAppointment;
    printf("Enter Aadhaar Number: ");
    scanf("%s", newAppointment.aadhaar);
    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", newAppointment.date);
    printf("Enter Time (HH:MM AM/PM): ");
    scanf("%s", newAppointment.time);
    printf("Enter Preferred Center Name: ");
    scanf("%s", newAppointment.centerName);
    FILE *file = fopen("appointments.txt", "a");
    if (file == NULL) {
        printf("Error opening appointments file for writing.\n");
        return;
    }
    fprintf(file, "Aadhaar Number: %s\n", newAppointment.aadhaar);
    fprintf(file, "Date: %s\n", newAppointment.date);
    fprintf(file, "Time: %s\n", newAppointment.time);
    fprintf(file, "Center Name: %s\n", newAppointment.centerName);
    fprintf(file, "--------------------\n");
    fclose(file);
    printf("Appointment scheduled successfully.\n");
}
void dashboard() {
    int choice;
    do {
        printf("\nDashboard\n");
        printf("1. Monitor Register\n");
        printf("2. View Stock\n");
        printf("3. Manage Centers\n");
        printf("4. General Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                monitorRegister(); 
                break;
            case 2:
                viewStock();
                break;
            case 3:
                manageCenters();
                break;
            case 4:
               generalReport();
                break;
            case 5:
                return; 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
void monitorRegister() {
    FILE *file = fopen("registration.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char line[200];
    printf("\nRegistered People:\n");
    printf("------------------\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}
void viewStock() {
    printf("Viewing stock...\n");

    FILE *file = fopen("stock.txt", "r");
    if (file == NULL) {
        printf("Error opening stock file.\n");
        return;
    }
    struct VaccineStock stock;
    printf("Vaccine Name\tQuantity\n");
    printf("-------------------------\n");
    while (fread(&stock, sizeof(struct VaccineStock), 1, file) == 1) {
        printf("%-15s\t%d\n", stock.vaccineName, stock.quantity);
    }
    fclose(file);
}
void manageCenters() { 
    int choice;
    do {
        printf("\nManage Centers\n");
        printf("1. Add Center\n");
        printf("2. Edit Center\n");
        printf("3. Delete Center\n");
        printf("4. View Centers\n");
        printf("5. Back to Dashboard\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCenter();
                break;
            case 2:
                editCenter();
                break;
            case 3:
                deleteCenter();
                break;
            case 4:
                viewCenters();
                break;
            case 5:
                return; 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
void addCenter() {
    struct PreferredCenter newCenter;
    printf("\nAdding a new center\n");
    printf("Enter Center Name: ");
    scanf("%s", newCenter.centerName);
    printf("Enter Address: ");
    scanf("%s", newCenter.address);
    printf("Enter City: ");
    scanf("%s", newCenter.city);
    printf("Enter State: ");
    scanf("%s", newCenter.state);
    printf("Enter Zipcode: ");
    scanf("%s", newCenter.zipcode);
    FILE *file = fopen("centers.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "Center Name: %s\n", newCenter.centerName);
    fprintf(file, "Address: %s\n", newCenter.address);
    fprintf(file, "City: %s\n", newCenter.city);
    fprintf(file, "State: %s\n", newCenter.state);
    fprintf(file, "Zipcode: %s\n", newCenter.zipcode);
    fprintf(file, "--------------------\n");
    fclose(file);
    printf("New center added successfully.\n");
}
void editCenter() { 
    printf("\nEditing a center\n");
    int selectedCenterIndex;
    FILE *file = fopen("centers.txt", "r+");
    if (file == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
    fseek(file, selectedCenterIndex * sizeof(struct PreferredCenter), SEEK_SET);
    struct PreferredCenter editedCenter;
    fread(&editedCenter, sizeof(struct PreferredCenter), 1, file);
    printf("Enter new Center Name: ");
    scanf("%s", editedCenter.centerName);
    printf("Enter new Address: ");
    scanf("%s", editedCenter.address);
    printf("Enter new City: ");
    scanf("%s", editedCenter.city);
    printf("Enter new State: ");
    scanf("%s", editedCenter.state);
    printf("Enter new Zipcode: ");
    scanf("%s", editedCenter.zipcode);
    fseek(file, selectedCenterIndex * sizeof(struct PreferredCenter), SEEK_SET);
    fwrite(&editedCenter, sizeof(struct PreferredCenter), 1, file);
    fclose(file);
    printf("Center information edited successfully.\n");
}
void deleteCenter() {
    printf("\nDeleting a center\n");
    int selectedCenterIndex;
    FILE *file = fopen("centers.txt", "r+");
    if (file == NULL) {
        printf("Error opening centers file.\n");
        return;
    }
    long int offset = selectedCenterIndex * sizeof(struct PreferredCenter);
    fseek(file, 0, SEEK_END);
    long int fileSize = ftell(file);
    for (long int i = offset + sizeof(struct PreferredCenter); i < fileSize; i++) {
        fseek(file, i, SEEK_SET);
        char c = fgetc(file);
        fseek(file, i - sizeof(struct PreferredCenter), SEEK_SET);
        fputc(c, file);
    }
    ftruncate(fileno(file), fileSize - sizeof(struct PreferredCenter));
    fclose(file);
    printf("Center information deleted successfully.\n");
}
void viewCenters() {
    printf("\nViewing all centers\n");
    FILE *file = fopen("centers.txt", "r");
    if (file == NULL) {
        printf("Error opening centers file.\n");
        return;
    }
    struct PreferredCenter center;
    char line[200];
    printf("List of registered centers:\n");
    printf("============================\n");
     while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    while (fread(&center, sizeof(struct PreferredCenter), 1, file) == 1) {
        printf("Center Name: %s\n", center.centerName);
        printf("Address: %s\n", center.address);
        printf("City: %s\n", center.city);
        printf("State: %s\n", center.state);
        printf("Zipcode: %s\n", center.zipcode);
        printf("---------------------------\n");
    }
    fclose(file);
}
void generalReport() {
    FILE *file = fopen("registration.txt", "r");
    if (file == NULL) {
        printf("Error opening registration file.\n");
        return;
    }
    printf("\nGeneral Report\n");
    printf("===================================\n");
    struct PersonalInfo person;
    struct ContactDetails contact;
    struct MedicalHistory history;
    struct PreferredCenter center;
    while (fread(&person, sizeof(struct PersonalInfo), 1, file) == 1) {
        fread(&contact, sizeof(struct ContactDetails), 1, file);
        fread(&history, sizeof(struct MedicalHistory), 1, file);
        fread(&center, sizeof(struct PreferredCenter), 1, file);
        printf("\nName: %s\n", person.name);
        printf("Aadhaar: %s\n", person.aadhaar);
        printf("Date of Birth: %s\n", person.dateOfBirth);
        printf("Gender: %s\n", person.gender);
        printf("Email: %s\n", contact.email);
        printf("Phone: %s\n", contact.phone);
        printf("Emergency Contact: %s\n", contact.emergencyContact);
        printf("Emergency Phone: %s\n", contact.emergencyPhone);
        printf("Address: %s\n", contact.address);
        printf("Medical History: %s\n", history.medicalHistory);
        printf("Prescription: %s\n", history.prescription);
        printf("Allergies: %s\n", history.allergies);
        printf("Current Medications: %s\n", history.currentMedications);
        printf("Preferred Center: %s\n", center.centerName);
        printf("Address: %s\n", center.address);
        printf("City of Preferred Center: %s\n", center.city);
        printf("State of Preferred Center: %s\n", center.state);
        printf("Zipcode of Preferred Center: %s\n", center.zipcode);
        printf("===================================\n");
    }
    fclose(file);
}
void vaccineInformation() {
    int choice;
    do {
        printf("\nVaccine Information Management\n");
        printf("1. Add Vaccine Information\n");
        printf("2. Edit Vaccine Information\n");
        printf("3. Delete Vaccine Information\n");
        printf("4. View Vaccine Information\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addVaccineInformation();
                break;
            case 2:
                editVaccineInformation();
                break;
            case 3:
                deleteVaccineInformation();
                break;
            case 4:
                viewVaccineInformation();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
void addVaccineInformation() {
    struct Vaccine newVaccine;
    printf("\nAdding new vaccine information\n");
    printf("Enter Vaccine Name: ");
    scanf("%s", newVaccine.name);
    printf("Enter Manufacturer: ");
    scanf("%s", newVaccine.manufacturer);
    printf("Enter Type: ");
    scanf("%s", newVaccine.type);
    printf("Enter Number of Doses Required: ");
    scanf("%d", &newVaccine.dosesRequired);
    FILE *file = fopen("vaccine_info.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "Vaccine Name: %s\n", newVaccine.name);
    fprintf(file, "Manufacturer: %s\n", newVaccine.manufacturer);
    fprintf(file, "Type: %s\n", newVaccine.type);
    fprintf(file, "Doses Required: %d\n", newVaccine.dosesRequired);
    fprintf(file, "--------------------\n");
    fclose(file);
    printf("New vaccine information added successfully.\n");
}
void editVaccineInformation() {
    printf("\nEditing vaccine information\n");
    int selectedVaccineIndex;
    FILE *file = fopen("vaccine_info.txt", "r+");
    if (file == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
    long int offset = selectedVaccineIndex * sizeof(struct Vaccine);
    fseek(file, offset, SEEK_SET);
    struct Vaccine editedVaccine;
    fread(&editedVaccine, sizeof(struct Vaccine), 1, file);
    printf("Enter new Vaccine Name: ");
    scanf("%s", editedVaccine.name);
    printf("Enter new Manufacturer: ");
    scanf("%s", editedVaccine.manufacturer);
    printf("Enter new Type: ");
    scanf("%s", editedVaccine.type);
    printf("Enter new Number of Doses Required: ");
    scanf("%d", &editedVaccine.dosesRequired);
    fseek(file, offset, SEEK_SET);
    fwrite(&editedVaccine, sizeof(struct Vaccine), 1, file);
    fclose(file);
    printf("Vaccine information edited successfully.\n");
}
void deleteVaccineInformation() {
    printf("\nDeleting vaccine information\n");
    int selectedVaccineIndex;
    FILE *originalFile = fopen("vaccine_info.txt", "r");
    if (originalFile == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    FILE *tempFile = fopen("temp_vaccine_info.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file for writing.\n");
        fclose(originalFile);
        return;
    }
    struct Vaccine vaccine;
    int currentIndex = 0;
while (fread(&vaccine, sizeof(struct Vaccine), 1, originalFile) == 1) {
    if (currentIndex != selectedVaccineIndex) {
        fwrite(&vaccine, sizeof(struct Vaccine), 1, tempFile);
    } currentIndex++;
}
    fclose(originalFile);
    fclose(tempFile);
    remove("vaccine_info.txt");
    rename("temp_vaccine_info.txt", "vaccine_info.txt");
    printf("Vaccine information deleted successfully.\n");
}
void viewVaccineInformation() {
    printf("\nViewing all vaccine information\n");
    FILE *file = fopen("vaccine_info.txt", "r");
    if (file == NULL) {
        printf("Error opening vaccine information file.\n");
        return;
    }
    struct Vaccine vaccine;
    char line[200];
    printf("List of registered vaccines:\n");
    printf("============================\n");
     while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    while (fread(&vaccine, sizeof(struct Vaccine), 1, file) == 1) {
        printf("Vaccine Name: %s\n", vaccine.name);
        printf("Manufacturer: %s\n", vaccine.manufacturer);
        printf("Type: %s\n", vaccine.type);
        printf("Doses Required: %d\n", vaccine.dosesRequired);
        printf("---------------------------\n");
    }
    fclose(file);
}
void manageAppointments() {
    int choice;
    do {
        printf("\nAppointment Management\n");
        printf("1. View Appointments\n");
        printf("2. Reschedule Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Send Reminder\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                viewAppointments();
                break;
            case 2:
                rescheduleAppointment();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                sendReminder();
                break;
            case 5:
                return; 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
void viewAppointments() {
    printf("\nViewing appointments\n");
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error opening appointments file.\n");
        return;
    }
    struct Appointment appointment;
    printf("List of scheduled appointments:\n");
    printf("==============================\n");
    while (fread(&appointment, sizeof(struct Appointment), 1, file) == 1) {
        printf("Aadhaar Number: %s\n", appointment.aadhaar);
        printf("Date: %s\n", appointment.date);
        printf("Time: %s\n", appointment.time);
        printf("Center Name: %s\n", appointment.centerName);
        printf("---------------------------\n");
    }
    fclose(file);
}
void rescheduleAppointment() {
    printf("\nRescheduling an appointment\n");
    int selectedAppointmentIndex; 
    FILE *file = fopen("appointments.txt", "r+");
    if (file == NULL) {
        printf("Error opening appointments file.\n");
        return;
    }
    long int offset = selectedAppointmentIndex * sizeof(struct Appointment);
    fseek(file, offset, SEEK_SET);
    struct Appointment rescheduledAppointment;
    fread(&rescheduledAppointment, sizeof(struct Appointment), 1, file);
    printf("Enter new Date: ");
    scanf("%s", rescheduledAppointment.date);
    printf("Enter new Time: ");
    scanf("%s", rescheduledAppointment.time);
    fseek(file, offset, SEEK_SET);
    fwrite(&rescheduledAppointment, sizeof(struct Appointment), 1, file);
    fclose(file);
    printf("Appointment rescheduled successfully.\n");
}
void cancelAppointment() {
    printf("\nCanceling an appointment\n");
    int selectedAppointmentIndex;
    FILE *originalFile = fopen("appointments.txt", "r");
    if (originalFile == NULL) {
        printf("Error opening appointments file.\n");
        return;
    }
    FILE *tempFile = fopen("temp_appointments.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file for writing.\n");
        fclose(originalFile);
        return;
    }
    struct Appointment appointment;
    int currentIndex = 0;
    while (fread(&appointment, sizeof(struct Appointment), 1, originalFile) == 1) {
        if (currentIndex != selectedAppointmentIndex) {
            fwrite(&appointment, sizeof(struct Appointment), 1, tempFile);
        }
        currentIndex++;
    }
    fclose(originalFile);
    fclose(tempFile);
    remove("appointments.txt");
    rename("temp_appointments.txt", "appointments.txt");
    printf("Appointment canceled successfully.\n");
}
void sendReminder() {
    printf("\nSending a reminder\n");
    int selectedAppointmentIndex;
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error opening appointments file.\n");
        return;
    }
    struct Appointment appointment;
    int currentIndex = 0;
    while (fread(&appointment, sizeof(struct Appointment), 1, file) == 1) {
        if (currentIndex == selectedAppointmentIndex) {
            printf("Sending a reminder for the following appointment:\n");
            printf("Aadhaar Number: %s\n", appointment.aadhaar);
            printf("Date: %s\n", appointment.date);
            printf("Time: %s\n", appointment.time);
            printf("Center Name: %s\n", appointment.centerName);
            printf("---------------------------\n");
            printf("Reminder sent.\n");
            break;
        }
        currentIndex++;
    }
    fclose(file);
}
void profileManagement() {
    int choice;
    do {
        printf("\nProfile Management\n");
        printf("1. Update Information\n");
        printf("2. Change Appointment\n");
        printf("3. Update Medical Report\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                updateInformation();
                break;
            case 2:
                changeAppointment();
                break;
            case 3:
                updateMedicalReport();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
void updateInformation() {
    printf("\nUpdating information\n");
    char aadhaarToUpdate[15];
    printf("Enter Aadhaar number of the profile to update: ");
    scanf("%s", aadhaarToUpdate);
    FILE *file = fopen("registration.txt", "r+");
    if (file == NULL) {
        printf("Error opening registration file.\n");
        return;
    }
    struct PersonalInfo person;
    struct ContactDetails contact;
    while (fread(&person, sizeof(struct PersonalInfo), 1, file) == 1) {
        if (strcmp(person.aadhaar, aadhaarToUpdate) == 0) {
            printf("Enter new Name: ");
            scanf("%s", person.name);
            printf("Enter new Date of Birth: ");
            scanf("%s", person.dateOfBirth);
            printf("Enter new Gender: ");
            scanf("%s", person.gender);
            printf("Enter new Email: ");
            scanf("%s", contact.email);
            printf("Enter new Phone: ");
            scanf("%s", contact.phone);
            printf("Enter new Emergency Contact: ");
            scanf("%s", contact.emergencyContact);
            printf("Enter new Emergency Phone: ");
            scanf("%s", contact.emergencyPhone);
            printf("Enter new Address: ");
            scanf("%s", contact.address);
            fseek(file, -sizeof(struct PersonalInfo), SEEK_CUR);
            fwrite(&person, sizeof(struct PersonalInfo), 1, file);
            printf("Information updated successfully.\n");
            break;
        }
    }
    fclose(file);
}
void changeAppointment() {
    printf("\nChanging appointment\n");
    printf("List of available appointments:\n");
    int totalAppointments = 0; 
    printf("Enter the index of the appointment you want to change (0-%d): ", totalAppointments - 1);
    int selectedAppointmentIndex;
    scanf("%d", &selectedAppointmentIndex);
    FILE *file = fopen("appointments.txt", "r+");
    if (file == NULL) {
        printf("Error opening appointments file.\n");
        return;
    }
    struct Appointment appointment;
    while (fread(&appointment, sizeof(struct Appointment), 1, file) == 1) {
        if (selectedAppointmentIndex == 0) {
            printf("Enter new Date: ");
            scanf("%s", appointment.date);
            printf("Enter new Time: ");
            scanf("%s", appointment.time);
            printf("Enter new Center Name: ");
            scanf("%s", appointment.centerName);
            fseek(file, -sizeof(struct Appointment), SEEK_CUR);
            fwrite(&appointment, sizeof(struct Appointment), 1, file);
            printf("Appointment changed successfully.\n");
            break;
        }
        selectedAppointmentIndex--;
    }
    fclose(file);
}
void updateMedicalReport() {
    printf("\nUpdating medical report\n");
    char aadhaarToUpdate[15];
    printf("Enter Aadhaar number of the profile to update: ");
    scanf("%s", aadhaarToUpdate);
    FILE *file = fopen("registration.txt", "r+");
    if (file == NULL) {
        printf("Error opening registration file.\n");
        return;
    }
    struct PersonalInfo person;
    struct MedicalHistory history;
    while (fread(&person, sizeof(struct PersonalInfo), 1, file) == 1) {
        if (strcmp(person.aadhaar, aadhaarToUpdate) == 0) {
            printf("Enter updated Medical History: ");
            scanf(" %[^\n]", history.medicalHistory);
            printf("Enter updated Prescription: ");
            scanf(" %[^\n]", history.prescription);
            printf("Enter updated Allergies: ");
            scanf(" %[^\n]", history.allergies);
            printf("Enter updated Current Medications: ");
            scanf(" %[^\n]", history.currentMedications);
            fseek(file, -sizeof(struct PersonalInfo), SEEK_CUR);
            fwrite(&person, sizeof(struct PersonalInfo), 1, file);
            printf("Medical report updated successfully.\n");
            break;
        }
    }
    fclose(file);
}
void addStock() {
    printf("Adding new stock...\n");

    FILE *file = fopen("stock.txt", "a");
    if (file == NULL) {
        printf("Error opening stock file.\n");
        return;
    }
    struct VaccineStock stock;
    printf("Enter vaccine name: ");
    scanf("%s", stock.vaccineName);
    printf("Enter quantity: ");
    scanf("%d", &stock.quantity);
    fwrite(&stock, sizeof(struct VaccineStock), 1, file);
    fclose(file);
    printf("Stock added successfully.\n");
}
