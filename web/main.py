from markovp import Markov
from forms import Markov_Form
import os
from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)
app.secret_key = 'development key'

@app.route("/")
def index():
#{
    form = Markov_Form()
    return render_template('form.html', form = form)
#}

@app.route("/submit", methods=["GET"])
def submit():
#{
    if request.method == "GET":
    #{
        if request.args.get('submit_button'):
        #{    
            # Get form values.
            # http://stackoverflow.com/a/20341272/5415895
            text = request.args.get("input_text")
            # We have to cast text as a string, otherwise C++ complains.
            mark = Markov(str(text), 1)
            output = mark.generate()

            return render_template("output.html", output = output)
        #}
        else:
        #{
            # Make sure nobody can access the submit path without submitting.
            return redirect(url_for('index'))
        #}
    #}
    else:
    #{
        return redirect(url_for('index'))
    #}
#}

if __name__ == "__main__":
#{ 
    app.run()
#}

# Test the Markov generator.
filename = "../Markov/text/nodejs.txt"
f = open(filename, 'r')
mark = Markov(f.read(), 1)
print(mark.generate())