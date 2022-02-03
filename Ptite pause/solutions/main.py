#Code issue d'une épreuve de BattleDev

#!/usr/bin/env python3

N, M, C = map(int, input().split())

gems = []
for i in range(N):
    gems.append(tuple(map(int, input().split())))

powders = []
for i in range(M):
    powders.append(tuple(map(int, input().split())))

# From https://codereview.stackexchange.com/questions/20569/dynamic-programming-knapsack-solution

from functools import lru_cache

def knapsack(items, maxweight):
    """Solve the knapsack problem by finding the most valuable subsequence
    of items that weighs no more than maxweight.

    items must be a sequence of pairs (value, weight), where value is a
    number and weight is a non-negative integer.

    maxweight is a non-negative integer.

    Return a pair whose first element is the sum of values in the most
    valuable subsequence, and whose second element is the subsequence.

    >>> items = [(4, 12), (2, 1), (6, 4), (1, 1), (2, 2)]
    >>> knapsack(items, 15)
    (11, [(2, 1), (6, 4), (1, 1), (2, 2)])

    """
    @lru_cache(maxsize=None)
    def bestvalue(i, j):
        # Return the value of the most valuable subsequence of the first
        # i elements in items whose weights sum to no more than j.
        if j < 0:
            return float('-inf')
        if i == 0:
            return 0
        value, weight = items[i - 1]
        return max(bestvalue(i - 1, j), bestvalue(i - 1, j - weight) + value)

    j = maxweight
    result = []
    for i in reversed(range(len(items))):
        if bestvalue(i + 1, j) != bestvalue(i, j):
            result.append(items[i])
            j -= items[i][1]
    result.reverse()
    return bestvalue(len(items), maxweight), result

# Store the remaining space of the backpack
gems = knapsack(gems, C)[1]
remaining_space = C - sum([gem[1] for gem in gems])

def density(x):
    if x[1] == 0:
        return float("inf")
    return float(x[0]) / float(x[1])

# Sort selected gems and powders by decreasing density
gems = sorted(gems, key=density, reverse=True)
powders = sorted(powders, key=lambda x: x[0], reverse=True)

# Try replace gems by powders with a greedy approach
def fill_with_powders(weight, powders):
    value = 0
    for i in range(len(powders)):
        powder_currency, powder_weight = powders[i]
        if powder_weight <= weight:
            value  += powder_currency * powder_weight
            powders[i] = (powder_currency, 0)
            weight -= powder_weight
        else:
            value += powder_currency * weight
            powders[i] = (powder_currency, powder_weight - weight)
            break
    return value, powders

# Fill remaining space with powder
total, powders = fill_with_powders(remaining_space, powders)

# Then, we start with least interesting gems VS most interesting powders
for gem_value, gem_weight in reversed(gems):
    powder_value, powders = fill_with_powders(gem_weight, powders)
    if gem_value < powder_value:
        total += powder_value
        gems.pop()
    else:
        break

# Finally we add gems to the total and print the result
print(total + sum([gem[0] for gem in gems]))
