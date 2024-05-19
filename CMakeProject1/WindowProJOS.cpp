#include "WindowProJOS.h"
#include "WindowMainProjOS.h"

WindowProJOS::WindowProJOS()
{
    this->Commandinput();
}

WindowProJOS::~WindowProJOS()
{
}

void WindowProJOS::Commandinput()
{
    string input;
    cout << "user@ : ";
    getline(cin, input);
    vector<string> words = HandleInput(input);
    this->Commandsystem(words);
}

vector<string> WindowProJOS::HandleInput(string input)
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

void WindowProJOS::Commandsystem(vector<string> words)
{
    if (words.empty()) {
        this->Commandinput();
        return;
    }

    if (words[0] == "login") {
        if (words.size() < 2) {
            cout << "Invalid login command. Please enter 'login -h' to proceed.\n";
            this->Commandinput();
            return;
        }
        if (words[1] == "-u" && words.size() < 3) {
            this->LoginFuncUser();
            return;
        }
        else if (words[1] == "-h" && words.size() < 3) {
            this->HelpLogin();
        }
    }

    else if (words[0] == "exit" && words.size() < 2) {
        exit(0);
    }

    else if (words[0] == "clear" && words.size() < 2) {
        system("cls");
        this->Commandinput();
        return;
    }

    else {
        this->Commandinput();
        return;
    }
    this->Commandinput();
}

void WindowProJOS::HelpLogin()
{
    cout << "HELP FUNC LOGIN\n";
    cout << "-h to call the function\n";
    cout << "-u to login to user\n";
}

void WindowProJOS::LoginLOGO()
{
    cout << "------------------" << endl;
    cout << "|  _   _  o ._" << endl;
    cout << "| (_) (_| | | | " << endl;
    cout << "       _|      " << endl;
    cout << "------------------" << endl;
}

string WindowProJOS::LoginFuncUser()
{
    string user;
    system("cls");
    this->LoginLOGO();
    cout << "Please enter your user: ";
    cin >> user;
    this->LoginFuncPassword(user);
    return user;

}
void WindowProJOS::LoginFuncPassword(string user)
{
    string password;
    cout << "Please enter your password: ";
    char ch;

    while ((ch = _getch()) != '\r') {
        if (ch == ' ') {
            system("cls");
            cout << "*Receiving password incorrectly*\n";
            this->LoginLOGO();
            cout << "Please enter your user : " << user << endl;
            password.clear();
            cout << "place enter password again : ";
        }
        else if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else {
            cout << '*';
            password.push_back(ch);
        }
    }
    cout << endl << password << endl;
    this->ChackPassword();
}

void WindowProJOS::ChackPassword()
{
    cout << "Password is ture\n";
    system("cls");
    WindowMainProjOS mainOS(this);
    cin.ignore();
    mainOS.ChaOS();
    mainOS.getUserInput();
}

void WindowProJOS::Logout() {
    system("cls");
    this->Commandinput();
}
