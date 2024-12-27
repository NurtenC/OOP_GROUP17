===========================================================
# README - CENG201 OOP **GROUP17** Project: Expense Tracker

### **GROUP MEMBERS:**  
- **Nurten Çiftçioğlu**  
- **Mehmet Emre Yıldız**  
- **Berat Mut**  
- **Furkan Demir**  
- **Mustafa Kamal Mustafa Mustafa**  

This repository is dedicated to the CENG201 project assignment.

---

## **INTRODUCTION**
This project focuses on developing an **Expense Tracking Application** that empowers users to:

- Log and track expenses efficiently.
- Categorize expenses for better organization.
- Set monthly budgets and manage spending limits.
- Receive timely notifications upon approaching or exceeding budget thresholds.

The application supports multiple users, enabling each user to independently manage their expenses while providing insightful reports and budget analytics.

---

## **HOW TO COMPILE**

To compile the project, follow these steps:

1. Ensure the **FLTK library** is installed and correctly configured. Update directory paths in the Makefile as necessary.
2. Open the project directory in your terminal.
3. Run the following command based on your system:
   - **Linux/MacOS:** `make`
   - **Windows:** `mingw32-make`

This will compile the project and generate the executable file.

## **Cleaning Up**
To remove the compiled executable, you can run:
 ```bash
make clean
```
This will delete the ExpenseTracker.exe file.

---

## **HOW TO RUN**

After successful compilation:

- Navigate to the project directory in your terminal.
- Run the executable. For example, on Windows, use:
  ```bash
  .\ExpenseTracker.exe

---

## **HOW TO USE**

### **Account Management**
1. **Create an Account:**  
   - Click the **Register** button and enter your information.  
2. **Log In:**  
   - Click the **Login** button and provide your credentials to access your account.

### **Navigation**  
Use the navigation menu on the left to switch between different sections of the application. You can move back and forth between pages by clicking on the desired section.

### **Features Overview**

#### **Homepage**  
- Displays user information.  
- Use the **Settings** tab to update your username and password.  
  - Changes require re-entering your credentials for security reasons.  

#### **Add Page**  
- **Add Expenses:**  
  - Choose a **Category**.  
  - Enter a **Description** and the **Amount**.  
  - Optionally, specify a **Date** for regular expenses.  
- **Add Income:**  
  - Enter a **Description** and the **Amount**.  
  - Regular income entries also support an optional **Date**.

#### **Report Page**  
- **Expense Table:**  
  - View expenses filtered by **Duration** (specific time period) or **Category**.  
- **Income Table:**  
  - View income records filtered by a defined time period.  

> **Note:** Tables update only after clicking the respective **List** button.

---

## **LINKS**
YouTube URL  :  https://www.youtube.com/watch?v=DnBcuvYefRI

## **CONTRIBUTIONS**
- **Nurten Çiftçioğlu**  :  Added GUI elements. Has done significant amount of work on implementation.  
- **Mehmet Emre Yıldız**  :  Wrote the README documentation. Did QA testing. Did the in-class presentation. Prepared the demonstration video.
- **Berat Mut**  :  Offered ideas on implementation. Did QA testing.
- **Furkan Demir**  :    Has generated the Doxygen documentation. Helped with implementation. Did QA testing.
- **Mustafa Kamal Mustafa Mustafa**  :  Has done significant amount of work on implementation.
