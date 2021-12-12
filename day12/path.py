from dataclasses import dataclass
from typing import List


@dataclass(frozen=True)
class Path:
    caves: List[str]
    small_revisit: bool = False

    @property
    def current_cave(self):
        return self.caves[-1]

    def expand(self, cave):
        small_revisit = self.small_revisit
        if not cave.isupper() and cave in self.caves:
            small_revisit = True

        return Path(self.caves + [cave], small_revisit=small_revisit)

