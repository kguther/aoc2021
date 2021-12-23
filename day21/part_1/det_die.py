class DetDie:
    def __init__(self):
        self._state = 0

    def roll(self):
        self._state += 1
        return (self. _state - 1) % 100 + 1

    def roll_count(self):
        return self._state
