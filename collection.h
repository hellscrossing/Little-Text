// Created by Sarah Nadzan for CSIS 2605's Final Project.
// Dotted lines are to keep the code separated and easy to read.

// ---------------------------------------------------------------------------------------------------------------------

// L O O T

// T A B L E  O F  C O N T E N T S

// Item Structures and Definitions.

// Loot Generation.

// Bag Array.

// Loot Pickup.

// Beg Check.

// ---------------------------------------------------------------------------------------------------------------------

#ifndef collection
#define collection

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

#include "generation.h"
#include "confrontation.h"
#include "interactions.h"


// ---------------------------------------------------------------------------------------------------------------------

// Item Structures and Definitions.

// ---------------------------------------------------------------------------------------------------------------------

// Herbs.

    struct herbs {
    public:
        std::string itemName;
        std::string itemDesc;
        std::string itemType = "Herb";
    };

    herbs goldenSeal = (herbs) {.itemName = "Goldenseal Cutting", .itemDesc = "The little white flowers are cute. Heals some "
                                                                              "HP.\n"};

    herbs bloodRoot = (herbs) {.itemName = "Bloodroot Cutting", .itemDesc = "The yellow center of the flower reminds you of "
                                                                            "the sun. Fully restores HP.\n"};

// Seeds.

    struct seeds {
    public:
        std::string itemName;
        std::string itemDesc;
        std::string itemType = "Seed";
    };

    seeds poppySeed = (seeds) {.itemName = "Poppy Seed", .itemDesc = "Makes your enemy sluggish for a short while.\n"};

// Berries.

    struct berries {
    public:
        std::string itemName;
        std::string itemDesc;
        std::string itemType = "Berry";
    };

    berries blackBerry = (berries) {.itemName = "Blackberry Handful", .itemDesc = "A handful of blackberries from the"
                                                                                  " forest. Give these to animals to help tame them.\n"};

    berries raspBerry = (berries) {.itemName = "Raspberry Handful", .itemDesc = "A handful of raspberries from the forest. Give these to "
                                                                                "animals to help tame them.\n"};

// ---------------------------------------------------------------------------------------------------------------------

// Setting up loot generation.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

std::string lootFound = "None";
std::string lootType = "None";
std::string lootDesc = "None";

// Loop.

void generateLoot()
{

    srand(time(NULL)); // Random chance generation.

    int mainChance = (rand() % 10); // Random chance generation.
    int subChance = (rand() % 10); // Random chance generation.

    if (mainChance <= 5)
// 50% Chance of a berry.
    {
        if (subChance <= 6)
// 60% chance of Blackberry.
        {
            lootFound = blackBerry.itemName;
            lootType = blackBerry.itemType;
            lootDesc = blackBerry.itemDesc;
        } // End of Blackberry.
        if (subChance > 6)
// 40% chance of Raspberry.
        {
            lootFound = raspBerry.itemName;
            lootType = raspBerry.itemType;
            lootDesc = raspBerry.itemDesc;
        } // End of Raspberry.

    } // End of berries.

    if (mainChance >= 6)
    {
    if ((6 >= mainChance) && (mainChance > 5))
// 10% chance of a seed.
        {
            lootFound = poppySeed.itemName;
            lootType = poppySeed.itemType;
            lootDesc = poppySeed.itemDesc;
        } // End of Poppyseed / Seeds.

// 50% chance of an herb.

        if ((subChance <= 7))
// 70% chance of Goldenseal.
        {
            lootFound = goldenSeal.itemName;
            lootType = goldenSeal.itemType;
            lootDesc = goldenSeal.itemDesc;
        }else
// 30% chance of Bloodroot.
        {
            lootFound = bloodRoot.itemName;
            lootType = bloodRoot.itemType;
            lootDesc = bloodRoot.itemDesc;
        } // End of bloodRoot and goldenSeal.

    } // End of herbs.

    std::cout << "You found a " << lootFound << "!\n";
    std::cout << "It's a kind of " << lootType << ".\n" << lootDesc << " \n";
}; // End of loot generation.

// ---------------------------------------------------------------------------------------------------------------------

// Setting up bag array.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

const int MAX_BAG_ROWS = 21; // Bag rows.
const int MAX_BAG_COLS = 3; // Bag columns.
std::string playerBag[MAX_BAG_ROWS][MAX_BAG_COLS]; // Bag init.

// Initialize array.

