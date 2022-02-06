Data Structure final assignment（a airline system） during bachelor's degree
資料結構期末專題
專題主題 :實作一個航班系統

一、動機與目的
我所設計的是一個航班系統，使用者可以選擇航空公司或顧客兩種進入方式。提供給航空公司發佈和刪除航班信息，同時顧客可以通過此系統以多種方式瀏覽和查找航空公司所發佈的航班信息。
因爲我是外籍生，所以每個學期都需要搭乘飛機來臺灣上學，難免會經由網絡搜索和購買機票，由此激發我想設計一個航班系統。
設計此系統的目的是：
1、提供買賣雙方一個交易的平臺。
2、提供給顧客從多方面瞭解航班信息之便利。
3、提供給航空公司管理航班之便利。
4、爲顧客提供多種到達目的地的途徑。

二、完成功能
此系統的功能如下：
1、使用者可以選擇航空公司或顧客兩種進入方式
2、可提供航空公司添加航班信息
3、可提供航空公司刪除航班信息
4、顧客可以按照價格由低到高查看所有航班
5、顧客可以按照價格由高到低查看所有航班
6、顧客可以輸入時間查找航班信息
7、顧客可以輸入起始地和目的地查找航班
8、若顧客按地點查找航班，系統會給出此起始地到目的地的所有路徑

三、程式操作手冊
1、按下任何按鈕進入系統主界面
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image01.png)
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image02.png)

2、系統主界面
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image03.png)
 
3、按下A or a鍵進航空公司系統界面
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image04.png)

4、在此頁面按下A or a鍵增加航班
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image05.png)
 
5、此頁面按B鍵刪除航班，輸入欲刪除的航班的id刪除航班
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image06.png)

6、按照下圖添加航班，方便之後顧客通過地點查找航班時列印出兩點間所有路徑（共添加19個航班）
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image07.png)
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image08.png)

7、按E返回主界面，再按B進入顧客界面
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image09.png)
 
8、在此界面按A以價格由低到高顯示所有航班
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image10.png)

9、在此界面按B以價格由高到低顯示所有航班
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image11.png)

10、在此界面按C輸入日期查找航班
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image12.png)

11、在此界面按D並輸入起始地點d，目的地g，系統列印出d到g的所有路徑
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image13.png)
 
12、主界面按E退出該系統
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image14.png)

四、系統設計
本程式所使用的資料結構有：stack、linked list、AVL Tree、Graph，使用到的演算法是樹排序。
之所以選擇使用AVL Tree來實作資料結構，是因爲AVL Tree能夠在樹的內容修改時，透過旋轉自動調節其高度，使得搜索成本降低。同時AVL Tree兼有二元樹的特性，使得資料可以比較容易依照大小排列顯示出來。在實作AVL Tree時我用到了linked list，因爲連結串列不需要連續的記憶體，所以在比較大的資料輸入時，不會出現資料溢出的情況。 爲了實現找出兩點間所有路徑的方法，本系統使用Adjacent Matrix實作出一幅圖，並運用到stack來協助實現這一功能。本程式所用的排序演算法是樹排序，原因是樹排序是建基於二元搜尋樹，不用另外設計其他的排序演算法，降低程式設計成本。  
![image](https://github.com/JiaqiFeng99/data-structure-assignment/blob/main/pics/image15.png)
