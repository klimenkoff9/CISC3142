#include "io.h"

void read(string fileName, vector<Enrollment> &records)
{
    ifstream in_stream;
    in_stream.open(fileName); // opening the file.

    if (!in_stream.fail())
    {
        string line;
        while (getline(in_stream, line))
        {
            stringstream ss(line);
            string studentID, instructorID, termID, sectionID, grade;
            int curseNo;
            ss >> studentID >> curseNo >> instructorID >> termID >> sectionID >> grade;
            records.push_back(Enrollment(studentID, curseNo, instructorID, termID, sectionID, grade));
        }
        in_stream.close();
    }
    else
    {
        cout << "Error: cannot open file " << fileName << endl;
    }
}