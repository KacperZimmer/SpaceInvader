#include "../Headers/gamePanel.h"
#include "../Headers/constValues.h"
#include <iostream>


void GamePanel::prepareMatrix(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix,short numOfRows, short numOfEnemy){

    enemyMatrix.resize(numOfRows); 
    
    for(int i = 0; i < numOfRows; ++i){
        enemyMatrix[i].resize(numOfEnemy); 
    }


}
void GamePanel::drawEnemies(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix, MainPlayer& mainPlayer){

    for(auto& row: enemyMatrix){
        for(auto& enemyInMatrix: row){
            if(enemyInMatrix && mainPlayer.bullet && CheckCollisionRecs(mainPlayer.bullet->calcDestRect(), enemyInMatrix->calcDestRect())){
                mainPlayer.bullet.reset(); 
                enemyInMatrix.reset(); 
            
            }else if(enemyInMatrix){
                enemyInMatrix->Render(); 
            }
        }
    }
}

bool GamePanel::isEnemyMatrixOutOfBound(short numOfRows,std::vector<std::vector<std::unique_ptr<Enemy>>>& enemy){


    for(auto& row : enemy){
        for(auto& enemySingle : row){
            
            if(enemySingle && enemySingle->getxPos() > WIDTH || enemySingle && enemySingle->getxPos() < 0) return true;
        }
    }

    return false;
}

void GamePanel::moveEnemies(std::vector<std::vector<std::unique_ptr<Enemy>>>& enemyMatrix,short numOfRows, short numOfEnemy){
    int vectorSense{1};
    
    for(auto& row : enemyMatrix){
        for(auto& enemy : row){
            if(enemy){
                float currentXpos = enemy->getxPos(); 
                currentXpos += vectorSense; 
                enemy->setXPos(currentXpos); 
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
            std::cout << enemy.getWidth() << std::endl; 

        }

        yPos += enemy.getHeight(); 
        xPos = startingXPos; 
        enemyMatrix[i] = std::move(row);
    }



}
