
// SNAKE AND LADDERS GAME C++ OOPS LLD Implementation

#include <bits/stdc++.h>
using namespace std;

class Entities{
    
    unordered_map<int,int> snakes;
    unordered_map<int,int> ladders;

    public:
       Entities()
       {
           snakes.clear();
           ladders.clear();
       }
       void setSnake(int low,int high)
       {
           snakes[high] = low;
       }
       void setLadder(int low,int high)
       {
          ladders[low] = high;
       }
       int getSnake(int pos)
       {
          if(snakes.find(pos) == snakes.end())
          {
            return -1;
          }
          else{
            return snakes[pos];
          }
       }
       int getLadder(int pos)
       {
          if(ladders.find(pos) == ladders.end())
          {
            return -1;
          }
          else{
            return ladders[pos];
          }
       }
};

class Player{

    string name;
    int dicePos;

    public:
       Player(string name,int dicePos)
       {
           this -> name = name;
           this -> dicePos = dicePos;
       }
       string getName()
       {
           return name;
       }
       int getdicePos()
       {
           return dicePos;
       }
       void setdicePos(int dicePos)
       {
          this -> dicePos = dicePos;
       }
};

class Players{

    vector<Player> players;
    int playerCount;

    public:
       Players()
       {
         
       }
       Players(int n)
       {
          playerCount = n;
       }
       void addPlayer(Player p)
       {
          players.push_back(p);
       }
       Player* getPlayer(int index)
       {
           return &players[index];
       }
       int getplayerCount()
       {
          return playerCount;
       }
};

class Dice {
    int val;
    public:
       int getdiceVal()
       {
            int val = rand() % 6;
            this -> val = val + 1;
            return this -> val;
       }
};

class Game{

    Players p;
    Entities e;
    Dice d;
    bool gameEnded;

    public :
       Game(Players p, Entities e, Dice d)
       {
          this -> p = p;
          this -> e = e;
          this -> d = d;
          gameEnded = false;
       }

       void start()
       {
           while(!gameEnded)
           {
           int playerCount = p.getplayerCount();
           
           for(int i = 0; i < playerCount; i++)
           {
              Player *pp = p.getPlayer(i);
              int dicePos = pp -> getdicePos();
              int diceVal = d.getdiceVal();
              int newPos = dicePos + diceVal;
              
              int snake = e.getSnake(newPos);

              if(snake != -1)
              {
                 newPos  = snake;
              }

              int ladder = e.getLadder(newPos);

              if(ladder != -1)
              {
                 newPos = ladder;
              }
              if(newPos > 100)
              {
                newPos = dicePos;
              }
              pp -> setdicePos(newPos);
              cout << pp -> getName() + " rolled a " << diceVal << " and moved to position " << newPos << endl;

              if(newPos == 100)
              {
                gameEnded = true;
                cout << pp -> getName() + "won the game" << endl;
              }
           }
           }
           return;
       }

};

int main()
{

    Entities e;

    int snakeCount; cin >> snakeCount;
    for(int i = 1; i <= snakeCount; i++)
    {
        int head, tail;
        cin >> head >> tail;
        e.setSnake(tail, head);
    }

    int ladderCount; cin >> ladderCount;
    for(int i = 1; i <= ladderCount; i++)
    {
        int start, end;
        cin >> start >> end;
        e.setLadder(start, end);
    }

    int playerCount; cin >> playerCount;
    Players p(playerCount);

    for(int i = 1; i <= playerCount; i++)
    {
        string name; cin >> name;
        Player pp(name,0);
        p.addPlayer(pp);
    }

    Dice d;

    Game g(p,e,d);
    g.start();

    return 0;
}
