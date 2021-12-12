from collections import defaultdict


class PathList:
    def __init__(self):
        self._paths = defaultdict(list)

    def add_path(self, path):
        self._paths[path.current_cave].append(path)

    def get_paths_to_cave(self, cave):
        if cave in self._paths:
            return self._paths[cave]
        return []

    def not_empty(self):
        return bool(self._paths)