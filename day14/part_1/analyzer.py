from functools import lru_cache


class Analyzer:
    def most_common_element_count(self, polymer):
        occurrences = self._get_occurrences(polymer)
        return max(occurrences)

    def least_common_element_count(self, polymer):
        occurrences = self._get_occurrences(polymer)
        return min(occurrences)

    def occurrence_diff(self, polymer):
        return self.most_common_element_count(polymer) - self.least_common_element_count(polymer)

    @lru_cache
    def _get_occurrences(self, polymer):
        elements = set(polymer)
        return [polymer.count(element) for element in elements]
