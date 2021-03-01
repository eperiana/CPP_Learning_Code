#include "Person.h"
#include "Phone.h"
#include "HomePhone.h"
#include "MobilePhone.h"

int main()
{
    Person paul { "Paul", 3 };

    HomePhone far_phone {paul,-10};
    const Phone& normal_phone = far_phone;

    normal_phone.ring();

    return 0;
}
