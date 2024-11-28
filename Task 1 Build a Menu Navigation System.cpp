#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
void display(vector<string>& menuItems){
    for(int i =0;i<menuItems.size();i++){
        cout<<i+1<<"."<<menuItems[i]<<endl;
    }
}
int main() {

    vector<string> mainMenu = {"Settings","Media"};
    vector<string> settingsMenu = {"Display Setting","Audio Setting"};
    vector<string> displaySettings = {"Submenu"};
    vector<string> audioSettings = {"Submenu"};
    vector<string> mediaMenu = {"Radio","Bluetooth Audio"};
    vector<string> radioMenu = {"Submenu"};
    vector<string> bluetoothAudio = {"Submenu"};
    vector<string>* currentMenu = &mainMenu;
    bool isInMenu = true;
    while(isInMenu){
        cout<<"Current Menu : "<<endl;
        display(*currentMenu);
        cout<<endl;
         cout << "Select an option:-"<<endl;
        cout << "1: Navigate down (select)"<<endl;
        cout << "2: Navigate up (go back)"<<endl;
        cout << "3: Enter submenu (if available)"<<endl;
        cout << "0: Exit"<<endl;
        cout << "Choice: ";
        int choice;
        cin>>choice;
        cout<<endl;
        if(choice == 0){
            cout<<"exiting..."<<endl;
            isInMenu = false;
        }else if(choice == 1 || choice == 3){
            int selectSubMenu;
            cout<<"Select Submenu of (1.Setting , 2.Media)"<<endl;
            cin>>selectSubMenu;
            if(selectSubMenu == 1){
                currentMenu = &settingsMenu;
            }else if(selectSubMenu == 2){
                currentMenu = &mediaMenu;
            }else{
                cout<<"Invalid submenu"<<endl;
            }
        }else if (choice == 2) {
            if (currentMenu == &settingsMenu || currentMenu == &mediaMenu) {
                currentMenu = &mainMenu;
            } else if (currentMenu == &displaySettings || currentMenu == &audioSettings) {
                currentMenu = &settingsMenu;
            } else if (currentMenu == &radioMenu || currentMenu == &bluetoothAudio) {
                currentMenu = &mediaMenu;
            }
        }
    }
    return 0;
}