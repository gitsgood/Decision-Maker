#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

static void inputSafetyCheckString(int& returnedInt) {
	using namespace std;

	constexpr int INTMIN_32 = -2147483648;
	constexpr int INTMAX_32 = 2147483647;

	string userInput{};
	cout << "Please, input thine integer...\n";
	while (true) {
		long long extractedInt{ 0 };
		int signInt{ 1 };
		int signOffset{ 0 };
		bool invalidInput{ false };

		getline(cin, userInput);
		if (userInput.empty()) { cout << "Don't just sit there doing nothing! Try again...\n"; continue; }
		if (userInput[0] == '-') { signInt = -1; signOffset = 1; }
		if (userInput[0] == '+') { signOffset = 1; }
		if (signOffset == 1 && userInput.size() == 1) { cout << "Cheeky little bugger, don't just throw signs at me, INPUT SOMETHING!\n"; continue; }
		if (userInput.size() - signOffset > 10) { cout << "WE CANNOT CONTAIN THIS MANY NUMBERS IN AN INTEGER SPELL\n\tTry again...\n"; continue; }
		for (int i = 0 + signOffset; i < userInput.size(); i++) {
			if ((userInput[i] > '9' || userInput[i] < '0')) {
				cout << "Thine input contains a non digit, this shall not pass! -> '" << userInput[i] << "'\n";
				invalidInput = true;
				continue;
			}
			extractedInt = extractedInt * 10 + (userInput[i] - '0');
		}
		if (invalidInput) { cout << "\tTRY AGAIN YOU RASCAL!\n"; continue; }
		if (extractedInt > INTMAX_32 || extractedInt * signInt < INTMIN_32) {
			cout << "Thine number is an affront to GOD, show some HUMILITY.\n";
			continue;
		}
		returnedInt = extractedInt * signInt;
		break;
	}
}

int main() {
	using namespace std;

	int optionQuantity = 0;
	cout << "Hello my fellow ADHD rotbrain specimen! I will make a decision for you...\n"
		<< "How many options do you have?\n";

	while (optionQuantity < 1 || optionQuantity > 9) {
		inputSafetyCheckString(optionQuantity);
		if (optionQuantity < 1) {
			cout << "No options? Thou art maidenless, go touch some grass (-V-_)9 !\n";
			return 0;
		}
		if (optionQuantity > 9) {
			cout << "Thou hast TOO MANY options l(_`-`) !\n";
		}
	}
	string* optionArray = new string[optionQuantity];

	cout << "Thou hast " << optionQuantity << " options I see...\n"
		<< "\tName them:\n";
	for (int i = 0; i < optionQuantity; i++) {
		cout << "Option " << i+1 << "'s name is: ";
		getline(cin, optionArray[i]);
		cout << endl;
	}

	int luckyNumber = 0;
	int finalDecision = 0;
	cout << "\nAll right, now thou must DECIDE on thine luckiest number, so that I can work my MAGIC...\n";
	inputSafetyCheckString(luckyNumber);
	srand(time(NULL));
	finalDecision = rand() % optionQuantity;
	cout << "\nThine DECISION  has been MADE!\n"
		<< "It shall be: "
		<< optionArray[finalDecision]
		<< endl;
	
	string userConsent{ };
	string yes = "YES";
	cout << "\nEnter 'YES' and submit to my will...\n";
	while (userConsent != yes) {
		getline(cin, userConsent);
		for (char &uWu : userConsent) {
			uWu = toupper(uWu);
		}
		if (userConsent != yes) {
			cout << "A decision has been made, follow your fate, or fight it in vain.\n";
		}
		else { cout << "Good...\n"; }
	}

	delete[] optionArray;
	optionArray = nullptr;
	return 0;
}

//comment