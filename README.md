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
  * App Inventor 開發程式
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
如前所述，L293D可控制最多4個DC馬達或單個步進馬達，一般用來控制2個馬達作正轉及反轉,並可由PWM控制轉速。由於**雙H橋設計**可使得輸出電流、電壓相反，且可同時控多顆馬達的特性，成為我們考慮使用此IC的原因。 <br> 

<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/Doul-H.png" width=50% align="center"/>

<br> 








