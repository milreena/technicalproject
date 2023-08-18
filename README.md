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
    This project aims to create a Vaccination Registration System that allows users to register for 
    vaccination appointments, manage appointments, view vaccination center information, and generate 
    reports.The system is designed to facilitate efficient vaccination appointment scheduling and management

 
## Functionality:
    The following functionalities have been implemented in the code:

    1.**Registratio**n: Users can register for vaccination by providing personal information,
    contact details,medical history, and preferred vaccination center.
    2.**Appointment Scheduling**: Users can schedule vaccination appointments by providing
    their Aadhaar number,date, and time.
    3.**Admin Dashboard**: Admins can monitor registrations, view available 
    vaccine stock, manage vaccination centers, and generate general reports.
    4.**Vaccine Information**: Admins can add, view, edit, and delete vaccine information.
    5.**Manage Appointments**: Admins can view appointments, reschedule appointments,
    cancel appointments,and send reminders to upcoming appointments.
    6.**Profile Management**: Registered users can update their personal information,
    change appointments,and update medical reports.


## Code Components:
     ## The code consists of several main components:
    1.Main Menu: This is the entry point of the program. It presents various options to the user,
    allowing them to navigate through different functionalities.
    2.Registration Form: Users can provide personal information, contact details, medical history,
    and preferred vaccination center for registration.
    3.Appointment Management: Users can schedule appointments, view appointments by date, and manage
    appointments (reschedule, cancel, and send reminders).
    4.Admin Dashboard: Admins can monitor registrations, view vaccine stock, manage vaccination centers,
    and generate general reports.
    5.Vaccine Information: Admins can manage vaccine information, including adding, viewing, editing,
    and deleting.
    6.Profile Management: Registered users can update their personal information, change appointments,
    and update medical reports.

## Important Functions:

## Some of the important functions of our code are as follows:

   ### 1.'registrationForm(): 
    This function handles the user registration process. It collects the user's personal information,
    contact details, medical history, and preferred vaccination center. The collected data is then stored
    in the registrations.txt file. This function is crucial for building the user database and allowing
    individuals to register for vaccinations.
    
   ### 2.'scheduleAppointment()':
      This function enables users to schedule their vaccination appointments. It prompts the user to
      enter their Aadhaar number, preferred date, and time for the  appointment. The entered appointment
      details are then stored in the appointments.txt file. By allowing users to schedule appointments,
      this function ensures a systematic and organized approach to vaccination.
  
   ### 3.'adminDashboard()':
       The admin dashboard function provides administrators with various tools to manage the vaccination
       system. It presents a menu with options to monitor registrations, manage vaccination centers,
       view available stock, and generate reports. This function is essential for administrators to
       have a comprehensive view of the system's status and to make informed decisions.
   
   ### 4.'addVaccineInfo()', 'viewVaccineInfo()', 'editVaccineInfo()',' deleteVaccineInfo()':
         These functions collectively manage vaccine information. addVaccineInfo() allows administrators
         to add new vaccine details, such as ID, name, manufacturer, and doses required, to the vaccine.txt file.
         viewVaccineInfo() displays the stored vaccine information. editVaccineInfo() enables administrators
         to update vaccine details by providing the vaccine's ID. deleteVaccineInfo() allows administrators
         to remove vaccine information based on the vaccine's ID. These functions facilitate efficient management
         of vaccine-related data.
   
   ### 5.'manageMenu()':
         These functions deal with appointment management and reminders. viewAppointments() displays
         the scheduled appointments. rescheduleAppointment() allows users to change their appointment
         date and time. cancelAppointment() enables users to cancel their appointments. sendReminder()
         automatically sends reminders for upcoming appointments. These functions ensure that users are
         informed about their appointments and have the flexibility to modify them if necessary.
    
   ### 6.'updateProfile()', 'changeAppointment()', 'updateMedicalReport()':
          These functions are part of the profile management system. updateProfile() lets users update
          their personal information, including their name and Aadhaar number. changeAppointment() allows
          users to modify their appointment details, such as date and time. updateMedicalReport() allows
          users to update their medical history and prescription information. These functions empower users
          to maintain accurate and up-to-date profiles.

## Usage:
    1. Compile the program using a C compiler.
    2. Run the executable.
    3. Follow the prompts to register, schedule appointments, or access admin functionalities.

## Additional Points
    1.The system promotes efficient registration and appointment scheduling for vaccinations.
    2.User-friendly menus guide users through various functionalities.
    3.Admins have control over vaccine information, appointment management, and center details.
    4.Automated reminders enhance user experience and appointment adherence.




