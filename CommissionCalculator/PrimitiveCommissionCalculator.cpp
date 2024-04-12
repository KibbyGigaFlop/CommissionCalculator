#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;

//This program is to help me calculate my art commission prices easier lmao.

static float commissionCalculator(int cropType, int renderType, int extraCharacters, int complexCharacterCount, int background) {

	//Set Illustration Prices (in USD)

	const float extraPersonPercentage = 0.35, backgroundPercentage = 0.5, 
		complexityFee = 10.0;
	float bustPrices[3] = { 10, 25, 40 };
	float halfBodyPrices[3] = { 25, 40, 75 };
	float fullBodyPrices[3] = { 40, 60, 95 };

	float basePrice;
	float total;

	switch (cropType) {

	case 1:

		basePrice = bustPrices[(renderType - 1)];

		break;
	case 2:

		basePrice = halfBodyPrices[(renderType - 1)];

		break;
	case 3:

		basePrice = fullBodyPrices[(renderType - 1)];

		break;

	}

	return total = basePrice + ((basePrice * extraPersonPercentage) * extraCharacters) +
		((basePrice * backgroundPercentage) * background) +
		(complexityFee * complexCharacterCount);


}

int main() {
	/*
		Keeping this here for reference

		const float bustSketchPrice = 10.0, bustLinedPrice = 25.0, bustRenderPrice = 40.0,
		halfbodySketchPrice = 25.0, halfbodyLinedPrice = 40.0, halfbodyRenderPrice = 75.0,
		fullbodySketchPrice = 40.0, fullbodyLinedPrice = 60.0, fullbodyRenderPrice = 95.0; */
	
	//==============================================

	int characterMultiplier = 0, complexCharacterMultiplier = 0,
		backgroundSelected = 0, selectedCroppingType, selectedRenderType, 
		userInputToYNQuestions;

	float grandTotalPrice;
	

	cout << "What commission is the client getting?\nBust (1), Half Body (2), or Full Body (3)?\n\n";
	cin >> selectedCroppingType;
	cout << "Render type?\n Sketch (1), Lined (2), or Full Render(3)\n\n";
	cin >> selectedRenderType;

	cout << "Are there any extra characters? 1 for yes, 0 for no\n\n";
	cin >> userInputToYNQuestions;

		if (userInputToYNQuestions == 1) {
			cout << "How many characters?\n\n";
			cin >> characterMultiplier;

		}

	cout << "Are there any complex characters? 1 for yes, 0 for no \n\n";
	cin >> userInputToYNQuestions;

		if (userInputToYNQuestions == 1) {

			cout << "How many complex characters?\n\n";
			cin >> complexCharacterMultiplier;

		}

	cout << "Is it supposed to be a scene/have a background? 1 for yes, 0 for no \n\n";
	cin >> userInputToYNQuestions;

		if (userInputToYNQuestions == 1) {
		
			backgroundSelected = 1;

		}

		grandTotalPrice = commissionCalculator(selectedCroppingType, selectedRenderType, 
			characterMultiplier, complexCharacterMultiplier, backgroundSelected);

		cout << "The Grand total of this commission is:\n";
		cout << "$" << fixed << setprecision(2) << grandTotalPrice;

}





