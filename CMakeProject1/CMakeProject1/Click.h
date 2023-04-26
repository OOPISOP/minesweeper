#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int dir[8][2] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };

    int Near_Boom(vector<vector<char>>& board, int x, int y) {
        int boom = 0;
        for (int i = 0; i < 8; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx >= board.size() || nexty >= board[0].size())
                continue;
            if (board[nextx][nexty] == 'X')
            {
                boom++;
            }
        }
        return boom;
    }
    //用于获取目的位置周围的地雷数目

    void BFS(vector<vector<char>>& board, int x, int y) {
        queue<pair<int, int>> que;
        que.push(pair<int, int>(x, y));
        //定义一个队列，存放周围无地雷（即B）的情况， 队列为空则说明已经被排查完毕
        //传进来的位置必然是周围无地雷，加入队列
        while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            //获取队头元素的坐标，下面来判断其周围是有地雷还是无地雷
            for (int i = 0; i < 8; i++) {
                int nextx = x + dir[i][0];
                int nexty = y + dir[i][1];
                if (nextx < 0 || nexty < 0 || nextx >= board.size() || nexty >= board[0].size())
                    continue;
                // 坐标超出有效范围，继续下一轮循环
                if (board[nextx][nexty] == 'B') continue;
                // 已经处理过的位置，跳过，防止重复加入队列造成死循环
                int tot = Near_Boom(board, nextx, nexty);
                // 获得当前处理位置的周围地雷数目
                if (tot != 0) board[nextx][nexty] = tot + '0';
                // 周围地雷不是0， 相当于case2， 修改值（注意是char类型）
                else {
                    board[nextx][nexty] = 'B';
                    que.push(pair<int, int>(nextx, nexty));
                }
                // 相当于case3， 周围无地雷， 更改为B， 加入队列
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        //case1 如果点击的是地雷，修改为X返回即可
        int res = Near_Boom(board, x, y);
        //定义Near_Boom函数，用于求得点击位置周围的地雷数目
        if (res) {
            board[x][y] = res + '0';
            return board;
        }
        //case2 点击位置周围有地雷， 修改为地雷数量返回即可
        board[x][y] = 'B';
        BFS(board, x, y);
        //case3 点击位置周围无地雷，修改为B，然后广度优先搜索，找出它周围的位置是什么case
        return board;

    }
};