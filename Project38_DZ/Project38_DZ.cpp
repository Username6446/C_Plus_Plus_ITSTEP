#include "SocialNetwork.h"
#include "Exception.h"
#include <iostream>

int main() {
    SocialNetwork sn;

    try {
        sn.Register("User1", "Qwerty123!");
        sn.Register("User2", "Qwerty123!");
        sn.Register("User2", "Qwerty123!");
        sn.Login();
    }
    catch (Exception& e) {
        cout << e.what() << endl;
    }

}