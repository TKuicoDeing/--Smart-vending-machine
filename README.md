# Smart-vending-machine
### 資工1B 第十二組
### *蔡承奎 
##### 負責帳密的類別撰寫，並統合程式碼
### 童冠晨 

### 黃彥慈

### Program introduction
##### 這段程式是一個簡易的智慧販賣機
##### 目前也沒有能力使用資料庫做後台
##### 一開始的註冊帳密，可以保證密碼不被外洩
##### 使用者可以嘗試不同試錯，系統會有回應喔
##### 帳密輸入成功，會進入購買商品的頁面
##### 為了讓更多人可以使用這個程式，在開頭加上了語言介面的選擇
##### 可以讓外國觀光客也能輕鬆使用
##### 接著就可以開始購買商品
##### 不同於市面販賣機，在選擇想購買的商品後
##### 會先顯示商品剩餘數量，避免供不應求的問題
##### 如果沒有注意，購買數量超出庫存
##### 會出現庫存不足的警示，讓客人重新選擇數量
##### 詢問是否繼續購買，可以讓客人繼續購買其他商品
##### 不用重複前面的流程
##### 每個段落運用清屏的功能，維持版面整齊
##### 必要時利用'sleep_for'時間函數停頓

### Rule of procedure
##### 首先註冊帳密時，不能直接點擊回車鍵
##### 字數也有限制，某些情況會直接跳出程序
##### 進入商品頁面，選擇的時候要使用商品開頭代碼來回應
##### 如果直接打中文或英文回應，頁面不會有反應
##### 使用者可以輸入投幣金額，金額必須大於0。
##### 程式會將每次投幣的金額累加到總金額中，並顯示已投入的金額。
##### 當投幣金額達到指定的金額(在主函數中的'productPrice'變數中指定）時，程序會計算找零。
##### 如果找零金額大於0，它會呼叫'Cost'類別的'addMoney'函數，將找零金額儲存在投幣器中。
##### 在每次操作之後，螢幕會被清除，以顯示更新後的狀態。
##### 當程式執行結束後，會輸出上一筆投幣金額和找零金額。

### Procedureal gameplay
##### 註冊帳密
##### 輸入密碼
##### 選擇語言
##### 選擇商品
##### 投錢
##### 回應是否繼續購買
##### Y/重複購買流程 N/結束購買

### How to install
![螢幕擷取畫面 2023-06-05 212824](https://github.com/TKuicoDeing/--Smart-vending-machine/assets/118408171/a8b002cf-77d7-4073-b231-de8d725560f0)
##### 下載解壓縮後就可以直接執行了
##### 使用Visual Studio開啟

### 註冊帳密
![image](https://github.com/TKuicoDeing/--Smart-vending-machine/assets/118408171/787d8388-6114-4d8a-82aa-68c2aa1ccf29)
![image](https://github.com/TKuicoDeing/--Smart-vending-machine/assets/118408171/81720fc1-1242-41b2-9ec0-c26348d31be2)
### 輸入密碼
![image](https://github.com/TKuicoDeing/--Smart-vending-machine/assets/118408171/d4a8c6c1-e1f9-4621-95cf-805313af5fde)
### 選擇語言
![image](https://github.com/TKuicoDeing/--Smart-vending-machine/assets/118408171/8622a9b5-2461-412a-ad27-abf1cd1d7a5e)
### 選擇商品
![image](https://github.com/TKuicoDeing/--Smart-vending-machine/assets/118408171/c33c6145-fb1f-4c68-85b3-d5cbcc46560c)
### 投幣
![image](https://github.com/TKuicoDeing/--Smart-vending-machine/assets/118408171/f279796e-f90c-4d73-b04f-0749a05339dc)
### 回應是否繼續購買
![image](https://github.com/TKuicoDeing/--Smart-vending-machine/assets/118408171/d4932073-5f44-4f70-8120-285e63ad3dd8)




