#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Province
{
public:
    Province() : conquered(false) {}

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

private:
    string name;
    bool conquered;
};

class Map
{
public:
    /*BELLA = 1   CALINE =2   ENNA = 3   ATELA = 4   PLADACI = 5   BORGE = 6   DIMASE = 7   MORINA = 8   OLIVIA = 9   ROLLO = 10   TALMONE = 11   ARMENTO = 12   LIA = 13   ELINE = 14               (These are the number of maps in order(in matrix they are n - 1 )) */
    Map() : boarderingProvinces{{
                // Initialize the adjacency matrix with specific borders
                /*BELLA*/ {0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                /*CALINE*/ {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                /*ENNA*/ {0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                /*ATELA*/ {0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                /*PLADACI*/ {1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
                /*BORGE*/ {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                /*DIMASE*/ {0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                /*MORINA*/ {0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0},
                /*OLIVIA*/ {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0},
                /*ROLLO*/ {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
                /*TALMONE*/ {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                /*ARMENTO*/ {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0},
                /*LIA*/ {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                /*ELINA*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            }}
    {
    }
    bool provinceOwnerDesignative (){
        for (int i = 0; i < 14; i++)
        {
            for (size_t j = 0; j < 14; j++)
            {
                for (int k = 0; k < 14; k++)
                {
                    if (i==1&&j==1&&k==1)
                    {
                        return true ; //   shayan in function hanooz kamel ni      baadan bayad ye fekri raje be case 4 ostani bokonam  
                    }
                    else {
                        return false ; 
                    }
                    
                }
                
            }
            
        }
        
    }


enum Province {//Shayan in enume injoorie ke syntaxesh mesle شی classe     yani  agara benevisi province.(PLADACI) miad tooye matrix adjacency    4 ro dar nazar migire   (n-1) 
    BELLA = 0,
    CALINE,
    ENNA,
    ATELA,
    PLADACI,
    BORGE,
    DIMASE,
    MORINA,
    OLIVIA,
    ROLLO,
    TALMONE,
    ARMENTO,
    LIA,
    ELINA,
    PROVINCE_COUNT 
};

private:
    array<Province, 14> provinces;
    array<array<int, 14>, 14> boarderingProvinces; // Adjacency matrix for revealing bordering provinces (by 0 and 1 )  the default value of the matrix elements is 0
};

class Player
{
public:
    Player(string name, int age, string color) // constructor
    {
        // Set player name
        this->name = name;
        this->color = color;

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

    string getColor() { return color; } // Color getter function

    int getTotalScore() { return totalScore; } // Total score getter function

    void setTotalScore(int score) { totalScore = score; } // Total score setter function

    void addProvince(Province province) // Add province to conqueredProvinces
    {
        conqueredProvinces.push_back(province);
    }

    int getProvincesNumber() // Return number of conqueredProvinces
    {
        return conqueredProvinces.size();
    }

private:
    string name;
    int age;
    int totalScore; // Total score of the cards player has played in a battle
    string color;

    vector<Province> conqueredProvinces;
    // vector<Card> cardsInHand;
    // vector<vector<Card>> cardsPlayed;
};

class Battle
{
public:
    void setPoint(int p ) { 
        point = p ; 
    }
    int getPoint(){
        return point ; 
    }

private:
    int point ; 
    Province *province;
    vector<Player> *players;
};
class Card {
    private : 
        array <string , 7>Mercenary{"y1","y2","y3","y4","y5","y6","y10"};
        array <string , 7>Special{"ZEMESTAN","BAHAR","TABL-ZAN","SHIR-ZAN","SHAH-DOKHT","MATARSAK","PARCHAMDAR"};// ina ro bayad file file konim 
    public : 
    
    
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