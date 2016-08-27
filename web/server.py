# Run this to run the web server.

from src import app
app.run(debug=True)

# I don't know if I need this but I'm too scared to delete it.
# http://stackoverflow.com/questions/419163/what-does-if-name-main-do
if __name__ == "__main__":
#{ 
    app.run()
#}