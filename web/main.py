#import markovp
import os
from flask import Flask, render_template
app = Flask(__name__)

@app.route("/")
def main():
    return render_template('index.html')

if __name__ == "__main__":
    app.run()

# Test the Markov generator.
#filename = "nodejs.txt"
#f = open(filename, 'r')
#mark = markovp.Markov(f.read(), 1)
#print(mark.generate())