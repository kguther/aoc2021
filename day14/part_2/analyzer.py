from collections import defaultdict


class Analyzer:
    def __init__(self, bounds):
        self._bounds = bounds

    def occurrence_diff(self, polymer):
        occurrences = self._get_occurrences(polymer)
        max_letter = max(occurrences, key=occurrences.get)
        min_letter = min(occurrences, key=occurrences.get)
        max_value = self._boundary_corrected_occurence(max_letter, occurrences)
        min_value = self._boundary_corrected_occurence(min_letter, occurrences)
        return max_value - min_value

    def _boundary_corrected_occurence(self, letter, occurrences):
        value = occurrences.get(letter)
        if letter in self._bounds:
            value += 0.5
        return value

    def _get_occurrences(self, polymer):
        letter_counts = defaultdict(int)
        for pair, count in polymer.pairs.items():
            for letter in pair:
                letter_counts[letter] += count * 0.5

        return letter_counts