from statistics import median

from syntax_checker import SyntaxChecker


class FileScorer:
    def __init__(self):
        self._checker = SyntaxChecker()

    def score_file(self, filename):
        scores = []
        with open(filename, "r") as sf:
            for line in sf:
                score = self._checker.get_line_score(line)
                if score > 0:
                    scores.append(score)

        return self._get_middle_score(scores)

    def _get_middle_score(self, scores):
        return median(scores)
