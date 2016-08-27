from flask import Flask
import forms
from views.home import home
from views.buzzfeed_titles import buzzfeed_titles
from views.api import api

app = Flask(__name__)
app.secret_key = 'development key'

# Register blueprints.
app.register_blueprint(home)
app.register_blueprint(buzzfeed_titles)
app.register_blueprint(api)