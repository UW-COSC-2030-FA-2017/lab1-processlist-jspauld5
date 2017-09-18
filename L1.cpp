#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// init variables for first, second, and last two numbers
	int num1, num2, num3, num4;

	// prompt for and get filename
	string filename;
	cout << "Enter the name of the file" << endl;
	cin >> filename;

	// create a ifstream variable to read file
	ifstream file;
	file.open(filename.c_str());

	double buffer = 0, bufferPrev = buffer;
	int counter = 0;

	if (!file) {
		cout << "Error opening file" << endl;
		return 0;
	} else {
		// itterate through the file
		while (!file.fail()) {
			// set bufferPrev = the last iteration of buffer UNLESS end of file
			int currentPos = file.tellg();
			if (currentPos != -1) {
				counter++;
				bufferPrev = buffer;
			}
			file >> buffer;
			int checkWs = file.tellg();
			if (checkWs == -1) {
				counter--;
				break;
			}
			switch (counter) {
			case 1:
				// set the first number
				num1 = buffer;
				break;
			case 2:
				// set the second number
				num2 = buffer;
				break;
			}
			cout << buffer << "\t" << bufferPrev << "\t" << currentPos << "\t" <<
			checkWs << endl;
		}
	}

	// set the last and second to last according to which buffer
	num3 = bufferPrev;
	num4 = buffer;
		

	cout << "Count: " << counter << endl;
	cout << "First: " << num1 << endl;
	cout << "Second: " << num2 << endl;
	cout << "Second to Last: " << num3 << endl;
	cout << "Last: " << num4 << endl;



	return 0;
}