# This script takes a text file,
# and inserts a word after every other word,
# and writes the output to a new text file.
# This is to test the add_input function of Markov.

# The directory where the text files are.
text_dir = ""
# The input file name.
input_file_name = "nodejs.txt"

# The input file object.
input_file = open(text_dir + input_file_name, 'r')

# The text from the input file.
input_text = input_file.read()
input_file.close()

# A list of all the words from the input file.
# http://stackoverflow.com/a/743807/5415895
words = input_text.split()

# http://stackoverflow.com/a/5656097/5415895
def joinit(iterable, delimiter):
#{
    it = iter(iterable)
    yield next(it)
    for x in it:
	#{
        yield delimiter
        yield x
	#}
#}

new_word = "harambe"
# http://stackoverflow.com/a/231855/5415895
gen = joinit(words, new_word)

output_file_name = "nodejs2.txt"
output_file = open(text_dir + output_file_name, 'w')

# http://stackoverflow.com/a/899176/5415895
for item in gen:
#{
	output_file.write("%s " % item)
	print item
#}
output_file.close()