void initBag() // Bag loop.
{

for (int bagRows = 0; bagRows < MAX_BAG_ROWS; bagRows++) {
    for (int bagCols = 0; bagCols < MAX_BAG_COLS; bagCols++) {

        playerBag[MAX_BAG_ROWS][MAX_BAG_COLS] = " ";
        playerBag[0][0] = playerAnimal + " Totem";
        playerBag[0][1] = "Special";
        playerBag[0][2] = "Physical object that holds magical energy. Blessed by the " + playerAnimal + " Spirit.";
    }
}
} // End initBag().

// ---------------------------------------------------------------------------------------------------------------------

// Setting up loot pickup.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

int bagCount = 0;

void lootPickup () // Loot pickup.
{

    bagCount = bagCount + 1; // Add a space in the bag display.

    playerBag[bagCount][0] = lootFound; // Item name.
    playerBag[bagCount][1] = lootType; // Item type.
    playerBag[bagCount][2] = lootDesc; // Item description.

} // End lootPickup();

// ---------------------------------------------------------------------------------------------------------------------

// Setting up loot use.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

int lootChoice = 0;

void lootUse () // Loot use.
{
        if (playerBag[lootChoice - 1][0] == (playerAnimal + " Totem"))
            {
                std::cout << "I can’t use treat recklessly! It was given to me when I was first apprenticed. "
                             "It’s what allows me to be a mage. \n";
                std::cout << playerAnimal << " Totem was not used. \n";
            } // End player Totem.
        if (playerBag[lootChoice - 1][0] == "Blackberry Handful")
            {
                if (playerTaming = true) // Yes taming screen.
                    {
                        creatureTrustBar = creatureTrustBar + 5;
                        std::cout << creatureFound << " trusts you more!\n";
                    } else // End taming screen.
                        {
                            std::cout << "There's nothing here to tame!\n";
                        } // End non-taming screen.
            } // End Blackberry Handful.
        if (playerBag[lootChoice - 1][0] == "Raspberry Handful")
            {
                if (playerTaming = true) // Yes taming screen.
                {
                    creatureTrustBar = creatureTrustBar + 5;
                    std::cout << creatureFound << " trusts you more!\n";
                } else // End taming screen.
                {
                    std::cout << "There's nothing here to tame!\n";
                } // End non-taming screen.
            } // End Raspberry Handful.
        if (playerBag[lootChoice - 1][0] == "Goldenseal Cutting")
            {
                if (player.healthBar < player.healthMax) // Not at full health.
                    {
                        for (int count = 0; count <= 10; count++) // Can't go over the HP Max.
                            {
                                player.healthBar = player.healthBar + 1; // Adding 1 HP at a time, loop 10 times.

                                if (player.healthBar > player.healthMax) // If it goes over the max.
                                    {
                                        player.healthBar = player.healthMax; // Sets it back to the max.
                                    } // End of if statement for health control.

                            } // End of health-adding for-loop.

                        std::cout << "10 Health restored! You feel better now, with "
                        << player.healthBar << " total health.\n"; // Flavor text.

                    } // End of health-adding if-statement.
                else // Can't go over HP Max.
                    {
                        std::cout << "Your health is already full! \n";
                    } // End of else statement.
            } // End Goldenseal Cutting.
        if (playerBag[lootChoice - 1][0] == "Bloodroot Cutting")
            {
                if (player.healthBar < player.healthMax) // Not at full health.
                    {

                        player.healthBar = player.healthMax; // Add 10 HP.
                        std::cout << "Health fully restored! You feel wonderful!\n";

                    } else // Can't add more HP than max.
                        {
                            std::cout << "Your health is already full! \n";
                        } // End else statement.
            } // End Bloodroot Cutting.
        if (playerBag[lootChoice - 1][0] == "Poppy Seed")
            {
                if (playerCombat = true) // Yes combat screen.
                {
                    monsterDefense = 0;
                    std::cout << monsterFound << " can't defend!\n";
                } else // End combat screen.
                {
                    std::cout << "There's nothing here to fight!\n";
                } // End non-combat screen.
            } // End Poppy Seed.

} // End lootUse();

// ---------------------------------------------------------------------------------------------------------------------

// Setting up loot deletion.

// ---------------------------------------------------------------------------------------------------------------------

