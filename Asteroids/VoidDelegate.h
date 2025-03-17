#pragma once
#include <vector>
#include <functional>

template<typename ReturnType, typename ArgType>
class Delegate
{
	using FuncType = std::function<ReturnType(ArgType)>;

protected:
	std::vector<FuncType> delegateVector;

public:
	/*
	 * Adds what to execute
	 * E.G. Use the [this] { //code// } lambda expression
	 */
	void AddDelegate(const FuncType& delegateToAdd) { delegateVector.push_back(delegateToAdd); }

	/*
	 * Executes all delegates
	 */
	void Execute(ArgType arg)
	{
		for (FuncType& func : delegateVector)
		{
			func(arg);
		}
	}
};

template<typename ReturnType>
class Delegate<ReturnType, void>
{
	using FuncType = std::function<ReturnType()>;

protected:
	std::vector<FuncType> delegateVector;

public:
	void AddDelegate(const FuncType& delegateToAdd) { delegateVector.push_back(delegateToAdd); }

	void Execute()
	{
		for (FuncType& func : delegateVector)
		{
			func();
		}
	}
};
