#include <iostream>
using std::string; 
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

#include "diceRolls.h"
#include <mysql++.h>
#include "dbconn.h"
#include "genEncounter.h"
#include "menu.h"

void genEncounter()
{

    int targetCR=0;
    int env=0;
    int xpBudget=0;
    int xpSpent=0;
    int pctMonster=0;
    int pctTrap=0;
    cout << "Okay, what CR are you looking for?" << endl;
    targetCR = menuOption(8);
    cout << endl;
    cout << "Sometimes an encounter has both traps and monsters." << endl;
    cout << "Enter the % of the encounter you'd like to be monsters." << endl;
    cout << "Entering 100 will have no traps, 0 will be all traps." << endl;
    cout << "(at lower CRs you may not be able to mix and match)" << endl;


    cout <<"What environment will the encounter be in?" << endl;
    cout <<"(1) Don't care / random " << endl;
    cout <<"(2) Dungeon " << endl;
    cout <<"(3) Forest " << endl;
    cout <<"(4) Swamp " << endl;
    cout <<"(5) Mountain " << endl;
    cout <<"(6) Desert " << endl;
    cout <<"(7) City " << endl;
    env = menuOption(7);

// The idea is to pull a list of entries from the database that meet the 
//   CR and environment requirements set above
    mysqlpp::Connection conn(false);
    if (conn.connect( DBNAME,DBHOST,DBUSER,DBPASS,DBPORT))
    {
        mysqlpp::Query query = conn.query("select * from `monsters` where `groups` like '%goblin%'");
        mysqlpp::StoreQueryResult res = query.store();
        if (res)
        {
            cout << "Results below: " << endl ;
            mysqlpp::StoreQueryResult::const_iterator it;
            for (it=res.begin(); it != res.end(); ++it)
            {
                mysqlpp::Row row = *it;
                cout << '\t' << row[1] <<endl ;

            }
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

