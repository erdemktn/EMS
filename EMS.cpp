#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
	int personNo;
	string name;
	string position;

public:
	Employee(int no, string name_, string position_) {
		personNo = no;
		name = name_;
		position = position_;
	}
	int getPersonNo() const { return personNo; }
	string getName() const { return name; }
	string getPosition() const { return position; }

	void print() const {
		cout << "Employee No: " << personNo << " Name: " << name << " Position: " << position << endl;
	}
};

void addEmployee(vector<Employee>& vEmployes) {
	int no;
	string name, position;

	cout << "Employee No:";
	cin >> no;
	cin.ignore();
	cout << "Employee Name: ";
	getline(cin, name);
	cout << "Employee Position: ";
	getline(cin, position);

	vEmployes.push_back(Employee(no, name, position));
	cout << "Employee was succesfuly added." << endl;
}

void listEmployee(const vector<Employee>& vEmployes) {
	if (vEmployes.empty()) {
		cout << "Employee list is empty." << endl;
		return;
	}
	cout << "\n---- Employee List ----\n";
	for (const auto& personel : vEmployes) {
		personel.print();
	}

}

void searchEmployee(const vector<Employee>& vEmployes) {
	int no;
	cout << "Enter the search employee no: ";
	cin >> no;
	for (const auto& p : vEmployes) { //listed
		if (p.getPersonNo() == no) {
			cout << "Succesfuly, Employee list:\n";
			p.print();
			return;
		}
	}
	cout << "The employee not found!\n";
}

void removeEmployee(vector<Employee>& vEmployes) {
	int no;
	cout << "Enter the remove employee no: ";
	cin >> no;
	for (auto it = vEmployes.begin(); it != vEmployes.end(); it++) {
		if (it->getPersonNo() == no) {
			vEmployes.erase(it);
			cout << "The employe was succesfuly removed..\n";
			return;
		}
	}
	cout << "The employee not found!\n";
}

int main() {
	vector<Employee> vEmployes;
	int choice;

	do {
		cout << "\n---- Employee Management System ----\n";
		cout << "1. Add Employee\n";
		cout << "2. List Employee\n";
		cout << "3. Search Employee\n";
		cout << "4. Remove Employee\n";
		cout << "5. Exit\n";

		cout << "Enter the choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			addEmployee(vEmployes);
			break;
		case 2:
			listEmployee(vEmployes);
			break;
		case 3:
			searchEmployee(vEmployes);
			break;
		case 4:
			removeEmployee(vEmployes);
			break;


		default:
			cout << "Invalid choice, Please enter  1-5 between number!" << endl;
			break;
		}

	} while (choice != 5);

}