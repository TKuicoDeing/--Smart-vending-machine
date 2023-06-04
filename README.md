# Smart-vending-machine
### 資工1B 第十二組
### *蔡承奎 童冠晨 黃彥慈

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
##### 如果沒有注意，購賣數量超出庫存
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

### Procedureal gameplay
##### 註冊帳密
##### 輸入帳密
##### 選擇語言
##### 選擇商品
##### 投錢
##### 回應是否繼續購買
##### Y/重複購買流程 N/結束購買
