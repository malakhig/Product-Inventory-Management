// Malakhi Griffin
// Program 2 2/19/2023
// The purpose of this program is to manipulate an inventory vector using struct and functions.

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

// Struct declaration
struct Product {
	string name;	// Name of product
	int qty{};		// Quantity of items in stock
	double price{};	// Price of item in vector 
};

// This function allows the user to pick how they wanted to proceed with the program, has a number validation loop.
int menu() {
	int choice;
	cout << endl;
	cout << "1. Add new poduct\n";
	cout << "2. Average Price\n";
	cout << "3. Highest Price\n";
	cout << "4. Display out of stock\n";
	cout << "5. Display all products in inventory\n";
	cout << "6. Exit the program\n\n";
	cout << "Enter your choice:";
	cin >> choice;
	while ((choice < 1) || (choice > 6)) {
		cout << "ERROR: Please enter number 1-6\n";
		cout << "Enter your choice:";
		cin >> choice;
	}
	return choice;
	

}

// This function allow the user to add a product to the inventory along with quantity and price.
void addprod(vector<Product> &bgInventory) {
	Product tempProduct;

	cout << "Enter product name: ";
	cin >> tempProduct.name;
	cout << "Enter product quantity: ";
	cin >> tempProduct.qty;
	cout << "Enter product price: $"; 
	cin >> tempProduct.price;
	
	
	

	bgInventory.push_back(tempProduct);
	
}

// This function displays the average price of all of the products.
void showavgprice(vector<Product>& bgInventory) {
	int i;
	double sum = 0;
	double avg = 0;
	for (i = 0; i < bgInventory.size(); ++i) {
		sum += bgInventory.at(i).price;
	}
	
	avg = sum / bgInventory.size();
	cout << "The average price is: $" << fixed << setprecision(2) << avg << endl;
}

// This function displays the highest price of all the products in the vector.
void showhiprice(vector<Product>& bgInventory) {
	int i;
	double high;
	int highName{};
	cout << endl;
	high = bgInventory.at(0).price;
	for (i = 0; i < bgInventory.size(); ++i) {
		if (bgInventory.at(i).price > high) {
			high = bgInventory.at(i).price;
			highName = i;
		}
	}
	cout << "The highest price is: " << bgInventory.at(highName).name << "|$" << high << endl;
}

// This function shows all the products with 0 quantity in tabular form.
void showoutofstock(vector<Product>& bgInventory) {
	int i;
	cout << left << setw(5) << "##" << left << setw(10) << "Name" << left << "Qty" << right << setw(10) << "Price" << endl;
	cout << left << setw(5) << "--" << left << setw(10) << "----" << left << "---" << right << setw(10) << "-----" << endl;
	for (i = 0; i < bgInventory.size(); ++i) {
		if (bgInventory.at(i).qty == 0) {
			cout << left << setw(5) << i + 1 << left << setw(10) << bgInventory.at(i).name << left << setw(8) << bgInventory.at(i).qty << left << setw(15) << bgInventory.at(i).price << endl;
		}
	}
	cout << setfill('-') << setw(29);
	cout << "\n";
	cout << setfill(' ');
	cout << endl;
}

// This function shows all products in the vector in tabular form.
void showinventory(vector<Product>& bgInventory) {

	int i;
	cout << left << setw(5) << "##" << left << setw(10) << "Name" << left << "Qty" << right << setw(10) << "Price" << endl;
	cout << left << setw(5) << "--" << left << setw(10) << "----" << left << "---" << right << setw(10) << "-----" << endl;

	for (i = 0; i < bgInventory.size(); ++i) {
	cout << fixed << setprecision(2) << left << setw(5) << i + 1 << left << setw(10) << bgInventory.at(i).name << left << setw(8) << bgInventory.at(i).qty << left << setw(15) << bgInventory.at(i).price << endl;
}

	cout << setfill('-') << setw(29);
	cout << "\n";
	cout << setfill(' ');
	cout << endl;
}

// The main function declares the vector and has a while loop for menu().
int main() {
	int numChoice = 0;
	vector<Product> bgInventory(0);
	
	addprod(bgInventory);
	numChoice = menu();
	while (numChoice != 6) {
		if (numChoice == 1) {
			addprod(bgInventory);
		}
		else if (numChoice == 2) {
			showavgprice(bgInventory);
		}
		else if (numChoice == 3) {
			showhiprice(bgInventory);
		}
		else if (numChoice == 4) {
			showoutofstock(bgInventory);
		}
		else if (numChoice == 5) {
			showinventory(bgInventory);
		}
		numChoice = menu();
	}


	return 0;
}
