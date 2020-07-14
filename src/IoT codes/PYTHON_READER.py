#This python script is used to read the data sent by the esp8266 over the local host and store the values in a text file, as per the name of the node.

import urllib.request
url = "http://192.168.137.31/"  # ESP's url, ex: https://192.168.102/ (Esp serial prints it when connected to wifi)

def get_data():
	global data

	n = urllib.request.urlopen(url).read() # get the raw html data in bytes (sends request and warn our esp8266)
	n = n.decode("utf-8") # convert raw html bytes format to string :3
	
	# data = n
	data = n.split() 			#<optional> split datas we got. (if you programmed it to send more than one value) It splits them into seperate list elements.
#	data = list(map(int, data)) #<optional> turn datas to integers, now all list elements are integers.

# Example usage
while True:
	get_data()
	#print("Your data(s) which we received from arduino: "+data)
	print(data)
	input("To test it again press enter.")

	f = open("node11.txt", "w")
	fullstr=' '.join(data)
	f.write(fullstr)
	f.close()


	f = open("node11.txt", "r")
	print("this is the first line")
	print(f.read())	
 	


