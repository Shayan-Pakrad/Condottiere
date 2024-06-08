#include <iostream>
#include <vector>
#include <array>

#include "Province.h"
#include "Map.h"
#include "Player.h"
#include "Battle.h"
#include "Card.h"

using namespace std;

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