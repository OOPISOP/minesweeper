# minesweeper

## current arch
<img width="298" alt="截圖 2023-04-12 上午1 09 11" src="https://user-images.githubusercontent.com/69885352/231238520-4e8f57ab-4093-4bc4-b89a-6221db00d8a4.png">

## File
### main.cpp
載入與顯示起始ui(mainwindows)
### mainwindows
是目前僅存的ui設定檔，名字可以改啦，還沒想好叫什麼
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
