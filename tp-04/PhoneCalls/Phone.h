#pragma once

#include "Person.h"

class Phone
{
protected:
	Phone(const Person& owner)
		: _owner { owner }
	{}

    const Person& _owner;

public:
	virtual void ring() const = 0;

};
