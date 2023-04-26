/***********************************************************************
 * File: Mine.h
 * Author: B11115028
 * Create Date: 2023/04/16
 * Editor: B11115028
 * Update Date: 2023/04/25
 * Description: Mine.h
***********************************************************************/

#include "Mine.h"

void out(ofstream* output, string command, bool readOrInput)
{
    if (readOrInput)
        (*output) << command;
    else
        cout << command;
}

string input(ifstream* file, bool readOrInput)
{
    string command;
    if (readOrInput)
        (*file) >> command;
    else
        cin >> command;
    return command;
}

void inputInt(ifstream* file, bool readOrInput, int* inY, int* inX)
{
    if (readOrInput)
        (*file) >> (*inY) >> (*inX);
    else
        cin >> (*inY) >> (*inX);
}


void Mine::setFileOrInOutput(bool fileOrInOutput)
{
    this->fileOrInOutput = fileOrInOutput;
}

// The function implement
bool Mine::inputCheck(int* row, int* col, float* mine, bool rateCheck)
{
    cout << "Please ipnut row、col and mine" << endl;

                    // Make sure rows cols and mines number can't be negative

                        cin >> *row >> *col >> *mine;

    // Make sure Map can exist
    if (*row <= 0 || *col <= 0)
        cout << "Map can't be negative or zero" << endl;

    // Mine number can't be negativor or zero
    if (rateCheck)
    {
        if (*mine <= 0 || *mine >= *row * *col)
            cout << "Over range\n";
        else if ((int)*mine / 1 != *mine)
            cout << "Count mode\n";
        else
            return true;
    }
    else
    {
        if (*mine <= 0 || *mine >= 1)
            cout << "Over range\n";
        else
            return true;
    }

    return false;
}

void Mine::readFileMapRange(ifstream* file)
{

    if(!(*file).is_open())
    {
        cout << "Failed to open file. Error code : " << errno << endl;
    }
    else
    {
        int row, col;
        char input;

        (*file) >> row >> col;

        for (int r = 0; r < row; r += 1)
        {
            vector<char> row;
            for (int c = 0; c < col; c += 1)
            {
                (*file) >> input;
                row.push_back(input);
            }
            this->mapAnswer.push_back(row);
        }
    }
}

bool Mine::boardSet(ifstream* file, ofstream* output)
{
    out(output, "Set map successfully\n", this->fileOrInOutput);

    int row = this->mapAnswer.size();
    int col = this->mapAnswer[0].size();

    // Declare the map display array
    vector<vector<char>> Board(row, vector<char>(col, '#'));
    this->mapBoard = Board;

    // Check bomb surround and store back to answer
    // Count each array surround mines number
    surroundBomb();

    int mine = runMap(this->mapAnswer, output, 'X', true, true);

    return (this->fileOrInOutput) ? stateSet(file, output, row, col, mine) : stateSet(NULL, NULL, row, col, mine);
}


bool Mine::randomSet(const int row, const int col, const int mine)
{
    cout << "Set map successfully" << endl;

    // Declare the map display array
    vector<vector<char>> board(row, vector<char>(col, '#'));
    this->mapBoard = board;

    // Declare the map answer array
    vector<vector<char>> answer(row, vector<char>(col, '0'));
    this->mapAnswer = answer;

    // Random set mines poistion
    for (int mP = 0; mP < mine; mP += 1)
    {
        int rowP = rand() % row;
        int colP = rand() % col;

        // Avoid bomb appear in same pistion
        (this->mapAnswer[rowP][colP] == 'X') ? mP -= 1 : this->mapAnswer[rowP][colP] = 'X';;
    }

    // Check bomb surround and store back to answer
    // Count each array surround mines number
    surroundBomb();
    return stateSet(NULL, NULL, row, col, mine);
}

bool Mine::stateSet(ifstream* file, ofstream* output, const int row, const int col, const int mine)
{
    //Set gameState Standby
    string command, gameState = "Standby";

    // blankArray[0] is open blank
    // blankArray[1] is flag blank
    int blankArray[4] = { 0 };

    // blankArray[2] is bomb blank
    blankArray[2] = mine;

    // blankArray[3] is total blank
    blankArray[3] = row * col;


    //If GameState == Quit
    while (true)
    {
        bool touchBomb = false;
        if ((runMap(this->mapBoard, output, '#', true, true) + runMap(this->mapBoard, output, 'f', true, true)) == blankArray[2] || touchBomb)
        {
            out(output, "You win the game\n", this->fileOrInOutput);
            out(output, "Command Reply to play it again, Quit to quit the game\n", this->fileOrInOutput);

            command = input(file, this->fileOrInOutput);

            if (command == "Quit")
            {
                out(output, "<Quit> : Success\n", this->fileOrInOutput);
                return false;
            }
            if (command == "Reply")
            {
                out(output, "<Reply> : Success\n", this->fileOrInOutput);
                return true;
            }
        }

        command = input(file, this->fileOrInOutput);

        //If mode Standby
        if (gameState == "Standby" && command == "StartGame")
        {
            gameState = "Playing";
            out(output, "<StartGame> : Success\n", this->fileOrInOutput);
        }
        //If mode StartGame
        else if (command == "StartGame")
        {
            out(output, "<StartGame> : Already\n", this->fileOrInOutput);
        }
        //If mode Print
        else if (command == "Print")
        {
            printCommand(file, output, gameState, blankArray, this->fileOrInOutput);
        }
        else if (command == "RightClick")
        {
            int inX, inY;
            inputInt(file, this->fileOrInOutput, &inY, &inX);

            if (gameState != "Playing" || this->mapBoard[inY][inX] >= '0' && this->mapBoard[inY][inX] <= '8')
            {
                string answer = "<RightClick  > : Failed\n";
                answer.insert(answer.begin() + 11, 1, ('0' + inY));
                answer.insert(answer.begin() + 13, 1, ('0' + inX));
                out(output, answer, this->fileOrInOutput);
            }
            else
            {
                string answer = "<RightClick  > : Success\n";
                answer.insert(answer.begin() + 11, 1, ('0' + inY));
                answer.insert(answer.begin() + 13, 1, ('0' + inX));
                out(output, answer, this->fileOrInOutput);

                if (this->mapBoard[inY][inX] == '#')
                {
                    this->mapBoard[inY][inX] = 'f';
                    blankArray[1] += 1;
                }
                else
                {
                    this->mapBoard[inY][inX] = (this->mapBoard[inY][inX] == 'f') ? '?' : '#';
                    blankArray[1] -= 1;
                }
            }
        }
        else if (command == "LeftClick")
        {
            int inX, inY;
            inputInt(file, this->fileOrInOutput, &inY, &inX);

            if (gameState != "Playing" || this->mapBoard[inY][inX] != '#' || this->mapBoard[inY][inX] == 'f')
            {
                string answer = "<LeftClick  > : Failed\n";
                answer.insert(answer.begin() + 11, 1, ('0' + inY));
                answer.insert(answer.begin() + 13, 1, ('0' + inX));
                out(output, answer, this->fileOrInOutput);
            }
            else
            {
                string answer = "<LeftClick  > : Success\n";
                answer.insert(answer.begin() + 11, 1, ('0' + inY));
                answer.insert(answer.begin() + 13, 1, ('0' + inX));
                out(output, answer, this->fileOrInOutput);

                if (this->mapBoard[inY][inX] == 'X')
                {
                    touchBomb = true;
                }
                spread(inY, inX);
            }
            blankArray[0] = blankArray[3] - runMap(this->mapBoard, output, '#', true, true);
        }
    }
}


