# Forms module.

from flask_wtf import Form
from wtforms import TextField, TextAreaField, SubmitField, validators

class Markov_Form(Form):
#{
	input_text = TextAreaField("Input text:", id = "inputText")
	submit_button = SubmitField("Submit")
#}