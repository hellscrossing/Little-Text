// Created by Sarah Nadzan for CSIS 2605's Final Project.
// Dotted lines are to keep the code separated and easy to read.

// ---------------------------------------------------------------------------------------------------------------------

// M O N S T E R S

// T A B L E  O F  C O N T E N T S

// Monster Generation.
// Monster Combat.

// ---------------------------------------------------------------------------------------------------------------------

#ifndef confrontation
#define confrontation

// ---------------------------------------------------------------------------------------------------------------------

#include "generation.h"
#include "collection.h"
#include "interactions.h"
#include "exploration.h"

// ---------------------------------------------------------------------------------------------------------------------

// Combat Structures.

// ---------------------------------------------------------------------------------------------------------------------

// Declaring combat variables for later.

bool playerCombat = false;
bool playerTaming = false;

// Struct.

struct combat {

public:
    std::string displayName;
    std::string combatType;
    std::string physical, inflicting;
    int healthMax;
    int healthBar;
    int attack;
    int defense;
    int totemLevel;
    int trustBar;
    int trustMax;
    bool encounter;
    std::string desc;
    std::string ability;
    bool defeat;
};

// Combat members.

// Player

combat player = (combat) {.displayName = "Apprentice", .combatType = "Mage",
    .physical = "", .inflicting = "", .healthMax = 20, .healthBar = 20, .attack = 3, .defense = 2, .totemLevel = 0,
    .trustBar = 0, .trustMax = 0, .encounter = false, .desc =
            "Small apprentice training to be a mage. Very quiet and kind.\n", .ability = "Tame", .defeat = false};

// Monsters

combat tinyShadow = (combat) {.displayName = "Tiny Shadow", .combatType= "Monster", .physical = "Bump", .inflicting = "Rattle", .healthMax = 10,
    .healthBar = 10, .attack = 3, .defense = 2, .totemLevel = 0, .trustBar = 0, .trustMax = 0, .encounter = false, .desc =
            "A tiny, mischievous shadow that appeared from nowhere. Likes to play pranks on passerby.\n", .ability = "Jitters", .defeat = false};

combat smallShadow = (combat) {.displayName = "Small Shadow", .combatType= "Monster", .physical = "Snare", .inflicting = "Curse", .healthMax = 13,
    .healthBar = 13, .attack = 1, .defense = 3, .totemLevel = 0, .trustBar = 0, .trustMax = 0, .encounter = false, .desc =
            "A small shadow that seems to be distressed. Lashes out at anyone who goes near it. Very crafty.\n", .ability = "Trickle", .defeat = false};

//Creatures

combat squirrel = (combat) {.displayName = "Squirrel", .combatType= "Creature", .physical = "Slice", .inflicting = "Restore", .healthMax = 5,
        .healthBar = 5, .attack = 3, .defense = 1, .totemLevel = 0, .trustBar = 0, .trustMax = 10, .encounter = false, .desc =
                "Small, woodland squirrel. Quite good at scouting the forest floor.\n", .ability = "Gather", .defeat = false};

combat rabbit = (combat) {.displayName = "Rabbit", .combatType= "Creature", .physical = "Kick", .inflicting = "Restore", .healthMax = 10,
        .healthBar = 10, .attack = 1, .defense = 2, .totemLevel = 0, .trustBar = 0, .trustMax = 10, .encounter = false, .desc =
                "Small, fluffy rabbit from a forest warren. Hugging it makes you feel warm.\n", .ability = "Hutch", .defeat = false
        };

combat deer = (combat) {.displayName = "Deer", .combatType= "Creature", .physical = "Stomp", .inflicting = "Restore", .healthMax = 15,
        .healthBar = 15, .attack = 2, .defense = 4, .totemLevel = 0, .trustBar = 0, .trustMax = 15, .encounter = false, .desc =
                "A slender, graceful deer from the forest. It’s ears are twitching as though it can hear something you can’t.\n",
        .ability = "Listen", .defeat = false};

