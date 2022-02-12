#include <iostream>
#include <thread>
#include <windows.h>


//Keep track of rockets launched from anywhere (global var)
static int m_totalRocketsLaunchedOnMoon = 0;

//Abort button/switch
static bool m_abortLaunchSwitch = false;

//Prototype functions
void RocketsLaunchedFromLaunchControlPadBuilding();


int main()
{
    //Title
    std::cout << "\n\n\t**** Welcome to the Lunar Base! ****\n\n";
    std::cout << "In our moon base, we launch Space X rockets, which is a big business and we get paid very well!";

    //This will be our main base which we, "The Space Rangers," can call mission control from the moon
    //We will have one rocket pad far away from mission control
    //There will also be another launch Control building which launches rockets from the same pad, staffed by space cadets
    //Let's find out what our thread is at mission control
    std::cout << "\nOur Mission Control thread ID is " << std::this_thread::get_id() << std::endl;
    system("pause");

    //Create our local Mission Control rocket count and tracking variables
    int missionControlLaunchCount = 0;

    std::cout << "\nTo launch the first 3 rockets from Mission control ";
    system("pause");

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Mission Control Rocket Launch #" << ++missionControlLaunchCount << " launched from Mission Control.\n";
        Sleep(3000);
        std::cout << "Mission Control Rocket Launch #" << ++m_totalRocketsLaunchedOnMoon << " launched from the moon base.\n";
        Sleep(3000);
    }

    std::cout << "\nMission Control has launched the first three rockets on the rocket pad.\n";
    std::cout << "\nTo turn over launch control to the Rocket Control substation building manned by a space cadet ";
    system("pause");

    std::thread RocketControlSubStationThread(RocketsLaunchedFromLaunchControlPadBuilding);

    std::cout << "\nSpace Ranger, any further launches can be stopped by the space cadet at Rocket Control Substation, to flip the abort switch ";
    system("pause");

    //Flip the about launch switch to true here at mission control
    m_abortLaunchSwitch = true;

    std::cout << "\nTo: Jr. Space Ranger! Abort launch switch has been flipped at mission control! Override has occurred. \n";
    std::cout << "\nThe thread ID here at mission control is " << std::this_thread::get_id() << std::endl;

    //We are about to join the thread
    RocketControlSubStationThread.join();
    std::cout << "\nFYI - The thread has been joined!";
    std::cout << "\nStats of launch\n";
    std::cout << "\nRocket Launches by Mission Control: " << missionControlLaunchCount << "\n";
    std::cout << "\nRocket launches by Rocket control Sub Station: " << m_totalRocketsLaunchedOnMoon - missionControlLaunchCount << "\n";
    std::cout << "\nTotal Rocket launches on the Moon: " << m_totalRocketsLaunchedOnMoon << "\n";

    std::cout << "\n\n\nNow ready to exit the simulation\n\n\n";
    system("pause");


    std::cout << "\n\n\n";

    return 0;
}

//Rocket launch function
void RocketsLaunchedFromLaunchControlPadBuilding()
{
    //Let's use the sleep to simulate time passing for processing.
    using namespace std::literals::chrono_literals;

    //Create our local rocket counr ant tracking variables
    int RocketControlSubstationLaunchCount = 0;

    //Let's identify if we are on a different thread by using the thread ID
    std::cout << "\nLet's get the thread ID of our Rocket Control Sub Station.\n";
    std::cout << "\nThe thread ID here at the Rocket Control Sub Station is " << std::this_thread::get_id() << std::endl;

    //Let's have our Jr. Space Ranger launch rockets at the launch pad
    while (m_abortLaunchSwitch != true)
    {
        std::cout << "\nOur Rocket Control Sub Station Launch #" << ++RocketControlSubstationLaunchCount << " Rocket launched at the Rocket Pad.\n";
        
        //Remeber the rocket bas is made up of both the mission control launch facilty and the launch pad facility
        std::cout << "\nRocket Base total launched Rocket #" << ++m_totalRocketsLaunchedOnMoon << " Rocket launched at the Moon Base.\n";
        std::this_thread::sleep_for(5s);
    }

}