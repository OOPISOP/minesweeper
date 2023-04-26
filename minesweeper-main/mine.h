/***********************************************************************
 * File: Mine.h
 * Author: B11115028
 * Create Date: 2023/04/16
 * Editor: B11115028
 * Update Date: 2023/04/25
 * Description: Mine.h
***********************************************************************/

#ifndef MINE_H
#define MINE_H

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

class Mine
{
private:

    vector<vector<char>> mapBoard;

    vector<vector<char>> mapAnswer;

    bool fileOrInOutput = false;

public:

    void setFileOrInOutput(bool fileOrInOutput);

    bool inputCheck(int* row, int* col, float* mine, bool rateCheck);

    void readFileMapRange(ifstream* file);

    bool boardSet(ifstream* file, ofstream* output);

    bool randomSet(const int row, const int col, const int mine);

    bool stateSet(ifstream* file, ofstream* output, const int row, const int col, const int mine);

    int runMap(vector<vector<char>>map, ofstream* output, const char check, const bool inOrOut, const bool getDataOrRun);

    void surroundBomb();

    void printCommand(ifstream* file, ofstream* output, string state, int* blankArray, bool readFile);

    void spread(int inY, int inX);

};

#endif // MINE_H
