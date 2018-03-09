#pragma once
#include<string>

class UIExceptions
{
public:
	UIExceptions(const std::string& exps);
	std::string getException() { return exceptions; }

private:
	std::string exceptions;
};
