#include "io.h"

void read(string fileName, vector<Enrollment> &records)
{
    ifstream in_stream;
    string studentID, curseNo, instructorID, termID, sectionID, grade;
    in_stream.open(fileName); // opening the file.

    if (!in_stream.fail())
    {
        string line;
        getline(in_stream, line); // read the first line
        while (getline(in_stream, line))
        {
            // read in from 5 columns studentID, curseNo, instructorID, termID, sectionID, grade that are separated by a comma
            stringstream ss(line); // create a stringstream from the line

            getline(ss, studentID, ',');
            stringstream sstudentID(studentID);
            string fstudentID = "";
            sstudentID >> fstudentID;

            getline(ss, curseNo, ',');
            stringstream scurseNo(curseNo);
            string fcurseNo = "";
            scurseNo >> fcurseNo;

            getline(ss, instructorID, ',');
            stringstream sinstructorID(instructorID);
            string finstructorID = "";
            sinstructorID >> finstructorID;

            getline(ss, termID, ',');
            stringstream sterminID(termID);
            string ftermID = "";
            sterminID >> ftermID;

            getline(ss, sectionID, ',');
            stringstream ssectionID(sectionID);
            string fsectionID = "";
            ssectionID >> fsectionID;

            getline(ss, grade, ',');
            stringstream sgrade(grade);
            string fgrade = "";
            sgrade >> fgrade;

            records.push_back(Enrollment(fstudentID, fcurseNo, finstructorID, ftermID, fsectionID, fgrade));
        }
        in_stream.close();
    }
    else
    {
        printf("Error opening file %s\n", fileName.c_str());
    }
}

void write(string fileName, string colA, string colB, unordered_map<string, int> &map1, unordered_map<string, int> &map2)
{
    ofstream out_stream(fileName); // opening the file.

    if (!out_stream.fail())
    {
        out_stream << colA
                   << "\t"
                   << colB << endl;

        for (auto it = map1.begin(); it != map1.end(); it++)
        {
            out_stream << it->first
                       << "\t"
                       << (double)it->second / map2[it->first] * 100 << "%" << endl;
        }
    }
    else
    {
        printf("Unable to open file %s\n", fileName.c_str());
    }
    out_stream.close();
}