combat fox = (combat) {.displayName = "Fox", .combatType= "Creature", .physical = "Trip", .inflicting = "Scratchmarks", .healthMax = 13,
        .healthBar = 13, .attack = 3, .defense = 2, .totemLevel = 0, .trustBar = 0, .trustMax = 15, .encounter = false, .desc =
                "A sleek, intelligent fox from the forest. It’s eyes seem to smile at you.\n", .ability = "Trot", .defeat = false};

combat wolf = (combat) {.displayName = "Wolf", .combatType= "Creature", .physical = "Crunch", .inflicting = "Scratchmarks", .healthMax = 15,
        .healthBar = 15, .attack = 4, .defense = 2, .totemLevel = 0, .trustBar = 0, .trustMax = 20, .encounter = false, .desc =
                "A thick-furred wolf from the forest. It’s eye glimmer with a fierce protection.\n", .ability = "Growl", .defeat = false};

combat bear = (combat) {.displayName = "Bear", .combatType= "Creature", .physical = "Swipe", .inflicting = "Scratchmarks", .healthMax = 20,
        .healthBar = 20, .attack = 4, .defense = 3, .totemLevel = 0, .trustBar = 0, .trustMax = 25, .encounter = false, .desc =
"A solid, large bear from the forest. It seems to be looking into the beyond.\n", .ability = "Block", .defeat = false};

// ---------------------------------------------------------------------------------------------------------------------

// Player Combat Setup.

// ---------------------------------------------------------------------------------------------------------------------

void playerMoveSetup () // Sets up Move Names.
{
    //Decides move names.

    if (playerAnimal == "Squirrel")
    {
        player.physical = "Slice";
        player.inflicting = "Restore";
    } // End of Squirrel.

    if (playerAnimal == "Rabbit")
    {
        player.physical = "Kick";
        player.inflicting = "Restore";
    } // End of Rabbit.

    if (playerAnimal == "Deer")
    {
        player.physical = "Stomp";
        player.inflicting = "Restore";
    } // End of Deer.

    if (playerAnimal == "Fox")
    {
        player.physical = "Trip";
        player.inflicting = "Scratchmarks";
    } // End of Fox.

    if (playerAnimal == "Wolf")
    {
        player.physical = "Crunch";
        player.inflicting = "Scratchmarks";
    } // End of Wolf.

    if (playerAnimal == "Bear")
    {
        player.physical = "Swipe";
        player.inflicting = "Scratchmarks";
    } // End of Bear.
} // End of playerMoveSetup()

// ---------------------------------------------------------------------------------------------------------------------

// Player Combat Function

// ---------------------------------------------------------------------------------------------------------------------

int playerDamage, playerDefend;

void getPlayerMove() {

    // Declaring variables.

    srand(time(NULL)); // Random chance generation.
    int mainChance = (rand() % 10); // Random chance generation.
    int playerMove; // Input for the player's choice.

    // Ask what they want to use.

    std::cout << "What move would you like to use?" << std::endl;
    std::cout << "1 - " << player.physical << "\n2 - " << player.inflicting << "\n3 - Defend\n" << std::endl; // Menu
    std::cin >> playerMove;

    switch(playerMove) // Battle menu for Player.
    {
        case 1:
        {
            std::cout << playerName << " used " << player.physical << "!\n";
            playerDamage = (player.attack + 3);
            playerDefend = player.defense;

            playerMove = 0;
            break;
        } // End case 1.
        case 2:
        {
            // Carnivorous Players.

            if (player.inflicting == "Scratchmarks") {
                playerDamage = player.attack + 6;
                playerDefend = player.defense;
                std::cout << playerName << " used Scratchmarks!" << std::endl;
                break;
            } // End of Carnivorous Inflicting.

            // Herbivorous Players.

            if (player.inflicting == "Restore") {
                playerDamage = 0;
                playerDefend = player.defense;
                player.healthBar = player.healthBar + 3;
                std::cout << playerName << " used Restore!" << std::endl;
                std::cout << playerName << " restored 3 health, and has " << player.healthBar << " total.\n";
                std::cout << " \n";
                break;
            } // End of Herbivorous Inflicting.

            playerMove = 0;
            break;
        } // End case 2.
        case 3:
        {
            if (mainChance > 5) {
                playerDefend = player.healthBar;
                std::cout << playerName << " blocked!\n" << std::endl;
            } // End of blocked move.

            if (mainChance <= 5)
            {
                playerDefend = player.defense;
                std::cout << playerName << "'s block failed!\n" << std::endl;
            } // End of failed block.
            playerMove = 0;
            break;
        } // End case 3.
        default:
        {
            std::cout << "Please enter a valid number!\n";
            playerMove = 0;
            break;
        }
    } // End of playerMove switchcase.

} // End of getPlayerMove.

