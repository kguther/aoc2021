from collections import defaultdict

from path import Path
from path_list import PathList

END_CAVE = "end"
START_CAVE = "start"


class PathMapper:
    def __init__(self, connections, revisitor_condition):
        self._connections = connections
        self.possible_paths = []
        self._revisitor_condition = revisitor_condition

    def expand_paths(self, paths):
        expanded_paths = PathList()
        for connection in self._connections:
            candidates = paths.get_paths_to_cave(connection.origin)
            for path in candidates:
                if self._revisitor_condition(connection, path):
                    expanded_paths.add_path(path.expand(connection.target))

        self.possible_paths += expanded_paths.get_paths_to_cave(END_CAVE)
        return expanded_paths
