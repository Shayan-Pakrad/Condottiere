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

int main()
{
    return 0;
}