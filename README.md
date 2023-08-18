# Technical Training Project: Vaccine Registration System
## CSE3 Batch-36

 ## Members-
    21CS131-Samruddhi.H.R
    21CS140-Sharadhi
    21CS145-Sanyuktha Satish Shetty
    21CS157-Sinchana Shetty
    21CS169-Swati Metri
    20CS098-Miliyana Reena Dsouza

## Problem Statement:
    This program manages the rollout of a vaccine registration system, allowing eligible 
    users to register for vaccine doses, schedule appointments, and manage vaccination 
    center information.

## Functionality:
    1. **Registration Form:** Collects personal information, contact details, medical history, 
    and preferred vaccination center.
    2. **Appointment Scheduling:** Allows users to schedule appointments with desired date 
    and time slots.
    3. **Admin Dashboard:** Provides admin functionalities such as monitoring registrations, 
    viewing stock,managing centers, and generating reports.


## Code Components:

    ### 1. Main Menu (`main()`):
    Handles the main menu navigation and user input to access different functionalities.

    ### 2. Registration Form (`registrationForm()`):
    Gathers personal information, contact details, medical history, and preferred vaccination center. 
    Saves registration data to a file.

    ### 3. Appointment Scheduling (`scheduleAppointment()`):
    Allows users to schedule appointments by providing Aadhaar number, date, and time slot. Saves appointment data to a file.

    ### 4. View Appointments by Date (`viewAppointmentsByDate(date)`):
    Displays appointments for a given date by reading from the appointments file.

    ### 5. Admin Dashboard (`adminDashboard()`):
    Offers admin-specific functionalities such as monitoring registrations, viewing stock, managing centers, 
    and generating general reports.

## Important Functions:

    1. **`registrationForm()`**: Collects and stores user registration data including personal information, 
    contact details, medical history, and preferred vaccination center.
    2. **`scheduleAppointment()`**: Enables users to schedule appointments with desired date and time slots,
    storing appointment data in a file. 
    3. **`viewAppointmentsByDate(date)`**: Displays appointments for a specified date by reading data from the 
    appointments file.
    4. **`adminDashboard()`**: Provides various admin functionalities such as monitoring registrations, 
    viewing stock, managing centers, and generating general reports.

## Usage:
    1. Compile the program using a C compiler.
    2. Run the executable.
    3. Follow the prompts to register, schedule appointments, or access admin functionalities.




