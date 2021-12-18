from nodes import PairNode, ValueNode
from tree_number import TreeNumber


def parse_tree_number(string):
    current_node = None
    for char in string:
        if char == "[":
            current_node = add_node(current_node)
        if char == "]":
            if current_node.parent:
                current_node = current_node.parent
            else:
                break
        if char in [str(i) for i in range(10)]:
            current_node.pair.append(ValueNode(parent=current_node, value=int(char)))
    return TreeNumber(current_node)


def add_node(current_parent):
    current_node = PairNode(parent=current_parent)
    if current_parent is not None:
        current_parent.pair.append(current_node)
    return current_node


