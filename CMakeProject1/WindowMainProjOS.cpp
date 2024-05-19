#include "WindowMainProjOS.h"
#include "WindowProJOS.h"

WindowMainProjOS::WindowMainProjOS(WindowProJOS* mainSystem) : mainSystem(mainSystem) {
}

WindowMainProjOS::~WindowMainProjOS() {
}

void WindowMainProjOS::ChaOS()
{
    cout << COLOR_GREEN;
    cout << "   ________  _____   ____  _____    ____  _____\n";
    cout << "  / ____/ / / /   | / __ \\/ ___/   / __ \\/ ___/\n";
    cout << " / /   / /_/ / /| |/ / / /\\__ \\   / / / /\\__ \\ \n";
    cout << "/ /___/ __  / ___ / /_/ /___/ /  / /_/ /___/ / \n";
    cout << "\\____/_/ /_/_/  |_\\____//____/   \\____//____/  \n";
    cout << "                                               \n";
    cout << COLOR_RESET;
}

string WindowMainProjOS::getUserInput() {
    string input;
    cout << "user@" << OSname << " : ";
    getline(cin, input);
    vector<string> words = HandleInputMainOS(input);
    this->ChackCallSystem(words, input);
    return words, input;
}

void WindowMainProjOS::ChackCallSystem(vector<string> words, string input)
{
    if (OSname == "user") {
        this->Commandsystem(words);
        return;
    }
    else {
        int result = system(input.c_str());
        this->getUserInput();
    }
}


vector<string> WindowMainProjOS::HandleInputMainOS(string input)
{
    vector<string> words;
    string word = "";

    for (char c : input) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    if (word != "") {
        words.push_back(word);
    }
    return words;
}

void WindowMainProjOS::Commandsystem(vector<string> words)
{
    if (words.empty()) {
        this->getUserInput();
        return;
    }
    if (words[0] == "exit") {
        if (words.size() < 2) {
            this->getUserInput();
            return;
        }
        if (words[1] == "-u" && words.size() < 3) {
            mainSystem->Logout();
            return;
        }
        else if (words[1] == "-p" && words.size() < 3) {
            exit(0);
        }
    }
    else if (words[0] == "clear" && words.size() < 2) {
        if (OSname == "system") {
            system("cls");
            this->ChaOS();
            cout << COLOR_YELLOW;
            this->getUserInput();
            return;
        }
        else {
            system("cls");
            this->ChaOS();
            this->getUserInput();
            return;
        }
    }
    else if (words[0] == "call") {
        if (words.size() < 2) {
            this->getUserInput();
            return;
        }
        if (words[1] == "system") {
            if (words.size() < 3) {
                this->getUserInput();
                return;
            }
            if (words[2] == "-s") {
                if (OSname == "system") {
                    cout << "-You are in system.\n";
                }
                cout << COLOR_YELLOW;
                OSname = "system";
            }
            else if (words[2] == "-u") {
                if (OSname == "user") {
                    cout << "-You are in user.\n";
                }
                cout << COLOR_RESET;
                OSname = "user";
            }
        }
    }
    else {
        this->getUserInput();
        return;
    }
    this->getUserInput();
}
