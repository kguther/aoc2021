class DiracDie:
    OUTCOMES = [1, 2, 3]

    def __init__(self):
        self.rolls = []
        for first in self.OUTCOMES:
            for second in self.OUTCOMES:
                for third in self.OUTCOMES:
                    self.rolls.append(first + second + third)

    def roll(self):
        return self.rolls