from functools import lru_cache


class Analyzer:
    def most_common_element_count(self, polymer):
        occurences = self._get_occurences(polymer)
        return max(occurences)

    def least_common_element_count(self, polymer):
        occurences = self._get_occurences(polymer)
        return min(occurences)

    def occurence_diff(self, polymer):
        return self.most_common_element_count(polymer) - self.least_common_element_count(polymer)

    @lru_cache
    def _get_occurences(self, polymer):
        elements = set(polymer)
        return [polymer.count(element) for element in elements]
