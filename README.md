  # # Technical Training Project: Vaccine Registration System
## CSE3 Batch-36

 ## Members-
    21CS131-Samruddhi.H.R
    21CS140-Sharadhi
    21CS145-Sanyuktha Satish Shetty
    21CS157-Sinchana Shetty
    21CS169-Swati Metri
    20CS098-Miliyana Reena Dsouza

## Problem Statement:
        The Vaccine Registration System is designed to streamline the process of vaccine registration,
        appointment scheduling, and management. It serves both customers who need vaccinations and administrators
        who manage the system and appointments. The system aims to provide a user-friendly interface for
        registration and appointment management while offering essential tools for administrators
        to oversee the process efficiently.
 
## Functionality:
        The following functionalities are implemented in the Vaccine Registration System:

    ### 1.Customer Menu:
    
    **Registration Form**: Allows customers to provide personal information, contact details,
    medical history, and a preferred vaccination center.
    **Appointment Scheduling**: Enables customers to schedule vaccination appointments.
    **Dashboard**: Provides customers with a summary of their appointments and profile information.
    **Profile Management**: Allows customers to update their personal details and medical history.
    
    ### 2.Admin Menu:
    
    **Manage Vaccine Information**: Enables administrators to add, edit, and delete vaccine information.
    **Manage Appointments**: Allows administrators to view, reschedule, and cancel appointments.
    **Add Vaccine Stock**: Permits administrators to add vaccine stock to the system.


## Code Components:
     ## The code consists of several main components:
     ## Division of Components ##
    1.**Main Function**: 
    The entry point of the program that prompts users to select their role
    (customer or admin) and directs them to the corresponding menu.
    2.**Customer Menu**: 
    Provides options for customers to access various functionalities related to 
    registration, appointments, dashboard, and profile management.
    3.**Admin Menu**: 
    Offers options for administrators to manage vaccine information, appointments, and vaccine stock.
    
    ## The code is divided futher into the following  components:
     1.**registrationForm()**: Collects customer's personal, contact, medical, and center preferences.
    2.**appointmentScheduling()**: Allows customers to schedule vaccination appointments.
    3.**dashboard()**: Displays appointment summary and profile information for customers.
    4.**profileManagement()**: Enables customers to update personal and medical information.
    5.**vaccineInformation()**: Allows administrators to manage vaccine details.
    6.**manageAppointments()**: Enables administrators to manage appointments.
    7.**addStock()**: Lets administrators add vaccine stock to the system.

## Important Functions:

## Some of the important functions of our code are as follows:

### 1. **`registrationForm()`:**
     - Purpose: Collects comprehensive customer information for registration, including personal,
     contact, medical, and preferred center details.
     - Components:
       - Personal Information: Collects the customer's name, Aadhaar number, date of birth, and gender.
       - Contact Details: Gathers email, phone number, emergency contact, emergency phone, and address.
       - Medical History: Records medical history, prescription, allergies, and current medications.
       - Preferred Center: Takes the center name for vaccination and its location.
     - Importance: Creates a comprehensive profile for the customer, helping the system cater to their
     needs effectively.

### 2. **`appointmentScheduling()`:**
     - Purpose: Enables customers to schedule vaccination appointments by selecting a suitable date and time.
     - Components:
       - Aadhaar Number: Identifies the customer for appointment association.
       - Date and Time: Allows customers to choose a date and time slot for their appointment.
       - Center Name: Specifies the preferred vaccination center for the appointment.
     - Importance: Facilitates organized appointment scheduling for customers.

### 3. **`dashboard()`:**
     - Purpose: Provides an overview of relevant information for customers, including appointment 
     summary, stock availability, and center details.
     - Components:
       - `monitorRegistrations()`: Displays registered people for monitoring.
       - `viewStock()`: Shows available stock of vaccines at various centers.
       - `manageCenters()`: Allows administrators to manage vaccination centers, including adding,
       editing, deleting, and viewing.
       - `generalReport()`: Generates a general report summarizing vaccination data.
     - Importance: Offers transparency and insights for both customers and administrators about
     registrations, stock, and center information.

### 4. **`vaccineInformation()`:**
     - Purpose: Enables administrators to manage vaccine details, including adding, editing, and deleting vaccine information.
     - Components:
       - `addVaccineInformation()`: Lets administrators add new vaccine information.
       - `editVaccineInformation()`: Allows administrators to modify existing vaccine details.
       - `deleteVaccineInformation()`: Permits administrators to remove outdated or incorrect vaccine information.
       - `viewVaccineInformation()`: Displays a list of available vaccines and their details.
     - Importance: Ensures accurate and up-to-date information about the vaccines being offered.

### 5. **`manageAppointments()`:**
     - Purpose: Empowers administrators to oversee appointments, including viewing, rescheduling, canceling, and sending reminders.
     - Components:
       - `viewAppointments()`: Displays a list of appointments for administrators to monitor.
       - `rescheduleAppointment()`: Allows administrators to change appointment dates and times.
       - `cancelAppointment()`: Permits administrators to cancel appointments.
       - `sendReminder()`: Sends reminders to customers about upcoming appointments.
     - Importance: Facilitates efficient management of appointments and improves communication with customers.

### 6. **`profileManagement()`:**
     - Purpose: Enables customers to update their profile information, including personal details, appointments, and medical reports.
     - Components:
       - `updateInformation()`: Allows customers to change their personal details.
       - `changeAppointment()`: Enables customers to reschedule their appointments.
       - `updateMedicalReport()`: Permits customers to update their medical history and prescriptions.
     - Importance: Offers customers the ability to keep their information accurate and up-to-date.

### 7. **`addStock()`:**
     - Purpose: Allows administrators to add vaccine stock to the system to ensure a continuous supply for vaccinations.
     - Components:
       - Vaccine Name: Specifies the name of the vaccine.
       - Quantity: Specifies the quantity of vaccines being added to the stock.
     - Importance: Maintains an adequate supply of vaccines, contributing to seamless vaccination operations.

## Usage:
    1. Compile the program using a C compiler.
    2. Run the executable.
    3. Follow the prompts to register, schedule appointments, or access admin functionalities.

## Additional Points
    1.The system promotes efficient registration and appointment scheduling for vaccinations.
    2.User-friendly menus guide users through various functionalities.
    3.Admins have control over vaccine information, appointment management,vaccine stock and center details.
    4.Automated reminders enhance user experience and appointment adherence.




