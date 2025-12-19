
Purpose: readfile is used as a command line interface to output file contents.
It can be used to read a file to the terminal stdout, or into another command, or piped to a new file.
For example: readfile -f myfile.txt >> newfile.txt (or) spawnex -- readfile -f myfile.txt 

Usage: myprogram [OPTIONS]
Options:
  --help, -h    Display this help message
  --version, -v Display program version
  --input, -f FILENAME  Specify an input file to open.

Report bugs or suggestions to Rick Malik, fcinstaller@gmail.com, subj:readfile-bug-report.
