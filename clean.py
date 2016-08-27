# A script to remove all output files.
# http://stackoverflow.com/a/6996628/5415895

import os
import shutil
import glob

# http://stackoverflow.com/a/5137509/5415895
project_dir = os.path.dirname(os.path.realpath(__file__))

#print project_dir

# Delete _build directory.
shutil.rmtree(project_dir + "/_build")
print "_build deleted."

# Remove all *.so files in web directory.
# http://stackoverflow.com/a/5532521/5415895
for fl in glob.glob(project_dir + "/web/*.so"):
#{
	print "Removing " + fl
	os.remove(fl)
#}

# Remove *.pyc files in web/src directory.
for fl in glob.glob(project_dir + "/web/src/*.pyc"):
#{
	print "Removing " + fl
	os.remove(fl)
#}

# Remove *.pyc files in web/src/views directory.
for fl in glob.glob(project_dir + "/web/src/views/*.pyc"):
#{
	print "Removing " + fl
	os.remove(fl)
#}