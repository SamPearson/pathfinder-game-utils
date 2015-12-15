#ifndef DICEROLLS_H
#define DICEROLLS_h

int rollD();

// Args slightly out of order due to the necessity of all optional args being at the end
// thus 1d20+3 would be called as rollD(20, 1, 3); 
// additionally, if you're adding a modifier, you MUST provide the number of dice
// rollD(20, 4) may act as 4d20, or d20+4 . Specify to ensure you get what you want.
int rollD(int faces, int dice=1, int modifier=0)
{
    int totalRoll = 0; 
    int natRoll = 0;
    for ( int rolls = 0 ; rolls < dice ; rolls ++ ) 
    {
        natRoll = rand() % faces + 1;
        totalRoll += natRoll;
    }
    totalRoll += modifier; 
    return totalRoll;
}

#endif
