#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <Windows.h>

using namespace std;

//First setup for the program, this will include the basic settings, such as what games do you want to mod and what startup options do you want to use

int optionsMenu() {
    cout << "Welcome to the Options Menu!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Change startup options" << endl;
    cout << "2. Change Health Steps" << endl;
    cout << "3. Change Ammo Steps" << endl;
    int SettingsSelection = 0;
    cin >> SettingsSelection;
    switch (SettingsSelection) {
        case 1:
            cout << "Changing Startup Options..." << endl;
            Sleep(500);
            cout << "Startup Options Changed!" << endl;
            break;
        case 2:
            cout << "Changing Health Steps..." << endl;
            Sleep(500);
            cout << "Health Steps Changed!" << endl;
            break;
        case 3:
            cout << "Changing Ammo Steps..." << endl;
            Sleep(500);
            cout << "Ammo Steps Changed!" << endl;
            break;
        default:
            cout << "Invalid Selection!" << endl;
            Sleep(2000);
            break;
    }
    return 0;
}

int healthSteps() {
    cout << "Please enter the new health steps: ";
    int healthSteps = 0;
    cin >> healthSteps;
    cout << "Health steps changed to " << healthSteps << "!" << endl;
    return optionsMenu();
}

int mainMenu() {
    cout << "Welcome to the Main Menu!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Options" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter a selection: ";
    int selection = 0;
    cin >> selection;
    switch (selection) {
        case 1:
            cout << "Start injection..." << endl;
            Sleep(500);
            cout << "Injection Started!" << endl;
            break;
        case 2:
            cout << "Opening Options..." << endl;
            Sleep(500);
            cout << "Options Opened!" << endl;
            optionsMenu();
        case 3:
            cout << "Exiting Program..." << endl;
            Sleep(500);
            cout << "Program Exited!" << endl;
            break;
        default:
            cout << "Invalid Selection!" << endl;
            Sleep(2000);
            break;
    }
    return 0;
}

int FirstSetup() {
    cout << "Welcome to the First Setup!" << endl;
    cout << "Select the game you want to mod: " << endl;
    cout << "1. Assault Cube" << endl;
    int StartupSelection = 0;
    cin >> StartupSelection;
    return mainMenu();
}


int normalStartup() {
    for (int i = 1; i <= 2; ++i) {
        cout << "Initializing Program..." << endl;
        Sleep(250);
        cout << "Initializing Program.." << endl;
        Sleep(250);
    }
    Sleep(500);
    cout << endl << "Program Initialized!" << endl << endl;
    return mainMenu();
}

int silentStartup() {
    cout << "Initializing Silent startup..." << endl;
    for (int i = 1; i <= 2; ++i) {
        cout << "Initializing Program..." << endl;
        Sleep(250);
        cout << "Initializing Program.." << endl;
        Sleep(250);
    }
    cout << "Program Initialized!" << endl;
    return mainMenu();
}

int debugStartup() {
    cout << "Initializing Debug startup..." << endl;
    Sleep(500);
    cout << "Program Initialized!" << endl;
    return mainMenu();
}


int Exit() {
    cout << "Exiting Program..." << endl;
    Sleep(500);
    cout << "Program Exited!" << endl;
    return 0;
}

int main() {
    cout << "Welcome to the Game Modder!" << endl;
    cout << "Please select a startup option: " << endl; // this option will be removed and there will be a config file created with the first setup with what startup option you want to use.
    cout << "1. Firstsetup" << endl;
    cout << "2. Normal Startup" << endl;
    cout << "3. silent Startup" << endl;
    cout << "4. Debug Startup" << endl;
    int StartupSelection = 0;
    cin >> StartupSelection;
    if (StartupSelection == 1) { // if config file doesnt exsist then run first setup
        FirstSetup();
    }
    else if (StartupSelection == 2) { // if config file states normal startup
        normalStartup();
    }
    else if (StartupSelection == 3) { // if config file states silent startup
        silentStartup();
    }
    else if (StartupSelection == 4) { // if config file states debug startup
        debugStartup();
    }
    else {
        cout << "Error: Config file is corrupted!" << endl;
        Sleep(2000);
        cout << "Please run First Setup!" << endl;
        Sleep(2000);
        FirstSetup();
    }
    return 0;
}