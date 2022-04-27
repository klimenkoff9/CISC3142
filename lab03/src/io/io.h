#ifndef IO_H // To make sure you don't declare the function more than once by including the header multiple times.
#define IO_H

#include <string>
#include <vector>
#include <fstream>
#include "../headers/enrollment.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include <unordered_map>
#include <stdio.h>

using namespace std;

// Reads the file and stores the records in the vector.
void read(string, vector<Enrollment> &);

void write(string, string, string, unordered_map<string, int> &, unordered_map<string, int> &);

#endif