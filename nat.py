
import requests 
image_url = "https://images.app.goo.gl/cqpYyzdxRuXpJYHs9"

r = requests.get(image_url) # create HTTP response object 

with open("python_logo.png",'wb') as f: 

	
	f.write(r.content) 
