#ifndef _PLAYER_H
#define _PLAYER_H

#include <cstdio>
#include <string>
using std::string;

class Player
{
public:
    Player(const string name);
    string getName() const;
    int getPosition() const;
    void setPosition(const int position);
    virtual int throwDice(Dice& dice) = 0;
    virtual bool isAI() = 0;
    
protected:
    string name;
    int position;
};

class AI : public Player
{
public:
    AI(const string name);
    int throwDice(Dice& dice);
    bool isAI();
};

class Human : public Player
{
public:
    Human(const string name);
    int throwDice(Dice& dice);
    bool isAI();
};

Player::Player(const string name)
{
    this->name = name;
    position = 0;
}

string Player::getName() const
{
    return name;
}

int Player::getPosition() const
{
    return position;
}

void Player::setPosition(const int position)
{
    this->position = position;
}
AI::AI(const string name) : Player(name)
{
}

int AI::throwDice(Dice& dice)
{
    int diceNumber = dice.throwDice();
    position += diceNumber;
    printf("Dice number: %d\n\n", diceNumber);
    return diceNumber;
}

bool AI::isAI()
{
    return true;
}
Human::Human(const string name) : Player(name)
{
}

int Human::throwDice(Dice& dice)
{
    int diceNumber;
    printf("Dice number: ");
    while(scanf("%d", &diceNumber) && !dice.isValid(diceNumber))
    {
        printf("Your input is invalid, please try again!\nDice number: ");
    }
    printf("\n");
    position += diceNumber;
    return diceNumber;
}

bool Human::isAI()
{
    return false;
}

#endif