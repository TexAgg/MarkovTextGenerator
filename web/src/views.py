# The main router for the web app.
# This file is disgusting and unorganized.

from markovp import Markov
from forms import Markov_Form
from buzzfeed import get_feed, get_titles
from flask import Flask, render_template, request, redirect, url_for, jsonify, make_response
import json

# http://stackoverflow.com/a/21190382/5415895
import sys  
reload(sys)  
sys.setdefaultencoding('utf8')

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

# Display Markovishly generated buzzfeed titles.
@app.route("/buzzfeed")
def buzzfeed():
#{
    feed = get_feed()
    j_feed = json.loads(feed)

    # Get a list of all the titles from the feed.
    # http://stackoverflow.com/questions/7271482/python-getting-a-list-of-value-from-list-of-dict
    #titles = [d['title'] for d in j_feed['big_stories']]
    titles = get_titles()

    mark = Markov(titles.pop(), 1)
    for item in titles:
        mark.add_input(item)

    # Arbitrarily limit the length of the headline to 30 words.
    return render_template("buzzfeed.html", generated_title = mark.generate(30))
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