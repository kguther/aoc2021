from collections import defaultdict
from dataclasses import dataclass
from typing import List, Tuple

WINNING_SCORE = 21


@dataclass(frozen=True)
class GameState:
    positions: Tuple[int, int]
    scores: Tuple[int, int]
    turn: int

    @property
    def winner(self):
        if self.scores[0] >= WINNING_SCORE:
            return 1 - self.turn
        return None


class DiracGame:
    BOARD_SIZE = 10

    def __init__(self, start_one, start_two, die):
        game_state = GameState((start_two, start_one), (0, 0), 0)
        self._game_states = defaultdict(int)
        self._game_states[game_state] = 1
        self._die = die

    def play(self):
        moving = True
        while moving:
            moving = self.move(self._die)

    def move(self, die):
        moving = False
        moved_games = defaultdict(int)
        for game_state, count in self._game_states.items():
            if game_state.winner is not None:
                moved_games[game_state] += count
            else:
                moving = True
                for roll in die.roll():
                    moved_game_state = self._step(game_state, roll)
                    moved_games[moved_game_state] += count
        self._game_states = moved_games
        return moving

    def _step(self, game_state, roll):
        new_position = (self._modulo_board_size(game_state.positions[1] + roll), game_state.positions[0])
        new_scores = (game_state.scores[1] + new_position[0], game_state.scores[0])
        return GameState(positions=new_position, scores=new_scores, turn=1-game_state.turn)

    def _modulo_board_size(self, position):
        return (position - 1) % self.BOARD_SIZE + 1

    def evaluate(self):
        counts = [0] * 2
        for game_state, count in self._game_states.items():
            counts[game_state.winner] += count

        return counts