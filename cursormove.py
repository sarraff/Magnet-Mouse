import time
import pyautogui
pyautogui.FAILSAFE= False
import turtle
turtle.setworldcoordinates(0, -1080, 1920, 0)
turtle.speed(3)
turtle.pensize(15)
turtle.color("#44ebb6")
turtle.st()
turtle.shape("square")

def chaap():
	turtle.down()
def no_chaap():
	turtle.up()

def bhaga_turtle(x,y):
	x*=1920/88
	y*=-1080/38
	if(x<1920 and y>-1080 and x>0 and y<0):
		turtle.goto(x,y)

def move_cursor(x,  y):
	x*=1920/88
	y*=1080/50
	if(x<1920 and y<1080):
		pyautogui.dragRel(int(x), int(y), duration = 0) 
		#print(pyautogui.position())
	#pyautogui.click(x, y) 


def click_cursor(x,  y):
	
	x*=1920/88
	y*=1080/50
	if(x<1920 and y<1080):
		pyautogui.moveTo(x, y, duration = 0)
		#print(pyautogui.position())
		pyautogui.click(x, y) 


#move_cursor(88,50)
#move_cursor(100,200)
#click_cursor(100,100)