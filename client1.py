import socket # for socket 
import requests 

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((socket.gethostname(),1234))
image_url = "https://lh3.googleusercontent.com/u78cGo_8fOTThE79PNQMvX436-gDxY82ChVn5OpnOjRx6cKLrIP9fbvCCVzUwdk6uAM=s360-rw"

r = requests.get(image_url) # create HTTP response object 

with open("download.png",'wb') as f: 

	
	f.write(r.content) 

print('connected to the server \n Receiving the file')
with open("got.txt",'wb') as f:
	while True:
		data = s.recv(1024)
		if data:
			f.write(data)
		else:
			print("file received and Downloaded!!!")
			f.close()
			break

 

