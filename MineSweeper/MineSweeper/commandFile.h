#pragma once

#include <vector>
#include <cstring>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int setCol = 0, setRow = 0;
vector<string> board;

char answerBoard[100][100], replyBoard[100][100];

bool replayChance = false, quitChance = true, startGame = false, showResult = false;
string gameState = "Standby";
ofstream newFile;

// Intent: load the file to get the data
// Pre: the input must be a fileName
// Post: the function return vector of string
vector<string> load(string input)
{
	// Open the file for reading.
	fstream file;
	file.open(input);

	// Declare variables to hold the data.
	string data;
	vector<string> fileData;

	// Check if the file opened successfully.
	if (!file.is_open())
	{
		std::cout << "Failed to open file. Error code: " << errno << std::endl;
	}

	// Read the file line by line and store each line in the vector.
	while (getline(file, data))
	{
		fileData.push_back(data);
	}

	// Return the vector containing the map data.
	return fileData;
}

// Intent:to output to the data into the outputFile
// Pre: the input must be a string
// Post:the function return nothing
void outputToFile(string input)
{
	// Write the input string to the output file.
	newFile << input << endl;
}

// Intent:to set the board and the replyboard
// Pre: the input must be a fileNumber
// Post:the function return nothing
void setBoard(const char fileNumber)
{
	fstream file;
	string data;
	string fileName = "board";

	// Add the file number to the filename.
	fileName = fileName + fileNumber + ".txt";

	// Open the file for input.
	file.open(fileName, ios::in);

	// Read the dimensions of the board from the file.
	file >> setRow >> setCol;

	// Read each line of the file and add it to the board vector.
	while (getline(file, data))
	{
		board.push_back(data);
	}
	// Remove the first line of the board vector.
	board.erase(board.begin());
	// Initialize the replyBoard with wall characters.
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			replyBoard[i][j] = '#';
		}
	}
}
// Intent:to count the amount of the input of the replyboard
// Pre: the input must be a char
// Post:the function return the amount of the input
int countReplyData(char input)
{
	string com;
	int count = 0;
	for (int i = 0; i < setRow; i++)
	{
		com = replyBoard[i];
		for (int j = 0; j < setCol; j++)
		{
			if (com[j] == input)
			{
				count++;
			}
		}
	}
	return count;
}
// Intent:to count the amount of the input of the answerboard
// Pre: the input must be a char
// Post:the function return the amount of the input
int countAnswerData(char input)
{
	string com;
	int count = 0;
	for (int i = 0; i < setRow; i++)
	{
		com = answerBoard[i];
		for (int j = 0; j < setCol; j++)
		{
			if (com[j] == input)
			{
				count++;
			}
		}
	}
	return count;
}
// Intent:to spread the blank if the answerboard[inY][inX] ='0'
// Pre: the input must be two int
// Post:the function return nothing
void spread(int inY, int inX)
{
	// check if the input coordinates are within the board boundaries
	if (inY >= setRow || inY < 0 || inX >= setCol || inX < 0)
	{
		return;
	}
	// if the current cell is hidden, reveal it and recursively call the function on adjacent cells
	if (answerBoard[inY][inX] == '0' && replyBoard[inY][inX] == '#')
	{
		replyBoard[inY][inX] = '0';
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
	else
	{
		replyBoard[inY][inX] = answerBoard[inY][inX];
	}
}
// Intent: Dig a space on the game board, either reveal the number or lose the game
// Pre: inY and inX are valid coordinates on the game board
// Post: If the space has a bomb, the game is over and the player loses,
// otherwise, the space is revealed on the reply board with either its number or a blank spot
void digBoard(int inY, int inX)
{
	//if the answerBoard[inY][inX]='X' and you lose the game.
	if (answerBoard[inY][inX] == 'X')
	{
		outputToFile("You lose the game");
		replayChance = true;
		gameState = "GameOver";
		quitChance = true;
		startGame = false;
	}
	//if the answerBoard[inY][inX]='0' and spreading the replyboard
	else if (answerBoard[inY][inX] == '0')
	{
		spread(inY, inX);
	}
	//else the replyboard[inY][inX]=answerBoard[inY][inX]
	else
	{
		replyBoard[inY][inX] = answerBoard[inY][inX];
	}
}
// Intent: Check the answerBoard at a specified location
// Pre: The answerBoard is not empty and the specified location is within its bounds
// Post: If the specified location contains a mine ('X'), leave it unchanged; otherwise, increment the number of adjacent mines by one.
void checkAnswer(int y, int x)
{
	if (answerBoard[y][x] == 'X')
	{
		answerBoard[y][x] = 'X';
	}
	else
	{
		answerBoard[y][x] += 1;
	}
}
// Intent: set the answerboar
// Pre:the input must be a vector of string
// Post:the function return nothing
void setAnswer(vector<string> input)
{
	string command;
	for (int i = 0; i < setRow; i++)
	{
		for (int j = 0; j < setCol; j++)
		{
			answerBoard[i][j] = '0';
		}
	}
	// Iterate through each command in the input vector and set corresponding cells on the answer board
	for (int i = 0; i < input.size(); i++)
	{
		command = input[i];
		for (int j = 0; j < command.size(); j++)
		{
			if (command[j] == 'X')
			{
				answerBoard[i][j] = 'X';
				// Check surrounding cells and update their value accordingly
				if (i == 0 && j == 0)
				{
					checkAnswer(i + 1, j);
					checkAnswer(i, j + 1);
					checkAnswer(i + 1, j + 1);
				}
				else if (i == 0 && j == setCol - 1)
				{
					checkAnswer(i + 1, j);
					checkAnswer(i, j - 1);
					checkAnswer(i + 1, j - 1);
				}
				else if (i == setRow - 1 && j == 0)
				{
					checkAnswer(i - 1, j);
					checkAnswer(i, j + 1);
					checkAnswer(i - 1, j + 1);
				}
				else if (i == setRow - 1 && j == setCol - 1)
				{
					checkAnswer(i - 1, j);
					checkAnswer(i, j - 1);
					checkAnswer(i - 1, j - 1);
				}
				else if (i == 0)
				{
					checkAnswer(i, j - 1);
					checkAnswer(i, j + 1);
					checkAnswer(i + 1, j);
					checkAnswer(i + 1, j + 1);
					checkAnswer(i + 1, j - 1);
				}
				else if (i == setRow - 1)
				{
					checkAnswer(i - 1, j - 1);
					checkAnswer(i - 1, j);
					checkAnswer(i - 1, j + 1);
					checkAnswer(i, j - 1);
					checkAnswer(i, j + 1);
				}
				else if (j == 0)
				{
					checkAnswer(i - 1, j);
					checkAnswer(i - 1, j + 1);
					checkAnswer(i, j + 1);
					checkAnswer(i + 1, j);
					checkAnswer(i + 1, j + 1);
				}
				else if (j == setCol - 1)
				{
					checkAnswer(i - 1, j - 1);
					checkAnswer(i - 1, j);
					checkAnswer(i, j - 1);
					checkAnswer(i + 1, j - 1);
					checkAnswer(i + 1, j);
				}
				else
				{
					checkAnswer(i - 1, j - 1);
					checkAnswer(i - 1, j);
					checkAnswer(i - 1, j + 1);
					checkAnswer(i, j - 1);
					checkAnswer(i, j + 1);
					checkAnswer(i + 1, j - 1);
					checkAnswer(i + 1, j);
					checkAnswer(i + 1, j + 1);
				}
			}
			else
			{
				continue;
			}
		}
	}
}

void runCommandFile(string inputFile, string outputFile)
{
	// This while loop will continue indefinitely until the program is terminated manually.
	while (true)
	{
		cout << "CommandFile command run successfully" << endl;
		// Initialize two strings for user input.
		string command;
		string fileName;
		
		// Read in the remaining user inputs.
		
		// Open the output file.
		newFile.open(outputFile);
		// Load the data from the input file into a vector.
		vector<string> data = load(inputFile);
		// Initialize four integers to store various counts.
		int flagBlank = 0, openBlank = 0, remainBlankCount = 0, bombBlank = 0;
		// Iterate through the data vector.
		for (int i = 0; i < data.size(); i++)
		{
			// Iterate through the data vector.
			command = data[i];
			// Initialize a string to store a substring of the command.
			string store;
			// Initialize a char to store a single character from the command.
			char fileNumber = '0';
			// Iterate through the command string.
			for (int i = 0; i < command.size(); i++)
			{
				// If the current character is a space or newline, exit the loop.
				if (command[i] == ' ' || command[i] == '\n')
				{
					break;
				}
				// Otherwise, append the character to the store string.
				else
				{
					store = store + command[i];
				}
			}
			// If the command is "Quit" and the quitChance variable is true, exit the program.
			if (command == "Quit" && quitChance == true)
			{
				outputToFile("<Quit> : Success");
				quitChance = false;
			}
			// If the command is "Replay" and the gameState variable is "GameOver", reset the game.
			else if (command == "Replay" && gameState == "GameOver")
			{
				outputToFile("<Replay> : Success");
				startGame = false;
				gameState = "Standby";
				quitChance = false;
				for (int i = 0; i < setRow; i++)
				{
					board.erase(board.begin());
				}
			}
			// If the gameState variable is "Standby", perform certain actions.
			else if (gameState == "Standby")
			{
				// If the store string is "Load", load the board file.
				if (store == "Load")
				{
					flagBlank = 0, openBlank = 0, remainBlankCount = 0, bombBlank = 0;
					startGame = true;
					showResult = true;
					quitChance = true;
					// Extract the board file name from the command string.
					for (int i = 0; i < command.size(); i++)
					{
						if (command[i] == '.')
						{
							fileName = command.substr(i, command.size());
							fileNumber = command[29];
							break;
						}
					}
					// Output a success message and load the board.
					string outputString;
					outputString = "<Load BoardFile " + fileName + "> : Success";
					outputToFile(outputString);
					setBoard(fileNumber);
					setAnswer(board);
				}
				// if the user entered "StartGame" and the game hasn't started yet
				else if (store == "StartGame" && startGame == true)
				{
					//set the game state to "Playing"
					gameState = "Playing";
					// output a success message to a file
					outputToFile("<StartGame> : Success");
				}
				// if the user entered "Print"
				else if (store == "Print")
				{
					// declare a string variable for the output message
					string outputString;
					// add the user's command to the output message
					outputString = "<" + command + "> : ";
					// output the message along with the current game state to a file
					outputToFile(outputString + gameState);
				}
				// if the user entered anything else
				else
				{
					// declare a string variable for the output message
					string outputString;
					// add the user's command to the output message and indicate that it failed
					outputString = "<" + command + "> : Failed";
					// output the message to a file
					outputToFile(outputString);
				}
			}
			// if the user entered "Print"
			else if (store == "Print")
			{
				// iterate through the command string
				for (int i = 0; i < command[i]; i++)
				{
					// if the current character is a space
					if (command[i] == ' ')
					{
						// extract the second word in the command and store it in the variable "store"
						store = command.substr(i + 1, command.size());
						// exit the loop
						break;
					}
				}
				// if the second word is "GameBoard"
				if (store == "GameBoard")
				{
					// output a message to indicate that the game board is being printed
					outputToFile("<Print GameBoard> :");
					// iterate through each row in the board
					for (int r = 0; r < setRow; r++)
					{
						// declare a string variable for the output message
						string outputString;
						// iterate through each column in the board
						for (int c = 0; c < setCol; c++)
						{
							// if this is the last column in the row
							if (c == setCol - 1)
							{
								// add the current cell to the output message
								outputString += string(1, replyBoard[r][c]);
							}
							// if this is not the last column in the row
							else
							{
								// add the current cell to the output message
								outputString += string(1, replyBoard[r][c]);
								// add a space to separate the cells
								outputString += " ";
							}
						}
						// output the row to a file
						outputToFile(outputString);
					}
				}
				// If store variable is equal to "GameState", output the current game state
				if (store == "GameState")
				{
					outputToFile("<Print GameState> : " + gameState);
				}
				// If store variable is equal to "GameAnswer", output the answer board to the file
				if (store == "GameAnswer")
				{
					// Output a message indicating that GameAnswer is being printed
					outputToFile("<Print GameAnswer> :");
					// Loop through each row of the answerBoard matrix
					for (int r = 0; r < setRow; r++)
					{
						// Create an empty string to hold the output for the current row
						string outputString;
						// Loop through each column of the answerBoard matrix for the current row
						for (int c = 0; c < setCol; c++)
						{
							// If we are at the last column of the current row, add the current cell value to the outputString
							if (c == setCol - 1)
							{
								outputString += string(1, answerBoard[r][c]);
							}
							// Otherwise, add the current cell value and a space to the outputString
							else
							{
								outputString += string(1, answerBoard[r][c]);
								outputString += " ";;
							}
						}
						// Output the outputString for the current row
						outputToFile(outputString);
					}
				}
				// If store variable is equal to "BombCount", output the number of bombs on the answer board to the file
				if (store == "BombCount")
				{
					bombBlank = countAnswerData('X');
					outputToFile("<Print BombCount> : " + to_string(bombBlank));
				}
				// If store variable is equal to "FlagCount", output the number of flagged cells on the reply board to the file
				if (store == "FlagCount")
				{
					flagBlank = countReplyData('f');
					outputToFile("<Print FlagCount> : " + to_string(flagBlank));
				}
				// If store variable is equal to "OpenBlankCount", output the number of opened blank cells on the reply board to the file
				if (store == "OpenBlankCount")
				{
					openBlank = setRow * setCol - countReplyData('#') - countReplyData('f') - countReplyData('?');
					outputToFile("<Print OpenBlankCount> : " + to_string(openBlank));
				}
				// If store variable is equal to "RemainBlankCount", output the number of remaining blank cells on the reply board to the file
				if (store == "RemainBlankCount")
				{
					openBlank = setRow * setCol - countReplyData('#') - countReplyData('f') - countReplyData('?');
					outputToFile("<Print RemainBlankCount> : " + to_string(setRow * setCol - countAnswerData('X') - openBlank));
				}
			}
			// If store variable is equal to "LeftClick", execute a left-click on the reply board at the given coordinates, output the result to the file
			else if (store == "LeftClick")
			{
				// Declares integer variables inX and inY, and string variable action
				int inX, inY;
				string action;
				// Creates an istringstream objectand uses it to parse the input command
				istringstream iss(command);
				iss >> action >> inY >> inX;
				// Checks if the game is currently in the "Playing" state, the selected cell is either '#' or '?',
				// and if the selected cell is within the boundaries of the game board
				if (gameState == "Playing" && (replyBoard[inY][inX] == '#' || replyBoard[inY][inX] == '?') && (inY < setRow && inY >= 0) && (inX < setCol && inX >= 0))
				{
					// Creates an output string indicating a successful left-click at the selected cell
					string outputString;
					outputString = "<LeftClick " + to_string(inY);
					outputString += " " + to_string(inX);
					outputString += ">";
					outputString += " : Success";
					outputToFile(outputString);
					// Reveals the selected cell by calling the digBoard function
					digBoard(inY, inX);
				}
				else
				{
					// Creates an output string indicating a failed left-click at the selected cell
					string outputString;
					outputString = "<LeftClick " + to_string(inY);
					outputString += " " + to_string(inX);
					outputString += ">";
					outputString += " : Failed";
					outputToFile(outputString);
				}
			}
			// If store variable is equal to "RightClick", execute a right-click on the reply board at the given coordinates, output the result to the file
			else if (store == "RightClick")
			{
				// Initialize variables to store the input x and y values
				int inX, inY;
				// Initialize a string variable to store the command action
				string action;
				// Create an istringstream object to extract the command input values
				istringstream iss(command);
				// Extract the action and input x and y values from the command and store them in their respective variables
				iss >> action >> inY >> inX;

				// Check if the game state is "Playing" and if the input x and y values are within the boundaries of the game board and if the location has not already been revealed or flagged
				if ((gameState == "Playing") && ((replyBoard[inY][inX] == '#') || ((replyBoard[inY][inX] == 'f') || (replyBoard[inY][inX] == '?'))) && (inY < setRow && inY >= 0) && (inX < setCol && inX >= 0))
				{
					// Create a string variable to store the output string
					string outputString;
					// Concatenate the "RightClick" action and input x and y values into the output string
					outputString = "<RightClick " + to_string(inY);
					outputString += " " + to_string(inX);
					outputString += ">";
					// Concatenate the success message into the output string
					outputString += " : Success";
					// Write the output string to the output file
					outputToFile(outputString);

					// If the location is already flagged, unflag it
					if (replyBoard[inY][inX] == 'f')
					{
						replyBoard[inY][inX] = '?';
					}
					// If the location is already questioned, mark it as unexplored
					else if (replyBoard[inY][inX] == '?')
					{
						replyBoard[inY][inX] = '#';
					}
					// If the location is unexplored, flag it
					else
					{
						replyBoard[inY][inX] = 'f';
					}
				}
				// If any of the conditions for a successful right-click are not met
				else
				{
					// Create a string variable to store the output string
					string outputString;
					// Concatenate the "RightClick" action and input x and y values into the output string
					outputString = "<RightClick " + to_string(inY);
					outputString += " " + to_string(inX);
					outputString += ">";
					// Concatenate the failure message into the output string
					outputString += " : Failed";
					// Write the output string to the output file
					outputToFile(outputString);
				}
			}
			// If the command is invalid, output a failure message to the file
			else
			{
				string outputString;
				outputString = '<' + command + " > : Failed";
				outputToFile(outputString);
			}
			openBlank = setRow * setCol - countReplyData('#') - countReplyData('f') - countReplyData('?');
			remainBlankCount = setRow * setCol - countAnswerData('X') - openBlank;
			// Check if the game is won, output a message to the file and set the game state to "GameOver" if there are no more blank cells left and showResult variable is true
			if (remainBlankCount == 0 && showResult == true)
			{
				outputToFile("You win the game");
				showResult = false;
				gameState = "GameOver";
				replayChance = true;
			}
		}
			
		// Close the output file after the loop is completed
		newFile.close();
	}
}