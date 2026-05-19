#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//1 class
struct Player {
public:
    int health = 100;
    int hunger = 100;
    int thirst = 100;
    int stress = 0;
    int bullets = 0;
    int fuel = 0;
    int battery = 0;
    int launchCode = 0;
};
//2 class
struct Enemy {
    string name;
    int damage;
};

Player carl;
vector<string> inventory;
Enemy bear = {"Mutated Bear", 20};
Enemy Zombie = {"Zombie", 20};

//17 func
void pauseGame() {
    cout << "\nPress ENTER to return...";
    cin.ignore(1000, '\n');
    cin.get();
}
//2 func
void showStats(Player p) {
    cout << "\nCURRENT STATS:" << endl;
    cout << "Health: " << p.health << endl;
    cout << "Hunger: " << p.hunger << endl;
    cout << "Thirst: " << p.thirst << endl;
    cout << "Stress: " << p.stress << endl;
    cout << "Bullets: " << p.bullets << endl;
    cout << "Fuel: " << p.fuel << endl;
    cout << "Battery: " << p.battery << endl;
    cout << "LaunchCode: " << p.launchCode << endl;
}
//28 func, penalties
void checkSurvival() {
    if(carl.hunger <= 0) {
        carl.health -= 10;
        cout << "\nYou are starving. Health decreased.\n";
    }
    if (carl.thirst <= 0) {
        carl.health -= 20;
        cout << "\nYou are dehydrated. Health decreased badly.\n";
    }
    if (carl.health <= 0) {
        cout << "\nCarl collapses. You died on Planet 4546b.\n";
    }
}
//28 func
void capStats() {
    if (carl.health > 100) carl.health = 100;
    if (carl.hunger > 100) carl.hunger = 100;
    if (carl.thirst > 100) carl.thirst = 100;
}
//29 func
void travelCost() {
    carl.hunger -= 5;
    carl.thirst -= 5;
    checkSurvival();
    showStats(carl);
}
//30 func
void checkStress() {
    if (carl.stress >= 50) {
        cout << "\nCarl is panicking. His stress levels are too high.\n";
        carl.health -= 5;
    }
    checkSurvival();
    showStats(carl);
}
//31 func
void calmDown() {
    cout << "\nCarl takes a moment to breathe and calm down.\n";
    carl.stress -= 15;
    if (carl.stress < 0) {
        carl.stress = 0;
    }
    showStats(carl);
    pauseGame();
}
//1 func
void showIntroMenu() {
    cout << "Hello! Welcome to [ Alone?... On Planet 4546b ]" << endl;
    cout << "\nType 1 for PLAYER CONTEXT.\n";
    cout << "Type 2 for STORY CONTEXT.\n";
    cout << "Type 3 to START GAME." << endl;
}
//3 func
void showInventory(vector<string> inventory) {
    cout << "\nYour inventory:\n";
    
    for (int i = 0; i < inventory.size(); i++) {
        cout << "- " << inventory [i] << endl;
    }
}
//13 func
void controlRoom() {
    cout << "\nYou enter the control room.\n";
    cout << "Dust covers the broken monitors.\n";
    cout << "One screen still flickers with an old colony log.\n";
    cout << "\nLOG ENTRY:";
    cout << "\n'Containment failure detected.'";
    cout << "\n'Backup power rerouted to the military sector.'";
    cout << "\n'Evacuation unsuccessful.'\n";

    carl.stress += 5;
    
    checkSurvival();
    showStats(carl);
    
    cout << "\nYou learned the colony that used to live here lost power during an emergency lockdown.\n";
    pauseGame();
}
//14 func
void solarField() {
    cout << "\nYou walk through the solar field.\n";
    cout << "You see a bunch of purple-dusted solar panels in the distance.\n";
    cout << "Some panels still faintly glow with some energy.\n";
    cout << "\nWhile searching the area, you find a damaged battery cell.\n";
    cout << "\nYou also notice claw marks scratched across multiple panels.\n";
    cout << "Something large definitely passed through here before.\n";
    carl.battery = 1;
    inventory.push_back("Battery cell");
    showInventory(inventory);
    cout << "\nPress ENTER to return...";
    cin.ignore(1000, '\n');
    cin.get();
}
//15 func
void roofTop() {
    cout << "\nYou climb onto the roof.\n";
    cout << "The cold wind blows across the purple forest below.\n";
    cout << "\nFrom the roof, you can see a massive rocket ship far to the East.\n";
    cout << "Its metallic surface reflects light above the trees.\n";
    cout << "\nYou also notice smoke rising somewhere Southwest.\n";
    cout << "Maybe another outpost still has power...\n";
    cout << "\nSuddenly, you hear a distant animal roar echo through the forest.\n";
    
    carl.stress += 5;
    
    checkSurvival();
    showStats(carl);

    cout << "\nPress ENTER to return...";
    cin.ignore(1000, '\n');
    cin.get();
}
//18 func
void inspectOil() {
    cout << "\nYou inspect the rusted oil drill...\n";
    cout << "A broken screen says:'Drilling team found movement below the rock.'\n";
    cout << "This might've been where the planet's disaster began.\n";
    cout << "They were drilling deeper underground than intended.\n";
    
    carl.stress += 5;
    checkSurvival();
    showStats(carl);
    pauseGame();
}
//19 func
void searchContainer() {
    cout << "\nYou search the fuel containers...\n";
    cout << "You find multiple containers with usable rocket fuel.\n";
    carl.fuel = 1;
    inventory.push_back("Rocket fuel");
    showInventory(inventory);
    pauseGame();
}
//20 func
void commandTent() {
    cout << "\nYou search the command tent.\n";
    cout << "A military order says infected civilians were not allowed near rocket zone.\n";
    carl.stress += 5;
    showStats(carl);
    pauseGame();
}
//21 func
void armoryLocation() {
    int correctCode = rand() % 10 + 1;
    int guess;
    cout << "\nYou try to enter the armory.\n";
    cout << "There is a locked keypad locking the door.\n";
    
    bool unlocked = false;
    
    while (!unlocked) {
        cout << "\n Guess the security code (1-10).\n";
        cout << "\n> ";
        cin >> guess;
    
        if (guess == correctCode) {
            cout << "You find a handgun magazine in there with some bullets.\n";
            carl.bullets += 16;
            inventory.push_back("Ammo");
            showInventory(inventory);
            
            unlocked = true;
        }
        else {
            cout << "\nACCESS DENIED. TRY AGAIN\n";
        }
    }
    checkSurvival();
    showStats(carl);
    pauseGame();
}
//22 func
void findFish() {
    cout << "\nYou catch several fish from the river.\n";
    cout << "They look strange, but they restore your hunger!!!\n";
    carl.hunger += 25;
    capStats();
    showStats(carl);
    pauseGame();
}
//23 func
void findHunt() {
    int choice;
    cout << "\nA mutated bear creature CHARGES from the trees.\n";
    cout << "What do you do?";
    cout << "\n1. Shoot it.";
    cout << "\n2. Run away.";
    cout << "\n> ";
    cin >> choice;
    
    if (choice == 1) {
        if(carl.bullets >= 4) {
            cout << "\nYou fire several shots and kill the bear!\n";
            carl.bullets -=4;
            carl.stress += 5;
        }
        else {
            cout << "\nYou pull the trigger, but you don't have enough bullets.\n";
            cout << "The bear claws you\n";
            carl.health -= 20;
            carl.stress += 15;
        }
    }
    else if (choice == 2) {
        cout << "You try to escape, but it claws your back!\n";
        carl.health -= 20;
        carl.stress += 10;
    }
    checkSurvival();
    showStats(carl);
    pauseGame();
}
//24 func
void findBerry() {
    cout << "\nYou collect and eat some cyan berries.\n";
    cout << "They taste bitter but aid your hunger...\n";
    carl.hunger += 20;
    capStats();
    showStats(carl);
    pauseGame();
}
//25 func
void drinkWater() {
    cout << "\nYou drink from the perfectly clear lake.\n";
    cout << "The water is surprisingly clean!\n";
    carl.thirst += 35;
    showStats(carl);
    pauseGame();
}
//26 func
void walkPollutedLake() {
    int choice;
    
    cout << "\nYou walk around the polluted lake.\n";
    cout << "A zombie hand grabs your leg from the mud.\n";
    cout << "What do you do?";
    cout << "\n1. Shoot it.";
    cout << "\n2. Kick free and run away.";
    cout << "\n> ";
    cin >> choice;
    
    if (choice == 1) {
        if(carl.bullets >= 4) {
            cout << "\nYou fire several shots and kill the zombie!\n";
            carl.bullets -=2;
            carl.stress += 5;
        }
        else {
            cout << "\nYou pull the trigger, but you don't have enough bullets.\n";
            cout << "The zombie bites your leg.\n";
            carl.health -= 20;
            carl.stress += 15;
        }
    }
    else if (choice == 2) {
        cout << "You try to escape, but it scratches your leg!\n";
        carl.health -= 20;
        carl.stress += 10;
    }
    checkSurvival();
    showStats(carl);
    pauseGame();
}
//27 func
void searchTent() {
    cout << "\nYou search the tents.\n";
    cout << "You find a medkit and old research notes.\n";
    cout << "The note says: 'The infection was created by our own experiments.'\n";
    cout << "There's also a launch code...\n";
    carl.health += 40;
    carl.launchCode = 1;
    capStats();
    inventory.push_back("Medkit");
    inventory.push_back("launchCode");
    showStats(carl);
    pauseGame();
}
//4 func
void goNorth() {
    cout << "\nYou travel North and find a medium sized building covered in solar panels.\n\n";
    
    travelCost();
    
    cout << "The journey took a while so now you are a bit more hungry and thirsty.\n\n";
    
    checkSurvival();
    showStats(carl);
    
    int northChoice;
    bool northArea = true;
    
    while(northArea) {
        cout << "\n<<< NORTH: Solar Facility >>>\n";

        cout << "\n1. Enter control room.";
        cout << "\n2. Explore solar field.";
        cout << "\n3. Climb roof.";
        cout << "\n4. Return back to escape pod.";
        
        cout << "\n\n> ";
        cin >> northChoice;
        
        if (northChoice == 1) {
            controlRoom();
        }
        else if (northChoice == 2) {
            solarField();
        }
        else if (northChoice == 3) {
            roofTop();
        }
        else if (northChoice == 4) {
            cout << "\nYou head back to the escape pod.\n";
            northArea = false;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
        
    }
}
//5 func
void goWest() {
    cout << "\nYou travel West and you find small tents with rusty machinery and gasoline containers.\n";
    
    travelCost();
    
    int westChoice;
    bool westArea = true;
    
    while(westArea) {
        cout << "\n<<< WEST: Oil/Fuel Site >>>\n";

        cout << "\n1. Inspect oil drill";
        cout << "\n2. Search fuel containersr";
        cout << "\n3. Return back to escape pod.";
        
        cout << "\n\n> ";
        cin >> westChoice;
        
        if (westChoice == 1) {
            inspectOil();
        }
        else if (westChoice == 2) {
            searchContainer();
        }
        else if (westChoice == 3) {
            cout << "\nYou head back to the escape pod.\n";
            westArea = false;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}
//6 func
void goSouth() {
    cout << "\nYou travel South and you find a destroyed & abandoned military camp.\n";
    
    travelCost();
    
    int southChoice;
    bool southArea = true;
    
    while(southArea) {
    cout << "\n<<< South: Military Camp >>>\n";

        cout << "\n1. Search command tent.";
        cout << "\n2. Explore armory.";
        cout << "\n3. Return back to escape pod.";
        
        cout << "\n\n> ";
        cin >> southChoice;
        
        if (southChoice == 1) {
            commandTent();
        }
        else if (southChoice == 2) {
            armoryLocation();
        }
        else if (southChoice == 3) {
            cout << "\nYou head back to the escape pod.\n";
            southArea = false;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}
//7 func
void goEast() {
    cout << "\nYou travel East and see a huge rocket ship reflecting light above the purple trees.\n";
    
    travelCost();
    
    cout << R"(
        /\
       /  \
      /____\
        ||
        ||
       /||\
    )";
    
    int eastChoice;
    bool eastArea = true;
    
    while(eastArea) {
    cout << "\n<<< East: Rocket Site >>>\n";

        cout << "\nThere is a rocket here. Maybe I can get out. It needs fuel, battery, and a launch code...\n";
        
        checkSurvival();
        showStats(carl);
        
        cout << "\n1. Try to launch rocket.";
        cout << "\n2. Return back to escape pod.";
        
        cout << "\n\n> ";
        cin >> eastChoice;
        
        if (eastChoice == 1) {
            if (carl.fuel >= 1 && carl.battery >= 1 && carl.launchCode >= 1) {
                cout << "\nYou insert the rocket fuel and battery cell.\n";
                cout << "The rocket powers on.\n";
                cout << "The engines roar as you eascape Planet 4546b.\n";
                cout << "\nENDING: Carl escaped the planet.\n";
                
                carl.health = 0;
                eastArea = false;
            }
            else {
                cout << "\nThe rocket still needs fuel and battery. Keep exploring.\n";
            }
        }
        else if (eastChoice == 2) {
            cout << "\nYou head back to the escape pod.\n";
            eastArea = false;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}
//8 func
void goNW() {
    cout << "\nNorthwest and see a river full of cyan fish.\n";
    
    travelCost();
    
    int nwChoice;
    bool nwArea = true;
    
    while(nwArea) {
    cout << "\n<<< Northwest: River/Bear Area >>>\n";

        cout << "\n1. Look for fish.";
        cout << "\n2. Hunt.";
        cout << "\n3. Return back to escape pod.";
        
        cout << "\n\n> ";
        cin >> nwChoice;
        
        if (nwChoice == 1) {
            findFish();
        }
        else if (nwChoice == 2) {
            findHunt();
        }
        else if (nwChoice == 3) {
            cout << "\nYou head back to the escape pod.\n";
            nwArea = false;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}
//9 func
void goNE() {
    cout << "\nYou travel Northeast and find bushes full of cyan berries.\n";
    
    travelCost();
    
    int neChoice;
    bool neArea = true;
    
    while(neArea) {
    cout << "\n<<< Northeast: Berry field >>>\n";

        cout << "\n1. Find & collect berries.";
        cout << "\n2. Return back to escape pod.";
        
        cout << "\n\n> ";
        cin >> neChoice;
        
        if (neChoice == 1) {
            findBerry();
        }
        else if (neChoice == 2) {
            cout << "\nYou head back to the escape pod.\n";
            neArea = false;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}
//10 func
void goSE() {
    cout << "\nYou travel Southeast and discover a perfectly clear lake.\n";
    
    travelCost();
    
    int seChoice;
    bool seArea = true;
    
    while(seArea) {
    cout << "\n<<< Southeast: Clear lake >>>\n";

        cout << "\n1. Drink water";
        cout << "\n2. Return back to escape pod.";
        
        cout << "\n\n> ";
        cin >> seChoice;
        
        if (seChoice == 1) {
            drinkWater();
        }
        else if (seChoice == 2) {
            cout << "\nYou head back to the escape pod.\n";
            seArea = false;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}
//11 func
void goSW() {
    cout << "\nYou travel Southwest and see a polluted brown lake with old tents nearby.\n";
    
    travelCost();
    
    int launchCode = 0;
    int swChoice;
    bool swArea = true;
    
    while(swArea) {
    cout << "\n<<< Southwest: Polluted lake & tents? >>>\n";

        cout << "\n1. Walk around polluted lake.";
        cout << "\n2. Search tents.";
        cout << "\n3. Return back to escape pod.";
        
        cout << "\n\n> ";
        cin >> swChoice;
        
        if (swChoice == 1) {
            walkPollutedLake();
        }
        else if (swChoice == 2) {
            searchTent();
        }
        else if (swChoice == 3) {
            cout << "\nYou head back to the escape pod.\n";
            swArea = false;
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}
//12 func
void goOut() {
    int directionChoice;
                    
    cout << "\nWhere do you want to go?\n";
    cout << "1. North\n";
    cout << "2. West\n";
    cout << "3. South\n";
    cout << "4. East\n";
    cout << "5. Northwest\n";
    cout << "6. Northeast\n";
    cout << "7. Southeast\n";
    cout << "8. Southwest\n";
    cout << "9. Rest and calm down\n";
    cout << "\n> ";
    //protect from letter input infinite loop
    while(!(cin >> directionChoice)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nInvalid input. Try again.\n";
        cout << "\n> ";
    }
                    
    if (directionChoice == 1) {
        goNorth();
    }
    else if (directionChoice == 2) {
        goWest();                
    }
    else if (directionChoice == 3) {
        goSouth();                
    }
    else if (directionChoice == 4) {
        goEast();             
    }
    else if (directionChoice == 5) {
        goNW();                
    }
    else if (directionChoice == 6) {
        goNE();                
    }
    else if (directionChoice == 7) {
        goSE();                
    }
    else if (directionChoice == 8) {
        goSW();                
    }
    else if (directionChoice == 9) {
        calmDown();                
    }
    else {
        cout << "\nInvalid direction.\n";
    }
}
//16 func
void startExploration() {
    while (carl.health > 0) {
        goOut();
    }
}

int main() {
    
    int playerChoice = 0;
    showIntroMenu();
    srand(time(0));

    while (playerChoice != 3) {
        cout << "\n> ";
        //protect from letter input infinite loop
        if(!(cin >> playerChoice)) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
            if (playerChoice == 1) {
                cout << "\nYou are Carl, a lonely 35 year old man living in the year 2126.\n";
                cout << "You are a Jack of All Trades but a master of none.\n";
            } 
            else if (playerChoice == 2) {
                cout << "\nYou went on a space cruise hoping to make new friends...\n";
                cout << "But after a ship emergency, you were accidentally launched in an escape pod.\n";
                cout << R"(
                         /\
                        /  \
                       /----\
                       | POD|
                       |____|)";
            } 
            else if (playerChoice == 3) {
                cout << "\nStarting Game...\n" << endl;
                checkSurvival();
                showStats(carl);
                
                cout << "\nYou wake up inside a damaged escape pod.\n";
                cout << "Red emergency lights flash around you.\n";
                cout << "The pod's AI system blurts: 𝘞 𝘢𝘳𝘯𝘪𝘯𝘨. 𝘉𝘢𝘵𝘵𝘦𝘳𝘺 𝘢𝘵 𝘤𝘳𝘪𝘵𝘪𝘤𝘢𝘭 𝘭𝘰𝘸 𝘭𝘦𝘷𝘦𝘭.";
                
                cout << "\n\nPress ENTER to continue...\n";
                cin.ignore();
                cin.get();
                
                cout << "The pod AI says you are on planet 4546b, an oxygenated planet." << endl;
                cout << "Knowing you can breathe here, you open the hatch and all you\nsee are purple trees and purple grass around you.";

                int firstChoice;
            
                cout << "\n\nWhat will you do?\n";
                cout << "1. Exit the pod\n";
                cout << "2. Search the pod\n";
                cout << "3. Rest for a while.\n";
            
                cout << "\n> ";
                //protect from letter input infinite loop 
                while (!(cin >> firstChoice)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nInvalid input. Try again.\n";
                    cout << "\n> ";
                }
                if (firstChoice == 1) {
                    cout << "\nYou carefully step outside onto Planet 4546b.\n\n";
                    travelCost();
                    checkSurvival();
                    showStats(carl);
                    
                    startExploration();
                    
                }
                else if (firstChoice == 2) {
                    cout << "\nYou found a handgun and a large axe.\n";
                    inventory.push_back("Handgun");
                    inventory.push_back("Large Axe");
                    
                    showInventory(inventory);
                    
                    char outsideChoice;
                    //prevent other letters stop run
                    while (true) {
                        cout << "\nWant to go outside now? Type y or n\n";
                        cout << "\n > ";
                        cin >> outsideChoice;
                        
                        if (outsideChoice == 'y' || outsideChoice == 'Y') {
                            cout << "\nYou step outside onto Planet 4546b.\n";
                        
                            startExploration();
                            break;
                        }
                        else if (outsideChoice == 'n' || outsideChoice == 'N') {
                            cout << "\nYou choose to stay inside but eventually you get bored." << endl;
                            cout << "You step outside onto Planet 4546b.\n\n";
                        
                            travelCost();
                            checkSurvival();
                            showStats(carl);
                    
                            startExploration();
                            break;
                        }
                        else {
                            cout << "\nInvalid choice. Try again...\n";
                        }
                    }
                    
                }
                else if (firstChoice == 3) {
                    cout << "\nYou try to rest, but the blaring alarms keep you awake.\n";
                    carl.stress += 10;
                    travelCost();
                    checkSurvival();
                    showStats(carl);
                    
                    cout << "\nThe alarms get louder. You cannot stay here forever.";
                    cout << "\nYou step outside onto Planet 4546b.\n";
                    
                    startExploration();
                }
                else {
                    cout << "\nInvalid choice.\n";
                }
            
            } 
            else {
                cout << "\nInvalid input. Try again.";
            }

    }
    
    
    return 0;

    } 
    

	



