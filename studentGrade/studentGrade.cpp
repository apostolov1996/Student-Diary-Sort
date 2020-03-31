#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef struct {
	std::string firstName{};
	int grade{};
}Student;


int getInteger() {
	int integer{};
	while (true) {
		std::cin >> integer;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, please try again\n";
		}
		else {
			std::cin.ignore(32767, '\n');
			return integer;
		}
	}
}

int getGrade() {
	constexpr int MAX_GRADE{ 100 };
	constexpr int MIN_GRADE{ 1 };
	int grade{};
	while (true) {
		std::cout << "Insert the grade: ";
		grade={ getInteger() };
		if (grade > MAX_GRADE || grade < MIN_GRADE) {
			std::cout << "Invalid input, please try again.\n";
		}
		else {
			return grade;
		}
	}
}

std::string getName() {
	std::cout << "Insert student name: ";
	std::string name;
	std::cin >> name;
	return name;
}

const int getNumberOfStudents() {
	int numberOfStudents{};
	while (true) {
		std::cout << "Insert the number of students: ";
		numberOfStudents = getInteger();
		if (numberOfStudents <= 0) {
			std::cout << "Invalid input, please try again.\n";
		}
		else {
			return numberOfStudents;
		}
	}
}

std::vector<Student> diaryConstructor() {
	
	std::vector<Student> students(getNumberOfStudents());
	
	int studentCounter{ 0 };
	for (auto &student : students) {
		studentCounter++;
		printf("Insert data related to student: %d\n", studentCounter);
		student.firstName = getName();
		student.grade = getGrade();
	}
	return students;

}

void printDiary(std::vector<Student> students) {
	int studentCounter{ 0 };
	for (auto student : students) {
		studentCounter++;
		std::cout << "\n\n--------------------------------------\n\n";
		printf("Student %d data:\n", studentCounter);
		std::cout << student.firstName << " got a grade of " << student.grade << '\n';
	}
}

bool greater(Student a, Student b) {
	return (a.grade > b.grade);
}

int main() {
	
	// GREETINS PRINT
	std::cout << "Hello this is your personal students diary\n";

	// DIARY DEFINTIION
	std::vector<Student> students{ diaryConstructor() };
	std::cout << "Before sorting\n";
	printDiary(students);
	std::sort(students.begin(), students.end(), greater);
	std::cout << "After sorting\n";
	printDiary(students);
	

	return 0;
}