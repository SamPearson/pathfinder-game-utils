#include <iostream>
using std::cout;
using std::endl;

#include "diceRolls.h"
#include "genTreasure.h"

void genMinorTreasure()
{
    int itemRoll = 0;
    itemRoll=rollD(100);
    cout <<"For the initial d% you rolled a "<< itemRoll <<"! " << endl;
    if ( itemRoll < 19 )
        cout <<  rollD(6,3) << " gold " << endl ;
    else if ( itemRoll < 49 )
        cout << rollD (10,5) << " gold " << endl ;
    else if ( itemRoll < 64 )
        cout << rollD(10,5) << " gold, " << rollD(10,5) << "GP in gems" << endl ;
    else if ( itemRoll < 74 )
        cout << rollD(10,2) << " gold, " << rollD(10,8) << "GP in gems" << endl ;
    else if ( itemRoll == 74 )
        cout << "Masterwork Weapon" << endl ;
    else if ( itemRoll < 100 )
        genMinorMagicItem();
    else
        cout << "Roll of 100, treasure map! and also reroll." ;
}


void genMinorMagicItem()
{
    int itemRoll = rollD(100) ;
    if (itemRoll < 3)
        genMinorMagicArmor();
    else if (itemRoll < 5 )
        genMagicShield();
    else if (itemRoll < 10)
        genMinorMagicWeapon();
    else if (itemRoll < 45)
        genPotion();
    else if (itemRoll < 47)
        genRing();
    else if (itemRoll < 82)
        genMinorScroll();
    else if (itemRoll < 92)
        genMinorWand();
    else
        genWonderousItem();
}

void genMinorMagicArmor()
{
    int itemRoll = rollD(100) ;
    if ( itemRoll < 63 )
        cout << "+1 Armor" << endl ;
    else if ( itemRoll < 66 )
        cout << "+1 Glamered half plate" << endl ;
    else if ( itemRoll < 72 )
        cout << "+1 Mithral chainmail" << endl;
    else if ( itemRoll < 78 )
        cout << "+1 poison resistant scale mail" << endl;
    else if ( itemRoll < 86 )
        cout << "+1 Shadow studded leather" << endl;
    else
        cout << " +2 Armor" << endl;
}

void genMagicShield()
{
    int itemRoll = rollD(100) ;
    if ( itemRoll < 81 )
        cout << "+1 Shield" << endl ;
    else if ( itemRoll < 83 )
        cout << "+1 Arrow Catching Shield" << endl ;
    else if ( itemRoll < 85 )
        cout << "+1 Blinding Shield" << endl ;
    else if ( itemRoll < 88 )
        cout << "+1 Feathered Shield" << endl ;
    else if ( itemRoll < 91 )
        cout << "+1 Light Fortification Shield" << endl ;
    else
        cout << "+2 Shield" ;
}
void genMinorMagicWeapon()
{
    int itemRoll = rollD(100) ;
    if ( itemRoll < 89 )
        cout << "+1 weapon" << endl ;
    else if ( itemRoll == 89 )
        cout << "+2 weapon" << endl ;
    else if ( itemRoll == 90  )
        cout << "DragonSlaying ammunition" << endl ;
    else if ( itemRoll < 94 )
        cout << "Javelin of lightning" << endl ;
    else if ( itemRoll < 96 )
        cout << "Masterwork Silver dagger" << endl ;
    else
        cout << "Silver Ammunition" << endl;
}

void genPotion()
{
    cout << "Poiton of ";
    int itemRoll = rollD(100) ;
    if ( itemRoll < 14 )
        cout << "Cure Light Wounds" << endl ;
    else if ( itemRoll < 21 )
        cout << "Feather fall" << endl ;
    else if ( itemRoll < 27 )
        cout << "Mage Armor" << endl ;
    else if ( itemRoll < 32 )
        cout << "Protection from evil" << endl ;
    else if ( itemRoll < 39 )
        cout << "Remove Fear" << endl ;
    else if ( itemRoll < 45 )
        cout << "Sanctuary" << endl ;
    else if ( itemRoll < 51 )
        cout << "Shield of Faith" << endl ;
    else if ( itemRoll < 54 )
        cout << "Aid" << endl ;
    else if ( itemRoll < 57 )
        cout << "Bull's Strength" << endl ;
    else if ( itemRoll < 62 )
        cout << "Cure Moderate Wounds" << endl ;
    else if ( itemRoll < 66 )
        cout << "Delay Poison" << endl ;
    else if ( itemRoll < 70 )
        cout << "Invisibility" << endl ;
    else if ( itemRoll < 73 )
        cout << "Levitate" << endl ;
    else if ( itemRoll < 77 )
        cout << "Resist Energy (acid)" << endl ;
    else if ( itemRoll < 81 )
        cout << "Resist Energy (cold)" << endl ;
    else if ( itemRoll < 85 )
        cout << "Resist Energy (elec)" << endl ;
    else if ( itemRoll < 91 )
        cout << "Resist Energy (fire)" << endl ;
    else if ( itemRoll < 94 )
        cout << "Cure srs wounds" << endl ;
    else if ( itemRoll < 96 )
        cout << "Fly" << endl ;
    else if ( itemRoll < 98 )
        cout << "Haste" << endl ;
    else if ( itemRoll == 98  )
        cout << "Remove Curse" << endl ;
    else if ( itemRoll == 99 )
        cout << "Remove Disease" << endl ;
    else
        cout << "Water Breathing" << endl ;
}

