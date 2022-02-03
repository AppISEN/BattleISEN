#******************************************************
#*                                                    *
#*            Solution par Youn Mélois                *
#*                                                    *
#******************************************************

#*******
#* Read input from STDIN
#* Use print to output your result to STDOUT.
#* ***/
import sys

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

lines = lines[2:]
lines = list(map(lambda x: list(map(int, x.split(" "))), lines))

print(len(list(filter(lambda x: sum(x)/len(x) < 0.9, lines))))