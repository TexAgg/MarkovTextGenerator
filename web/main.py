import markovp

filename = "nodejs.txt"
f = open(filename, 'r')

mark = markovp.Markov(f.read(), 1)
print(mark.generate())