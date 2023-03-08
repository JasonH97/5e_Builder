#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Character {
    private:
        string name;
        string class_;
        string race;
        int hit_points;
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
        string equipment;
    public:
        Character(string name, string class_, string race, int hit_points, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, string equipment) { 
            this-> name = name;
            this-> class_ = class_;
            this-> race = race;
            this-> hit_points = hit_points;
            this-> strength = strength;
            this-> dexterity = dexterity;
            this-> constitution = constitution;
            this-> intelligence = intelligence;
            this-> wisdom = wisdom;
            this-> charisma = charisma;
            this-> equipment = equipment;
        }

        // VIEWS //
        string get_name() { return this->name; }
        string get_class() { return this->class_; }
        string get_race() { return this->race; }
        int get_strength() { return this->strength; }
        int get_dexterity() { return this->dexterity; }
        int get_constitution() { return this->constitution; }
        int get_intelligence() { return this->intelligence; }
        int get_wisdom() { return this->wisdom; }
        int get_charisma() { return this->charisma; }

        // SETS //
        void set_name(string name) { this->name = name; }
        void set_hit_points(int hit_points) { this->hit_points = hit_points; }
        void set_strength(int strength) { this->strength = strength; }
        void set_dexterity(int dexterity) { this->dexterity = dexterity; }
        void set_constitution(int constitution) { this->constitution = constitution; }
        void set_intelligence(int intelligence) { this->intelligence = intelligence; }
        void set_wisdom(int wisdom) { this->wisdom = wisdom; }
        void set_charisma(int charisma) { this->charisma = charisma; }

        void set_class() {
            int choice;
            cout << "\nChoose a class from the following:" << endl;
            cout << "1:  Barbarian" << endl;
            cout << "2:  Bard" << endl;
            cout << "3:  Cleric" << endl;
            cout << "4:  Druid" << endl;
            cout << "5:  Fighter" << endl;
            cout << "6:  Monk" << endl;
            cout << "7:  Paladin" << endl;
            cout << "8:  Ranger" << endl;
            cout << "9:  Rogue" << endl;
            cout << "10: Sorcerer" << endl;
            cout << "11: Warlock" << endl;
            cout << "12: Wizard" << endl;
            cin >> choice;
            switch(choice) { 
                case 1:  this->class_ = "Barbarian"; break;
                case 2:  this->class_ = "Bard"; break;
                case 3:  this->class_ = "Cleric"; break;
                case 4:  this->class_ = "Druid"; break;
                case 5:  this->class_ = "Fighter"; break;
                case 6:  this->class_ = "Monk"; break;
                case 7:  this->class_ = "Paladin"; break;
                case 8:  this->class_ = "Ranger"; break;
                case 9:  this->class_ = "Rogue"; break;
                case 10: this->class_ = "Sorcerer"; break;
                case 11: this->class_ = "Warlock"; break;
                case 12: this->class_ = "Wizard"; break;
                default: cout << "Invalid choice" << endl; break;
            }
        }
        void set_race() {
            int choice;
            cout << "\nChoose a race from the following:" << endl;
            cout << "1:  Hill Dwarf" << endl;
            cout << "2:  Mountain Dwarf" << endl;
            cout << "3:  High Elf" << endl;
            cout << "4:  Wood Elf" << endl;
            cout << "5:  Dark Elf (Drow)" << endl;
            cout << "6:  Lightfoot Halfling" << endl;
            cout << "7:  Stout Halfling" << endl;
            cout << "8:  Human" << endl;
            cout << "9:  Variant Human" << endl;
            cout << "10: Dragonborn" << endl;
            cout << "11: Forest Gnome" << endl;
            cout << "12: Rock Gnome" << endl;
            cout << "13: Half-Elf" << endl;
            cout << "14: Half-Orc" << endl;
            cout << "15: Tiefling" << endl;
            cin >> choice;
            switch(choice) { 
                case 1:  this->race = "Hill Dwarf"; break;
                case 2:  this->race = "Mountain Dwarf"; break;
                case 3:  this->race = "High Elf"; break;
                case 4:  this->race = "Wood Elf"; break;
                case 5:  this->race = "Dark Elf (Drow)"; break;
                case 6:  this->race = "Lightfoot Halfling"; break;
                case 7:  this->race = "Stout Halfling"; break;
                case 8:  this->race = "Human"; break;
                case 9:  this->race = "Variant Human"; break;
                case 10: this->race = "Dragonborn"; break;
                case 11: this->race = "Forest Gnome"; break;
                case 12: this->race = "Rock Gnome"; break;
                case 13: this->race = "Half-Elf"; break;
                case 14: this->race = "Half-Orc"; break;
                case 15: this->race = "Tiefling"; break;
                default: cout << "Invalid choice" << endl; break;
            }
        }
        void set_initial_health() {
            if (class_ == "Barbarian") this->hit_points = 7+((constitution-10)/2);
            if (class_ == "Bard")      this->hit_points = 5+((constitution-10)/2);
            if (class_ == "Cleric")    this->hit_points = 5+((constitution-10)/2);
            if (class_ == "Druid")     this->hit_points = 5+((constitution-10)/2);
            if (class_ == "Fighter")   this->hit_points = 6+((constitution-10)/2);
            if (class_ == "Monk")      this->hit_points = 5+((constitution-10)/2);
            if (class_ == "Paladin")   this->hit_points = 6+((constitution-10)/2);
            if (class_ == "Ranger")    this->hit_points = 6+((constitution-10)/2);
            if (class_ == "Rogue")     this->hit_points = 5+((constitution-10)/2);
            if (class_ == "Sorcerer")  this->hit_points = 4+((constitution-10)/2);
            if (class_ == "Warlock")   this->hit_points = 5+((constitution-10)/2);
            if (class_ == "Wizard")    this->hit_points = 4+((constitution-10)/2);
        }

        void apply_race_modifiers() {
            if (race == "Hill Dwarf") {
                //CON=CON+2
                //WIS=WIS+1
                //HP=HP+1 & future HP gain +1 on lv up 
                set_constitution(constitution+2);
                set_wisdom(wisdom+1);
                set_hit_points(hit_points+1);
                //speed=25
                //darkvision=60
                //dwarven resilience = adv/resist vs poison
                //prof w/ battleaxe, handaxe, throwing hammer, warhammer
                //prof w/ smith's tools, brewer's supplies, or mason's tools
                //stonecunning
                //languages = common, dwarvish
            }
            if (race == "Mountain Dwarf") {
                //CON=CON+2
                //STR=STR+2
                set_constitution(constitution+2);
                set_strength(strength+2);
                //speed=25
                //darkvision=60
                //dwarven resilience = adv/resist vs poison
                //prof w/ battleaxe, handaxe, throwing hammer, warhammer
                //prof w/ smith's tools, brewer's supplies, or mason's tools
                //stonecunning
                //languages = common, dwarvish
                //prof w/ light/med armor
            }
            if (race == "High Elf") {
                //DEX=DEX+2
                //INT=INT+1
                set_dexterity(dexterity+2);
                set_intelligence(intelligence+1);
                //speed=30
                //darkvision=60
                //prof w/ Perception
                //adv vs being charmed, magic can't put you to sleep
                //languages = common, elvish
                //prof w/ longsword,shortsword,longbow
                //know 1 cantrip from wizard list, using INT as cast modifier
                //know one additional language
            }
            if (race == "Wood Elf") {
                //DEX=DEX+2
                //WIS=WIS+1
                set_dexterity(dexterity+2);
                set_wisdom(wisdom+1);
                //speed=35
                //darkvision=60
                //prof w/ Perception
                //adv vs being charmed, magic can't put you to sleep
                //languages = common, elvish
                //prof w/ longsword,shortsword,longbow
                //can attempt to hide even when only lightly obscured by nature
            }
            if (race == "Dark Elf (Drow)") {
                //DEX=DEX+2
                //CHA=CHA+1
                set_dexterity(dexterity+2);
                set_charisma(charisma+1);
                //speed=30
                //darkvision=120
                //prof w/ Perception
                //adv vs being charmed, magic can't put you to sleep
                //languages = common, elvish
                //disadvantage on attack rolls and WIS checks in direct sunlight
                //know `Dancing Lights` cantrip w/ CHA as cast modifier
                //@lv3 know `Faerie Fire` w/ CHA as cast modifier
                //@lv5 know `Darkness` w/ CHA as cast modifier
                //prof w/ rapiers, shortswords, hand-crossbows
            }
            if (race == "Lightfoot Halfling") {
                //DEX=DEX+2
                //CHA=CHA+1
                set_dexterity(dexterity+2);
                set_charisma(charisma+1);
                //speed=25
                //Lucky - reroll on nat 1 for attack, ability checks, saving throws
                //Brave - adv vs being frightened
                //Nimble - can move through space of any creature larger than you
                //languages = common, halfling
                //can attempt to hide when obscured only by creature one size larger than you
            }
            if (race == "Stout Halfling") {
                //DEX=DEX+2
                //CON=CON+1
                set_dexterity(dexterity+2);
                set_constitution(constitution+1);
                //speed=25
                //Lucky - reroll on nat 1 for attack, ability checks, saving throws
                //Brave - adv vs being frightened
                //Nimble - can move through space of any creature larger than you
                //languages = common, halfling
                //adv/resist vs poison
            }
            if (race == "Human") {
                //all stats++
                set_strength(strength+1);
                set_dexterity(dexterity+1);
                set_constitution(constitution+1);
                set_intelligence(intelligence+1);
                set_wisdom(wisdom+1);
                set_charisma(charisma+1);
                //speed=30
                //langauges = common, 1 lang of choice
            }
            if (race == "Variant Human") {
                // FREE FEAT
                // choose 2 stats ++
                int choice1;
                int choice2;
                cout << "\n(Variant Human) Select First Ability to increase:" << endl;
                cout << "1: Strength" << endl;
                cout << "2: Dexterity" << endl;
                cout << "3: Constitution" << endl;
                cout << "4: Intelligence" << endl;
                cout << "5: Wisdom" << endl;
                cout << "6: Charisma" << endl;
                cin >> choice1;
                switch(choice1) {
                    case 1: set_strength(strength+1); break;
                    case 2: set_dexterity(dexterity+1); break;
                    case 3: set_constitution(constitution+1); break;
                    case 4: set_intelligence(intelligence+1); break;
                    case 5: set_wisdom(wisdom+1); break;
                    case 6: set_charisma(charisma+1); break;
                    default: cout << "Invalid choice" << endl; break;
                }
                cout << "(Variant Human) Select Second Ability to increase:" << endl;
                cout << "1: Strength" << endl;
                cout << "2: Dexterity" << endl;
                cout << "3: Constitution" << endl;
                cout << "4: Intelligence" << endl;
                cout << "5: Wisdom" << endl;
                cout << "6: Charisma" << endl;
                choice2 = choice1;
                while (choice1 == choice2) {
                    cout << "(You cannot choose the same ability twice)" << endl;
                    cin >> choice2;
                }
                switch(choice2) {
                    case 1: set_strength(strength+1); break;
                    case 2: set_dexterity(dexterity+1); break;
                    case 3: set_constitution(constitution+1); break;
                    case 4: set_intelligence(intelligence+1); break;
                    case 5: set_wisdom(wisdom+1); break;
                    case 6: set_charisma(charisma+1); break;
                    default: cout << "Invalid choice" << endl; break;
                }
            }
            if (race == "Dragonborn") {
                int choice;
                string breath;
                //STR=STR+2
                //CHA=CHA+1
                set_strength(strength+2);
                set_charisma(charisma+1);
                //speed=30
                //breath weapon
                cout << "\n(Dragonborn) Select Ancestry:" << endl;
                cout << "1:  Black  (Acid)      - 5 by 30ft line (DEX Save)" << endl;
                cout << "2:  Blue   (Lightning) - 5 by 30ft line (DEX Save)" << endl;
                cout << "3:  Brass  (Fire)      - 5 by 30ft line (DEX Save)" << endl;
                cout << "4:  Bronze (Lightning) - 5 by 30ft line (DEX Save)" << endl;
                cout << "5:  Copper (Acid)      - 5 by 30ft line (DEX Save)" << endl;
                cout << "6:  Gold   (Fire)      - 15 ft. cone (DEX Save)" << endl;
                cout << "7:  Green  (Poison)    - 15 ft. cone (CON Save)" << endl;
                cout << "8:  Red    (Fire)      - 15 ft. cone (DEX Save)" << endl;
                cout << "9:  Silver (Cold)      - 15 ft. cone (CON Save)" << endl;
                cout << "10: White  (Cold)      - 15 ft. cone (CON Save)" << endl;
                cin >> choice;
                switch(choice) {
                    case 1:  breath = "Black"; break;
                    case 2:  breath = "Blue"; break;
                    case 3:  breath = "Brass"; break;
                    case 4:  breath = "Bronze"; break;
                    case 5:  breath = "Copper"; break;
                    case 6:  breath = "Gold"; break;
                    case 7:  breath = "Green"; break;
                    case 8:  breath = "Red"; break;
                    case 9:  breath = "Silver"; break;
                    case 10: breath = "White;"; break;
                    default: cout << "Invalid choice" << endl; break;
                }
                //languages = common + draconic
            }
            if (race == "Forest Gnome") {
                //INT=INT+2
                //DEX=DEX+1
                set_intelligence(intelligence+2);
                set_dexterity(dexterity+1);
                //speed=25
                //darkvision=60
                //adv on int,wis,cha saving throws VS MAGIC
                //languages = common + gnomish
                //know minor illusion cantrip, INT cast modifier
                //can nonverbally communicate simple ideas with small beasts
            }
            if (race == "Rock Gnome") {
                //INT=INT+2
                //CON=CON+1
                set_intelligence(intelligence+2);
                set_constitution(constitution+2);
                //speed=25
                //darkvision=60
                //adv on int,wis,cha saving throws VS MAGIC
                //languages = common + gnomish
                //artificer's lore, look it up homie
                //tinker - gimmick ability
            }
            if (race == "Half-Elf") {
                //CHA=CHA+2
                set_charisma(charisma+2);
                //2 other scores +1 
                int choice1;
                int choice2;
                cout << "\n(Half-Elf) Select First Ability to increase:" << endl;
                cout << "1: Strength" << endl;
                cout << "2: Dexterity" << endl;
                cout << "3: Constitution" << endl;
                cout << "4: Intelligence" << endl;
                cout << "5: Wisdom" << endl;
                cin >> choice1;
                switch(choice1) {
                    case 1: set_strength(strength+1); break;
                    case 2: set_dexterity(dexterity+1); break;
                    case 3: set_constitution(constitution+1); break;
                    case 4: set_intelligence(intelligence+1); break;
                    case 5: set_wisdom(wisdom+1); break;
                    default: cout << "Invalid choice" << endl; break;
                }
                cout << "(Half-Elf) Select Second Ability to increase:" << endl;
                cout << "1: Strength" << endl;
                cout << "2: Dexterity" << endl;
                cout << "3: Constitution" << endl;
                cout << "4: Intelligence" << endl;
                cout << "5: Wisdom" << endl;
                choice2 = choice1;
                while (choice1 == choice2) {
                    cout << "(You cannot choose the same ability twice)" << endl;
                    cin >> choice2;
                }
                switch(choice2) {
                    case 1: set_strength(strength+1); break;
                    case 2: set_dexterity(dexterity+1); break;
                    case 3: set_constitution(constitution+1); break;
                    case 4: set_intelligence(intelligence+1); break;
                    case 5: set_wisdom(wisdom+1); break;
                    default: cout << "Invalid choice" << endl; break;
                }
                //speed=30
                //darkvision=60
                //adv vs being charmed, magic can't put you to sleep
                //prof in 2 skills of choice
                //languages = common, elvish, 1 extra language
            }
            if (race == "Half-Orc") {
                //STR=STR+2
                //CON=CON+1
                set_strength(strength+2);
                set_constitution(constitution+1);
                //speed=30
                //darkvision=60
                //prof w/ Intimidation
                //relentless endurance: when dropped to 0 HP but not killed outright, drop to 1 HP instead (once / long rest)
                //savage attacks: when scoring a crit with a melee weapon attack, roll one of the weapon's dice an extra time and add to total damage
                //languages = common + orc
            }
            if (race == "Tiefling") {
                //CHA=CHA+2
                //INT=INT+1
                set_charisma(charisma+2);
                set_intelligence(intelligence+1);
                //speed=30
                //darkvision=60
                //resist fire damage
                //know `Thaumaturgy` cantrip w/ CHA as cast modifier
                //@lv3 know `Hellish Rebuke` 1x/day as 2nd level w/ CHA as cast modifier
                //@lv5 know `Darkness` 1x/day w/ CHA as cast modifier
                //languages = common + infernal
            }
        }
