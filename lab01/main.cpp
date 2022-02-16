// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code!

/* Homework Objective: fix this program to match the requirements listed:
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main()
{

    // define variables
    string sku, brand, category, year, price;
    vector<int> vSKU;
    vector<string> vBrand;
    vector<string> vCategory;
    vector<int> vYear;
    vector<float> vPrice;
    map<string, vector<float> > mBrand;
    map<string, vector<float> > mCategory;
    map<int, vector<int> > mYear;

    ifstream in_stream;
    in_stream.open("data.csv"); // opening the file.

    if (!in_stream.fail())
    { // if the file is open

        string line;
        getline(in_stream, line); // read the first line

        while (getline(in_stream, line))
        {
            // while the end of file is NOT reached

            // Fields: sku, brand, category, year, price
            stringstream ss(line); // create a stringstream from the line
            getline(ss, sku, ',');
            stringstream ssku(sku);
            int iSKU = 0;
            ssku >> iSKU;
            vSKU.push_back(iSKU);

            getline(ss, brand, ',');
            stringstream sbrand(brand);
            string sBrand = "";
            sbrand >> sBrand;
            vBrand.push_back(sBrand);

            getline(ss, category, ',');
            stringstream scategory(category);
            string sCategory = "";
            scategory >> sCategory;
            vCategory.push_back(sCategory);

            getline(ss, year, ',');
            stringstream syear(year);
            int iYear;
            syear >> iYear;
            vYear.push_back(iYear);

            getline(ss, price, '\n');
            stringstream sprice(price);
            float fPrice;
            sprice >> fPrice;
            vPrice.push_back(fPrice);

            // update the map
            if (mBrand.find(sBrand) == mBrand.end())
            {
                mBrand[sBrand] = vector<float>();
            }
            mBrand[sBrand].push_back(fPrice);

            if (mCategory.find(sCategory) == mCategory.end())
            {
                mCategory[sCategory] = vector<float>();
            }
            mCategory[sCategory].push_back(fPrice);

            if (mYear.find(iYear) == mYear.end())
            {
                mYear[iYear] = vector<int>();
            }
            mYear[iYear].push_back(iSKU);
        }
        in_stream.close(); // closing the file
    }
    else
    {
        cout << "Unable to open file";
    }

    ofstream out_stream;

    out_stream.open("output.txt"); // opening the file.
    if (!out_stream.fail())
    {
        out_stream
            << "SKU"
            << "\t"
            << "Brand"
            << "\t"
            << "Year" << endl;

        for (int j = 0; j < vSKU.size(); j++)
        {
            out_stream << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << endl;
        }

        out_stream << "Feature 1" << endl;
        // calculate average price per brand
        out_stream << "Average price per brand" << endl;
        for (map<string, vector<float> >::iterator it = mBrand.begin(); it != mBrand.end(); it++)
        {
            float sum = 0;
            for (int i = 0; i < it->second.size(); i++)
            {
                sum += it->second[i];
            }
            out_stream << it->first << ": " << sum / it->second.size() << endl;
        }

        // calculate average price per category
        out_stream << "Average price per category" << endl;
        for (map<string, vector<float> >::iterator it = mCategory.begin(); it != mCategory.end(); it++)
        {
            float sum = 0;
            for (int i = 0; i < it->second.size(); i++)
            {
                sum += it->second[i];
            }
            out_stream << it->first << ": " << sum / it->second.size() << endl;
        }

        out_stream << "Feature 2" << endl;
        out_stream << "Count of SKUs per year" << endl;
        for (map<int, vector<int> >::iterator it = mYear.begin(); it != mYear.end(); it++)
        {
            out_stream << it->first << " (" << it->second.size() << "): ";
            for (int i = 0; i < it->second.size() - 1; i++)
            {
                out_stream << it->second[i] << ", ";
            }
            out_stream << it->second[it->second.size() - 1] << endl;
        }
    }
    else
    {
        out_stream << "Unable to open file";
    }
}