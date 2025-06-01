#include <bits/stdc++.h>
using namespace std;

map<string, string> faq = {
    {"EMI", "EMI stands for Equated Monthly Installment."},
    {"tenure", "Tenure is the loan repayment period."},
    {"interest", "Interest is the cost of borrowing money."},
    {"collateral", "Collateral is an asset pledged against the loan."},
    {"principal", "Principal is the original loan amount borrowed."},
    {"credit score", "Credit score shows how reliable you are at repaying loans."},
    {"default", "Default means failure to repay the loan on time."},
    {"foreclosure", "Foreclosure is paying off the loan before its end date."},
    {"prepayment", "Prepayment is an early partial or full loan payment."},
    {"disbursal", "Disbursal is when the loan amount is given to you."},
    {"cheque bounce", "Cheque bounce happens when there are insufficient funds."},
    {"NPA", "NPA means the loan has not been repaid for 90+ days."},
    {"overdraft", "Overdraft lets you withdraw more than your account balance."},
    {"lien", "A lien is the lender's legal claim on your asset until the loan is repaid."},
    {"fixed interest", "Fixed interest stays the same through the loan."},
    {"floating interest", "Floating interest changes with the market rate."},
    {"annual interest", "Annual interest is the yearly cost of borrowing money."},
    {"repayment", "Repayment is the act of paying back the loan."},
    {"monthly EMI", "Monthly EMI is the fixed monthly loan payment."},
    {"processing fee", "Processing fee is the charge for processing your loan."},
    {"co-applicant", "A co-applicant shares the loan responsibility with you."},
    {"guarantor", "A guarantor promises to repay the loan if you can't."},
    {"loan sanction", "Loan sanction means the loan has been approved."},
    {"loan agreement", "A loan agreement is a legal document outlining loan terms."},
    {"debt", "Debt is money you owe to someone else."}
};


string preprocess(const string& str) {
    string clean;
    for (char c : str) {
        if (isalnum(c) || isspace(c)) clean += tolower(c);
    }
    return clean;
}

set<string> tokenize(const string& str) {
    set<string> tokens;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        tokens.insert(word);
    }
    return tokens;
}

int getSimilarityScore(const string& userInput, const string& faqQuestion) {
    set<string> inputTokens = tokenize(preprocess(userInput));
    set<string> faqTokens = tokenize(preprocess(faqQuestion));
    int common = 0;
    for (const string& word : inputTokens) {
        if (faqTokens.count(word)) common++;
    }
    return common;
}

string getBestMatchAnswer(const string& userInput) {
    int bestScore = 0;
    string bestAnswer = "Sorry, I couldn't understand that. If you want to end chat please enter 'end'.";
    for (const auto& pair : faq) {
        const string& question = pair.first;
        const string& answer = pair.second;
        int score = getSimilarityScore(userInput, question);
        if (score > bestScore) {
            bestScore = score;
            bestAnswer = answer;
        }
    }
    return bestAnswer;
}

int main() {
    cout << "BOT: Welcome to the Loan Help Chatbot, Please ask your questions!" << endl;

    string question;
    while (true) {
        cout << "\nYou: ";
        getline(cin, question);
        if (preprocess(question) == "end") break;

        string response = getBestMatchAnswer(question);
        cout << "Bot: " << response << endl;
    }

    cout << "\n Chat ended. Thank you!\n";
    return 0;
}
