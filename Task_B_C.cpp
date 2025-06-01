#include <bits/stdc++.h>
using namespace std;

int low = 0, high = 0, medium = 0;

string classifyLoanRisk(int missed_repayments, float loan_amount, float collateral_value, float interest) {
    float score = (missed_repayments * 2) + (loan_amount / collateral_value) + (interest / 2);
    if (score < 15) return "LOW";
    else if (score <= 25) return "MEDIUM";
    else return "HIGH";
}

int safe_stoi(const string& str) {
    try {
        return stoi(str);
    } catch (...) {
        return 0;
    }
}

float safe_stof(const string& str) {
    try {
        return stof(str);
    } catch (...) {
        return 0.0f;
    }
}

string apply(const string& line) {
    stringstream ss(line);
    vector<string> fields;
    string item;

    while (getline(ss, item, ',')) {
        fields.push_back(item);
    }

    if (fields.size() < 12) return "";

    float loan_amount = safe_stof(fields[4]);
    float collateral_value = safe_stof(fields[5]);
    int missed_repayments = safe_stoi(fields[8]);
    float interest = safe_stof(fields[11]);

    string risk = classifyLoanRisk(missed_repayments, loan_amount, collateral_value, interest);

    if (risk == "HIGH") high++;
    else if (risk == "LOW") low++;
    else medium++;

    return line + "," + risk;
}

int main() {
    string inputPath;
    cout << "Enter input CSV file path: ";
    getline(cin, inputPath);

    ifstream inFile(inputPath);
    if (!inFile.is_open()) {
        cout << "Error: Could not open input file!\n";
        return 1;
    }

    vector<string> updatedRows;
    string line;

    if (getline(inFile, line)) {
        updatedRows.push_back(line + ",risk_level"); 
    }

    while (getline(inFile, line)) {
        string result = apply(line);
        if (!result.empty()) {
            updatedRows.push_back(result);
        }
    }

    inFile.close();

    ofstream outFile(inputPath);
    if (!outFile.is_open()) {
        cout << "Error: Could not write to input file!\n";
        return 1;
    }

    for (const string& row : updatedRows) {
        outFile << row << "\n";
    }

    outFile.close();

    cout << "low - " << low << "\n";
    cout << "medium - " << medium << "\n";
    cout << "high - " << high << "\n";
    cout << "Risk levels written to '" << inputPath << "' successfully.\n";

    return 0;
}
