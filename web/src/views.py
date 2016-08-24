from markovp import Markov
from forms import Markov_Form
from flask import Flask, render_template, request, redirect, url_for, jsonify, make_response

from src import app

# Index.
@app.route("/")
def index():
#{
    form = Markov_Form()
    return render_template('form.html', form = form)
#}

# The submission page.
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

            return render_template("output.html", input = str(text), output = output)
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

# A REST method.
@app.route("/api", methods=["GET"])
def api():
#{
    # Get GET args.
    input_text = request.args.get('input_text')
    mark = Markov(str(input_text), 1)
    
    return mark.generate()
#}

# Handle errors.
# http://blog.miguelgrinberg.com/post/designing-a-restful-api-with-python-and-flask
@app.errorhandler(404)
def not_found(error):
#{
    return make_response(jsonify({'error': 'Not found'}), 404)
#}

# Test the Markov generator.
#filename = "../Markov/text/nodejs.txt"
#f = open(filename, 'r')
#mark = Markov(f.read(), 1)
#print(mark.generate())
#f.close()