void genRing()
{
    int itemRoll = rollD(100) ;
    if ( itemRoll < 16 )
        cout << "Ring of Climbing" << endl ;
    else if ( itemRoll < 31 )
        cout << "Ring of Feather Falling" << endl ;
    else if ( itemRoll < 51 )
        cout << "Ring of Jumping" << endl ;
    else if ( itemRoll < 81 )
        cout << "Ring of Protection" << endl ;
    else if ( itemRoll < 91 )
        cout << "Ring of Sustenance" << endl ;
    else
        cout << "Ring of Swimming" << endl ;
}       

void genMinorScroll()
{       
    cout <<"Scroll of "; 
    int itemRoll = rollD(100) ;
    if ( itemRoll < 6 )
        cout << "Bless" << endl ; 
    else if ( itemRoll < 14 )
        cout << "Burning Hands" << endl ; 
    else if ( itemRoll < 20 )
        cout << "Cause Fear" << endl ; 
    else if ( itemRoll < 26 )
        cout << "Cure Light Wounds" << endl ;
    else if ( itemRoll < 32 )
        cout << "Detect Secret Doors" << endl ;
    else if ( itemRoll < 35 )
        cout << "Disguise self" << endl ; 
    else if ( itemRoll < 39 )
        cout << "Doom" << endl ;
    else if ( itemRoll < 47 )
        cout << "Mage Armor" << endl ; 
    else if ( itemRoll < 55 )
        cout << "Magic Missile" << endl ; 
    else if ( itemRoll < 61 )
        cout << "Protection From Evil" << endl ;
    else if ( itemRoll < 65 )
        cout << "Remove Fear" << endl ;
    else if ( itemRoll < 70 )
        cout << "Shield of Faith" << endl ;
    else if ( itemRoll < 76 ) 
        cout << "Sleep" << endl ; 
    else if ( itemRoll < 78 )
        cout << "Acid Arrow" << endl ;
    else if ( itemRoll < 80 )
        cout << "Bull's Strength" << endl ;
    else if ( itemRoll < 82 )
        cout << "Cure Moderate Wounds" << endl ;
    else if ( itemRoll == 82 )
        cout << "Darkness" << endl ;
    else if ( itemRoll < 85 )
        cout << "Delay Poison" << endl ;
    else if ( itemRoll < 87 )
        cout << "Hideous Laughter" << endl ;
    else if ( itemRoll < 89 )
        cout << "Hold Person" << endl ;
    else if ( itemRoll < 91 )
        cout << "Invisibility" << endl ;
    else if ( itemRoll < 93 )
        cout << "Knock" << endl ;
    else if ( itemRoll == 93 )
        cout << "Levitate" << endl ;
    else if ( itemRoll < 96 )
        cout << "Resist Energy" << endl ;
    else if ( itemRoll < 98 )
        cout << "Scorching Ray" << endl ;
    else if ( itemRoll == 98 )
        cout << "Sound Burst" << endl ;
    else if ( itemRoll == 99 )
        cout << "Spiritual Weapon" << endl ;
    else if ( itemRoll == 100 )
        cout << "Web" << endl ;
}

