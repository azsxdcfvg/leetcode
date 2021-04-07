#pragma once
#include<vector>
#include<string>
/*
string word = "AAB";
vector<vector<char>> board{ {'C', 'A', 'A'},{'A', 'A', 'A' }, {'B', 'C', 'D'} };
*/
using namespace std;
int raw = 0, col = 0;
vector<vector<bool>> is_visit;
bool getFullPath(vector<vector<char>>& board, string word, unsigned int lay, int loc_raw, int loc_col) {
    int i = loc_raw;
    int j = loc_col;
    if (lay == word.size()) return true;
    if (j > 0 && !is_visit[i][j - 1] && word[lay] == board[i][j - 1]) {
        is_visit[i][j - 1] = true;
        if (getFullPath(board, word, lay + 1, i, j - 1)) return true;
        is_visit[i][j - 1] = false;
    }
    if (j < col - 1 && !is_visit[i][j + 1] && word[lay] == board[i][j + 1]) {
        is_visit[i][j + 1] = true;
        if (getFullPath(board, word, lay + 1, i, j + 1)) return true;
        is_visit[i][j + 1] = false;
    }
    if (i < raw - 1 && !is_visit[i + 1][j] && word[lay] == board[i + 1][j]) {
        is_visit[i + 1][j] = true;
        if (getFullPath(board, word, lay + 1, i + 1, j)) return true;
        is_visit[i + 1][j] = false;
    }
    if (i >  0 && !is_visit[i - 1][j] && word[lay] == board[i - 1][j]) {
        is_visit[i - 1][j] = true;
        if (getFullPath(board, word, lay + 1, i - 1, j)) return true;
        is_visit[i - 1][j] = false;
    }
    return false;
}

bool findString(vector<vector<char>>& board, string word, unsigned int lay) {
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == word[lay] && !is_visit[i][j]) {
                is_visit[i][j] = true;
                if (getFullPath(board, word, lay + 1, i, j)) {
                    return true;
                }
                is_visit[i][j] = false;
            }
        }
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    if (board.empty())
        return false;
    raw = board.size(), col = board[0].size();
    for (int i = 0; i < raw; i++) {
        vector<bool> temp;
        for (int j = 0; j < col; j++) {
            temp.push_back(false);
        }
        is_visit.push_back(temp);
    }
    int lay = 0;
    return findString(board, word, lay);
}