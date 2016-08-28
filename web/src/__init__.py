from flask import Flask
import forms
from views.home import home
from views.buzzfeed_titles import buzzfeed_titles
from views.api import api
from flask.ext.navigation import Navigation

app = Flask(__name__)
app.secret_key = 'development key'

# Register blueprints.
app.register_blueprint(home)
app.register_blueprint(buzzfeed_titles)
app.register_blueprint(api)

# Add navbar.
# https://flask-navigation.readthedocs.io/en/latest/
nav = Navigation(app)
nav.Bar('top', [
	nav.Item("Markov Text Generator", "home.index"),
	nav.Item("Buzzfeed Titles", "buzzfeed_titles.index")
])