class Node:
    def __init__(self, data):
        self.left_child = None
        self.right_child = None
        self.parent_node = data

    # print function
    def print_tree(self):
        # if there is no left_child then don't print
        if self.left_child:
            self.left_child.print_tree()

        # print parent_node at the center
        print(self.parent_node)

        # if there is no right_child then don't print
        if self.right_child:
            self.right_child.print_tree()

    def insert_number(self, input_number):
        # Compare the new value with the parent node
        if self.parent_node:
            # if input number less than parent node, then it is on the left
            if input_number < self.parent_node:
                if self.left_child is None:
                    self.left_child = Node(input_number)
                else:
                    self.left_child.insert_number(input_number)

            # if input number greater than parent node, then it is on the right
            elif input_number > self.parent_node:
                if self.right_child is None:
                    self.right_child = Node(input_number)
                else:
                    self.right_child.insert_number(input_number)
        else:
            self.parent_node = input_number


root = Node(69)
root.insert_number(39)
root.insert_number(79)
root.insert_number(68)
root.insert_number(75)
root.insert_number(30)
root.insert_number(80)

root.print_tree()
