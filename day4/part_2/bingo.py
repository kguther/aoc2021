import numpy


class BingoBoard:
    def __init__(self, board_array):
        self._board_array = board_array
        self._marker_array = numpy.zeros((5, 5), bool)
        self.has_won = False

    def mark_number(self, marked_value):
        pos = numpy.where(self._board_array == marked_value)
        x = pos[0]
        y = pos[1]
        if x.size > 0:
            self._marker_array[x[0]][y[0]] = True

    def bingo(self):
        return self._bingo_rows(self._marker_array) or self._bingo_rows(self._marker_array.transpose())

    def win(self):
        self.has_won = True

    def _bingo_rows(self, marker_array):
        for row in marker_array:
            if all(row):
                return True
        return False

    def points(self, draw):
        return numpy.sum(self._board_array[numpy.logical_not(self._marker_array)]) * draw
