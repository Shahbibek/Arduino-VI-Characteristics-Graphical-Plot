from asyncio.windows_events import NULL
from calendar import weekday
from email.utils import formatdate
from traceback import print_tb
from cvzone.SerialModule import SerialObject
from time import sleep
import mysql.connector 
import urllib.request

arduino = SerialObject()
arduino = SerialObject("COM8")
print(arduino)
while True:
    myData = arduino.getData()
    # print(myData)
    # formatedData = 100 - int(myData[0])/1023 * 100;
    if not myData:
        # print("hi")
        pass

    else:
        # print("moisture " + myData[0])
        # print(type( myData[0]))
        if float(myData[0]) > 0:
            # url = "https://sanjay.rpme.website/IoT/SoilMoistureApi/addSoilMoisture.php?temperature="+myData[0]

            # print(url)
            # webUrl = urllib.request.urlopen(url)

            print("Moisture Level: " + myData[0] +" uploaded")
            
        
        if float(myData[1]) > 0:
            print(type( myData[1]))
            # print("level "+myData[1])

            # url = "https://sanjay.rpme.website/IoT/SoilMoistureApi/addSoilMoisture.php?humidity="+myData[1]
            # print(url)
            # webUrl = urllib.request.urlopen(url)
            # # print("result code: " + str(webUrl.getcode()))
            print("Water Level: " + myData[1] +" uploaded")
    # new way



