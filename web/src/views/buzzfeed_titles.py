from markovp import Markov
from flask import Flask, render_template, request, redirect, url_for, Blueprint, make_response
from buzzfeed import get_feed, get_titles
import json

# http://stackoverflow.com/a/21190382/5415895
import sys  
reload(sys)  
sys.setdefaultencoding('utf8')

buzzfeed_titles = Blueprint("buzzfeed_titles", __name__)

# Display Markovishly generated buzzfeed titles.
@buzzfeed_titles.route("/buzzfeed")
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