void lootDrop () // Loot drop.
{
    if (playerBag[lootChoice - 1][0] == (playerAnimal + " Totem")) // DO NOT LET THE PLAYER TOSS THEIR TOTEM!
    {
        std::cout << "I can’t treat this recklessly! It was given to me when I was first apprenticed. "
                     "It’s what allows me to be a mage. \n";
        std::cout << playerAnimal << " Totem was not dropped. \n";
    } else // Not a Totem, they can do whatever they want.
    {
        bagCount = bagCount - 1; // Remove a display space.

        // Loop 1 to shuffle everything up a space.

        for (int countRows = lootChoice - 1; countRows < bagCount; countRows++)
        {
            playerBag[countRows][1] = playerBag[countRows + 1][1];
            playerBag[countRows][2] = playerBag[countRows + 1][2];
            playerBag[countRows][3] = playerBag[countRows + 1][3];
        } // End shuffle for loop.


    } // End of Drop Statement.

    lootChoice = 0; // Reset the choice.

} // End of lootDrop().

// ---------------------------------------------------------------------------------------------------------------------

// Item submenu.

//----------------------------------------------------------------------------------------------------------------------

void itemSubMenu() {

    // Declare variables.

    int itemSubChoice;
    int subConfirmation;

    std::cout << "What would you like to do with this item?\n";
    std::cout << "1 - Use \n";
    std::cout << "2 - Drop \n";
    std::cout << "3 - Exit \n";
    std::cin.ignore(),'\n';
    std::cin >> itemSubChoice;

    switch(itemSubChoice){

        case 1: // Use the item.
        {
            for(;;)
            {
                std::cout << "Are you sure you want to use the " << playerBag[lootChoice - 1][0] << "?\n";
                std::cout << "1 - Yes\n";
                std::cout << "2 - No\n";
                std::cin >> subConfirmation;

                if (subConfirmation == 1)
                {
                    lootUse();
                    lootDrop();
                    lootChoice = 0;
                    break;
                }
                if (subConfirmation == 2)
                {
                    lootChoice = 0;
                    break;
                }
                else{
                    std::cout << "Please enter a valid choice!\n";
                    std::cin.clear();
                    std::cin.ignore(),'\n';
                    std::cin >> subConfirmation;
                }
                break;
            } // End validation loop.
            break;
        }
        case 2: // Drop the item.
        {
            for(;;)
            {
                std::cout << "Are you sure you want to drop the " << playerBag[lootChoice - 1][0] << "?\n";
                std::cout << "1 - Yes\n";
                std::cout << "2 - No\n";
                std::cin.ignore(),'\n';
                std::cin >> subConfirmation;

                if (subConfirmation == 1) {
                    lootDrop();
                    lootChoice = 0;
                    break;
                }
                if (subConfirmation == 2)
                {
                    lootChoice = 0;
                    break;
                }else
                    {
                    std::cout << "Please enter a valid choice!\n";
                    std::cin.clear();
                    std::cin.ignore(),'\n';
                    std::cin >> subConfirmation;
                    } // End invalid option.
                break;
            } // End validation loop.
        }
        case 3:
        {
            lootChoice = 0;
            subConfirmation = 0;
            break;
        }
    }
} // End of itemSubMenu().

// ---------------------------------------------------------------------------------------------------------------------

// Checking Bag.

// ---------------------------------------------------------------------------------------------------------------------

void checkBag() {

    // Declare variables.

    int bagChoice;

    // Show items.

    std::cout << "-----------------------------------------------------------------------------------------------------------\n";

    for (int bagRows = 0; bagRows < bagCount + 1; bagRows++) { // Only present rows with items on them.
            std::cout << "| #" << bagRows + 1 << " | " << playerBag[bagRows][0] << " | " << playerBag[bagRows][1] << " | " << playerBag[bagRows][2] << " |\n";
            std::cout << "-----------------------------------------------------------------------------------------------------------\n";
        } // End of bag presentation.

        // User chooses to use items.
    std::cout << "Would you like to inspect an item?\n";
    std::cout << "1 - Yes\n";
    std::cout << "2 - Exit\n";
    std::cin.ignore(),'\n';
    std::cin >> bagChoice;

    switch(bagChoice){

         case 1: { // Pick an item.
             for(;;)
             {
                 std::cout << "Which item do you want to inspect?\n";
                 std::cout << "Enter the item number:\n";
                 std::cin >> lootChoice; // User chooses.
                 if (lootChoice <= (bagCount + 1))
                 {
                     itemSubMenu();
                     break;
                 } else{
                     std::cout << "There isn't an item with that number! \n";
                     std::cin.clear();
                     std::cin.ignore(),'\n';
                     std::cin >> lootChoice;
                 }
             } // End validation loop.
            break;
                } // End item use. case 1

        case 2:{ // Exit bag.
                    lootChoice = 0;
                    break;
                } // End menu exit. case 2

        default: { // Invalid number.
                    std::cout << "There isn't an item with that number! \n";
                    std::cin.clear();
                    std::cin.ignore(),'\n';
                    std::cin >> bagChoice;
                } // End default.
    } // End of switch case (bagChoice).

} // End of checkBag().

