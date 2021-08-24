/*
 * Author   J Meeks
 * Purpose  implementation file for classes relating to game visuals
 */

#include <stdio.h>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <ctime>

namespace visuals{

std::string clearScreen(){ //function that can be used to clear the screen by filling a string with white space
    return "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void introSequence(){ //function that plays the story intro for the game. Composed only of functions to display text, then briefly pause program to allow user to read
    std::chrono::seconds one(1);
    std::chrono::seconds four(4);
    std::chrono::seconds eight(8);
    std::cout << clearScreen();
    
    std::cout << "*Ding* *Ding*";
    std::this_thread::sleep_for(one);
    std::cout << "\n\nHello, this is your captain speaking. It's looking like we're approaching some severe turbulence, so please remain seated with your seatbelts fastened for the next portion of the flight";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\n*BANG* *BANG*";
    std::this_thread::sleep_for(four);
    std::cout << "\n\nUh, hello again. It seems like some lightning has struck the plane and taken our right engine out of commission.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nWorry not though, as all passenger airlines, including this one, are designed to support continued flight, even when power to one engine is lost.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nPlease remain seated with your seatbelts fastened and we should be out of this turbulence in no time";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\n*BANG* *BANG* *BANG* *BANG*";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nLadies and gentleman, this is your captain speaking. We've lost power to both engines and contact with Air Traffic Control has been interrupted. ";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nWe're losing altitude fast, but I think I see an uncharted land mass nearby. Prepare to brace for impact, and God help us all.\n\n";
    std::this_thread::sleep_for(eight);
    std::string filler;
    for(unsigned int i = 0; i < 10; i++){
        std::this_thread::sleep_for(one);
        filler += "%#@&^$&@^%#%$&#*%@$&#$@%^#%$@%&#*&%@^&$%#%&%@^#%&@%#$&@^#*^@%$#&^%@#67@$#&%^*@%#$&@^#%@^&#$&@^#$%@&%@^#%&@%#$&@^#*^@%$#&^%@#67@$#&%^*@%#$&@^#%@^&#$&@^#$%@@*#&$%@*#%&%@^#%&@%#$&@^#*^@%$#&^%@#67@$#&%^*@%#$&@^#%@^&#$&@^#$%@&#^@";
        std::cout  << filler;
    }
    
    std::cout << clearScreen();
    std::this_thread::sleep_for(eight);
    std::cout << "You open your eyes, only to see the charred remains of what was once your plane scattered around you.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nYou search around for survivors, but it soon becomes clear that you are alone on this unknown island.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nRealizing the seriousness of your situation, you hatch a plan to create a boat and escape the island.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nBut you know this will not be easy, as the worn state of the island tells you that it likely becomes fully submerged under the tides for parts of the year.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nBecause of this, you predict that you have around 100 days before the tides rise too high, and you will no longer be able to survive.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nTime is ticking, so let your adventure begin...\n";
    std::this_thread::sleep_for(four);
}

void win(){ //function that display winning ending for the game, composed only of printing messages and waiting
    std::chrono::seconds four(4);
    std::chrono::seconds eight(8);
    std::cout << clearScreen();
    std::this_thread::sleep_for(four);
    std::cout << "You awake feeling positive for the first time since crash landing on the island, knowing that today is the day you finally make your escape from this island.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nYou drag your boat to the water, and load it up with all of your supplies, taking one last look at the island before pushing off the shore, and heading out to sea to await your rescue.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nWhat seems like weeks goes by on the water with no sign of rescue, but suddenly, your communication device lights up, indicating that somebody has recieved your distress signal";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nSoon after, you look to the horizon and faintly see a boat headed your direction. A smile crosses your face, and suddenly you know that everything will be okay...";
    std::this_thread::sleep_for(eight);
    std::cout << clearScreen() << "\n\nCongratulations! You escaped the island in 100 days! Good job! If you'd like to keep playing, feel free to resume from your previous save point, or start a new game.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nThank you for playing,\n       John\n\n";
    std::this_thread::sleep_for(eight);
}

void lose(){ //function that displays the losing ending of the game, composed only of printing messages and waiting
    std::chrono::seconds four(4);
    std::chrono::seconds eight(8);
    std::cout << clearScreen();
    std::this_thread::sleep_for(four);
    std::cout << "As day 100 on the island comes and goes, you awake to feel the ocean water lapping at your feet, and open yours eyes to a camp underwater.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nYou try to stand, and see if there's any chance of escape, but your weak body won't let you, and you fall back to where you were asleep seconds ago.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nRealizing the inevitability of your fate, you close your eyes, and let the ocean surround you, saying goodbye to this cruel world...";
    std::this_thread::sleep_for(eight);
    std::cout << clearScreen() << "\n\nYou did not escape the island in 100 days! Feel free to resume from your previous save point, or start a new game.";
    std::this_thread::sleep_for(eight);
    std::cout << "\n\nThank you for playing,\n       John\n\n";
    std::this_thread::sleep_for(eight);
}

void welcome(){ //function for welcoming the player to the program whenever they open it
    
    //display welcome to
    std::cout << clearScreen()
    <<  "██     ██ ███████ ██       ██████  ██████  ███    ███ ███████     ████████  ██████" << std::endl
    <<  "██     ██ ██      ██      ██      ██    ██ ████  ████ ██             ██    ██    ██" << std::endl
    <<  "██  █  ██ █████   ██      ██      ██    ██ ██ ████ ██ █████          ██    ██    ██" << std::endl
    <<  "██ ███ ██ ██      ██      ██      ██    ██ ██  ██  ██ ██             ██    ██    ██" << std::endl
    <<  " ███ ███  ███████ ███████  ██████  ██████  ██      ██ ███████        ██     ██████  ██ ██ ██" << std::endl;
    std::chrono::seconds welcome(2);
    std::this_thread::sleep_for( welcome );
    
    //wait a few seconds and display game title word by word
    std::chrono::seconds title( 1);
    std::chrono::seconds titleFin( 5);
    std::cout << clearScreen()
    << "██╗      ██████╗ ███████╗████████╗" << std::endl
    << "██║     ██╔═══██╗██╔════╝╚══██╔══╝" << std::endl
    << "██║     ██║   ██║███████╗   ██║   " << std::endl
    << "██║     ██║   ██║╚════██║   ██║   " << std::endl
    << "███████╗╚██████╔╝███████║   ██║   " << std::endl
    << "╚══════╝ ╚═════╝ ╚══════╝   ╚═╝   " << std::endl;
    std::this_thread::sleep_for( title );
    std::cout << clearScreen()
    << "██╗      ██████╗ ███████╗████████╗    ██╗███████╗██╗      █████╗ ███╗   ██╗██████╗  " << std::endl
    << "██║     ██╔═══██╗██╔════╝╚══██╔══╝    ██║██╔════╝██║     ██╔══██╗████╗  ██║██╔══██╗ " << std::endl
    << "██║     ██║   ██║███████╗   ██║       ██║███████╗██║     ███████║██╔██╗ ██║██║  ██║ " << std::endl
    << "██║     ██║   ██║╚════██║   ██║       ██║╚════██║██║     ██╔══██║██║╚██╗██║██║  ██║ " << std::endl
    << "███████╗╚██████╔╝███████║   ██║       ██║███████║███████╗██║  ██║██║ ╚████║██████╔╝ " << std::endl
    << "╚══════╝ ╚═════╝ ╚══════╝   ╚═╝       ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝  " << std::endl;
    std::this_thread::sleep_for( title );
    std::cout << clearScreen()
    << "██╗      ██████╗ ███████╗████████╗    ██╗███████╗██╗      █████╗ ███╗   ██╗██████╗      █████╗ ██████╗ ██╗   ██╗███████╗███╗   ██╗████████╗██╗   ██╗██████╗ ███████╗" << std::endl
    << "██║     ██╔═══██╗██╔════╝╚══██╔══╝    ██║██╔════╝██║     ██╔══██╗████╗  ██║██╔══██╗    ██╔══██╗██╔══██╗██║   ██║██╔════╝████╗  ██║╚══██╔══╝██║   ██║██╔══██╗██╔════╝" << std::endl
    << "██║     ██║   ██║███████╗   ██║       ██║███████╗██║     ███████║██╔██╗ ██║██║  ██║    ███████║██║  ██║██║   ██║█████╗  ██╔██╗ ██║   ██║   ██║   ██║██████╔╝█████╗" << std::endl
    << "██║     ██║   ██║╚════██║   ██║       ██║╚════██║██║     ██╔══██║██║╚██╗██║██║  ██║    ██╔══██║██║  ██║╚██╗ ██╔╝██╔══╝  ██║╚██╗██║   ██║   ██║   ██║██╔══██╗██╔══╝" << std::endl
    << "███████╗╚██████╔╝███████║   ██║       ██║███████║███████╗██║  ██║██║ ╚████║██████╔╝    ██║  ██║██████╔╝ ╚████╔╝ ███████╗██║ ╚████║   ██║   ╚██████╔╝██║  ██║███████╗" << std::endl
    << "╚══════╝ ╚═════╝ ╚══════╝   ╚═╝       ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝     ╚═╝  ╚═╝╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═══╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝" << std::endl;
    std::this_thread::sleep_for(titleFin);
}

}
