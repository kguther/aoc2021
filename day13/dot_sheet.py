import numpy as np

from fold_matrix_factory import FoldMatrixFactory


class DotSheet:
    def __init__(self, dots):
        self._dot_matrix = np.zeros([dots.size_y(), dots.size_x()])
        for dot in dots.coordinates:
            self._dot_matrix[dot[1]][dot[0]] = 1

        self._setup_factory()

    def _setup_factory(self):
        self.matrix_factory = FoldMatrixFactory(self._dot_matrix.shape)

    def fold(self, fold_instruction):
        if fold_instruction.axis == "x":
            fold_matrix = self.matrix_factory.x_fold_matrix(fold_instruction.position)
            new_dot_matrix = np.matmul(self._dot_matrix, fold_matrix)
        else:
            fold_matrix = self.matrix_factory.y_fold_matrix(fold_instruction.position)
            new_dot_matrix = np.matmul(fold_matrix, self._dot_matrix)

        self._dot_matrix = new_dot_matrix
        self._setup_factory()

    def number_of_dots(self):
        return np.count_nonzero(self._dot_matrix)

    def output(self):
        output_string = ""
        for i in range(self._dot_matrix.shape[0]):
            for j in range(self._dot_matrix.shape[1]):
                if self._dot_matrix[i][j] > 0:
                    output_string += "#"
                else:
                    output_string += "."
            output_string += "\n"

        return output_string
