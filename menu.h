#ifndef MENU_H
#define MENU_H

int menuOption(int choices)
{
    int choice = -1;
    while (choice == -1 )
    {
        cin >> choice ;
        if (cin.fail() || choice > choices )
        {
            cerr << "Bad input, try again." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            choice= -1;
            continue;
        }
    }
    return choice;
}

#endif
