import numpy

from bingo import BingoBoard


def read_draws(line):
    return list(map(int, line.rstrip().split(",")))


def read_board(filestream):
    board_values = []
    for i in range(5):
        row = filestream.readline().rstrip().split()
        board_values.append([int(val) for val in row])
    return BingoBoard(numpy.array(board_values))


def read_input(filename):
    boards = []
    with open(filename, "r") as bg:
        draws = read_draws(bg.readline())
        while bg.readline():
            boards.append(read_board(bg))
    return boards, draws