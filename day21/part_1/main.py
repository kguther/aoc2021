from det_die import DetDie
from game_board import GameBoard


def main():
    game_board = GameBoard(5, 9, die=DetDie(), score=1000)
    score = game_board.play()
    print(f"Final score is {score}")

if __name__ == "__main__":
    main()
