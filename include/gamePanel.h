#include <vector>
#include "MainPlayer.h"
#include "../include//enemy.h"

#ifndef GAMEPANEL_H
#define GAMEPANEL_H


class GamePanel{

private:

    void prepareMatrix(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix,short numOfRows, short numOfEnemy);
    bool isEnemyMatrixOutOfBound(short numOfRows,std::vector<std::vector<std::unique_ptr<Enemy>>>& enemy);
    bool shouldTerminate{false};


private:
    int numberOfEnemiesInMatrix{};


public:
    bool ShouldTerminate() const;
    void moveEnemies(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix,short numOfRows, short numOfEnemy);
    void initizeEnemy(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix, short numOfRows, short enemyNumber, float xPos, float yPos);
    void drawEnemies(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix, MainPlayer& mainPlayer);


    explicit GamePanel(int numOfRows, int numOfCols);

    int getNumberOfEnemiesInMatrix() const;

};



#endif