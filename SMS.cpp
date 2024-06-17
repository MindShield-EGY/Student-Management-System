/*
 * Copyright (c) 2024 [MindShield-EGY]
 * All rights reserved.
 *
 * This code is licensed under the MIT License.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
g++ <source-file> -o <executable>

#include <array>
#include <chrono> // For delay
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread> // For delay
#include <vector>


#define RESET_COLOR "\033[0m"

#define RED         "\033[31m"     // Defining Red
#define GREEN       "\033[32m"     // Defining Green
#define YELLOW      "\033[33m"     // Defining Yellow
#define BLUE        "\033[34m"     // Defining Blue
#define BOLD        "\033[1m"      // Defining Bold


#ifdef _WIN32

#include <windows.h>

#else
#include <unistd.h>
#endif

using namespace std;
// MindShield Copyrights
const int MAX_COURSES = 100; // Maximum number of courses per student
const int MAX_STUDENTS = 10000;

// MindShield Copyrights
void ClearTerminal() { // Ergonomics
#ifdef _WIN32
    system("cls");
#endif
}
// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
#ifdef _WIN32 //--System Integrity & Cross platform support // MindShield Copyrights
#define RESET_COLOR                                                            \
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),                     \
                          FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
// ANSI code
#define RESET_COLOR "\033[0m"

#define RED         "\033[31m"     // Defining Red
#define GREEN       "\033[32m"     // Defining Green
#define YELLOW      "\033[33m"     // Defining Yellow
#define BLUE        "\033[34m"     // Defining Blue

#define BOLD        "\033[1m"      // Defining Bold

#endif

// Function to print colored and bold text
void printColor(const string &color, const string &text, bool bold = false) {
    cout << (bold ? BOLD : "") << color << text << RESET_COLOR;
}

// MindShield Copyrights
class LimiterBase {
// MindShield Copyrights
protected:
    virtual void drawFrame(char c1, char c2, char c3, int loops, int milliseconds) {
        for (int i = 0; i <= loops; ++i) {
            cout << " " << c1;
            this_thread::sleep_for(chrono::milliseconds(milliseconds));
            cout << "\b\b"; // Erase the character
            cout.flush();
            cout << " " << c2;
            this_thread::sleep_for(chrono::milliseconds(milliseconds));
            cout << "\b\b"; // Erase the character
            cout.flush();
            cout << " " << c3;// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
            this_thread::sleep_for(chrono::milliseconds(milliseconds));
            cout << "\b\b"; // Erase the character
            // ! Erasing animation
            this_thread::sleep_for(chrono::milliseconds(milliseconds));
            cout << "\b\b";
            cout.flush();
        }
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

public:
    virtual void start() = 0;
};

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
class LimiterS {

protected:
    virtual void drawFrame(char c1, char c2, char c3, int loops,
                           int Secs) {
        for (int i = 0; i <= loops; ++i) {

            cout << " " << c1;
            this_thread::sleep_for(chrono::milliseconds(Secs));
            cout << "\b\b"; // Erase the character
            cout.flush();
            cout << " " << c2;
            this_thread::sleep_for(chrono::milliseconds(Secs));
            cout << "\b\b"; // Erase the character
            cout.flush();
            cout << " " << c3;
            this_thread::sleep_for(chrono::milliseconds(Secs));
            cout << "\b\b"; // Erase the character
            // ! Erasing animation
            this_thread::sleep_for(chrono::milliseconds(Secs));
            cout << "\b\b";
            cout.flush();
        }
        this_thread::sleep_for(chrono::milliseconds(Secs));
    }
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
public:
    virtual void start() = 0;
};
// MindShield Copyrights// MindShield Copyrights

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
class Limiter : public LimiterBase {
public:
    void start() override {
        printColor(RED, "Limiter is Active", true);
        drawFrame('-', '/', '|', 9, 80);
        ClearTerminal();
    }
};

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
class Contributors : public LimiterS {
public:
    void start() override {
        printColor(GREEN, " Contributors", true);
        drawFrame('-', '/', '|', 6, 200);
        ClearTerminal();
    }
};

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
// Course class to store course information
class Course {
private:
    string courseId;
    string courseName;
    double creditHours;
    double percentageGrade;
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
public:
    Course(const string &courseId, const string &courseName, double creditHours)
            : courseId(courseId), courseName(courseName), creditHours(creditHours),
              percentageGrade(-1) {}// MindShield Copyrights// MindShield Copyrights
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    void setGrade(double percentageGrade) {
        this->percentageGrade = percentageGrade;
    }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    double getGrade() const { return percentageGrade; }

    string getCourseId() const { return courseId; }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    double getCreditHours() const { return creditHours; }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    string getLetterGrade() const {
        if (percentageGrade >= 97 && percentageGrade <= 100)
            return "A+";
        else if (percentageGrade >= 93 && percentageGrade < 97)
            return "A";
        else if (percentageGrade >= 89 && percentageGrade < 93)
            return "A-";
        else if (percentageGrade >= 84 && percentageGrade < 89)
            return "B+";
        else if (percentageGrade >= 80 && percentageGrade < 84)
            return "B";
        else if (percentageGrade >= 76 && percentageGrade < 80)
            return "B-";
        else if (percentageGrade >= 73 && percentageGrade < 76)
            return "C+";
        else if (percentageGrade >= 70 && percentageGrade < 73)
            return "C";
        else if (percentageGrade >= 67 && percentageGrade < 70)
            return "C-";
        else if (percentageGrade >= 64 && percentageGrade < 67)// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
            return "D+";
        else if (percentageGrade >= 60 && percentageGrade < 64)
            return "D";
        else if (percentageGrade < 0 || percentageGrade > 100)
            return "null"; // If percentage is negative or greater than 100, return
            // "null" // MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
        else
            return "F";// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
    }

    double getGradePoints() const {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        string letterGrade = getLetterGrade();
        if (letterGrade == "A+" || letterGrade == "A")
            return 4.0;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "A-")
            return 3.7;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "B+")
            return 3.3;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "B")
            return 3.0;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "B-")
            return 2.7;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "C+")// MindShield Copyrights
            return 2.3;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade ==
                 "C")// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            return 2.0;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "C-")
            return 1.7;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "D+")
            return 1.3;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "D")
            return 1.0;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else if (letterGrade == "F")
            return 0.0;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        else
            return 0.0; // Return 0.0 for "null" grade// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    }

    void
    displayInfo() const { // MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        cout << "Course ID: " << courseId << "\tCourse Name: " << courseName
             << "\tCredit Hours: " << creditHours << "\tGrade: " << getLetterGrade()
             << " (" << getGradePoints() << " points)"
             << endl;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

    void editCourseInfo(const string &newCourseName, double newCreditHours) {
        courseName = newCourseName;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        creditHours = newCreditHours;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        cout << "Course details updated."
             << endl;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        // MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
};

// User class to store user information
class User {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
protected:
    int id;
    string name;

public:
    User(int id, const string &name) : id(id), name(name) {}

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    void displayInfo() const {
        cout << "ID: " << id << "\tName: " << name << endl;
    }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    int getId() const { return id; }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    string getName() const { return name; }
};// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

// Student class derived from User// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
class Student : public User {
private:
    Course *courses[MAX_COURSES]; // Array to store courses
    int courseCount;
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
public:
    friend class Administrator;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    Student(int id, const string &name) : User(id, name), courseCount(0) {}

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    void addCourse(const string &courseId, const string &courseName,
                   double creditHours) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        if (courseCount <
            MAX_COURSES) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            courses[courseCount++] = new Course(courseId, courseName, creditHours);
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    void removeCourse(
            const string &courseId) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        for (int i = 0; i <
                        courseCount; ++i) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            if (courses[i]->getCourseId() == courseId) {
                delete courses[i];// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                for (int j = i; j < courseCount - 1; ++j) {
                    courses[j] = courses[j +
                                         1];// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                courseCount--;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                cout << "Course with ID " << courseId << " removed for student with ID "
                     << getId() << "." << endl;
                return;
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        }
        cout << "Course with ID " << courseId << " not found for student with ID "
             << getId() << "."
             << endl;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

    void inputGrade(const string &courseId, double percentageGrade) {
        for (int i = 0; i <
                        courseCount; ++i) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            if (courses[i]->getCourseId() ==
                courseId) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                courses[i]->setGrade(
                        percentageGrade);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                cout << "Grade added for course ID "
                     << courseId// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                     << " for student with ID " << getId() << "."
                     << endl;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                return;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        }
        cout << "Course with ID " << courseId << " not found for student with ID "
             << getId() << "." << endl;
    }

    double
    calculateGPA() const {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        double totalPoints = 0;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        double totalCreditHours = 0;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        for (int i = 0; i <
                        courseCount; ++i) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            if (courses[i]->getGrade() >=
                0) { // Only consider graded courses for GPA calculation// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                totalPoints +=
                        courses[i]->getGradePoints() * courses[i]->getCreditHours();
                totalCreditHours += courses[i]->getCreditHours();
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        }
        if (totalCreditHours > 0) {
            return totalPoints / totalCreditHours;
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        return 0; // Return 0 if no courses
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

    void
    displayCourses() const {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        for (int i = 0; i <
                        courseCount; ++i) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            courses[i]->displayInfo();// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    void editUserInfo(const string &newName) {
        name = newName;
        cout << "\nStudent details updated." << endl;
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    void editCourseInfo(const string &courseId, const string &newCourseName,
                        double newCreditHours) {
        for (int i = 0; i < courseCount; ++i) {
            if (courses[i]->getCourseId() == courseId) {
                courses[i]->editCourseInfo(newCourseName, newCreditHours);
                cout << "Course details updated for student with ID " << getId() << "."
                     << endl;
                return;
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        }
        cout << "Course with ID " << courseId << " not found for student with ID "
             << getId() << "." << endl;
    }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    int getCourseIndex(const string &courseId) const {
        for (int i = 0; i < courseCount; ++i) {
            if (courses[i]->getCourseId() == courseId) {
                return i;
            }
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        return -1; // Course not found
    }

    ~Student() {
        for (int i = 0; i < courseCount; ++i) {
            delete courses[i];
        }
    }
};
int mindshield_egy = 1;
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
// Administrator class derived from User
class Administrator : public User {
private:
    pair<string, pair<string, double>>
            courseInfo[MAX_COURSES]; // Array to store course information linked with course ID
    Student *students[MAX_STUDENTS];
    int studentCount;
    int courseInfoCount;
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
public:
    Administrator(int id, const string &name)
            : User(id, name), studentCount(0), courseInfoCount(0) {}

    void addCourseInfo(const string &courseId, const string &courseName,
                       double creditHours) {
        if (courseInfoCount < MAX_COURSES) {
            courseInfo[courseInfoCount++] =
                    make_pair(courseId, make_pair(courseName, creditHours));
        }
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    pair<string, double> getCourseInfo(const string &courseId) {
        for (int i = 0; i < courseInfoCount; ++i) {
            if (courseInfo[i].first == courseId) {
                return courseInfo[i].second;
            }
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        return make_pair("", 0.0); // Return empty pair if course not found
    }

// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    void addStudent(int id, const string &name) {
        int x = 0;
        for (int i = 0; i < studentCount; ++i) {
            if (students[i]->getId() == id) {
                printColor(RED, "Duplicated id (This data won't be saved) \n",
                           true);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                x = 1;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        if (studentCount < MAX_STUDENTS && x == 0) {
            students[studentCount++] = new Student(id, name);

            printColor(GREEN, "Student added with ID ", true);
            cout
                    << id;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            printColor(BLUE, ".\nStudent name is ",
                       true);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            cout << name << "." << endl;
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            x = 1;
        }
    }

    void removeStudent(int id) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i]->getId() == id) {
                delete students[i];
                for (int j = i; j < studentCount - 1; ++j) {
                    students[j] = students[j + 1];
                }// MindShield Copyrights// MindShield Copyrights
                studentCount--;
                cout << "Student with ID " << id << " removed." << endl;
                return;
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        cout << "Student with ID " << id << " not found." << endl;
    }

    void removeStudentFromCourse(int studentId, const string &courseId) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i]->getId() == studentId) {
                students[i]->removeCourse(courseId);
                return;
            }
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        cout << "Student with ID " << studentId << " not found." << endl;
    }

    Student *findStudent(int id) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i]->getId() == id) {
                return students[i];
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        return nullptr;
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

    void addCourseToStudent(int studentId, const string &courseId) {
        Student *student = findStudent(studentId);
        if (student) {
            pair<string, double> courseInfo = getCourseInfo(courseId);
            if (!courseInfo.first.empty()) {
                student->addCourse(courseId, courseInfo.first, courseInfo.second);
                cout << "Course " << courseInfo.first << " added for student ID "
                     << studentId << "." << endl;
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            else {
                cout << "Course with ID " << courseId << " not found." << endl;
            }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        } else {
            cout << "Student with ID " << studentId << " not found." << endl;
        }// MindShield Copyrights
    }

    void displayStudents() const {
        for (int i = 0; i <
                        studentCount; ++i) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            students[i]->displayInfo();
            students[i]->displayCourses();
            cout << "GPA: " << students[i]->calculateGPA() << endl;
        }
    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

    // Bubble sort implementation to rank students based on GPA
    void rankStudents() {
        for (int i = 0; i < studentCount - 1; ++i) {
            for (int j = 0; j < studentCount - i - 1; ++j) {
                if (students[j]->calculateGPA() < students[j + 1]->calculateGPA()) {
                    // Swap students
                    Student *temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        cout << "\n  Rank\tStudent ID\tStudent Name\tGPA" << endl;
        cout << "------------------------------------------------" << endl;
        for (int i = 0; i < studentCount; ++i) {
            cout << "   " << i + 1 << "\t " << students[i]->getId() << "\t"
                 << students[i]->getName() << "\t";
            cout << students[i]->calculateGPA() << endl;
        }
    }

    void addCourse(const string &courseId, const string &courseName,
                   double creditHours) {
        addCourseInfo(courseId, courseName, creditHours);
        cout << "Course " << courseName << " added with ID " << courseId << "."
             << endl;
    }

    void removeCourse(const string &courseId) {
        // Remove course from courseInfo
        int indexToRemove = -1;
        for (int i = 0; i < courseInfoCount; ++i) {
            if (courseInfo[i].first == courseId) {
                indexToRemove = i;// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
                break;
            }// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
        }
        if (indexToRemove != -1) {
            for (int i = indexToRemove; i < courseInfoCount - 1; ++i) {
                courseInfo[i] = courseInfo[i + 1];
            }
            courseInfoCount--;
        }

        // Remove course from all students
        for (int i = 0; i < studentCount; ++i) {
            students[i]->removeCourse(courseId);
        }

        cout << "Course with ID " << courseId << " removed." << endl;
    }

    void removeAllStudents() {
        for (int i = 0; i < studentCount; ++i) {
            delete students[i];
        }
        studentCount = 0;
        cout << "All students removed." << endl;
    }

    void removeAllCourses() {
        courseInfoCount = 0;
        for (int i = 0; i < studentCount; ++i) {
            students[i]->removeCourse(courseInfo[i].first);
        }
        cout << "All courses removed." << endl;
    }

    // Edit course details
    void editCourseDetails(const string &courseId, const string &newCourseName,
                           double newCreditHours) {
        for (int i = 0; i < courseInfoCount; ++i) {
            if (courseInfo[i].first == courseId) {
                // Update course info
                courseInfo[i].second.first = newCourseName;
                courseInfo[i].second.second = newCreditHours;
                // Update course details for all enrolled students
                for (int j = 0; j < studentCount; ++j) {
                    students[j]->editCourseInfo(courseId, newCourseName, newCreditHours);
                }
                cout << "\nCourse details updated." << endl;
                return;
            }
        }
        cout << "Course with ID " << courseId << " not found." << endl;
    }

    // Display enrolled students for a specific course
    void displayEnrolledStudents(const string &courseId) const {
        cout << "Enrolled students for course with ID " << courseId << ":" << endl;
        bool found = false;
        for (int i = 0; i < studentCount; ++i) {
            if (students[i]->getCourseIndex(courseId) != -1) {
                found = true;
                cout << "Student ID: " << students[i]->getId()
                     << "\tName: " << students[i]->getName() << endl;
            }
        }
        if (!found) {
            printColor(RED, "No students enrolled in course with ID ", true);
        }
    }

    void readDataFromFile(const string &filename) {
        ifstream infile(filename);
        if (infile.is_open()) {
            string line;
            while (getline(infile, line)) {
                istringstream iss(line);
                char type;
                iss >> type;
                if (type == 'S') {
                    int id;
                    string name;
                    iss >> id;
                    getline(iss, name);
                    addStudent(id, name);
                } else if (type == 'C') {
                    string courseId, courseName;
                    double creditHours;
                    iss >> courseId >> courseName >> creditHours;
                    addCourseInfo(courseId, courseName, creditHours);
                } else if (type == 'E') {
                    int studentId;
                    string courseId;
                    iss >> studentId >> courseId;
                    addCourseToStudent(studentId, courseId);
                } else if (type == 'G') {
                    int studentId;
                    string courseId;
                    double percentageGrade;
                    iss >> studentId >> courseId >> percentageGrade;
                    findStudent(studentId)->inputGrade(courseId, percentageGrade);
                }
            }
            infile.close();
        } else {
            cerr << "Unable to open file for reading.";
        }
    }

    void writeDataToFile(const string &filename, Administrator &admin) {
        ofstream outfile(filename);
        if (outfile.is_open()) {
            // Write course info
            for (int i = 0; i < admin.courseInfoCount; ++i) {
                outfile << "C " << admin.courseInfo[i].first << " "
                        << admin.courseInfo[i].second.first << " "
                        << admin.courseInfo[i].second.second << endl;
            }

            // Write students and their courses
            for (int i = 0; i < admin.studentCount; ++i) {
                outfile << "S " << admin.students[i]->getId() << " "
                        << admin.students[i]->getName() << endl;
                for (int j = 0; j < admin.students[i]->courseCount; ++j) {
                    outfile << "E " << admin.students[i]->getId() << " "
                            << admin.students[i]->courses[j]->getCourseId() << endl;
                    double grade = admin.students[i]->courses[j]->getGrade();
                    if (grade >= 0) {
                        outfile << "G " << admin.students[i]->getId() << " "
                                << admin.students[i]->courses[j]->getCourseId() << " "
                                << grade << endl;
                    }
                }
            }

            outfile.close();
            cout << "Data successfully written to file: " << filename << endl;
        } else {
            cerr << "Unable to open file for writing: " << filename << endl;
        }
    }

    ~Administrator() {
        for (int i = 0; i < studentCount; ++i) {
            delete students[i];
        }
    }
};

void menu_of_options() {
    printColor(GREEN, "\n***** Welcome to Student Managment System *****\n\n",
               true);

    printColor(BLUE, "1. Add Student\n", false);
    printColor(BLUE, "2. Add Course\n", false);
    printColor(BLUE, "3. Enroll Student To A Course\n", false);
    printColor(BLUE, "4. Input Grade for Course\n\n", false);

    printColor(YELLOW, "6.  Edit Course Details\n", false);
    printColor(YELLOW, "7.  Find Specific Student\n", false);
    printColor(YELLOW, "5.  Edit Student Details\n", false);
    printColor(YELLOW, "8.  Display Enrolled Students for a Specific Course\n", false);
    printColor(YELLOW, "9.  Display Detailed Students info\n", false);
    printColor(YELLOW, "10. Rank Students by GPA\n\n", false);

    printColor(RED, "11. Remove Course\n", false);
    printColor(RED, "12. Remove Student\n", false);
    printColor(RED, "13. Remove Student from Course\n", false);
    printColor(RED, "14. Remove All Students\n", false);
    printColor(RED, "15. Remove All Courses\n", false);
    printColor(RED, "16. Clear Terminal\n", true);// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
    printColor(RED, "17. Exit\n", true);
    cout
            << "\n";// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
}


int main() {
    if(mindshield_egy == 1) {
        Contributors CC;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        Administrator admin1(1,
                             "Program Director");// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        admin1.readDataFromFile(
                "C:\\Users\\awaad\\OneDrive\\Documents\\PROJECT\\PROJECT.txt");
        CC.start();
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        int choice, studentId;
        double grade;
        string studentName, courseId, newCourseName;
        double newCreditHours;

        do {
            menu_of_options();
            cout << "Enter your choice: ";
            cin
                    >> choice;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            if (cin.fail()) {
                cin.clear();// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                cin.ignore(256, '\n');
                continue;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            }

            switch (choice) {
                case 1:
                    cout << "Enter Student ID: ";
                    cin
                            >> studentId;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cin.ignore();// MindShield Copyrights// MindShield Copyrights
                    cout << "Enter Student Name(First Name, Last Name): ";
                    getline(cin,
                            studentName);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    admin1.addStudent(studentId,
                                      studentName);// MindShield Copyrights // MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    break;
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                case 2:
                    cout << "Enter Course ID: ";
                    cin >> courseId;
                    cin.ignore();// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cout << "Enter Course Name: ";
                    getline(cin, studentName);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cout << "Enter Credit Hours: ";
                    double creditHours;
                    cin >> creditHours;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    admin1.addCourse(courseId, studentName, creditHours);
                    break;

                case 3:
                    cout << "Enter Student ID: ";
                    cin >> studentId;
                    cin.ignore();
                    if (admin1.findStudent(studentId)) {
                        cout
                                << "Enter Course ID: ";// MindShield Copyrights // MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                        getline(cin, courseId);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                        admin1.addCourseToStudent(studentId,
                                                  courseId);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    } else {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                        cout << "Student with ID " << studentId << " not found." << endl;
                    }
                    break;
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                case 4:
                    cout << "Enter Student ID: ";
                    cin
                            >> studentId;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cin.ignore();
                    if (admin1.findStudent(studentId)) {
                        cout
                                << "Enter Course ID: ";// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                        cin >> courseId;// MindShield Copyrights// MindShield Copyrights
                        cout << "Enter Grade (Percentage): ";// MindShield Copyrights// MindShield Copyrights
                        cin >> grade;// MindShield Copyrights// MindShield Copyrights
                        admin1.findStudent(studentId)->inputGrade(courseId, grade);
                    } else {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                        cout << "Student with ID " << studentId << " not found."
                             << endl;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    }
                    break;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

                case 5:// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cout
                            << "Enter Student ID to edit details: ";// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cin >> studentId;
                    cin.ignore();
                    if (admin1.findStudent(studentId)) {
                        cout
                                << "Enter new Student Name(First Name, Last Name): ";// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                        getline(cin,
                                studentName);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                        admin1.findStudent(studentId)->editUserInfo(studentName);
                    }// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    else {
                        cout << "Student with ID " << studentId << " not found." << endl;
                    }
                    break;

                case 6:
                    cout << "Enter Course ID to edit details: ";
                    cin >> courseId;
                    cin.ignore();
                    if (admin1.getCourseInfo(courseId).first != "") {
                        cout << "Enter new Course Name: ";
                        getline(cin, newCourseName);
                        cout << "Enter new Credit Hours: ";
                        cin >> newCreditHours;
                        admin1.editCourseDetails(courseId, newCourseName,
                                                 newCreditHours);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    } else {
                        cout << "Course with ID " << courseId << " not found." << endl;
                    }
                    break;

                case 7:
                    cout << "Enter Student ID: ";
                    cin >> studentId;
                    {
                        Student *foundStudent = admin1.findStudent(studentId);
                        if (foundStudent) {// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                            cout << "Student found:" << endl;
                            foundStudent->displayInfo();
                            foundStudent->displayCourses();
                            cout << "GPA: " << foundStudent->calculateGPA() << endl;
                        } else {
                            cout << "Student with ID " << studentId << " not found." << endl;
                        }
                    }
                    break;

                case 8:
                    cout << "Enter Course ID: ";
                    cin >> courseId;
                    admin1.displayEnrolledStudents(courseId);
                    break;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

                case 9:// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    admin1.displayStudents();
                    break;

                case 10:// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    admin1.rankStudents();
                    break;
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                case 11:// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cout << "Enter Student ID to remove: ";
                    cin >> studentId;
                    admin1.removeStudent(
                            studentId);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    break;

                case 12:
                    cout
                            << "Enter Course ID to remove: ";// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cin >> courseId;
                    admin1.removeCourse(courseId);
                    break;

                case 13:
                    cout
                            << "Enter Student ID: ";// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cin >> studentId;
                    cin.ignore();
                    cout << "Enter Course ID to remove: ";
                    getline(cin, courseId);
                    admin1.removeStudentFromCourse(studentId,
                                                   courseId);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    break;

                case 14:
                    admin1.removeAllStudents();// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrightsv// MindShield Copyrights
                    break;// MindShield Copyrights// MindShield Copyrights

                case 15:// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    admin1.removeAllCourses();// MindShield Copyrights// MindShield Copyrights
                    break;

                case 16:
                    ClearTerminal();// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrightsv// MindShield Copyrights
                    break;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

                case 17:// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                    cout << "Exiting..." << endl;
                    break;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights

                default:
                    cout << "Invalid choice! please try again" << endl;// MindShield Copyrightsv
                    break;// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
            }

        } while (choice != 17);
// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
        admin1.writeDataToFile(// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
                "C:\\Users\\awaad\\OneDrive\\Documents\\PROJECT\\PROJECT.txt",
                admin1);// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
    }
    return 0;// MindShield Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights// MindShield Copyrights
}
// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights// MindShield-EGY Copyrights
