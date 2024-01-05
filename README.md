# Hospital Management System

## Project Overview
The Hospital Management System is a C++ console application designed to streamline the management of hospital-related tasks. The system incorporates functionalities for administrators, doctors, patients, lab tests, and ward admissions. It allows administrators to manage doctors, including hiring and sacking, as well as monitoring hospital statistics. Doctors can handle patient appointments, assign beds, conduct lab tests, and more. Patients can schedule appointments with doctors, and the system maintains information on lab tests and ward admissions.

## Table of Contents
1. [Folder Structure](#folder-structure)
2. [Source Code Files](#source-code-files)
    - [doctor.h](#doctorh)
    - [main.cpp](#maincpp)
    - [patient.h](#patienth)
3. [Features](#features)
4. [Usage](#usage)
5. [License](#license)

## Folder Structure
The project is organized into the following structure:

- **`Hospital-Management-System`**: Main project folder
  - **`include`**: Header files
    - [doctor.h](#doctorh)
    - [patient.h](#patienth)
  - **`src`**: Source code files
    - [main.cpp](#maincpp)
  - **`data`**: Data files
    - `Admin.txt`
    - `Doctor.DAT`
    - `Patient.DAT`
  - **`build`**: Compiled binaries

## Source Code Files

### [doctor.h](#doctorh)

Defines the base class `doctor` and its derived classes (`physician`, `emergencyDoc`, `indoorDoc`, `surgeon`). The class includes methods for managing doctors, patients, lab tests, and other related operations.

#### Relevant Functions:

- `add()`: Adds a new doctor to the system.
- `sack()`: Removes a doctor from the system.
- `assignWardBed()`: Assigns a bed in a ward to a patient under a specific indoor doctor.
- `assignLab()`: Assigns a lab test to a patient appointed to a doctor.
- `write()`: Writes all doctor data to a binary file.
- `read()`: Reads doctor data from a binary file.
- `patToDocPatients()`: Assigns patients to their respective doctors.
- `WardInDe()`: Updates the number of wards in the hospital.
- `BedInDe()`: Updates the number of beds in each ward.
- `searchAllpatientsOfDoc(int d)`: Displays all patients under a specific doctor.

### [main.cpp](#maincpp)

The main program file responsible for user interaction and system control. It includes the main function and the menu-based interface.

#### Relevant Functions:

- `print()`: Displays the main menu.
- `printDept()`: Displays the department information.
- `main()`: The main function handling user interactions and program flow.

### [patient.h](#patienth)

Contains the class definition for the `patient` class and its derived classes (`regularPatient`, `emergencyPatient`, `indoorPatient`, `forSurgeryPatient`). The class includes methods for managing patient details.

## Features
- **Administrator Panel:**
  - Hiring and sacking doctors.
  - Managing hospital statistics.

- **Doctor Menu:**
  - Handling patient appointments.
  - Assigning beds in wards.
  - Conducting lab tests.

- **Patient Menu:**
  - Scheduling appointments with doctors.

- **Lab Test Integration:**
  - Assigning and managing lab tests for patients.

- **Ward Admission System:**
  - Assigning beds to indoor patients.

## Usage
Upon running the program, users are presented with a menu allowing navigation to different panels. Administrators can manage doctors, view statistics, and perform various administrative tasks. Doctors can handle patient appointments, assign beds, conduct lab tests, and more. Patients can schedule appointments with doctors and undergo lab tests.

## License
This project is licensed under the MIT License.
