#define WINVER 0x0500
#include <Windows.h>
#include <CommCtrl.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    //Stuff for setting console color
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    //Structure for the keyboard event
    INPUT ip;

    unsigned short int code[23];
    code[0] = 0x15; //y
    code[1] = 0x18; //o
    code[2] = 0x16; //u
    code[3] = 0x39; // 
    code[4] = 0x23; //h
    code[5] = 0x1E; //a
    code[6] = 0x2F; //v
    code[7] = 0x12; //e
    code[8] = 0x39; // 
    code[9] = 0x30; //b
    code[10] = 0x12; //e
    code[11] = 0x12; //e
    code[12] = 0x31; //n
    code[13] = 0x39; // 
    code[14] = 0x23; //h
    code[15] = 0x1E; //a
    code[16] = 0x2E; //c
    code[17] = 0x25; //k
    code[18] = 0x12; //e
    code[19] = 0x20; //d
    code[20] = 0x34; //.
    code[21] = 0x34; //.
    code[22] = 0x34; //.

    system("start notepad"); //Initiate notepad
    Sleep(800);

    for (int lip = 0; lip < 23; lip++)
    {
        //Set up the INPUT structure
        ip.type = INPUT_KEYBOARD;
        ip.ki.time = 0;
        ip.ki.wVk = 0; //We're doing scan codes instead
        ip.ki.dwExtraInfo = 0;
        //This let's you do a hardware scan instead of a virtual keypress
        ip.ki.dwFlags = KEYEVENTF_SCANCODE;
        ip.ki.wScan = code[lip];  //Set a unicode character to use (A)

        //Send the press
        SendInput(1, &ip, sizeof(INPUT));

        //Prepare a keyup event
        ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(120); //Set timer between each key stroke to simulate human behaviour.
    }
    //               :.:.:.:.:Abhi maza aye ga na beeru:.:.:.:.:
    cout << "Hahahaha. Ghabrana nhi hai!!!!!!!!!!!!!!!!!!!!!\n\nCredits: Muhammad Mobeen (Markhor)\nGithub: github.com/muhammad-mobeen\n\n";
    system("pause");

    return 0;
}