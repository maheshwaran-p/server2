import socket  
import requests 

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((socket.gethostname(),1234))
s.listen(5)
filePath ="C:\Users\Mirna\downloads\mytext.txt"
file = open(filePath,'rb')
clientsocket ,address = s.accept()
print("listening for client and ready to upload the file")
l = file.read(1024)
while l:
	clientsocket.send(bytes(l))
	l = file.read(1024)
print("upload completed")
  

