#ifndef IO_H // To make sure you don't declare the function more than once by including the header multiple times.
#define IO_H

#include <string>
#include <vector>
#include <fstream>
#include "../headers/enrollment.h"
#include <iostream>
#include <sstream>
#include <filesystem>

using namespace std;

// Reads the file and stores the records in the vector.
void read(string, vector<Enrollment> &);

#endif