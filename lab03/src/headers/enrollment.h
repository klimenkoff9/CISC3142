#include <string>

using namespace std;

struct record_t
{
    string studentID;
    int curseNo;
    string instructorID;
    string termID;
    string sectionID;
    string grade;
};

class Enrollment
{
public:
    Enrollment(string studentID_, int curseNo_, string instructorID_,
               string termID_, string sectionID_, string grade_)
        : studentID(studentID_),
          curseNo(curseNo_),
          instructorID(instructorID_),
          termID(termID_),
          sectionID(sectionID_),
          grade(grade_) {}

    string getStudentID() { return studentID; }
    int getCurseNo() { return curseNo; }
    string getInstructorID() { return instructorID; }
    string getTermID() { return termID; }
    string getSectionID() { return sectionID; }
    string getGrade() { return grade; }

    void setStudentID(string studentID_) { studentID = studentID_; }
    void setCurseNo(int curseNo_) { curseNo = curseNo_; }
    void setInstructorID(string instructorID_) { instructorID = instructorID_; }
    void setTermID(string termID_) { termID = termID_; }
    void setSectionID(string sectionID_) { sectionID = sectionID_; }
    void setGrade(string grade_) { grade = grade_; }

private:
    string studentID;
    int curseNo;
    string instructorID;
    string termID;
    string sectionID;
    string grade;
};