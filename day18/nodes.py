import uuid
from abc import ABC, abstractmethod


class Node(ABC):
    def __init__(self, parent):
        self.parent = parent
        self.id = uuid.uuid4()

    @property
    @abstractmethod
    def subnodes(self):
        ...

    @property
    @abstractmethod
    def magnitude(self):
        ...

    @abstractmethod
    def copy(self):
        ...

    @property
    def direction(self):
        if self.parent and self.parent.subnodes:
            if self == self.parent.subnodes[0]:
                return 0
            return 1
        return None

    def __eq__(self, other):
        return self.id == other.id


class ValueNode(Node):
    def __init__(self, parent, value):
        super().__init__(parent)
        self.value = value

    @property
    def subnodes(self):
        return []

    @property
    def magnitude(self):
        return self.value

    def copy(self):
        return ValueNode(parent=self.parent, value=self.value)


class PairNode(Node):
    def __init__(self, parent):
        super().__init__(parent)
        self.pair = []

    @property
    def subnodes(self):
        return self.pair

    @property
    def magnitude(self):
        return 3 * self.subnodes[0].magnitude + 2 * self.subnodes[1].magnitude

    def copy(self):
        new_node = PairNode(parent=self.parent)
        copy_pair = [node.copy() for node in self.pair]
        for node in copy_pair:
            node.parent = new_node
        new_node.pair = copy_pair
        return new_node


def replace_node(node, new_node):
    direction = node.direction
    node.parent.subnodes[direction] = new_node

