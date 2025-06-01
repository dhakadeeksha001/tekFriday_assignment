# Loan Risk Assessment & FAQ Chatbot

This project includes two C++ programs:

1. *Loan Help Chatbot* – An interactive command-line chatbot that answers frequently asked loan-related queries.
2. *Loan Risk Classifier* – A CSV-based risk classification tool that evaluates the loan risk level (LOW, MEDIUM, HIGH) based on user financial data.

---

## Features

### 1. Loan Help Chatbot (Chatbot_Task_A.cpp)
- Answers FAQs related to loans such as EMI, interest, tenure, collateral, etc.
- Uses simple keyword matching and similarity scoring to find the best response.
- Gracefully exits when the user types end.

### 2. Loan Risk Classifier (Task_B_C.cpp)
- Accepts a CSV file path with loan-related data.
- Calculates a custom risk score using missed repayments, loan amount, collateral value, and interest rate.
- Classifies the loan as LOW, MEDIUM, or HIGH risk.
- Appends the classification to the original CSV and rewrites it.
- Outputs the count of each risk level.

---

## Requirements

- C++11 or higher
- A C++ compiler like g++
- A CSV file with loan data for the risk classifier (must include fields like loan amount, collateral value, missed repayments, interest rate)

---

## Compilation

```bash
g++ Chatbot_Task_A.cpp -o Chatbot_Task_A
g++ Task_B_C.cpp -o Task_B_C