// ---------------------------------------------------------------------------------------------------------------------

// Setting up creatures array.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

const int MAX_TAME_ROWS = 3; // Creature rows.
const int MAX_TAME_COLS = 3; // Creature columns.
std::string playerTame[MAX_TAME_ROWS][MAX_TAME_COLS]; // Tamed creatures init.
std::string creatureName;

// Initialize array.

void initTame() // Creature loop.
{

    for (int tameRows = 0; tameRows < MAX_TAME_ROWS; tameRows++) {
        for (int tameCols = 0; tameCols < MAX_TAME_COLS; tameCols++) {

            playerTame[MAX_TAME_ROWS][MAX_TAME_COLS] = " ";
        } // End init for loop 1.
    } // End init for loop 2.
} // End initTame().

// ---------------------------------------------------------------------------------------------------------------------

// Setting up tame joining.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

int tameCount = 0;
int tameChoice = 0;

void tameJoin () // Loot pickup.
{

    tameCount = tameCount + 1; // Add a space in the bag display.

    playerTame[tameCount - 1][0] = creatureName; // Creature name.
    playerTame[tameCount - 1][1] = creatureFound; // Creature type.
    playerTame[tameCount - 1][2] = creatureAbility; // Creature ability.

} // End lootPickup();

// ---------------------------------------------------------------------------------------------------------------------

// Setting up tame deletion.

// ---------------------------------------------------------------------------------------------------------------------

void tameFree () // tame drop.
{
        tameCount = tameCount - 1; // Remove a display space.

                for (int countRows = tameChoice; countRows < tameCount; countRows++)
                {
                    playerTame[countRows][1] = playerTame[countRows - 1][1];
                    playerTame[countRows][2] = playerTame[countRows - 1][2];
                    playerTame[countRows][3] = playerTame[countRows - 1][3];
                } // End shuffle for loop.

    tameChoice = 0; // Reset the choice.

} // End tameFree ();

// ---------------------------------------------------------------------------------------------------------------------

// Tame submenu.

//----------------------------------------------------------------------------------------------------------------------

void tameSubMenu() {

    // Declare variables.

    int tameChoice;
    int tameSubChoice;
    int subConfirmation;

    std::cout << "What would you like to do with this creature?\n";
    std::cout << "1 - Info \n";
    std::cout << "2 - Part Ways \n";
    std::cout << "3 - Exit \n";
    std::cin.ignore(),'\n';
    std::cin >> tameSubChoice;

    switch(tameSubChoice){

        case 1: // Creature Info
        {
            std::cout << "Name: " << playerTame[tameChoice - 1][0] << "\n"
            << "Type: " << playerTame[tameChoice - 1][1] << "\n"
            << "Ability: " << playerTame[tameChoice - 1][2] << "\n"
            << "Found: Wish Plains" << "\n";
            break;
        }
        case 2: // Free the creature.
        {
            for(;;)
            {
                std::cout << "Are you sure you want to part ways with " << playerTame[tameChoice - 1][0] << "?\n";
                std::cout << "1 - Yes\n";
                std::cout << "2 - No\n";
                std::cin.ignore(),'\n';
                std::cin >> subConfirmation;

                if (subConfirmation == 1) {
                    tameFree();
                    break;
                }
                if (subConfirmation == 2)
                {
                    break;
                }else
                {
                    std::cout << "Please enter a valid choice!\n";
                    std::cin.clear();
                    std::cin.ignore(),'\n';
                    std::cin >> subConfirmation;
                } // End invalid option.
                break;
            } // End validation loop.
        }
        case 3:
        {
            subConfirmation = 0;
            break;
        }
    }
} // End of itemSubMenu().

// ---------------------------------------------------------------------------------------------------------------------

// Checking Tames.

// ---------------------------------------------------------------------------------------------------------------------

