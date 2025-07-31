#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    double x, y;
    double speed;
    int numBomb;

public:
    Player();
    void CreateBomb();
    void Move(const char& WASD);
};

#endif // PLAYER_H
