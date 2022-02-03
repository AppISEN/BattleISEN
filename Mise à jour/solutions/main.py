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

n = int(lines[0])
farmable = 0

lines = list(map(list, lines[1:]))

for i, line in enumerate(lines):
	for j in range(n):
		if (line[j] == "X"):
			try:
				if (i == 0 or j == 0):
					raise(ValueError())
				if (lines[i - 1][j - 1] not in ["X", "O"]):
					lines[i - 1][j - 1] = "O"
					farmable += 1
			except:
				pass
			try:
				if (i == 0):
					raise(ValueError())
				if (lines[i - 1][j] not in ["X", "O"]):
					lines[i - 1][j] = "O"
					farmable += 1
			except:
				pass
			try:
				if (i == 0 or j == n - 1):
					raise(ValueError())
				if (lines[i - 1][j + 1] not in ["X", "O"]):
					lines[i - 1][j + 1] = "O"
					farmable += 1
			except:
				pass
			try:
				if (j == 0):
					raise(ValueError())
				if (lines[i][j - 1] not in ["X", "O"]):
					lines[i][j - 1] = "O"
					farmable += 1
			except:
				pass
			try:
				if (j == n - 1):
					raise(ValueError())
				if (lines[i][j + 1] not in ["X", "O"]):
					lines[i][j + 1] = "O"
					farmable += 1
			except:
				pass
			try:
				if (i == n - 1 or j == 0):
					raise(ValueError())
				if (lines[i + 1][j - 1] not in ["X", "O"]):
					lines[i + 1][j - 1] = "O"
					farmable += 1
			except:
				pass
			try:
				if (i == n - 1):
					raise(ValueError())
				if (lines[i + 1][j] not in ["X", "O"]):
					lines[i + 1][j] = "O"
					farmable += 1
			except:
				pass
			try:
				if (i == n - 1 or j == n - 1):
					raise(ValueError())
				if (lines[i + 1][j + 1] not in ["X", "O"]):
					lines[i + 1][j + 1] = "O"
					farmable += 1
			except:
				pass
			


print(farmable)