void genMinorWand()
{
    int itemRoll = rollD(100) ;
    cout << "Wand of ";
    if ( itemRoll < 4 )
        cout << "Alarm" << endl ;
    else if ( itemRoll < 9 )
        cout << "Bless" << endl ;
    else if ( itemRoll < 14 )
        cout << "Burning Hands" << endl ;
    else if ( itemRoll < 19 )
        cout << "Cause Fear" << endl ;
    else if ( itemRoll < 22 )
        cout << "Charm Person" << endl ;
    else if ( itemRoll < 27 )
        cout << "Cure Light Wounds" << endl ;
    else if ( itemRoll < 31 )
        cout << "Detect Evil" << endl ;
    else if ( itemRoll < 35 )
        cout << "Detect Secret Doors" << endl ;
    else if ( itemRoll < 38 )
        cout << "Disguise Self" << endl ;
    else if ( itemRoll < 41 )
        cout << "Divine Favor" << endl ;
    else if ( itemRoll < 47 )
        cout << "Doom" << endl ;
    else if ( itemRoll < 51 )
        cout << "Feather Fall" << endl ;
    else if ( itemRoll < 56 )
        cout << "Mage Armor" << endl ;
    else if ( itemRoll < 61 )
        cout << "Magic Missile" << endl ;
    else if ( itemRoll < 66 )
        cout << "Protection From Evil" << endl ;
    else if ( itemRoll < 69 )
        cout << "Remove Fear" << endl ;
    else if ( itemRoll < 72 )
        cout << "Sanctuary" << endl ;
    else if ( itemRoll < 77 )
        cout << "Shield of Faith" << endl ;
    else if ( itemRoll < 82 )
        cout << "Sleep" << endl ;
    else if ( itemRoll == 82 )
        cout << "Acid Arrow" << endl ;
    else if ( itemRoll == 83 )
        cout << "Aid" << endl ;
    else if ( itemRoll == 84 )
        cout << "Augury" << endl ;
    else if ( itemRoll == 85 )
        cout << "Bull's Strength" << endl ;
    else if ( itemRoll == 86 )
        cout << "Cure Moderate Wounds" << endl ;
    else if ( itemRoll == 87 )
        cout << "Darkness" << endl ;
    else if ( itemRoll == 88 )
        cout << "Delay Poison" << endl ;
    else if ( itemRoll == 89 )
        cout << "False Life" << endl ;
    else if ( itemRoll == 90 )
        cout << "Hideous Laughter" << endl ;
    else if ( itemRoll == 91 )
        cout << "Hold Person" << endl ;
    else if ( itemRoll == 92 )
        cout << "Invisibility" << endl ;
    else if ( itemRoll == 93 )
        cout << "Knock" << endl ;
    else if ( itemRoll == 94 )
        cout << "Levitate" << endl ;
    else if ( itemRoll == 95 )
        cout << "Resist Energy" << endl ;
    else if ( itemRoll == 96 )
        cout << "Scorching Ray" << endl ;
    else if ( itemRoll == 97 )
        cout << "See Invisibility" << endl ;
    else if ( itemRoll == 98 )
        cout << "Sound Burst" << endl ;
    else if ( itemRoll == 99 )
        cout << "Spiritual Weapon" << endl ;
    else
        cout << "Web" << endl ;
}

void genWonderousItem()
{
    int itemRoll = rollD(100) ;
    if ( itemRoll < 11 )
        cout << "Bandages of Rapid Recovery" << endl ;
    else if ( itemRoll < 18 )
        cout << "Bird Feather Token" << endl ;
    else if ( itemRoll < 20 )
        cout << "Bracers of Armor" << endl ;
    else if ( itemRoll < 28 )
        cout << "Brooch of Shielding" << endl ;
    else if ( itemRoll < 31 )
        cout << "Campfire Bead" << endl ;
    else if ( itemRoll < 33 )
        cout << "Cloak of resistance +1" << endl ;
    else if ( itemRoll == 33 )
        cout << "Dust of Illusion" << endl ;
    else if ( itemRoll == 34 )
        cout << "Elemental Gem" << endl ;
    else if ( itemRoll < 37 )
        cout << "Elixir of Fire Breath" << endl ;
    else if ( itemRoll < 52 )
        cout << "Elixir of Hiding" << endl ;
    else if ( itemRoll < 67 )
        cout << "Elixir of Swimming" << endl ;
    else if ( itemRoll < 83 )
        cout << "Elixir of Vision" << endl ;
    else if ( itemRoll < 85 )
        cout << "Hand of the Mage" << endl ;
    else if ( itemRoll < 89 )
        cout << "Heroic Tabbard" << endl ;
    else if ( itemRoll == 89 )
        cout << "Pearl of Power (lvl 1)" << endl ;
    else if ( itemRoll == 90 )
        cout << "Salve of Slipperiness" << endl ;
    else if ( itemRoll < 96 ) 
        cout << "Silversheen" << endl ;
    else
        cout << "Tree Feather Token" << endl ;
}       