void checkTame() {

    // Declare variables.

    int tameChoice;
    int companionChoice;

    // Show items.

    std::cout << "------------------------------------------------------------------------------------------------------\n";

    for (int tameRows = 0; tameRows < tameCount; tameRows++) { // Only present rows with creatures on them.
        std::cout << "| #" << tameRows + 1 << " | " << playerTame[tameRows][0] << " | " << playerTame[tameRows][1] << " | "
        << playerTame[tameRows][2] << " |\n";
        std::cout << "-----------------------------------------------------------------------------------------------------\n";
    } // End of tame presentation.

    // User chooses to inspect items.

    std::cout << "Would you like to inspect a companion?\n";
    std::cout << "1 - Yes\n";
    std::cout << "2 - Exit\n";
    std::cin.ignore(),'\n';
    std::cin >> companionChoice;

    switch(companionChoice){

        case 1: { // Pick a companion.
            for(;;)
            {
                std::cout << "Which companion do you want to inspect?\n";
                std::cout << "Enter the companion number:\n";
                std::cin >> tameChoice; // User chooses.
                if (lootChoice <= (tameCount + 1))
                {
                    tameSubMenu();
                    break;
                } else{
                    std::cout << "There isn't a companion with that number! \n";
                    std::cin.clear();
                    std::cin.ignore(),'\n';
                    std::cin >> tameChoice;
                }
            } // End validation loop.
            break;
        } // End item use. case 1

        case 2:{ // Exit bag.
            break;
        } // End menu exit. case 2

        default: { // Invalid number.
            std::cout << "There isn't a companion with that number! \n";
            std::cin.clear();
            std::cin.ignore(),'\n';
            std::cin >> tameChoice;
        } // End default.
    } // End of switch case (tameChoice).

} // End of checkTame().


// ---------------------------------------------------------------------------------------------------------------------

// Tame Confirmation.

// ---------------------------------------------------------------------------------------------------------------------

void tameConfirmation() {
    for (;;) {

        int tameConfirmation;
        int nameChoice;

        std::cout << "Would you like to take " << creatureFound << " along? \n";
        std::cout << "1 - Yes\n";
        std::cout << "2 - No\n";
        std::cin >> tameConfirmation;
        if (tameConfirmation == 1) // Yes
        {
            for (;;) {
                std::cout << "Would you like to name your new companion?\n";
                std::cout << "1 - Yes\n";
                std::cout << "2 - No\n";
                std::cin >> nameChoice;
                if (nameChoice == 1) // yes name
                {
                    std::cout << "Please enter a name:\n";
                    std::cin >> creatureName;
                    break;
                } // End yes name.
                if (nameChoice == 2) // no name
                {
                    creatureName = creatureFound;
                    break;
                } // End No name.
                else { // invalid choice

                    std::cout << "Please enter a valid choice!\n";
                    std::cin.clear();
                    std::cin.ignore(), '\n';
                    std::cin >> nameChoice;
                } // End else.


            } // End validation loop.

            tameJoin(); // Add to party.
            creatureName = "";
            break;
        } // End yes.
        if (tameConfirmation == 2) // No
        {
            std::cout << "The " << creatureFound << " has wandered away.\n";
            break;
        } // End no.
        else {
            std::cout << "Please enter a valid choice!\n";
            std::cin.clear();
            std::cin.ignore(), '\n';
            std::cin >> tameConfirmation;
        } // End else.
    } // End validation loop.
} // End tameConfirmation();

// ---------------------------------------------------------------------------------------------------------------------

// Encounter Journal.

// ---------------------------------------------------------------------------------------------------------------------

