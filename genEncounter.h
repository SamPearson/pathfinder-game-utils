#ifndef GENENCOUNTER_H
#define GENENCOUNTER_H

void genEncounter();

class encounter
{
    private:
        int targetCR;
        int xpBudget;
        int xpTotal;
        int pctMonster;
        int pctTrap;
        string environment;
        string mosters[20];
        string traps[20];

    public:
        void setCR(int cr);
        int getCR();
};


#endif
