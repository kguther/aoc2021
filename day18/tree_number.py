from math import ceil, floor

from nodes import ValueNode, replace_node, PairNode


class TreeNumber:
    def __init__(self, parent_node):
        self.parent_node = parent_node
        self._reducing = False
        self.reduce()

    def reduce(self):
        self._reducing = True
        while self._reducing:
            self._reducing = False
            self._check_explosion()
            self._check_split()

    def _check_explosion(self):
        self._check_node_explosion(self.parent_node)

    def _check_node_explosion(self, node):
        if self._reducing:
            return
        if self._nesting_level(node) == 4 and node.subnodes:
            self._explode(node)
        else:
            for node in node.subnodes:
                self._check_node_explosion(node)

    def _explode(self, node):
        for direction in [0, 1]:
            next_value_node = self._next_value_node(node, direction)
            if next_value_node:
                next_value_node.value += node.subnodes[direction].value
        replace_node(node, ValueNode(parent=node.parent, value=0))
        self._reducing = True

    def _check_split(self):
        self._check_node_split(self.parent_node)

    def _check_node_split(self, node):
        for s_node in node.subnodes:
            if self._reducing:
                return
            if not s_node.subnodes and s_node.value > 9:
                self._split(s_node)
            self._check_node_split(s_node)

    def _split(self, node):
        new_node = PairNode(parent=node.parent)
        new_node.pair.append(ValueNode(parent=new_node, value=floor(node.value / 2)))
        new_node.pair.append(ValueNode(parent=new_node, value=ceil(node.value / 2)))
        replace_node(node, new_node)
        self._reducing = True

    def _nesting_level(self, node):
        parent_node = node.parent
        nesting_level = 0
        while parent_node:
            parent_node = parent_node.parent
            nesting_level += 1
        return nesting_level

    def _next_value_node(self, source_node, direction):
        node = source_node
        while node:
            if not node.parent:
                return None
            if node.parent.subnodes[direction] == node:
                node = node.parent
            else:
                node = node.parent.subnodes[direction]
                break

        return self._next_value_subnode(node, 1-direction)


    def _next_value_subnode(self, node, direction):
        while node.subnodes:
            node = node.subnodes[direction]
        return node

    def magnitude(self):
        return self.parent_node.magnitude

    def __add__(self, other):
        new_parent_node = PairNode(parent=None)
        left_base = self.parent_node.copy()
        right_base = other.parent_node.copy()
        new_parent_node.pair = [left_base, right_base]
        right_base.parent = new_parent_node
        left_base.parent = new_parent_node
        return TreeNumber(new_parent_node)


def print_tree_number(tree_number):
    node = tree_number.parent_node
    print(node_to_string(node))


def node_to_string(node):
    string = ""
    if node.subnodes:
        string += "["
        for node in node.subnodes:
            string += node_to_string(node)
        string += "]"
    else:
        string += str(node.value) + ","
    return string