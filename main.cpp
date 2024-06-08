#include <iostream>
#include <vector>
#include <array>

#include "Province.h"
#include "Map.h"
#include "Player.h"

using namespace std;

class Battle
{
public:
    
private:
    Province *province;
    vector<Player> *players;
};
class Card {
    public : 
    void setPoint(int p ) { 
        point = p ; 
    }
    int getPoint(){
        return point ; 
    }

    private : 
        int point ; 
        array <string , 7>Mercenary{"y1","y2","y3","y4","y5","y6","y10"};
        array <string , 7>Special{"ZEMESTAN","BAHAR","TABL-ZAN","SHIR-ZAN","SHAH-DOKHT","MATARSAK","PARCHAMDAR"};// ina ro bayad file file konim 
    
    
};

class Game
{
public:
    Game() { startGame(); }

    void startGame()
    {
        initPlayers();
        sortPlayers();
    }

    void initPlayers()
    {

        // Get number of players
        cout << "Number of players : ";
        int numberOfPlayers;
        cin >> numberOfPlayers;

        for (int i = 0; i < numberOfPlayers; i++)
        {
            // Get player name
            cout << "Player " << i + 1 << " name : ";
            string name;
            cin >> name;

            // Get player age
            cout << "Player " << i + 1 << " age : ";
            int age;
            cin >> age;

            // Get player color
            cout << "Player " << i + 1 << " color : ";
            string color;
            cin >> color;

            // Add new player to players list
            Player player{name, age, color};
            players.push_back(player);
        }
    }

    void addPlayer(Player player) // Player adder function
    {
        players.push_back(player);
    }

    void sortPlayers() // Sort players vector based on their age
    {
        int n = players.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (players[j].getAge() > players[j + 1].getAge())
                {
                    Player temp = players[j];
                    players[j] = players[j + 1];
                    players[j + 1] = temp;
                }
            }
        }
    }

private:
    vector<Player> players; // List of the game players
    Map map;
};

int main()
{

    return 0;
}