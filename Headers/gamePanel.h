#include <vector>
#include "MainPlayer.h"
#include "../Headers/enemy.h"

#ifndef GAMEPANEL_H
#define GAMEPANEL_H


class GamePanel{
 
    private:

        static void prepareMatrix(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix,short numOfRows, short numOfEnemy);
        static bool isEnemyMatrixOutOfBound(short numOfRows,std::vector<std::vector<std::unique_ptr<Enemy>>>& enemy); 
        static bool timeToDraw(); 
 

    public:
        GamePanel() = delete; 
        static void moveEnemies(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix,short numOfRows, short numOfEnemy);
        static void initizeEnemy(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix, short numOfRows, short enemyNumber, float xPos, float yPos); 
        static void drawEnemies(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix, MainPlayer& mainPlayer); 

};



#endif