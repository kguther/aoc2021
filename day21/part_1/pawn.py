class Pawn:
    BOARD_SIZE = 10

    def __init__(self, starting_position):
        self._pos = starting_position
        self._score = 0

    def move(self, die):
        step_size = 0
        for i in range(3):
            step_size += die.roll()
        self._pos += step_size
        self._pos = (self._pos - 1) % self.BOARD_SIZE + 1
        self._score += self._pos

    def total_score(self):
        return self._score
