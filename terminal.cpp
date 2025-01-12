#include <iostream>
#include <vector>
#include <cstdlib>
#include <direct.h>
#include <limits.h>
#include <string>

using namespace std;

const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";
const string YELLOW = "\033[33m";
const string RED = "\033[31m";
const string CYAN = "\033[36m";

vector<string> history;

string getCurrentDirectory()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr)
    {
        return string(cwd);
    }
    cerr << RED << "Error retrieving current directory." << RESET << '\n';
    return "";
}

void changeDirectory(const string &command)
{
    static string previousDirectory = getCurrentDirectory();
    string path = command.length() > 3 ? command.substr(3) : "";

    if (path.empty())
    {
        cerr << RED << "Error: Missing directory path." << RESET << '\n';
        return;
    }
    if (path == "-")
    {
        path = previousDirectory;
    }

    string currentDirectory = getCurrentDirectory();
    if (chdir(path.c_str()) != 0)
    {
        perror("Error changing directory");
    }
    else
    {
        previousDirectory = currentDirectory;
    }
}

void showHistory()
{
    if (history.empty())
    {
        cout << CYAN << "No history available for your commands." << RESET << '\n';
        return;
    }

    cout << YELLOW << "Your Commands History (last 10 commands):" << RESET << '\n';
    for (const string &hist : history)
    {
        cout << hist << '\n';
    }
}

void showHelp()
{
    cout << GREEN << "Available commands:" << RESET << '\n'
         << BLUE << "cd <path>" << RESET << "   - Change directory" << '\n'
         << BLUE << "history" << RESET << "     - Show last 10 commands" << '\n'
         << BLUE << "exit" << RESET << "        - Exit the shell" << '\n'
         << BLUE << "help" << RESET << "        - Show this help message" << '\n'
         << BLUE << "<command>" << RESET << "   - Execute your command" << '\n';
}

void executeCommand(const string &command)
{
    if (history.size() == 10)
        history.erase(history.begin());
    history.push_back(command);

    if (command == "history")
    {
        showHistory();
        return;
    }
    if (command == "help")
    {
        showHelp();
        return;
    }
    if (command.substr(0, 2) == "cd")
    {
        changeDirectory(command);
        return;
    }
    if (command == "exit")
    {
        cout << RED << "Bye! Terminal terminated." << RESET << '\n';
        exit(0);
    }

    int retCode = system(command.c_str());
    if (retCode != 0)
    {
        cerr << RED << "Error while executing the command: " << command << RESET << '\n';
    }
}

int main()
{
    string input;
    cout << GREEN << "Welcome to my Terminal" << RESET << '\n';
    while (true)
    {
        cout << BOLD << BLUE << getCurrentDirectory() << RESET << " >> ";
        getline(cin, input);
        executeCommand(input);
    }
    return 0;
}
