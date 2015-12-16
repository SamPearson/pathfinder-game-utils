#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

#include <mysql++.h>
//define db connection credentials in dbconn.h (not included)
#include "dbconn.h"

#include "diceRolls.h"
#include "menu.h"

#include "genEncounter.h"
#include "genTreasure.h"
#include "genDungeon.h"

int main()
{
    // seed random number generator for dice rolls
    srand (time(NULL));

    cout << "----------------------------------------" << endl ;
    cout << "|      Welcome to DungeonMaster        |" << endl ;
    cout << "| The Dungeon Creation Automation tool |" << endl ;
    cout << "----------------------------------------" << endl ;

    int genWhat = -1 ; 
    while ( genWhat != 0 ) 
    {
        cout << endl << std::endl ; 
        cout << "Are you looking to:" << endl;
        cout << "(1) -  make a dungeon " << endl ; 
        cout << "(2) - generate a minor treasure roll "  << endl; 
        cout << "(3) - generate a combat encounter?" << endl ; 
        cout << "(0) - or are you done ? " << endl ; 

        genWhat = menuOption(3) ;

        if ( genWhat == 1 )
            genDungeon();
        if ( genWhat == 2 )
            genMinorTreasure();
        if ( genWhat == 3 )
            genEncounter();
        
    }
    return 0;




}


