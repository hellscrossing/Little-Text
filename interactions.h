// Created by Sarah Nadzan for CSIS 2605's Final Project.
// Dotted lines are to keep the code separated and easy to read.

// ---------------------------------------------------------------------------------------------------------------------

// P L A Y E R

// T A B L E  O F  C O N T E N T S

// Player v.s. Monster.

// Player v.s. Creature.

// Welcome Dialogue.

// Intro Dialogue.

// ---------------------------------------------------------------------------------------------------------------------

#ifndef interactions
#define interactions

#include "generation.h"

// ---------------------------------------------------------------------------------------------------------------------

// Game State Structure.

// ---------------------------------------------------------------------------------------------------------------------

struct gameState {
    int intro;
    int quiz;
    int welcome;
    int wish;
    int forest;
    int outro;
} active;

// ---------------------------------------------------------------------------------------------------------------------

// Welcome.

// ---------------------------------------------------------------------------------------------------------------------

// Declare variables.

std::string playerName;

void welcomeDialogue()
{
    std::string quizSkip; // If you want to skip the quiz.

    std::cout << "\nHello there, and welcome! I can't really tell you who I am, or where you are right now.. \n";
    std::cout << "But I have exciting news.. You're about to enter Wish Village! \n";
    std::cout << "In the Village, you will train to become a Mage of the Forest. \n";
    std::cout << "You will explore dungeons, collect treasures, and make friends- not all of them human- as you adventure!\n";
    std::cout << "I know this sounds exciting, but before you go in, I do have a few questions for you, if you'll allow. \n";
    /*std::cout << "Answer questions? \n";
    std::cout << "(y/n) \n";
    std::cin >> quizSkip;
    if(quizSkip == "y" || "Y" || "yes" || "Yes")
    {
        std::cout << "I respect your wishes.. give me one moment. \n"; */
        animalRandom();
    /*} else
    {
        animalQuiz();
    } */

    std::cout << "After much consideration, it seems that the " << playerAnimal << " deity has taken a liking to you! \n";
    std::cout << "You are now one of their Children, and have been blessed with the power of the stars. \n";
    std::cout << "Now, I can let you enter the world of Wish Village. \n";
    std::cout << "Good luck, stay safe, and come back to me with lots of stories one day! \n";
}

// ---------------------------------------------------------------------------------------------------------------------

// Introduction.

// ---------------------------------------------------------------------------------------------------------------------
std::string introDialogue() // Introduction Dialogue.
{
    std::string dialogueSkip;
    std::string dialogueCont;
for (;;) {
    std::cout << "Skip Dialogue? (y/n) \n";
    std::cin >> dialogueSkip;
    if (dialogueSkip == "y") {
        std::cout << "What is your name? \n";
        std::cin >> playerName;
        break;
    } // End of skip.

    if (dialogueSkip == "n") {
        std::cout << "... \n";

        // Nora enters.

        std::cout << "\n''Well, hello there, it's a pleasure to meet you. I hear you're my new apprentice!'' \n";
        std::cout
                << "\nA woman in her 40's is shaking your hand. She has shorter hair, kind eyes, and a large smile. \n";
        std::cout << "\nShe is wearing lots of wooden beads, and a large cloak with a hood. The hood has deer ears. \n";
        std::cout
                << "\nYou take a look around, and notice the vast network of treehouses in the forest surrounding you. \n";
        std::cout
                << "\nThere are many other people in animal hoods walking around, seemingly going about their daily lives. \n" << std::endl;

        // Break.

        std::cout << "Press a key to continue.\n";
        std::cin >> dialogueCont;
        std::cout << "\n";

        // Player responds.

        std::cout << "\n> ...Apprentice? \n";

        // Break.

        std::cout << "Press a key to continue.\n";
        std::cin >> dialogueCont;
        std::cout << "\n";


        // Lana didn't tell the player anything... Exposition.

        std::cout
                << "\n''Oh, for the love of... Did a woman of the Fox Children bring you? Red hair? She has a tendency to not \n";
        std::cout << "explain anything.\n"
                     " I apologize.. You have been blessed by the " << playerAnimal
                  << ", honey. Our village \n";
        std::cout << "has earmarked you for your potential.'' \n";

        // Break.

        std::cout << "Press a key to continue.\n";
        std::cin >> dialogueCont;
        std::cout << "\n";

        // Begin to move to the forest.

        std::cout << "The woman smiled, ''You seem like a lovely child. We'll get along swimmingly.''\n";
        std::cout << "''Well, let's get a move on then.'' She begins to lead you down a path, to the edge of town. \n";

        std::cout
                << "\n''My name is Nora, by the way. I am a Mentor of the Forest, as well as a Child of the Deer.'' \n";
        std::cout
                << "\n''It is my job to train new apprentices in the ways of the Mages; today, I will be assessing you.'' \n";
        std::cout
                << "''Now, don't worry. This test is to see how we can best train you and put your talents to use here.'' \n";

        // Break.

        std::cout << "Press a key to continue.\n";
        std::cin >> dialogueCont;
        std::cout << "\n";

        // Player responds.

        std::cout << "\n> What will we be doing? \n";

        // Break.

        std::cout << "Press a key to continue.\n";
        std::cin >> dialogueCont;
        std::cout << "\n";

        // End.

        std::cout << "\n''That's soon to come, dear!'' \n";

        std::cout << "\n''I'm glad to have you with us!'' \n";
        std::cout << "\nNora stops at the edge of the field. \n";
        std::cout
                << "\nLush, green grass, and rolling hills are shining in the sun; you can make out a river in the distance. \n";

        std::cout << "\n''Now, what is your name?'' \n";
        std::cin >> playerName;

        break;

    } else {
        std::cout << "That isn't a choice! \n";
        std::cin.clear();
        std::cin.ignore(), '\n';
        std::cin >> dialogueSkip;
    } // End of Extra dialogue.
} // End of input loop.

    return playerName; // Return player's name.

} // End of intro dialogue.

// ---------------------------------------------------------------------------------------------------------------------

#endif //interactions

// ---------------------------------------------------------------------------------------------------------------------
