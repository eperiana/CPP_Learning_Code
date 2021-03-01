//
// Created by etienne on 08/02/2021.
//

#pragma once

class MobilePhone : public Phone
{
public:
    MobilePhone(Person& owner)
    :Phone(owner)
    {}

    void ring() const override {
        std::cout << "Hi! Paul on the phone" << std::endl;
    }
};
