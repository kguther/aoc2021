from io_handler import read_input


def bingo_game(filename):
    boards, draws = read_input(filename)
    board_counter = 1
    for draw in draws:
        for board in boards:
            board.mark_number(draw)
            if board.bingo():
                if board_counter == len(boards) and not board.has_won:
                    return board.points(draw)
                elif not board.has_won:
                    board_counter += 1
                    board.win()

def main():
    winner_points = bingo_game("input")
    print(f"Winner has {winner_points} points")

if __name__ == "__main__":
    main()