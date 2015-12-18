#ifndef GENENCOUNTER_H
#define GENENCOUNTER_H

#include <vector>
using std::vector;
 
void genEncounter();

class monster
{
    private:
        int xp;
        string name;
    public:
        monster(string name, int xp)
        {
            this->xp = xp;
            this->name = name;
        }
        int getXP()
        {
            return xp;
        };
        string getName()
        {
            return name;
        };
};
class trap
{
    private:
        int xp;
        int name;

};

class encounter
{
    private:
        int targetCR=0;
        int xpBudget=0;
        int xpSpent=0;
        int pctMonster=0;
        int pctTrap=0;
        string environment;
        vector<monster> monsters;
        string traps[20];

    public:
        void setCR(int cr)
        {
            if (cr == 0.25)
                xpBudget = 100;
            if (cr == 0.3)
                xpBudget = 135;
            if (cr == 0.5)
                xpBudget = 200;
            if (cr == 1)
                xpBudget = 400;
            if (cr == 2)
                xpBudget = 600;
            if (cr == 3)
                xpBudget = 800;
            if (cr == 4)
                xpBudget = 1200;
            if (cr == 5)
                xpBudget = 1600;
            if (cr == 6)
                xpBudget = 2400;
            if (cr == 7)
                xpBudget = 3200;
            if (cr == 8)
                xpBudget = 4800;
        };

        void addMonster(monster newMon)
        {
            monsters.push_back(newMon);
            xpSpent += newMon.getXP();
            cout << "added" << newMon.getXP() << " xp " ; 
            cout << "total xp spend is " << xpSpent << endl ; 
            cout << "and there's " << xpLeft() << " xp left " << endl ; 
        };
/*
        void removeMonster(monster deadMon)
        {
            monsters.erase(some index)
            xpSpent -= deadMon.getXP();
        }
*/
        void removeLastMonster()
        {
            xpSpent -= monsters[monsters.size()-1].getXP();
            cout << "removed " << monsters[monsters.size()-1].getXP() << " from the ledger" << endl ; 
            monsters.pop_back();
        };
        void showMonsters()
        {
            for (int i=0; i < monsters.size() ; i++)
            {
                cout << monsters[i].getName() << endl;

            }
        };
        int xpLeft()
        {
            cout << "xpbudget: " << xpBudget << endl ;
            cout << "xpSpent: " << xpSpent << endl;
            return xpBudget - xpSpent;
        };
        bool budgetMet()
        {
            cout << "budget - " << 0.75 * xpBudget << endl ;
            if (xpLeft() <= 0.25 * xpBudget )
                return true;
            else
                return false;
        };
        bool budgetBlown()
        {
            if (xpSpent > 1.25 * xpBudget)
                return true;
            else
                return false;
        };
};

#endif
