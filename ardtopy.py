import serial
from Arduino import Arduino
import time
import math
import cursormove

a1 = serial.Serial('COM5',baudrate = 9600,timeout=.1)
a2 = serial.Serial('COM6',baudrate = 9600,timeout=.1)
#myArd = Arduino("9600",port="COM5" )
i=0
xx1 = 0
yy1=0
while i<1000:
	# if myArd.digitalRead(12) == "LOW":
	# 	print("\t\tSHAKALAKA BOOM BOOM\n")
	flag = False
	data1 = a1.readline()
	data2 = a2.readline()
	#print(data)
	i+=1
	#8.71 , 21,12, 123.12
	Nishant2 = 0
	b2 =0
	if (len(data1)>5):
	    Nishant1=str(data1)
	    # if("LOW" in Nishant1):
	    # 	flag =True
	    # else:
	    rece = Nishant1[2:len(Nishant1)-5]
	    if(len(rece) <7):
		    if(rece[-1] =="L"):
		    	Nishant2=float(rece[:-1])
		    	flag =True
		    else :
		    	Nishant2=float(rece)
		    print("Data2: ", rece)

	if (len(data2)>5):
	    b1=str(data2)
	    rece2=b1[2:len(b1)-5]
	    if(len(rece2) <7):
	    	b2=float(rece2)
	    else:
	    	b2=0
	    print("Data1: ", b2)
	if(b2>0 and Nishant2>0):
		d22= Nishant2*Nishant2
		d12 = b2*b2
		xx = (d12-d22+1056)/24
		yy = math.sqrt(abs(d22-((xx-50)*(xx-50))))
		if(flag):
			cursormove.chaap() 
			cursormove.bhaga_turtle(int(xx),int(yy))
		else:
			cursormove.no_chaap() 
			cursormove.bhaga_turtle(int(xx),int(yy))
		#xx1=xx
		#yy1=yy
		#print(xx,yy)
	time.sleep(0.1)
#print(a1)