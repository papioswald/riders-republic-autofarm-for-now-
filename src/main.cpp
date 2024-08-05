#include <iostream>
#include <cstdlib>
#include <Windows.h>

/*
space : 0x20
enter : 0x0D
w key : 0x57
*/

int main() {
    INPUT in1 = { 0 };
    INPUT in2 = { 0 };

    std::cout << "would you like to use quick mode or not? (0 for no, 1 for yes) \n\n";
    int opt;
    std::cin >> opt;
    DWORD time = 0;

    if (opt == 1) {
        time = 4000;
    }
    else if (opt == 0) {
        time = 240000;
    }
    else {
        return 0;
    }


    std::cout << "autofarm working, you have 5 seconds to get in game\n";
    std::cout << time;
    Sleep(5000);
    int hi = 0;

    while (true) {


        SHORT key;
        SHORT key2;
        UINT mappedkey;
        UINT mappedkey2;

        INPUT input = { 0 };
        INPUT input2 = { 0 };
        key = VkKeyScan('w');
        mappedkey = MapVirtualKey(LOBYTE(key), 0);
        input.type = INPUT_KEYBOARD;
        input.ki.dwFlags = KEYEVENTF_SCANCODE;
        input.ki.wScan = mappedkey;
        SendInput(1, &input, sizeof(input));
        Sleep(50);
        input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(input));

        std::cout << "\n1\n";
        Sleep(15000);



        for (int penis = 0; penis < 16; penis++) {
            input2.type = INPUT_KEYBOARD;
            input2.ki.dwFlags = KEYEVENTF_SCANCODE;




            key2 = VkKeyScan('\r');
            mappedkey2 = MapVirtualKey(LOBYTE(key2), 0);
            input2.ki.wScan = mappedkey2;
            SendInput(1, &input2, sizeof(input2));
            Sleep(50);
            input2.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
            SendInput(1, &input2, sizeof(input2));
            Sleep(700);
        }

        std::cout << "2"; //made to fix commit
        Sleep(time);

        system("cls");
        hi++;
        std::cout << "completed " << hi << " cycles!\n\n";
    }

    return 0;
}
