#include "VoidDelegate.h"

void VoidDelegate::AddVoidDelegate(std::function<void()> delegateToAdd)
{
	delegateVector.push_back(delegateToAdd);
}

void VoidDelegate::Execute()
{
	for (auto& sDelegate : delegateVector)
	{
		sDelegate();
	}
}