void checkJournal() // Journal loop.
{

    // Monsters

    std::cout << "" << std::endl;
    std::cout << "-------M O N S T E R S-------" << std::endl;
    std::cout << "" << std::endl;

    // tinyShadow

    if(tinyShadow.encounter == true)
    {
        std::cout << "Name: " << tinyShadow.displayName << "\n";
        std::cout << "Type: " << tinyShadow.combatType << "\n";
        std::cout << "Ability: " << tinyShadow.ability << "\n";
        std::cout << "About: " << tinyShadow.desc << "\n";

        if (tinyShadow.defeat == true)
        {
            std::cout << "Health: " << tinyShadow.healthMax << "\n";
            std::cout << "Moves:\n" << tinyShadow.physical << "\n" << tinyShadow.inflicting << "\n";
        } // End defeat

        std::cout << "" << std::endl;

    } // End tinyShadow    if(tinyShadow.encounter == true)

    // smallShadow

    if(smallShadow.encounter == true)
    {
        std::cout << "Name: " << smallShadow.displayName << "\n";
        std::cout << "Type: " << smallShadow.combatType << "\n";
        std::cout << "Ability: " << smallShadow.ability << "\n";
        std::cout << "About: " << smallShadow.desc << "\n";

        if (smallShadow.defeat == true)
        {
            std::cout << "Health: " << smallShadow.healthMax << "\n";
            std::cout << "Moves:\n" << smallShadow.physical << "\n" << smallShadow.inflicting << "\n";
        } // End defeat

        std::cout << "-----------------------------" << std::endl;
        std::cout << "" << std::endl;

    } // End smallShadow

    // Creatures

    std::cout << "" << std::endl;
    std::cout << "------C R E A T U R E S------" << std::endl;
    std::cout << "" << std::endl;


    // squirrel

    if(squirrel.encounter == true)
    {
        std::cout << "Name: " << squirrel.displayName << "\n";
        std::cout << "Type: " << squirrel.combatType << "\n";
        std::cout << "Ability: " << squirrel.ability << "\n";
        std::cout << "About: " << squirrel.desc << "\n";

        if (squirrel.defeat == true)
        {
            std::cout << "Health: " << squirrel.healthMax << "\n";
            std::cout << "Moves:\n" << squirrel.physical << "\n" << squirrel.inflicting << "\n";
        } // End defeat

        std::cout << "" << std::endl;

    } // End squirrel

    // rabbit

    if(rabbit.encounter == true)
    {
        std::cout << "Name: " << rabbit.displayName << "\n";
        std::cout << "Type: " << rabbit.combatType << "\n";
        std::cout << "Ability: " << rabbit.ability << "\n";
        std::cout << "About: " << rabbit.desc << "\n";

        if (rabbit.defeat == true)
        {
            std::cout << "Health: " << rabbit.healthMax << "\n";
            std::cout << "Moves:\n" << rabbit.physical << "\n" << rabbit.inflicting << "\n";
        } // End defeat

        std::cout << "" << std::endl;

    } // End rabbit

    // deer

    if(deer.encounter == true)
    {
        std::cout << "Name: " << deer.displayName << "\n";
        std::cout << "Type: " << deer.combatType << "\n";
        std::cout << "Ability: " << deer.ability << "\n";
        std::cout << "About: " << deer.desc << "\n";

        if (deer.defeat == true)
        {
            std::cout << "Health: " << deer.healthMax << "\n";
            std::cout << "Moves:\n" << deer.physical << "\n" << deer.inflicting << "\n";
        } // End defeat

        std::cout << "" << std::endl;

    } // End deer

    // fox

    if(fox.encounter == true)
    {
        std::cout << "Name: " << fox.displayName << "\n";
        std::cout << "Type: " << fox.combatType << "\n";
        std::cout << "Ability: " << fox.ability << "\n";
        std::cout << "About: " << fox.desc << "\n";

        if (fox.defeat == true)
        {
            std::cout << "Health: " << fox.healthMax << "\n";
            std::cout << "Moves:\n" << fox.physical << "\n" << fox.inflicting << "\n";
        } // End defeat

        std::cout << "" << std::endl;

    } // End fox

    // wolf

    if(wolf.encounter == true)
    {
        std::cout << "Name: " << wolf.displayName << "\n";
        std::cout << "Type: " << wolf.combatType << "\n";
        std::cout << "Ability: " << wolf.ability << "\n";
        std::cout << "About: " << wolf.desc << "\n";

        if (wolf.defeat == true)
        {
            std::cout << "Health: " << wolf.healthMax << "\n";
            std::cout << "Moves:\n" << wolf.physical << "\n" << wolf.inflicting << "\n";
        } // End defeat

        std::cout << "" << std::endl;

    } // End wolf

    // bear

    if(bear.encounter == true)
    {
        std::cout << "Name: " << bear.displayName << "\n";
        std::cout << "Type: " << bear.combatType << "\n";
        std::cout << "Ability: " << bear.ability << "\n";
        std::cout << "About: " << bear.desc << "\n";

        if (bear.defeat == true)
        {
            std::cout << "Health: " << bear.healthMax << "\n";
            std::cout << "Moves:\n" << bear.physical << "\n" << bear.inflicting << "\n";
        } // End defeat

        std::cout << "" << std::endl;

    } // End bear

    std::cout << "-----------------------------" << std::endl;
    std::cout << "" << std::endl;

} // End checkJournal().

// ---------------------------------------------------------------------------------------------------------------------

#endif //collection end

// ---------------------------------------------------------------------------------------------------------------------