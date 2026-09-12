// Windows Automation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

int main()
{
	//The sum variable is the number of files that the user wants to make. The directory variable is the location of the new file(s).
	int sum;
	std::filesystem::path directory;
	std::cout << "How many files would you like to make?" << "\n";
	std::cin >> sum;
	std::cout << "Enter the location of the new file(s):" << "\n";
	std::cin >> directory;

	//We create a loop of file creation, until the number of created files is equal to the number of files that the user wants to make.
	while (sum > 0) {
		std::filesystem::path c;
		int t = 0;
		std::string type;
		std::string fileName;
		std::string stem;
		int number;
		
		//The c variable stores the location of the file that the user wants to copy from.
		std::cout << "Enter the file that you want to copy from:" << "\n";
		std::cin >> c;
		std::cout << "Name these files." << "\n";
		std::cin >> fileName;
		while (type != "1" && type != "2" && type != "3") {
			//The user is asked what kind of file they want to make. 1 is for Word, 2 is for Excel, and 3 is for Powerpoint, and the type variable stores the user's input.
			std::cout << "Please press 1 for Word, 2 for Excel, and 3 for Powerpoint" << "\n";
			std::cout << "What kind of file would you like to make?" << "\n";
			std::cin >> type;
		}
		t = std::stoi(type);
		//The extension of the new file, stored in stem variable, is identified by the type of the file.
		switch (t) {
			case 1:
				stem = ".docx";
				break;
			case 2:
				stem = ".xlsx";
				break;
			case 3:
				stem = ".pptx";
				break;
		}
		//The user is asked how many of the new files they want to make, and the number variable stores their input.
		std::cout << "How many of these files would you like to make?:" << "\n";
		std::cin >> number;

		for (int i = 0; i < number;i++) {
			//The new file is created.
			std::fstream f;
			std::string newFile = fileName;
			//If the new file has the same name as the previously created file. We assign a new number to the new file.
			if (i > 0) newFile += std::to_string(i);
			//The extension of the new file is added to its name.
			newFile += stem;
			f.open(directory/newFile, std::ios::out);
			//The file stored in the c variable is copied to the new file.
			std::filesystem::copy(c, directory/newFile, std::filesystem::copy_options::overwrite_existing);
			//The sum variable is decremented by 1, indicating that one less file needs to be created.
			sum--;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
