#include <iostream>
#include <vector>
using namespace std;

vector<float> grades;
vector<int> units;
vector<string> course_code;
float e, final_grade, total_grades = 0;
int i, number, decision, total_units;
string c;

void selection() {
cin >> decision;
    while (decision < 0 || decision > 2) {
    cout << "Invalid Response. Try again." << endl;
    cin >> decision;
	}
}

void grade_conversion() { // clunky as hell but idk if there's a better way to go about this
		for (i = 0; i < grades.size(); i++){
			if (grades[i] >= 0 && grades[i] < 50) {
				grades[i] = 0;
			} else if (grades[i] >= 50 && grades[i] < 55.5) {
    			grades[i] = 3.00;
			} else if (grades[i] >= 55.5 && grades[i] < 61) {
    			grades[i] = 2.75;
			} else if (grades[i] >= 61 && grades[i] < 65.5) {
    			grades[i] = 2.50;
			} else if (grades[i] >= 65.5 && grades[i] < 72) {
    			grades[i] = 2.25;
			} else if (grades[i] >= 72 && grades[i] < 77.5) {
    			grades[i] = 2.00;
			} else if (grades[i] >= 77.5 && grades[i] < 83) {
    			grades[i] = 1.75;
			} else if (grades[i] >= 83 && grades[i] < 88.5) {
    			grades[i] = 1.50;
			} else if (grades[i] >= 88.5 && grades[i] < 94) {
				grades[i] = 1.25;
			} else if (grades[i] >= 94 && grades[i] <= 100) {
    			grades[i] = 1.00;
			} else {
    			grades[i] = 8.00;
		}
	}
}

int main (int argc, char** argv) {
    cout << "Grade Converter and Calculator" << endl << endl;
    cout << "Press 1 to convert your grades." << endl << "Press 2 to compute your grades." << endl << endl;
    cout << "Answer: ";

    selection();
 
    if (decision == 1) {
    	cout << endl << "How many grades are you going to convert?" << endl;
    	cout << "Number of Grades: ";
		cin >> number;
    	
    	cout << endl << "Please enter your grades" << endl;
    	
    	for (i = 0; i < number; i++) {
        	cin >> e;
        	grades.push_back(e);
    	}
		
		grade_conversion();
		
		cout << endl << "Converted Grades: ";
		
		for (i = 0; i < grades.size(); i++) { // Again clunky, but switch doesn't like vectors apparently
			if (grades[i] == 0 || grades[i] == 8){
				if (grades[i] ==0) {
					cout << "Failed" << " ";
				}
				else {
					cout << "Invalid Grade" << " ";
				}
			}		
			else {
				cout << grades[i] << "  ";
			}
    	}
	}
	
	else {
		cout << endl << "How many courses do you have?" << endl;
    	cout << "Number of Courses: ";
		cin >> number;
		
		for (i = 0; i < number; i++) { // turn into function later?
			cout << endl << "Input Course: ";
			cin >> c;
        	course_code.push_back(c);
        	
        	cout << "Input Grade in Percentage: ";
        	cin >> e;
        	grades.push_back(e);
        	
        	cout << "Input number of Units: ";
        	cin >> e;
        	units.push_back(e);
		}
		
		for (i = 0; i < number; i++) {
			total_units = total_units + units[i];
		}
			
		for (i = 0; i < number; i++) {
			total_grades = total_grades + grades[i] * units[i];
		}
			
		final_grade = total_grades / total_units;
		
		cout << "Grades for this semester: " << endl;
		cout << endl << "COURSE		Units	Grade" << endl;
		
		for (i = 0; i < number; i++) {
			cout << course_code[i] << "		" << units[i] << "	" << grades[i] << endl;
		}
		cout << endl << "General Weighted Average (GWA) = " << final_grade;
	} 	
		
    return 0;

}
