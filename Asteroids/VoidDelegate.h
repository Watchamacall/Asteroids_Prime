#pragma once
#include <vector>
#include <functional>
class VoidDelegate
{
protected:
	std::vector<std::function<void()>> delegateVector;

public:
	/*
	* Adds what to execute
	* E.G. Use the [this] { //code// } lambda expression
	*/
	void AddVoidDelegate(std::function<void()> delegateToAdd);

	/*
	* Executes all delegates
	*/
	void Execute();
};

