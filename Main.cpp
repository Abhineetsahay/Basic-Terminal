#include <iostream>
#include <vector>
#include <cstdlib>
#include <direct.h>
#include <limits.h>
#include <string>

using namespace std;

vector<string> history;
string getCurrentDirectory()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr)
    {
        return cwd;
    }
    else
    {
        cerr << "Error retrieving current directory." << '\n';
    }
    return "";
}

void changeDirectory(const string &command)
{
    static string previousDirectory = getCurrentDirectory();
    string path = command.substr(3);

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
        cout << "No history availabe for your commands" << '\n';
        return;
    }

    cout << "Your Commands History (last 10 commands) " << '\n';
    for (string hist : history)
    {
        cout << hist << endl;
    }
}
void showHelp()
{
    cout << "Available commands:\n"
         << "cd <path>   - Change directory\n"
         << "history     - Show last 10 commands\n"
         << "exit        - Exit the shell\n"
         << "help        - Show this help message\n"
         << "<command>   - Execute your command\n";
}
void executeCommand(const string &command)
{
    if (history.size() == 10)
        history.clear();
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
        cout << "Bye Shell programming\n";
        exit(0);
    }

    int retCode = system(command.c_str());
    if (retCode != 0)
    {
        cerr << "Error while executing the command: " << command << '\n';
    }
}

int main()
{
    string input;
    cout << "Welcome to my Terminal" << '\n';
    while (true)
    {
        cout << getCurrentDirectory() << " >> ";
        getline(cin, input);
        executeCommand(input);
    }
}