int Mine::runMap(vector<vector<char>>map, ofstream* output, const char check, const bool inOrOut, const bool getDataOrRun)
{
    int count = 0;
    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            if (getDataOrRun)
            {
                count = (map[r][c] == check) ? count + 1 : count;
            }
            else
            {
                if (inOrOut)
                    map[r][c] = check;
                else
                {
                    string answer = {map[r][c], ' '};
                    out(output, answer, this->fileOrInOutput);
                }
            }
        }
        if (!inOrOut)
            out(output,"\n", this->fileOrInOutput);
    }

    return count;
}

void Mine::surroundBomb()
{
    // The input surround poistion
    int dir[8][2] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };

    for (int r = 0; r < this->mapAnswer.size(); r++)
    {
        for (int c = 0; c < this->mapAnswer[0].size(); c++)
        {
            if (this->mapAnswer[r][c] != 'X')
            {
                int boom = 0;
                for (int i = 0; i < 8; i++)
                {
                    int nextx = c + dir[i][0];
                    int nexty = r + dir[i][1];
                    if (nextx < 0 || nexty < 0 || nexty >= this->mapAnswer.size() || nextx >= this->mapAnswer[0].size())
                        continue;
                    if (this->mapAnswer[nexty][nextx] == 'X')
                        boom += 1;
                }

                this->mapAnswer[r][c] = ('0' + boom);
            }
        }
    }
}

void Mine::printCommand(ifstream* file, ofstream* output, string state, int* blankArray, bool readFile)
{
    // blankArray[0] is open blank
    // blankArray[1] is flag blank
    // blankArray[2] is bomb blank
    // blankArray[3] is total blank

    string command;

    command = input(file, readFile);

    if (command == "GameBoard")
    {
        out(output, "<Print GameBoard> :\n", this->fileOrInOutput);
        runMap(this->mapBoard, output, '#', false, false);
    }
    if (command == "GameState")
    {
        out(output, "<GameState> : \n", this->fileOrInOutput);
    }
    if (command == "GameAnswer")
    {
        out(output, "<Print GameAnswer> :", this->fileOrInOutput);
        runMap(this->mapAnswer, output, '#', false, false);
    }
    if (command == "BombCount")
    {
        cout << "<BombCount> : " << blankArray[2] << endl;
    }
    if (command == "FlagCount")
    {
        cout << "<FlagCount> : " << blankArray[1] << endl;
    }
    if (command == "OpenBlankCount")
    {
        cout << "<OpenBlankCount> : " << blankArray[0] << endl;
    }
    if (command == "RemainBlankCount")
    {
        cout << "<RemainBlankCount> : " << blankArray[3] - blankArray[0] - blankArray[1] - blankArray[2] << endl;
    }
}

// Intent:to spread the blank if the answerboard[inY][inX] ='0'
// Pre: the input must be two int
// Post:the function return nothing
void Mine::spread(int inY, int inX)
{
    // check if the input coordinates are within the board boundaries
    if (inY >= this->mapBoard.size() || inY < 0 || inX >= this->mapBoard[0].size() || inX < 0)
    {
        return;
    }

    // if the current cell is hidden, reveal it and recursively call the function on adjacent cells
    if (this->mapAnswer[inY][inX] == '0' && this->mapBoard[inY][inX] == '#')
    {
        this->mapBoard[inY][inX] = '0';
        spread(inY - 1, inX + 1);
        spread(inY + 1, inX - 1);
        spread(inY, inX + 1);
        spread(inY, inX - 1);
        spread(inY + 1, inX);
        spread(inY - 1, inX);
        spread(inY + 1, inX + 1);
        spread(inY - 1, inX - 1);
    }
    // if the current cell is not hidden, reveal it
    else if (this->mapBoard[inY][inX] != 'f' && this->mapBoard[inY][inX] != '?')
    {
        this->mapBoard[inY][inX] = this->mapAnswer[inY][inX];
    }
}
