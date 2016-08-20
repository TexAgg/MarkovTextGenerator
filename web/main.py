import markovp
from forms import Markov_Form
import os
from flask import Flask, render_template, request

app = Flask(__name__)
app.secret_key = 'development key'

@app.route("/", methods = ["POST", "GET"])
def main():
#{
    form = Markov_Form()
    return render_template('index.html')
#}

if __name__ == "__main__":
#{ 
    app.run()
#}

# Test the Markov generator.
filename = "../Markov/text/nodejs.txt"
f = open(filename, 'r')
mark = markovp.Markov(f.read(), 1)
print(mark.generate())