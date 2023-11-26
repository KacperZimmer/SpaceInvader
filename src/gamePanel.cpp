#include "../include/gamePanel.h"
#include "../include//constValues.h"
#include "raylib.h"
#include <iostream>



bool detectCollisionWithPlayerBullet(Rectangle&& enemyRect, Rectangle&& playerBulletRect){

    return CheckCollisionRecs(enemyRect, playerBulletRect);
}

bool detectCollisonWithEnemyBullet(Rectangle&& enemyRect, Rectangle&& playerBulletRect){
    return CheckCollisionRecs(enemyRect, playerBulletRect);

}


void GamePanel::prepareMatrix(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix,short numOfRows, short numOfEnemy){

    enemyMatrix.resize(numOfRows); 
    
    for(int i = 0; i < numOfRows; ++i){
        enemyMatrix[i].resize(numOfEnemy); 
    }

}
void GamePanel::drawEnemies(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix, MainPlayer& mainPlayer) {
    for (auto& row : enemyMatrix) {
        for (auto& enemyInMatrix : row) {

            if (enemyInMatrix && mainPlayer.getBullet() && detectCollisionWithPlayerBullet(enemyInMatrix->calcDestRect(), mainPlayer.getBullet()->calcDestRect())) {
                mainPlayer.getBullet().reset();
                enemyInMatrix.reset();
                --this->numberOfEnemiesInMatrix;

            } else if (enemyInMatrix) {
                enemyInMatrix->Render();
            }

            if(enemyInMatrix && enemyInMatrix->getBullet() && detectCollisonWithEnemyBullet(enemyInMatrix->getBullet()->calcDestRect(), mainPlayer.calcDestRect())){

                this->shouldTerminate = true;
            }

        }
    }
}


bool GamePanel::isEnemyMatrixOutOfBound(short numOfRows,std::vector<std::vector<std::unique_ptr<Enemy>>>& enemy){


    for(auto& row : enemy){
        for(auto& enemySingle : row){


            if(enemySingle && enemySingle->getxPos() > WIDTH - 50 || enemySingle && enemySingle->getxPos() < 0) return true;
        }
    }

    return false;
}

void GamePanel::moveEnemies(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix,short numOfRows, short numOfEnemy){
    static int vectorSense{1};
    float currentXpos{};
    float currentYpos{};
    for(auto& row : enemyMatrix){
        for(auto& enemy : row){
            if(enemy){
                //TODO make move xDirection and yDirection functions

                currentXpos = enemy->getxPos();
                currentXpos += vectorSense;
                enemy->setXPos(currentXpos);

                currentYpos = enemy->getYPos();
                currentYpos += 0.1f;
                enemy->setYPos(currentYpos);

            }
        }
    }

    if(isEnemyMatrixOutOfBound(2,enemyMatrix)) vectorSense *= -1;

}

void GamePanel::initizeEnemy(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix, short numOfRows, short enemyNumber, float xPos, float yPos){

    static float startingXPos{20}; 

      
    Enemy enemy(0.f,0.f); 
    xPos += startingXPos; 

    prepareMatrix(enemyMatrix, numOfRows,enemyNumber); 

    for(int i = 0; i < numOfRows; ++i){
        std::vector<std::unique_ptr<Enemy>> row; 
        for(int j = 0; j < enemyNumber; ++j){

            row.emplace_back(std::make_unique<Enemy>(xPos, yPos));
            xPos += enemy.getWidth();

        }

        yPos += enemy.getHeight(); 
        xPos = startingXPos; 
        enemyMatrix[i] = std::move(row);
    }



}

GamePanel::GamePanel(int numOfRows, int numOfCols) {
    this->numberOfEnemiesInMatrix = numOfCols * numOfRows;
}

int GamePanel::getNumberOfEnemiesInMatrix() const {
    return numberOfEnemiesInMatrix;
}

bool GamePanel::isShouldTerminate() const {
    return shouldTerminate;
}
