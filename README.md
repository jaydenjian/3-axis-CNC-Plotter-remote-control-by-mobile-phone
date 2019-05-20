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

* **L293D(2個)：**
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/L293D.png" width=10%/>

<br> 

* **藍芽模組 HC-06：**
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/Bluetooth%20model.png" width=20%/>

<br> 

* **降壓模組 mp1584en：**
<img src="https://github.com/jaydenjian/3-axis-CNC-Plotter-remote-control-by-mobile-phone/blob/master/media/mp1584en%20model.png" width=20%/>

<br> 
