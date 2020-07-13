from flask import Flask, render_template, request
import random

f = open("node11.txt", "r") //file handling, reading from the file according to the node that is desired.
print("this is the first line")
if f.mode == 'r':
  ini_array=f.readline() 
  temp_array=f.readline()
print("printing the initial array")
print(ini_array) # ini_array is a string
print(temp_array)

def convert(string):
  li=list(string.split(" "))
  return li

greetOut=convert(ini_array)
print("printing greetout")
print(greetOut[0])


# final_array=ini_array.astype(np.float)
# print("this is the final array")
# print(final_array[0])

app = Flask(__name__, template_folder='templates')


@app.route('/', methods=['GET','POST'])
def samplefunction():
    if request.method == 'GET':
        return render_template('home.html')
    if request.method == 'POST':
        greetIn = ['1', '2', '3', '4', '5', '6', '7', '8','9']
        # greetOut = [45, 50, 12, 23, 34, 45, 56, 67, 78]
        node1 = request.form['node']
        
        if node1 in greetIn:
            if node1=="1":
              bot1= greetOut[int(node1)-1]
              
              return render_template('home.html', bot1=bot1)
            
            elif node1=="2":
              bot2= greetOut[int(node1)-1]
              return render_template('home.html', bot2=bot2)

            elif node1=="3":
              bot3= greetOut[int(node1)-1]
              return render_template('home.html', bot2=bot3)

            elif node1=="4":
              bot4= greetOut[int(node1)-1]
              return render_template('home.html', bot2=bot4)

            elif node1=="5":
              bot5= greetOut[int(node1)-1]
              return render_template('home.html', bot2=bot5)  
            
            elif node1=="6":
              bot6= greetOut[int(node1)-1]
              return render_template('home.html', bot2=bot6)

            elif node1=="7":
              bot7= greetOut[int(node1)-1]
              return render_template('home.html', bot2=bot7)
            
            elif node1=="8":
              bot8= greetOut[int(node1)-1]
              return render_template('home.html', bot2=bot8)

            elif node1=="9":
              bot9= greetOut[int(node1)-1]
              return render_template('home.html', bot2=bot9)

        else:
            render_template('home.html')

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)

