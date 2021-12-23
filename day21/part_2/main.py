
from dirac_die import DiracDie
from game_board import DiracGame


def main():
    game_board = DiracGame(5, 9, die=DiracDie())
    game_board.play()
    wins = game_board.evaluate()
    print(f"Wins per player {wins}")

if __name__ == "__main__":
    main()
