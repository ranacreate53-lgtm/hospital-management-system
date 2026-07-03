#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// ================= BASE CLASS =================
class Person
{
protected:
    int id;
    string name;

public:
    virtual ~Person() {}

    void inputPerson()
    {
        cout << "Enter ID: ";
        while (!(cin >> id))
        {
            cout << "Invalid input. Enter numeric ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name: ";
        getline(cin, name);
    }

    virtual void displayInfo()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }

    int getId() const { return id; }
};

// ================= DOCTOR =================
class Doctor : public Person
{
private:
    string specialization;
    string availability;
    string schedule;

public:
    void inputDoctor()
    {
        inputPerson();

        cout << "Enter Specialization: ";
        getline(cin, specialization);

        cout << "Enter Availability: ";
        getline(cin, availability);

        cout << "Enter Working Schedule: ";
        getline(cin, schedule);
    }

    void displayInfo() override
    {
        cout << "\n--- Doctor Info ---\n";
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Availability: " << availability << endl;
        cout << "Working Schedule: " << schedule << endl;
    }
};

// ================= PATIENT =================
class Patient : public Person
{
private:
    int age;
    string disease;
    int assignedDoctorID;

public:
    void inputPatient()
    {
        inputPerson();

        cout << "Enter Age: ";
        while (!(cin >> age))
        {
            cout << "Invalid input. Enter numeric age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Disease: ";
        getline(cin, disease);

        cout << "Enter Assigned Doctor ID: ";
        while (!(cin >> assignedDoctorID))
        {
            cout << "Invalid input. Enter numeric Doctor ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void displayInfo() override
    {
        cout << "\n--- Patient Info ---\n";
        Person::displayInfo();
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
        cout << "Assigned Doctor ID: " << assignedDoctorID << endl;
    }
};

// ================= APPOINTMENT =================
class Appointment
{
public:
    int appID;
    int doctorID;
    int patientID;
    string date;
    string time;

    void inputAppointment()
    {
        cout << "\nEnter Appointment ID: ";
        while (!(cin >> appID))
        {
            cout << "Invalid input. Enter numeric ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Doctor ID: ";
        while (!(cin >> doctorID))
        {
            cout << "Invalid input. Enter numeric Doctor ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Patient ID: ";
        while (!(cin >> patientID))
        {
            cout << "Invalid input. Enter numeric Patient ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Date (DD/MM/YYYY): ";
        getline(cin, date);

        cout << "Enter Time: ";
        getline(cin, time);
    }

    void displayAppointment()
    {
        cout << "\n--- Appointment ---\n";
        cout << "App ID: " << appID << endl;
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
    }
};

// ================= HELPERS =================
int readChoice()
{
    int choice;
    while (!(cin >> choice))
    {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void showAllDoctors(vector<Doctor> &doctors)
{
    if (doctors.empty())
    {
        cout << "\nNo doctors found.\n";
        return;
    }
    for (auto &doc : doctors)
        doc.displayInfo();
}

void showAllPatients(vector<Patient> &patients)
{
    if (patients.empty())
    {
        cout << "\nNo patients found.\n";
        return;
    }
    for (auto &pat : patients)
        pat.displayInfo();
}

void showAllAppointments(vector<Appointment> &appointments)
{
    if (appointments.empty())
    {
        cout << "\nNo appointments found.\n";
        return;
    }
    for (auto &app : appointments)
        app.displayAppointment();
}

// ================= MAIN MENU =================
int main()
{
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;

    int choice;

    do
    {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Doctor\n";
        cout << "2. Add Patient\n";
        cout << "3. Show All Doctors\n";
        cout << "4. Show All Patients\n";
        cout << "5. Add Appointment\n";
        cout << "6. Show All Appointments\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        choice = readChoice();

        switch (choice)
        {
        case 1:
        {
            Doctor d;
            cout << "\nEnter Doctor Data:\n";
            d.inputDoctor();
            doctors.push_back(d);
            cout << "Doctor added successfully!\n";
            break;
        }

        case 2:
        {
            Patient p;
            cout << "\nEnter Patient Data:\n";
            p.inputPatient();
            patients.push_back(p);
            cout << "Patient added successfully!\n";
            break;
        }

        case 3:
            showAllDoctors(doctors);
            break;

        case 4:
            showAllPatients(patients);
            break;

        case 5:
        {
            Appointment a;
            a.inputAppointment();
            appointments.push_back(a);
            cout << "Appointment added successfully!\n";
            break;
        }

        case 6:
            showAllAppointments(appointments);
            break;

        case 0:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
