# 3 axis CNC Plotter remote control by mobile phone <br> (made with a CD Player) <img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-made-with-a-CD-Player/blob/master/media/Prototype.png" width=20% align="right"/>
利用光碟機馬達所製作的三軸繪圖機。


<br>


## 目錄 Table of Content
* [裝置設計 Device Design](#裝置設計-Device-Design)
  * 使用元件
  * 馬達IC選用與電路圖
  * 平台設計
* [程式設計 Programming](#程式設計-Programming)
  * 程式流程
  * App Inventor 開發程式 與 Arduino藍芽模組連接
* [Prototype](#Prototype)


<br> 


## 裝置設計 Device Design
### 使用元件
* **廢棄的光碟機：**  <br>
二手廢棄的光碟機大部分都是讀寫的雷射頭壞掉，裡面的控制馬達大部分都是好的。裡面的馬達屬於雙極性步進馬達，可利用馬達控制模組加以操控。<br>
這裡將光碟機的兩個步進馬達分別拿來做繪圖機的**x、y軸控制**。
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/CDPlayer.png" width=50%/>

<br>

* **Arduino UNO：** 
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/ARDUINO_UNO_DIP_01.png" width=50%/>

<br>

* **伺服馬達：** <br>
透過訊號線傳送PWM脈波來控制軸柄的停止位置旋轉角度，這個訊號脈波必須每秒重複50次（也就是50Hz），而脈衝持續時間長短便代表了馬達該將軸柄轉到什麼位置。 <br>
這裡將伺服馬達做為繪圖機的**y軸控制**。
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/Servo.png" width=50%/>

<br> 

* **L293D(2個)：** <br>
L293D可控制最多4個DC馬達或單個步進馬達，一般用來控制2個馬達作正轉及反轉,並可由PWM控制轉速。<br>
這裡使用L293D來進行**馬達控制模組設計**。

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/L293D.png" width=10%/>

<br> 

* **藍芽模組 HC-06：** <br>
使用手機連結藍芽模組，操控繪圖機。

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/Bluetooth%20model.png" width=20%/>

<br> 

* **降壓模組 mp1584en：** <br>
考慮供電問題，使用12V電池供電，因Arduino輸入電壓為5V，故使用降壓模組，將12V降為5V來驅動Arduino。

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/mp1584en%20model.png" width=20%/>


<br> 


### 馬達IC選用與電路圖 <br>
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/L293D_Model.png" width=20% align="right"/>
<br> 

原定直接使用市面上販售的L293D馬達控制模組，但因為以下理由，而改用其他方案： <br> 
* 一塊馬達控制版**占掉整塊UNO板腳位**，導致其它腳位無法使用。 <br> 

* 馬達控制板除了可以控制多顆伺服馬達及多顆步進馬達以外，沒有其他進階功能，但是這裡**只需控制2個步進及1個伺服馬達**，剩下的控制腳位沒有用到。<br><br>


> 解決方案:  <br> 
**直接使用兩個L293D晶片來做馬達控制模組設計。** <br> <br>
如前所述，L293D可控制最多4個DC馬達或單個步進馬達，一般用來控制2個馬達作正轉及反轉,並可由PWM控制轉速。由於**雙H橋設計**可使得輸出電流、電壓相反(可控制雙極性步進馬達)，且可同時控多顆馬達的特性，成為我們考慮使用此IC的原因。 <br> 

<p align="center"><img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/Doul-H.png" width=50% >
<br> <p align="center"> 雙H橋設計 <br><br>

<p align="center"><img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/CircuitFinal.png" width=90% >
<br> <p align="center"> 馬達驅動電路設計 <br><br>

<p align="center"><img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/Circuit_.png" width=60% >
<br> <p align="center"> 實際接線圖 <br><br>

<br>


### 平台設計
* 拆卸馬達後，焊接單心線連至麵包版上進行控制

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/CDPlayer2.png" width=50%/>
<br>

* 使用廢棄木材製作繪圖平台

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/xyAxis.png" width=50%/>
<br>

* 使用L型鐵片固定z軸

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/L_metal.png" width=30%/>
<br>

* 利用彈簧及樂高零件組成一個可動開關，藉由馬達的控制，Z軸的筆會回到原本的位置。

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/zAxis.png" width=40%/>
<br>


<br>


## 程式設計 Programming
### 程式流程
* Main Flow
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/PictureAnalysisFlow.png" width=60%/>
<br>

* Gcode Execute Flow
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/GcodeExecuteFlow.png" width=70%/>
<br>

* App Pass Message Flow
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/AppFlow.png" width=70%/>
<br>

### App Inventor 開發程式 與 Arduino藍芽模組連接
* **App Inventor** —— 用於建置app的圖形化介面開發環境。<br>
此處利用他先開發了兩種APP，其一是僅一執行按鈕去執行繪圖動作，其二是直接操控三軸繪圖機做前、後、左、右移動及起筆、落筆動作，最後再將兩者結合。 <br> 

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/APP_Window1.png" width=30% ><img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/APP_Window2.png" width=32% >

<br>
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/App_Block1.png" width=60% > <br>

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/App_Block2.png" width=80% >
<br>
<br>

* **Arduino藍芽模組連接** 

由於Arduino並沒有Serial1的序列埠，因此我們重設了新的序列埠BTSerial，而經測試過後，發現Arduino本身的Tx,Rx輸出入腳(PIN0,PIN1)，會有bug導致程式無法燒錄，故又自行定義了新的Tx,Rx(PIN12,PIN13)，此外，包率經過測試，改為57600。

> 程式碼請參照此：[Arduino藍芽連接程式碼](https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/BluetoothForPrinter_self_control.ino)

<br>
<br>



## Prototype
* Mobile Phone Control
<br> <a href="https://youtu.be/gG9Y0EEsjDo" target="_blank"><img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/MobilePhoneControl.png" 
width=30% /></a>
<br> 點擊圖像觀看影片
<br>

* Plotting
<br> <a href="https://youtu.be/-ubjCdSmq3U" target="_blank"><img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/Plotting.png" 
width=70% /></a>
<br> 點擊圖像觀看影片
<br>