// write a function that prints out the character's attributes in a nicely formatted way.
        void print() {
            cout << "\nName: " << name << endl;
            cout << "Class: " << class_ << endl;
            cout << "Race: " << race << endl;
            cout << "Hit Points: " << hit_points << endl;
            cout << "Strength: " << strength << endl;
            cout << "Dexterity: " << dexterity << endl;
            cout << "Constitution: " << constitution << endl;
            cout << "Intelligence: " << intelligence << endl;
            cout << "Wisdom: " << wisdom << endl;
            cout << "Charisma: " << charisma << endl;
        }
};

int main() {
    Character my_char("","","",0,0,0,0,0,0,0,"");

    string name;
    cout << "What is the name of your character?" << endl;
    cin >> name;
    my_char.set_name(name);

    my_char.set_class();
    my_char.set_race();

    int roll;
    cout << "\nRoll for each of your abilities and assign the values." << endl;
    cout << "Strength:" << endl;
    cin >> roll;
    my_char.set_strength(roll);

    cout << "Dexterity:" << endl;
    cin >> roll;
    my_char.set_dexterity(roll);

    cout << "Constitution:" << endl;
    cin >> roll;
    my_char.set_constitution(roll);

    cout << "Intelligence:" << endl;
    cin >> roll;
    my_char.set_intelligence(roll);

    cout << "Wisdom:" << endl;
    cin >> roll;
    my_char.set_wisdom(roll);

    cout << "Charisma:" << endl;
    cin >> roll;
    my_char.set_charisma(roll);

    my_char.apply_race_modifiers();
    my_char.set_initial_health();
    my_char.print();
    return 0;
}
