#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// TODO: 
// - class abilities
// - skills
// - spells/cantrips
// - equipment

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
        vector<string> abilities;
        vector<string> proficiencies;
        int speed;
        int darkvision;

    public:
        Character(string name, string class_, string race, int hit_points, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, vector<string> abilities, int speed, int darkvision, vector<string> proficiencies) {
            this-> name          =          name;
            this-> class_        =        class_;
            this-> race          =          race;
            this-> hit_points    =    hit_points;
            this-> strength      =      strength;
            this-> dexterity     =     dexterity;
            this-> constitution  =  constitution;
            this-> intelligence  =  intelligence;
            this-> wisdom        =        wisdom;
            this-> charisma      =      charisma;
            this-> abilities     =     abilities;
            this-> speed         =         speed;
            this-> darkvision    =    darkvision;
            this-> proficiencies = proficiencies;
        }

        void set_hit_points(int hit_points) {
            if (race != "Hill Dwarf") {
                this->hit_points  =  hit_points;
            } else {
                this->hit_points = hit_points+1;
            }
        }
        void set_name(string name)              { this->name          =          name; }
        void set_strength(int strength)         { this->strength      =      strength; }
        void set_dexterity(int dexterity)       { this->dexterity     =     dexterity; }
        void set_constitution(int constitution) { this->constitution  =  constitution; }
        void set_intelligence(int intelligence) { this->intelligence  =  intelligence; }
        void set_wisdom(int wisdom)             { this->wisdom        =        wisdom; }
        void set_charisma(int charisma)         { this->charisma      =      charisma; }
        void set_speed(int speed)               { this-> speed        =         speed; }
        void set_darkvision(int darkvision)     { this-> darkvision   =    darkvision; }
        void add_ability(string ability)        { this->abilities.push_back(ability);  }
        void add_proficiency(string prof)       { this->proficiencies.push_back(prof); }

        void set_class() {
            int choice;
            cout << "\nChoose a class from the following:" << endl;
            cout << "1:  Barbarian" << endl;
            cout << "2:  Bard"      << endl;
            cout << "3:  Cleric"    << endl;
            cout << "4:  Druid"     << endl;
            cout << "5:  Fighter"   << endl;
            cout << "6:  Monk"      << endl;
            cout << "7:  Paladin"   << endl;
            cout << "8:  Ranger"    << endl;
            cout << "9:  Rogue"     << endl;
            cout << "10: Sorcerer"  << endl;
            cout << "11: Warlock"   << endl;
            cout << "12: Wizard"    << endl;
            cin >> choice;
            switch(choice) { 
                case 1:  this->class_ = "Barbarian"; break;
                case 2:  this->class_ = "Bard";      break;
                case 3:  this->class_ = "Cleric";    break;
                case 4:  this->class_ = "Druid";     break;
                case 5:  this->class_ = "Fighter";   break;
                case 6:  this->class_ = "Monk";      break;
                case 7:  this->class_ = "Paladin";   break;
                case 8:  this->class_ = "Ranger";    break;
                case 9:  this->class_ = "Rogue";     break;
                case 10: this->class_ = "Sorcerer";  break;
                case 11: this->class_ = "Warlock";   break;
                case 12: this->class_ = "Wizard";    break;
                default: cout << "Invalid choice" << endl; break;
            }
        }

        void set_race() {
            int choice;
            cout << "\nChoose a race from the following:" << endl;
            cout << "1:  Hill Dwarf"         << endl;
            cout << "2:  Mountain Dwarf"     << endl;
            cout << "3:  High Elf"           << endl;
            cout << "4:  Wood Elf"           << endl;
            cout << "5:  Dark Elf (Drow)"    << endl;
            cout << "6:  Lightfoot Halfling" << endl;
            cout << "7:  Stout Halfling"     << endl;
            cout << "8:  Human"              << endl;
            cout << "9:  Variant Human"      << endl;
            cout << "10: Dragonborn"         << endl;
            cout << "11: Forest Gnome"       << endl;
            cout << "12: Rock Gnome"         << endl;
            cout << "13: Half-Elf"           << endl;
            cout << "14: Half-Orc"           << endl;
            cout << "15: Tiefling"           << endl;
            cin >> choice;
            switch(choice) { 
                case 1:  this->race = "Hill Dwarf";         break;
                case 2:  this->race = "Mountain Dwarf";     break;
                case 3:  this->race = "High Elf";           break;
                case 4:  this->race = "Wood Elf";           break;
                case 5:  this->race = "Dark Elf (Drow)";    break;
                case 6:  this->race = "Lightfoot Halfling"; break;
                case 7:  this->race = "Stout Halfling";     break;
                case 8:  this->race = "Human";              break;
                case 9:  this->race = "Variant Human";      break;
                case 10: this->race = "Dragonborn";         break;
                case 11: this->race = "Forest Gnome";       break;
                case 12: this->race = "Rock Gnome";         break;
                case 13: this->race = "Half-Elf";           break;
                case 14: this->race = "Half-Orc";           break;
                case 15: this->race = "Tiefling";           break;
                default: cout << "Invalid choice" << endl; break;
            }
        }

        void set_initial_health() {
            if (class_ == "Barbarian") this->hit_points = 7+((constitution-10)/2); return;
            if (class_ == "Bard")      this->hit_points = 5+((constitution-10)/2); return;
            if (class_ == "Cleric")    this->hit_points = 5+((constitution-10)/2); return;
            if (class_ == "Druid")     this->hit_points = 5+((constitution-10)/2); return;
            if (class_ == "Fighter")   this->hit_points = 6+((constitution-10)/2); return;
            if (class_ == "Monk")      this->hit_points = 5+((constitution-10)/2); return;
            if (class_ == "Paladin")   this->hit_points = 6+((constitution-10)/2); return;
            if (class_ == "Ranger")    this->hit_points = 6+((constitution-10)/2); return;
            if (class_ == "Rogue")     this->hit_points = 5+((constitution-10)/2); return;
            if (class_ == "Sorcerer")  this->hit_points = 4+((constitution-10)/2); return;
            if (class_ == "Warlock")   this->hit_points = 5+((constitution-10)/2); return;
            if (class_ == "Wizard")    this->hit_points = 4+((constitution-10)/2); return;
        }

        // APPLY & MODIFY //
        void apply_race_modifiers() {
            if (race == "Hill Dwarf") {
                set_constitution(constitution+2);
                set_wisdom(wisdom+1);
                // hp +1 logic applied in set_hit_points() function
                set_speed(25);
                set_darkvision(60);
                add_ability("Dwarven Resilience: You have advantage on saving throws against poison, and you have resistance against poison damage");
                add_ability("Stonecunning: Whenever you make an Intelligence (History) check related to the Origin of Stonework, you are considered proficient in the History skill and add double your Proficiency bonus to the check, instead of your normal Proficiency bonus.");
                add_proficiency("Battleaxes");
                add_proficiency("Handaxes");
                add_proficiency("Throwing Hammers");
                add_proficiency("Warhammers");
                int choice;
                cout << "(Dwarf) Select proficiency in 1 of the following:" << endl;
                cout << "1. Smith's Tools"     << endl;
                cout << "2. Brewer's Supplies" << endl;
                cout << "3. Mason's Tools"     << endl;
                cin >> choice;
                switch(choice) {
                    case 1: add_proficiency("Smith's Tools");     break;
                    case 2: add_proficiency("Brewer's Supplies"); break;
                    case 3: add_proficiency("Mason's Tools");     break;
                }
                //languages = common, dwarvish
                return;
            }
            if (race == "Mountain Dwarf") {
                set_constitution(constitution+2);
                set_strength(strength+2);
                set_speed(25);
                set_darkvision(60);
                add_ability("Dwarven Resilience: You have advantage on saving throws against poison, and you have resistance against poison damage");
                add_ability("Stonecunning: Whenever you make an Intelligence (History) check related to the Origin of Stonework, you are considered proficient in the History skill and add double your Proficiency bonus to the check, instead of your normal Proficiency bonus.");
                add_proficiency("Battleaxes");
                add_proficiency("Handaxes");
                add_proficiency("Throwing Hammers");
                add_proficiency("Warhammers");
                add_proficiency("Light Armors");
                add_proficiency("Medium Armors");
                int choice;
                cout << "(Dwarf) Select proficiency in 1 of the following:" << endl;
                cout << "1. Smith's Tools"     << endl;
                cout << "2. Brewer's Supplies" << endl;
                cout << "3. Mason's Tools"     << endl;
                cin >> choice;
                switch(choice) {
                    case 1: add_proficiency("Smith's Tools");     break;
                    case 2: add_proficiency("Brewer's Supplies"); break;
                    case 3: add_proficiency("Mason's Tools");     break;
                }
                //languages = common, dwarvish
                return;
            }
            if (race == "High Elf") {
                set_dexterity(dexterity+2);
                set_intelligence(intelligence+1);
                set_speed(30);
                set_darkvision(60);
                add_ability("Fey Ancestry: You have advantage on Saving Throws against being Charmed, and magic can’t put you to sleep.");
                add_ability("Trance: Elves don’t need to sleep. Instead, they meditate deeply, remaining semiconscious, for 4 hours a day. (The Common word for such meditation is “trance.”) While meditating, you can dream after a fashion; such Dreams are actually mental exercises that have become reflexive through years of practice. After Resting in this way, you gain the same benefit that a human does from 8 hours of sleep.");
                add_proficiency("Perception (Skill)");
                add_proficiency("Longsword");
                add_proficiency("Shortsword");
                add_proficiency("Longbow");
                //know 1 cantrip from wizard list, using INT as cast modifier
                //know one additional language
                //languages = common, elvish
                return;
            }
            if (race == "Wood Elf") {
                set_dexterity(dexterity+2);
                set_wisdom(wisdom+1);
                set_speed(35);
                set_darkvision(60);
                add_ability("Fey Ancestry: You have advantage on Saving Throws against being Charmed, and magic can’t put you to sleep.");
                add_ability("Trance: Elves don’t need to sleep. Instead, they meditate deeply, remaining semiconscious, for 4 hours a day. (The Common word for such meditation is “trance.”) While meditating, you can dream after a fashion; such Dreams are actually mental exercises that have become reflexive through years of practice. After Resting in this way, you gain the same benefit that a human does from 8 hours of sleep.");
                add_ability("Mask of the Wild: You can attempt to hide even when you are only lightly obscured by foliage, heavy rain, falling snow, mist, and other natural phenomena.");
                add_proficiency("Perception (Skill)");
                add_proficiency("Longsword");
                add_proficiency("Shortsword");
                add_proficiency("Longbow");
                //languages = common, elvish
                return;
            }
            if (race == "Dark Elf (Drow)") {
                set_dexterity(dexterity+2);
                set_charisma(charisma+1);
                set_speed(30);
                set_darkvision(120);
                add_ability("Fey Ancestry: You have advantage on Saving Throws against being Charmed, and magic can’t put you to sleep.");
                add_ability("Sunlight Sensitivity: You have disadvantage on attack rolls and on Wisdom (Perception) checks that rely on sight when you, the target of your attack, or whatever you are trying to perceive is in direct sunlight.");
                add_proficiency("Perception (Skill)");
                add_proficiency("Rapiers");
                add_proficiency("Shortswords");
                add_proficiency("Hand-Crossbows");
                //know `Dancing Lights` cantrip w/ CHA as cast modifier
                //@lv3 know `Faerie Fire` w/ CHA as cast modifier
                //@lv5 know `Darkness` w/ CHA as cast modifier
                //languages = common, elvish
                return;
            }
            if (race == "Lightfoot Halfling") {
                set_dexterity(dexterity+2);
                set_charisma(charisma+1);
                set_speed(25);
                add_ability("Lucky: When you roll a 1 on The D20 for an Attack roll, ability check, or saving throw, you can Reroll the die and must use the new roll.");
                add_ability("Brave: You have advantage on Saving Throws against being Frightened.");
                add_ability("Halfling Nimbleness: You can move through the space of any creature that is of a size larger than yours.");
                add_ability("Naturally Stealthy: You can attempt to hide even when you are obscured only by a creature that is at least one size larger than you.");
                //languages = common, halfling
                return;
            }
            if (race == "Stout Halfling") {
                set_dexterity(dexterity+2);
                set_constitution(constitution+1);
                set_speed(25);
                add_ability("Lucky: When you roll a 1 on The D20 for an Attack roll, ability check, or saving throw, you can Reroll the die and must use the new roll.");
                add_ability("Brave: You have advantage on Saving Throws against being Frightened.");
                add_ability("Halfling Nimbleness: You can move through the space of any creature that is of a size larger than yours.");
                add_ability("Stout Resilience: You have advantage on saving throws against poison, and you have resistance against poison damage.");
                //languages = common, halfling
                return;
            }
            if (race == "Human") {
                set_strength(strength+1);
                set_dexterity(dexterity+1);
                set_constitution(constitution+1);
                set_intelligence(intelligence+1);
                set_wisdom(wisdom+1);
                set_charisma(charisma+1);
                set_speed(30);
                //langauges = common, 1 lang of choice
                return;
            }
            if (race == "Variant Human") {
                // TODO: FREE FEAT
                int choice1;
                int choice2;
                cout << "\n(Variant Human) Select First Ability to increase:" << endl;
                cout << "1: Strength"     << endl;
                cout << "2: Dexterity"    << endl;
                cout << "3: Constitution" << endl;
                cout << "4: Intelligence" << endl;
                cout << "5: Wisdom"       << endl;
                cout << "6: Charisma"     << endl;
                cin >> choice1;
                switch(choice1) {
                    case 1: set_strength(strength+1);         break;
                    case 2: set_dexterity(dexterity+1);       break;
                    case 3: set_constitution(constitution+1); break;
                    case 4: set_intelligence(intelligence+1); break;
                    case 5: set_wisdom(wisdom+1);             break;
                    case 6: set_charisma(charisma+1);         break;
                    default: cout << "Invalid choice" << endl; break;
                }
                cout << "(Variant Human) Select Second Ability to increase:" << endl;
                cout << "1: Strength"     << endl;
                cout << "2: Dexterity"    << endl;
                cout << "3: Constitution" << endl;
                cout << "4: Intelligence" << endl;
                cout << "5: Wisdom"       << endl;
                cout << "6: Charisma"     << endl;
                choice2 = choice1;
                while (choice1 == choice2) {
                    cout << "(You cannot choose the same ability twice)" << endl;
                    cin >> choice2;
                }
                switch(choice2) {
                    case 1: set_strength(strength+1);         break;
                    case 2: set_dexterity(dexterity+1);       break;
                    case 3: set_constitution(constitution+1); break;
                    case 4: set_intelligence(intelligence+1); break;
                    case 5: set_wisdom(wisdom+1);             break;
                    case 6: set_charisma(charisma+1);         break;
                    default: cout << "Invalid choice" << endl; break;
                }
                return;
            }
            if (race == "Dragonborn") {
                int choice;
                string breath;
                set_strength(strength+2);
                set_charisma(charisma+1);
                set_speed(30);
                cout << "\n(Dragonborn) Select Ancestry:" << endl;
                cout << "1:  Black  (Acid)      - 5 by 30ft line (DEX Save)" << endl;
                cout << "2:  Blue   (Lightning) - 5 by 30ft line (DEX Save)" << endl;
                cout << "3:  Brass  (Fire)      - 5 by 30ft line (DEX Save)" << endl;
                cout << "4:  Bronze (Lightning) - 5 by 30ft line (DEX Save)" << endl;
                cout << "5:  Copper (Acid)      - 5 by 30ft line (DEX Save)" << endl;
                cout << "6:  Gold   (Fire)      - 15 ft. cone (DEX Save)"    << endl;
                cout << "7:  Green  (Poison)    - 15 ft. cone (CON Save)"    << endl;
                cout << "8:  Red    (Fire)      - 15 ft. cone (DEX Save)"    << endl;
                cout << "9:  Silver (Cold)      - 15 ft. cone (CON Save)"    << endl;
                cout << "10: White  (Cold)      - 15 ft. cone (CON Save)"    << endl;
                cin >> choice;
                switch(choice) {
                    case 1:  breath = "Breath Weapon: Black (Acid) - 5 by 30ft line (DEX Save)";       break;
                    case 2:  breath = "Breath Weapon: Blue (Lightning) - 5 by 30ft line (DEX Save)";   break;
                    case 3:  breath = "Breath Weapon: Brass (Fire) - 5 by 30ft line (DEX Save)";       break;
                    case 4:  breath = "Breath Weapon: Bronze (Lightning) - 5 by 30ft line (DEX Save)"; break;
                    case 5:  breath = "Breath Weapon: Copper (Acid) - 5 by 30ft line (DEX Save)";      break;
                    case 6:  breath = "Breath Weapon: Gold (Fire) - 15 ft. cone (DEX Save)";           break;
                    case 7:  breath = "Breath Weapon: Green (Poison) - 15 ft. cone (CON Save)";        break;
                    case 8:  breath = "Breath Weapon: Red (Fire) - 15 ft. cone (DEX Save)";            break;
                    case 9:  breath = "Breath Weapon: Silver (Cold) - 15 ft. cone (CON Save)";         break;
                    case 10: breath = "Breath Weapon: White (Cold) - 15 ft. cone (CON Save)";         break;
                    default: cout << "Invalid choice" << endl; break;
                }
                add_ability(breath+" - When you use your Breath Weapon, each creature in the area of the exhalation must make a saving throw. The DC for this saving throw equals 8 + your Constitution modifier + your Proficiency bonus. A creature takes 2d6 damage on a failed save, and half as much damage on a successful one. The damage increases to 3d6 at 6th Level, 4d6 at 11th level, and 5d6 at 16th level.");
                //languages = common + draconic
                return;
            }
            if (race == "Forest Gnome") {
                set_intelligence(intelligence+2);
                set_dexterity(dexterity+1);
                set_speed(25);
                set_darkvision(60);
                add_ability("Gnome Cunning: You have advantage on all Intelligence, Wisdom, and Charisma Saving Throws against magic.");
                add_ability("Speak with Small Beasts: Through sound and gestures, you may communicate simple ideas with Small or smaller beasts.");
                //know minor illusion cantrip, INT cast modifier
                //languages = common + gnomish
                return;
            }
            if (race == "Rock Gnome") {
                set_intelligence(intelligence+2);
                set_constitution(constitution+2);
                set_speed(25);
                set_darkvision(60);
                add_ability("Gnome Cunning: You have advantage on all Intelligence, Wisdom, and Charisma Saving Throws against magic.");
                add_ability("Artificer's Lore: Whenever you make an Intelligence (History) check related to magic items, alchemical Objects, or technological devices, you can add twice your Proficiency bonus, instead of any Proficiency bonus you normally apply.");
                add_ability("Tinker: You have Proficiency with artisan’s tools (tinker’s tools). Using those tools, you can spend 1 hour and 10 gp worth of materials to Construct a Tiny clockwork device (AC 5, 1 hp). The device ceases to function after 24 hours (unless you spend 1 hour repairing it to keep the device functioning), or when you use your Action to dismantle it; at that time, you can reclaim the materials used to create it. You can have up to three such devices active at a time. When you create a device, choose one of the following options: ; 1) Clockwork Toy: This toy is a clockwork animal, monster, or person, such as a frog, mouse, bird, Dragon, or Soldier. When placed on the ground, the toy moves 5 feet across the ground on each of your turns in a random direction. It makes Noises as appropriate to the creature it represents. ; 2) Fire Starter: The device produces a miniature flame, which you can use to light a Candle, torch, or campfire. Using the device requires your Action. ; 3) Music Box: When opened, this music box plays a single song at a moderate volume. The box stops playing when it reaches the song’s end or when it is closed.");
                //languages = common + gnomish
                return;
            }
            if (race == "Half-Elf") {
                set_charisma(charisma+2);
                int choice1;
                int choice2;
                cout << "\n(Half-Elf) Select First Ability to increase:" << endl;
                cout << "1: Strength"     << endl;
                cout << "2: Dexterity"    << endl;
                cout << "3: Constitution" << endl;
                cout << "4: Intelligence" << endl;
                cout << "5: Wisdom"       << endl;
                cin >> choice1;
                switch(choice1) {
                    case 1: set_strength(strength+1);         break;
                    case 2: set_dexterity(dexterity+1);       break;
                    case 3: set_constitution(constitution+1); break;
                    case 4: set_intelligence(intelligence+1); break;
                    case 5: set_wisdom(wisdom+1);             break;
                    default: cout << "Invalid choice" << endl; break;
                }
                cout << "(Half-Elf) Select Second Ability to increase:" << endl;
                cout << "1: Strength"     << endl;
                cout << "2: Dexterity"    << endl;
                cout << "3: Constitution" << endl;
                cout << "4: Intelligence" << endl;
                cout << "5: Wisdom"       << endl;
                choice2 = choice1;
                while (choice1 == choice2) {
                    cout << "(You cannot choose the same ability twice)" << endl;
                    cin >> choice2;
                }
                switch(choice2) {
                    case 1: set_strength(strength+1);         break;
                    case 2: set_dexterity(dexterity+1);       break;
                    case 3: set_constitution(constitution+1); break;
                    case 4: set_intelligence(intelligence+1); break;
                    case 5: set_wisdom(wisdom+1);             break;
                    default: cout << "Invalid choice" << endl; break;
                }
                set_speed(30);
                set_darkvision(60);
                add_ability("Fey Ancestry: You have advantage on Saving Throws against being Charmed, and magic can’t put you to sleep.");
                //prof in 2 skills of choice
                //languages = common, elvish, 1 extra language
                return;
            }
            if (race == "Half-Orc") {
                set_strength(strength+2);
                set_constitution(constitution+1);
                set_speed(30);
                set_darkvision(60);
                add_ability("Relentless Endurance: When you are reduced to 0 Hit Points but not killed outright, you can drop to 1 hit point instead. You can’t use this feature again until you finish a Long Rest.");
                add_ability("Savage Attacks: When you score a critical hit with a melee weapon Attack, you can roll one of the weapon’s damage dice one additional time and add it to the extra damage of the critical hit.");
                //prof w/ Intimidation
                add_proficiency("Intimidation (Skill)");
                //languages = common + orc
                return;
            }
            if (race == "Tiefling") {
                set_charisma(charisma+2);
                set_intelligence(intelligence+1);
                set_speed(30);
                set_darkvision(60);
                add_ability("Hellish Resistance: You have resistance to Fire damage.");
                //know `Thaumaturgy` cantrip w/ CHA as cast modifier
                //@lv3 know `Hellish Rebuke` 1x/day as 2nd level w/ CHA as cast modifier
                //@lv5 know `Darkness` 1x/day w/ CHA as cast modifier
                //languages = common + infernal
                return;
            }
        }

        void roll_abilities() {
            int roll;
            cout << "\nRoll for each of your abilities and assign the values." << endl;
            cout << "Strength:" << endl;
            cin >> roll;
            set_strength(roll);

            cout << "Dexterity:" << endl;
            cin >> roll;
            set_dexterity(roll);

            cout << "Constitution:" << endl;
            cin >> roll;
            set_constitution(roll);

            cout << "Intelligence:" << endl;
            cin >> roll;
            set_intelligence(roll);

            cout << "Wisdom:" << endl;
            cin >> roll;
            set_wisdom(roll);

            cout << "Charisma:" << endl;
            cin >> roll;
            set_charisma(roll);
        }
        
        void print() {
            cout << "\nName: "       << name         << endl;
            cout << "Class: "        << class_       << endl;
            cout << "Race: "         << race         << endl;
            cout << "Hit Points: "   << hit_points   << endl;
            cout << "Speed: "        << speed        << endl;
            cout << "Darkvision: "   << darkvision   << endl;
            cout << "Strength: "     << strength     << endl;
            cout << "Dexterity: "    << dexterity    << endl;
            cout << "Constitution: " << constitution << endl;
            cout << "Intelligence: " << intelligence << endl;
            cout << "Wisdom: "       << wisdom       << endl;
            cout << "Charisma: "     << charisma     << endl;
            cout << "Abilities: "                    << endl;
            for (size_t i=1; i < abilities.size(); i++) {
                cout << "  - "+abilities[i] << endl;
            }
            cout << "Proficiencies: "                    << endl;
            for (size_t i=1; i < proficiencies.size(); i++) {
                cout << "  - "+proficiencies[i] << endl;
            }
        }
};

int main() {
    Character my_char("","","",0,0,0,0,0,0,0,{""},0,0,{""});

    string name;
    cout << "What is the name of your character?" << endl;
    getline(cin, name);
    my_char.set_name(name);
    my_char.set_class();
    my_char.set_race();
    my_char.roll_abilities();
    my_char.apply_race_modifiers();
    my_char.set_initial_health();
    my_char.print();
    return 0;
}
