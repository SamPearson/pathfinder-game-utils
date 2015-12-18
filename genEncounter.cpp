#include <iostream>
#include <stdio.h>
#include <vector>
using std::string; 
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::vector;

#include "diceRolls.h"
#include <mysql++.h>
#include <mystring.h>
#include "dbconn.h"
#include "genEncounter.h"
#include "menu.h"

void genEncounter()
{
    encounter newEncounter;
    int targetCR=0;
    int env=0;
    int xpBudget=0;
    int xpSpent=0;
    int pctMonster=0;
    int pctTrap=0;
    cout << "Okay, what CR are you looking for?" << endl;
    targetCR = menuOption(8);
    newEncounter.setCR(targetCR);

/*
    cout << endl;
    cout << "Sometimes an encounter has both traps and monsters." << endl;
    cout << "Enter the % of the encounter you'd like to be monsters." << endl;
    cout << "Entering 100 will have no traps, 0 will be all traps." << endl;
    cout << "(at lower CRs you may not be able to mix and match)" << endl;
*/

    cout <<"What environment will the encounter be in?" << endl;
    cout <<"(1) Don't care / random " << endl;
    cout <<"(2) Dungeon " << endl;
    cout <<"(3) Forest " << endl;
    cout <<"(4) Swamp " << endl;
    cout <<"(5) Mountain " << endl;
    cout <<"(6) Desert " << endl;
    cout <<"(7) City " << endl;
    env = menuOption(7);
    string envString="";
    if (env == 1)
        env = rollD(6,1) + 1 ;
    if (env == 2)
        envString = "Dungeon";
    if (env == 3)
        envString = "Forest";
    if (env == 4)
        envString = "Swamp";
    if (env == 5)
        envString = "Mountain";
    if (env == 6)
        envString = "Desert";
    if (env == 7)
        envString = "City";
    
    string crString = std::to_string (targetCR) ;
    string grabAllQuery = "SELECT * FROM `monsters` WHERE `CR` <= " +
        crString + " AND `environment` like '%" + envString + "%' " ; 

// The idea is to pull a list of entries from the database that meet the 
//   CR and environment requirements set above
    mysqlpp::Connection conn(false);
    if (conn.connect( DBNAME,DBHOST,DBUSER,DBPASS,DBPORT))
    {
        mysqlpp::Query query = conn.query(grabAllQuery);
        mysqlpp::StoreQueryResult res = query.store();
        if (res)
        {
            vector<monster> eligibleMonsters;
//            int givenXP;
            mysqlpp::String dbString; 
            string name;
            int xp;
            mysqlpp::StoreQueryResult::const_iterator it;
            for (it=res.begin(); it != res.end(); ++it)
            {
                mysqlpp::Row row = *it;
                //converting from mysqlpp string to a c++ string
                dbString = row[0];
                name = string(dbString.data(),dbString.length());
                dbString = row[2];
                xp = dbString;
                monster freshMonster(name,xp);
                eligibleMonsters.push_back(freshMonster);
            }

/* 
//          Debug - if you need to see the vector's elements
            for (int i=0; i < eligibleMonsters.size() ; i++)
            {
                cout << eligibleMonsters[i].getName() << endl;

            }
*/

            int randIndex;
            while ( newEncounter.budgetMet() == false )
            {
                cout << "searching for monster" << endl ; 
                //select from eligibleMonsters at random
                randIndex = rand() % eligibleMonsters.size();
                newEncounter.addMonster(eligibleMonsters[randIndex]);
                cout << "added it" << endl; 
                cout << "its xp was " << eligibleMonsters[randIndex].getXP() << endl ; 
                //if we've blown the xp budget
                if ( newEncounter.budgetBlown() )
                {
                    cout << "budget was blown." << endl ; 
                    //  pop the last value off the eligibleMonsters vector
                    newEncounter.removeLastMonster();
                    //  trim off monsters that wont fit in the remaining xp
                    cout << "removed the last monster" << endl ; 
                }
            }

            cout << "Encounter built successfully. Monster list below:" << endl ; 
            newEncounter.showMonsters();

        }
        else
        {
            cout << "Query failed" << endl ;
            cout << query.error() << endl ;
        }
    }
    else
    {
        cout << "DB connection failed:  " << endl;
        cout << conn.error() << endl;
    }


}

