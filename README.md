# minesweeper
## Intro
- 踩地雷是一款經典的電腦遊戲，玩家需透過揭開方塊，避免踩到地雷，同時藉由周圍的數字推測哪些方塊為地雷，直到所有空白方塊都被開啟就為獲勝，踩到地雷就算失敗。
- 每格的數字代表其9宮格內含有的炸彈數量
- 玩家可以放置旗幟或問號來輔助判斷

## Features
### 主功能
- [x] 指令檔模式：輸入指令檔，將所有輸出寫入輸出檔

### 加分功能
- [x] 指令模式：用cin輸入指令，cout輸出指令
- [x] GUI模式：開啟GUI遊玩
## How to compile
- 確保有QT6.5版本以上，且能開啟，有qt core與gui套件
- 能使用qmake
- 進入qt點開啟專案，選minesweeper.pro打開專案後點選左下角綠色箭頭即可編譯

## Current Arch
<img width="298" alt="截圖 2023-04-12 上午1 09 11" src="https://user-images.githubusercontent.com/69885352/231238520-4e8f57ab-4093-4bc4-b89a-6221db00d8a4.png">

## File
### main.cpp
載入與顯示起始ui(mainwindows)
### mainwindows
- mainwindows.cpp 實現mainwindows
- mainwindows.h 定義mainwindows
### minesweeper.pro
為qmake，是qt版的cmake
### Resources.qrc
裡面包含了boards資料夾的東西，原始盤面
### boards dir
裡面是放一些原始盤面，board1.txt~board5.txt
還有pri和qrc檔，用來表示在Resources裡面
## current state
- [x] 起始GUI
<img width="1035" alt="截圖 2023-04-12 上午12 43 27" src="https://user-images.githubusercontent.com/69885352/231238544-e7f0c099-ddf7-485e-ac13-a2dd7aa0e8a4.png">
