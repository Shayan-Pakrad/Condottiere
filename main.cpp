#include <iostream>
#include <vector>

using namespace std;

class Player
{
public:
    Player(string name, int age) // constructor
    {
        // Set player name
        this->name = name;

        // Set player age
        if (age > 0)
        {
            this->age = age;
        }
        else
        {
            while (true)
            {
                cout << "Age is invalid input another : ";
                cin >> age;
                if (age > 0)
                {
                    this->age = age;
                    break;
                }
            }
        }
    }

    int getAge() { return age; } // Age getter function

    string getName() { return name; } // Name gatter function

    int getTotalScore() { return totalScore; } // Total score getter function

    void setTotalScore(int score) { totalScore = score; } // Total score setter function

private:
    string name;
    int age;
    int totalScore; // Total score of the cards player has played in a battle

    // vector<Province> seizedProvinces;
    // vector<Card> cardsInHand;
    // vector<vector<Card>> cardsPlayed;
};

class Battle
{
public:
private:
    // Province *province;
    vector<Player> *players;
};

class Game
{
public:
    void addPlayer(Player player) // Player adder function
    {
        players.push_back(player);
    }

    Player findYoungestPlayer() // Return the youngest player
    {

        Player youngestPlayer = players[0];

        for (int i = 1; i < players.size(); i++)
        {
            if (players[i].getAge() < youngestPlayer.getAge())
            {
                youngestPlayer = players[i];
            }
        }

        return youngestPlayer;
    }

private:
    vector<Player> players; // List of game players
};

int main()
{
    return 0;
}