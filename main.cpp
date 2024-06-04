#include <iostream>
#include <vector>
#include <array>

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
                cout << "Age is invalid " << endl
                     << "You cannot be UNBORN --- (Enter a positive number for age ) : ";
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

    string getName() { return name; } // Name getter function

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
    vector<Player> players; // List of the game players
};


class Map {
public:
/*BELLA = 1   CALINE =2   ENNA = 3   ATELA = 4   PLADACI = 5   BORGE = 6   DIMASE = 7   MORINA = 8   OLIVIA = 9   ROLLO = 10   TALMONE = 11   ARMENTO = 12   LIA = 13   ELINE = 14               (These are the number of maps in order(in matrix they are n - 1 )) */
Map() : boarderingProvinces {{
        // Initialize the adjacency matrix with specific borders
    /*BELLA*/  {0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    /*CALINE*/ {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    /*ENNA*/   {0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    /*ATELA*/  {0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    /*PLADACI*/{1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    /*BORGE*/  {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    /*DIMASE*/ {0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    /*MORINA*/ {0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0},
    /*OLIVIA*/ {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0},
    /*ROLLO*/  {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    /*TALMONE*/{0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    /*ARMENTO*/{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0},
    /*LIA*/    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
    /*ELINA*/  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    }} {}

private:   
    array<Province, 14> provinces;
    array<array<int, 14>, 14> boarderingProvinces; //Adjacency matrix for revealing bordering provinces (by 0 and 1 )  the default value of the matrix elements is 0

};



class Province {
public:


    void setname (string n ) { 
        name = n ; 
    }


    string getname () {
        return name ; 
    }


    Province(): conquared(false) {}


private: 
    string name;
    bool conquared;
};
int main()
{
    
    return 0;
}