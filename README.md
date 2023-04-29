<<<<<<< HEAD
# How To Compile
=======
# minesweeper
## Intro
- 踩地雷是一款經典的電腦遊戲，玩家需透過揭開方塊，避免踩到地雷，同時藉由周圍的數字推測哪些方塊為地雷，直到所有空白方塊都被開啟就為獲勝，踩到地雷就算失敗。
- 每格的數字代表其9宮格內含有的炸彈數量
- 玩家可以放置旗幟或問號來輔助判斷

## Features
### 主功能
- [x] 載入盤面檔
- [x] 指令檔模式：輸入指令檔，將所有輸出寫入輸出檔
### 加分功能
- [x] 隨機盤面生成
- [x] 指令模式：用cin輸入指令，cout輸出指令
- [x] GUI模式：開啟GUI遊玩
## How to compile
>>>>>>> origin/main
- 確保有QT6.5版本以上，且能開啟，有qt core與gui套件
- 能使用qmake
- c++17，或更新版本
- 進入qt點開啟專案，選minesweeper.pro打開專案後點選左下角綠色箭頭即可編譯
<<<<<<< HEAD
=======

## How to run
- 載入盤面檔：minesweeper.exe CommandFile <輸入指令檔> <輸出檔>
- 輸入指令模式：minesweeper.exe CommandInput
- GUI：minesweeper.exe GUI，或是點minesweeper.exe即可開啟

## Current Arch
<img width="298" alt="截圖 2023-04-12 上午1 09 11" src="https://user-images.githubusercontent.com/69885352/231238520-4e8f57ab-4093-4bc4-b89a-6221db00d8a4.png">

## File and Dir
### main.cpp
- 載入與顯示起始ui(mainwindows)
### mainwindows
- 一開始為startui，遊戲開始後轉為game，使用stackWidget
### assignboard
- 用來改變指定炸彈盤面和指定炸彈生成率盤面，使用stackWidget
### mineamountboard
- 指定炸彈數量盤面
### minerateboard
- 指定炸彈生成率盤面
### mybutton
- 繼承QPushButton，實作左鍵與右鍵觸發事件
### originboard
- 載入盤面檔
### startui
- 一開始的ui
### game
- 進入遊戲後
### minesweeper.pro
為qmake，是qt版的cmake
### Resources.qrc
裡面包含了boards資料夾的東西，原始盤面，images資料夾，圖片檔與gif動畫檔
### boards dir
裡面是放一些原始盤面，board1.txt~board5.txt
還有pri和qrc檔，用來表示在Resources裡面
### images dir
裡面放一些圖片檔與gif，炸彈、爆炸動畫、旗子、問號

>>>>>>> origin/main