// ---------------------------------------------------------------------------------------------------------------------

// Setting up the monster combat.

// ---------------------------------------------------------------------------------------------------------------------

// Declaring variables.

int monsterDamage, monsterDefend; // Monster Output
int monsterHealthBar, monsterHealthMax, monsterAttack, monsterDefense; // Monster Stats
std::string monsterPhysical, monsterInflicting; // Monster Moves

// Get the Stats.

void getMonsterStats()
{

    // Get stats.

    if (monsterFound == tinyShadow.displayName)
        {
            monsterHealthBar = tinyShadow.healthBar;
            monsterHealthMax = tinyShadow.healthMax;
            monsterPhysical = tinyShadow.physical;
            monsterInflicting = tinyShadow.inflicting;
            monsterAttack = tinyShadow.attack;
            monsterDefense = tinyShadow.defense;
        } // End tiny Shadow.

    if (monsterFound == smallShadow.displayName)
        {
            monsterHealthBar = smallShadow.healthBar;
            monsterHealthMax = smallShadow.healthMax;
            monsterPhysical = smallShadow.physical;
            monsterInflicting = smallShadow.inflicting;
            monsterAttack = smallShadow.attack;
            monsterDefense = smallShadow.defense;
        } // End small Shadow.

} // end getMonsterStats

// ---------------------------------------------------------------------------------------------------------------------

// Monster's Turn.

void getMonsterMove ()
{
    srand(time(NULL)); // Random chance generation.
    int mainChance = (rand() % 10); // Random chance generation.

    // Inflict player damage.

    if (playerDamage <= 0) // No damage done.
    {
        std::cout << playerName << " dealt " << 0 << " damage!\n";
        std::cout << " \n";
        playerDamage = 0; // reset player damage.
        playerDefend = player.defense; // reset vblovk.
    } else{ // Damage done.
        monsterHealthBar = monsterHealthBar - (playerDamage - monsterDefend);
        std::cout << playerName << " dealt " << (playerDamage - monsterDefend) << " damage!\n";
        std::cout << " \n";
        playerDamage = 0; // Reset player damage.
        playerDefend = player.defense; // Reset block.
    } // End damage if/else.

    // If health is low, try to defend.

    if ((monsterHealthBar * 4) < monsterHealthMax)
    {
        if (mainChance > 5)
        {
            monsterDefend = monsterHealthBar; // Defense is equal to the health to keep damage from hitting.

            std::cout << monsterFound << " blocked! \n" << std::endl;

        } // End of block succeeded.

        else
        {
            monsterDefend = monsterDefense; // Regular defense.

            std::cout << monsterFound << "'s block failed! \n" << std::endl;

        } // End of block failed.
    } // End of low monster health pattern.

    // Physical move.

    else
        {
        if (mainChance >= 6) {
            std::cout << monsterFound << " has used " << monsterPhysical << "! \n";
            if (monsterAttack - playerDefend <= 0) // No damage dealt.
            {
                std::cout << monsterFound << " dealt " << " 0 " << " damage!\n";
            } else { // Damage dealt.
                std::cout << monsterFound << " dealt " << ((monsterAttack + 3) - playerDefend) << " damage!\n";

                player.healthBar = player.healthBar - ((monsterAttack + 3) - playerDefend);
            } // End attack ifelse.

        } // End of Physical Monster.

            // Inflicting move.

        else {
            std::cout << monsterFound << " has used " << monsterInflicting << "! \n";
            std::cout << monsterFound << " dealt " << ((monsterAttack + 6) - playerDefend) << " damage!\n";

            player.healthBar = player.healthBar - ((monsterAttack + 6) - playerDefend);

        } // End of Inflicting Monster.
    } // End normal pattern.

    std::cout << "\n";
    std::cout << playerName << " total health: " << player.healthBar << " \n";
    std::cout << monsterFound << " total health: " << monsterHealthBar << " \n";
    std::cout << "\n";

}; // End of getMonsterMove().

