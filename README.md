# Student-Management-System
MindShield-EGY

# UML Class diagram
```mermaid
classDiagram
    class LimiterBase {
        +void drawFrame(char, char, char, int, int)
        <<abstract>> +void start()
    }

    class LimiterS {
        +void drawFrame(char, char, char, int, int)
        <<abstract>> +void start()
    }

    class Limiter {
        +void start()
    }

    class Contributors {
        +void start()
    }

    class Course {
        -string courseId
        -string courseName
        -double creditHours
        -double percentageGrade
        +Course(string, string, double)
        +void setGrade(double)
        +double getGrade() const
        +string getCourseId() const
        +double getCreditHours() const
        +string getLetterGrade() const
        +double getGradePoints() const
        +void displayInfo() const
        +void editCourseInfo(string, double)
    }

    class User {
        #int id
        #string name
        +User(int, string)
        +void displayInfo() const
        +int getId() const
        +string getName() const
    }

    class Student {
        -Course* courses[MAX_COURSES]
        -int courseCount
        +Student(int, string)
        +void addCourse(string, string, double)
        +void removeCourse(string)
        +void inputGrade(string, double)
        +double calculateGPA() const
        +void displayCourses() const
        +void editUserInfo(string)
        +void editCourseInfo(string, string, double)
        +int getCourseIndex(string) const
        ~Student()
    }

    class Administrator {
        -pair<string, pair<string, double>> courseInfo[MAX_COURSES]
        -Student* students[MAX_STUDENTS]
        -int studentCount
        -int courseInfoCount
        +Administrator(int, string)
        +void addCourseInfo(string, string, double)
        +pair<string, double> getCourseInfo(string)
        +void addStudent(int, string)
        +void removeStudent(int)
        +void removeStudentFromCourse(int, string)
        +Student* findStudent(int)
        +void addCourseToStudent(int, string)
        +void displayStudents() const
        +void rankStudents()
        +void addCourse(string, string, double)
        +void removeCourse(string)
        +void removeAllStudents()
        +void removeAllCourses()
        +void editCourseDetails(string, string, double)
        +void displayEnrolledStudents(string) const
        +void readDataFromFile(string)
        +void writeDataToFile(string, Administrator&)
        ~Administrator()
    }

    LimiterBase <|-- Limiter
    LimiterS <|-- Contributors
    User <|-- Student
    User <|-- Administrator
    Student --> Course : enrolls in

    Limiter ..> printColor : uses
    Contributors ..> printColor : uses
    Administrator ..> Student : manages
    Administrator ..> Course : manages

```