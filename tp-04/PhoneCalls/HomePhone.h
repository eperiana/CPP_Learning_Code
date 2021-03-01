//
// Created by etienne on 08/02/2021.
//

#pragma once
#include "Phone.h"

class HomePhone : public Phone
{
public:
    HomePhone(const Person& person, int position)
            : Phone(person)
            , _position{position}
    {}

    void ring() const override
    {
        if (Phone::_owner.get_position() == _position)
            std::cout << "Hi! Paul on the phone" << std::endl;
        else
            std::cout << "This is the voicemail of Paul. Please leave a message" << std::endl;
    }

private:
    int _position;

};

