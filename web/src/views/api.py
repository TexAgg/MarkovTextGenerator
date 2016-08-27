from markovp import Markov
from src.forms import Markov_Form
from buzzfeed import get_feed, get_titles
from flask import Flask, render_template, request, redirect, url_for, jsonify, make_response, Blueprint
import json

api = Blueprint("api", __name__)

# A REST method.
@api.route("/api", methods=["GET"])
def api_route():
#{
    # Get GET args.
    input_text = request.args.get('input_text')
    mark = Markov(str(input_text), 1)
    
    return mark.generate()
#}

# Handle errors.
# http://blog.miguelgrinberg.com/post/designing-a-restful-api-with-python-and-flask
@api.errorhandler(404)
def not_found(error):
#{
    return make_response(jsonify({'error': 'Not found'}), 404)
#}