# Markov Text Generator
A [Markov](https://en.wikipedia.org/wiki/Markov_chain) text generator.
Takes in input and produces realistic seeming gibberish.

---

## Instructions

### Building
Requires [Boost](http://www.boost.org/) and [cpprest](https://github.com/Microsoft/cpprestsdk).
In the root directory,
type
```
mkdir _build
cd _build
cmake ..
```
Then, depending on your OS, type `make` or open the project in Visual Studio.

### Running

#### Command Line App
The command line app is called `Main`,
and it takes a command-line argument which is the file to read from.
`libMarkov.so`, and `libUtility.so` must be built,
as they are shared libraries.

#### Web App
In the `web` directory,
```
python server.py
```
and open your browser to whichever location it tells you to.
In order to run `server.py`, 
`markovp.so`, `libMarkov.so`, and `libUtility.so` must be built.

---

## Todo
1. Support cases other than order 1.

---

## Resources
* A clone of this written in [PHP](https://bitbucket.org/gaikema/markovbot).
* Libraries [download](https://bitbucket.org/gaikema/markovtextgenerator/downloads).

### Markov Text Generators
* [Summary](http://stackoverflow.com/questions/4081662/explain-markov-chain-algorithm-in-laymans-terms)
* [Mark V. Shaney](http://www.yisongyue.com/shaney/)

### C++
* [Maps](http://www.cplusplus.com/reference/map/map/)

### Python
* [Flask tutorial](http://code.tutsplus.com/tutorials/creating-a-web-app-from-scratch-using-python-flask-and-mysql--cms-22972)
* [WTForms tutorial](http://www.tutorialspoint.com/flask/flask_wtf.htm)