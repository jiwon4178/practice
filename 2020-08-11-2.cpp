#include <iostream>
#include<vector>
#include<algorithm>

//https://programmers.co.kr/learn/courses/30/lessons/12905#
int solution(std::vector<std::vector<int>> board)
{
    int answer = 0;//모두 0인경우 return값 0됨
    int row = board[0].size();
    int col = board.size();
    if(row ==1 && col ==1){
        if(board[0][0] == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(row ==1 && col ==2){
        if(board[0][0] == 1 or board[0][1] == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(row ==2 && col ==1){
        if(board[0][0] == 1 or board[1][0] == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(row ==2 && col ==2){
        if(board[1][1] == 0){
             if(board[0][0]==1||board[1][0]==1||board[0][1]==1){
                return 1;
            }
        
        }
    }
    
    for(int i = 1; i < col; i++){
        for(int j = 1; j < row; j++){
            if(board.at(i).at(j) == 1){
                board[i][j] = std::min(board[i][j - 1], board[i - 1][j]);
                board[i][j] = std::min(board[i - 1][j - 1], board[i][j]) + 1;
                answer = std::max(answer, board[i][j]);
            }
        }
    }
    
    

    return answer*answer;
}