// ---------------------------------------------------------------------------------------------------------------------

// Setting up the creature's combat.

// ---------------------------------------------------------------------------------------------------------------------

// Declaring variables.

int creatureDamage, creatureDefend; // Creature Output
int creatureHealthBar, creatureHealthMax, creatureAttack, creatureDefense, creatureTrustBar, creatureTrustMax; // Creature Stats
std::string creaturePhysical, creatureInflicting, creatureDesc, creatureAbility; // Creature Moves and Flavors for taming

// Get the Stats.

void getCreatureStats()
{
    // Get stats.

    if (creatureFound == squirrel.displayName)
    {
        creatureHealthBar = squirrel.healthMax;
        creatureHealthMax = squirrel.healthMax;
        creaturePhysical = squirrel.physical;
        creatureInflicting = squirrel.inflicting;
        creatureAttack = squirrel.attack;
        creatureDefense = squirrel.defense;
        creatureTrustBar = squirrel.trustBar;
        creatureTrustMax = squirrel.trustMax;
        creatureDesc = squirrel.desc;
        creatureAbility = squirrel.ability;
    } // End squirrel.

    if (creatureFound == rabbit.displayName)
    {
        creatureHealthBar = rabbit.healthMax;
        creatureHealthMax = rabbit.healthMax;
        creaturePhysical = rabbit.physical;
        creatureInflicting = rabbit.inflicting;
        creatureAttack = rabbit.attack;
        creatureDefense = rabbit.defense;
        creatureTrustBar = rabbit.trustBar;
        creatureTrustMax = rabbit.trustMax;
        creatureDesc = rabbit.desc;
        creatureAbility = rabbit.ability;
    } // End rabbit.

    if (creatureFound == deer.displayName)
    {
        creatureHealthBar = deer.healthMax;
        creatureHealthMax = deer.healthMax;
        creaturePhysical = deer.physical;
        creatureInflicting = deer.inflicting;
        creatureAttack = deer.attack;
        creatureDefense = deer.defense;
        creatureTrustBar = deer.trustBar;
        creatureTrustMax = deer.trustMax;
        creatureDesc = deer.desc;
        creatureAbility = deer.ability;
    } // End deer.

    if (creatureFound == fox.displayName)
    {
        creatureHealthBar = fox.healthMax;
        creatureHealthMax = fox.healthMax;
        creaturePhysical = fox.physical;
        creatureInflicting = fox.inflicting;
        creatureAttack = fox.attack;
        creatureDefense = fox.defense;
        creatureTrustBar = fox.trustBar;
        creatureTrustMax = fox.trustMax;
        creatureDesc = fox.desc;
        creatureAbility = fox.ability;
    } // End fox.

    if (creatureFound == wolf.displayName)
    {
        creatureHealthBar = wolf.healthMax;
        creatureHealthMax = wolf.healthMax;
        creaturePhysical = wolf.physical;
        creatureInflicting = wolf.inflicting;
        creatureAttack = wolf.attack;
        creatureDefense = wolf.defense;
        creatureTrustBar = wolf.trustBar;
        creatureTrustMax = wolf.trustMax;
        creatureDesc = wolf.desc;
        creatureAbility = wolf.ability;
    } // End wolf.

    if (creatureFound == bear.displayName)
    {
        creatureHealthBar = bear.healthMax;
        creatureHealthMax = bear.healthMax;
        creaturePhysical = bear.physical;
        creatureInflicting = bear.inflicting;
        creatureAttack = bear.attack;
        creatureDefense = bear.defense;
        creatureTrustBar = bear.trustBar;
        creatureTrustMax = bear.trustMax;
        creatureDesc = bear.desc;
        creatureAbility = bear.ability;
    } // End bear.

} // end getCreatureStats

