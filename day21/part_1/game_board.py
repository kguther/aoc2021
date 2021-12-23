from pawn import Pawn


class GameBoard:
    def __init__(self, start_one, start_two, die, score):
        self._pawns = [Pawn(start_one), Pawn(start_two)]
        self._die = die
        self._winning_score = score

    def play(self):
        game_running = True
        while game_running:
            for pawn in self._pawns:
                pawn.move(self._die)
                if pawn.total_score() >= self._winning_score:
                    game_running = False
                    break

        return self._score()

    def _score(self):
        losing_score = min(pawn.total_score() for pawn in self._pawns)
        return losing_score * self._die.roll_count()

