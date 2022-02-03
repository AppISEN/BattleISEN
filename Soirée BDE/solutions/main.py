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
import math

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

my_notes = list(map(int, lines[0].split(" ")))
num_bf = int(lines[2])
t = list()

for i, line in enumerate(lines[3:]):
	notes = list(map(int, line.split(" ")))
	s = 0
	for j in range(5):
		s += abs(my_notes[j] - notes[j])
	t.append((s, notes[5]))

t = sorted(t, key=lambda x: x[0])[:num_bf]
t = [i[1] for i in t]
print(math.floor(sum(t)/len(t)))

