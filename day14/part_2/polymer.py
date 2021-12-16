from collections import defaultdict


class Polymer:
    def __init__(self):
        self.pairs = defaultdict(int)

    def add_pair(self, pair, count):
        self.pairs[pair] += count

    @classmethod
    def from_string(cls, string):
        polymer_pairs = defaultdict(int)
        for i in range(len(string) - 1):
            polymer_pairs[string[i:i + 2]] += 1

        polymer = Polymer()
        polymer.pairs = polymer_pairs
        polymer.first_pair = string[0:2]
        polymer.last_pair = string[-2:]
        return polymer


