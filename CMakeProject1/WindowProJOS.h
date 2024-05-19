#ifndef WINDOWPROJOS_H
#define WINDOWPROJOS_H
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>


using namespace std;

class WindowMainProjOS;

class WindowProJOS
{
public:
	WindowProJOS();
	virtual ~WindowProJOS();
	void Logout();
private:
	vector<string> HandleInput(string);
	void Commandinput();
	void Commandsystem(vector<string>);
	void HelpLogin();
	void LoginLOGO();
	string LoginFuncUser();
	void LoginFuncPassword(string);
	void ChackPassword();
};

#endif // WINDOWPROJOS_H