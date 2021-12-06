from io_handler import read_input


def bingo_game(filename):
    boards, draws = read_input(filename)
    for draw in draws:
        for board in boards:
            board.mark_number(draw)
            if board.bingo():
                boards.remove(board)

def main():
    winner_points = bingo_game("input")
    print(f"Winner has {winner_points} points")

if __name__ == "__main__":
    main()