import numpy as np


class FoldMatrixFactory:
    def __init__(self, shape):
        self.size_x = shape[1]
        self.size_y = shape[0]

    def x_fold_matrix(self, axis_coordinate):
        fold_matrix = self._build_fold_matrix(self.size_x, axis_coordinate)

        return fold_matrix

    def _build_fold_matrix(self, size, axis_coordinate):
        fold_matrix = np.eye(size, axis_coordinate)
        for i in range(size-axis_coordinate-1):
            if axis_coordinate-i > 0:
                fold_matrix[axis_coordinate+i+1][axis_coordinate-i-1] = 1

        return fold_matrix

    def y_fold_matrix(self, axis_coordinate):
        fold_matrix = self._build_fold_matrix(self.size_y, axis_coordinate)
        return fold_matrix.transpose()