// ---------------------------------------------------------------------------------------------------------------------

// Creature's Turn.

void getCreatureMove ()
{
    srand(time(NULL)); // Random chance generation.
    int mainChance = (rand() % 10); // Random chance generation.

    // Inflict player damage.

    if (playerDamage <= 0) // No damage done.
    {
        std::cout << playerName << " dealt " << 0 << " damage!\n";
        std::cout << " \n";
        playerDamage = 0; // reset player damage.
        playerDefend = player.defense; // reset block.
    } else{ // Damage done.
        creatureHealthBar = creatureHealthBar - (playerDamage - creatureDefense);
        std::cout << playerName << " dealt " << (playerDamage - creatureDefense) << " damage!\n";
        std::cout << " \n";
        playerDamage = 0; // reset player damage.
        playerDefend = player.defense; // reset block.
    } // End damage if/else.

    // If health is low, try to defend.

    if ((creatureHealthBar * 4) < creatureHealthMax)
    {
        if ((mainChance > 5) && (mainChance != 5))
        {
            creatureDefend = creatureHealthBar; // Defense is equal to the health to keep damage from hitting.

            std::cout << creatureFound << " blocked!\n" << std::endl;

        } // End of block succeeded.

        else
        {
            creatureDefend = creatureDefense; // Regular defense.

            std::cout << creatureFound << "'s block failed!\n" << std::endl;

        } // End of block failed.
    } // End of low creature health.

    // Physical move.

    else
        {
        if (mainChance >= 3) {
            std::cout << creatureFound << " has used " << creaturePhysical << "! \n";
            if (creatureAttack - playerDefend <= 0) // No damage dealt.
            {
                std::cout << creatureFound << " dealt " << " 0 " << " damage!\n";
            } else { // Damage dealt.
                std::cout << creatureFound << " dealt " << ((creatureAttack + 3) - playerDefend) << " damage!\n";

                player.healthBar = player.healthBar - ((creatureAttack + 3) - playerDefend);
            } // End attack ifelse.

        } // End of Physical Creature.

            // Inflicting move.

        else {
            std::cout << creatureFound << " has used " << creatureInflicting << "! \n";

            // Inflicting Effect.

            if (creatureInflicting == "Restore") // Herbivorous Creature
            {
                creatureHealthBar = creatureHealthBar + 3;
                std::cout << creatureFound << " healed 3 damage!\n";
            } // End Restore
            if (creatureInflicting == "Scratchmarks") // Carnivorous Creature
            {
                std::cout << creatureFound << " has used " << creatureInflicting << "! \n";
                if ((creatureAttack + 3) - playerDefend <= 0) // No damage dealt.
                {
                    std::cout << creatureFound << " dealt " << " 0 " << " damage!\n";
                } else { // Damage dealt.
                    std::cout << creatureFound << " dealt " << ((creatureAttack + 6) - playerDefend) << " damage!\n";

                    player.healthBar = player.healthBar - ((creatureAttack + 6) - playerDefend);
                } // End attack ifelse.
            } // End Scratchmarks

        } // End of Inflicting Creature.
    } // End of normal creature pattern.

    std::cout << "\n";
    std::cout << playerName << " total health: " << player.healthBar << " \n";
    std::cout << creatureFound << " total health: " << creatureHealthBar << " \n";
    std::cout << "\n";

}; // End of getCreatureMove().

// ---------------------------------------------------------------------------------------------------------------------

#endif //confrontation

// ---------------------------------------------------------------------------------------------------------------------