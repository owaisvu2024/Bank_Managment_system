# 🏦 Bank Management System (C++ + MySQL)

## 📌 Project Overview

This is a console-based **Bank Management System** developed using **C++** and **MySQL**.
The system simulates basic banking operations like account creation, login, deposit, withdrawal, and balance checking.

This project helped in understanding **Object-Oriented Programming (OOP)** concepts and **database connectivity** with C++.

---

## 🚀 Features

* 👤 Admin (Manager) Signup & Login
* 🏦 Create New Bank Account
* 🔍 Search Account
* 📋 View All Accounts
* 💰 Deposit Money
* 💸 Withdraw Money
* 📊 Check Account Balance
* ❌ Delete Account
* 🔐 Basic Authentication (Username & PIN)

---

## 🛠️ Technologies Used

* **C++ (OOP Concepts)**
* **MySQL Database**
* **MySQL Connector (C API)**

---

## 🗄️ Database Structure

### Database Name:

```
bank
```

### Tables:

#### 1. Manager Table

```
CREATE TABLE manager(
    username VARCHAR(15),
    password VARCHAR(8)
);
```

#### 2. Employee Table

```
CREATE TABLE employee1(
    account_no INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(15),
    pin INT UNIQUE,
    balance FLOAT
);
```

---

## ⚙️ How to Run the Project

### Step 1: Setup MySQL

* Install MySQL Server
* Create database:

```
CREATE DATABASE bank;
USE bank;
```

* Create required tables (given above)

---

### Step 2: Configure Connection

Update this line in code if needed:

```
mysql_real_connect(conn, "localhost", "root", "12345", "bank", 3306, NULL, 0);
```

---

### Step 3: Compile & Run

* Open project in **Dev C++ / VS Code**
* Make sure MySQL connector is properly linked
* Compile and run the program

---

## 📷 System Modules

### 🔐 Admin Panel

* Signup
* Login
* Create Account
* View/Search/Delete Accounts

### 🏧 ATM Machine

* Login with Username & PIN
* Check Balance
* Deposit Money
* Withdraw Money

---

## ⚠️ Limitations

* No encryption for passwords
* No transaction history
* Basic input validation

---

## 🔮 Future Improvements

* 🔐 Password encryption
* 📜 Transaction history
* 📊 Mini statement
* 🎨 GUI interface (C++ or Web-based)
* 🛡️ SQL Injection protection

---

## 🙌 Author

**Owais Khan**
BSCS Student | C++ Developer (Beginner Level)

---

## ⭐ Final Note

This project is created for learning purposes and demonstrates basic banking operations using C++ and MySQL.

Feel free to improve and contribute 🚀
