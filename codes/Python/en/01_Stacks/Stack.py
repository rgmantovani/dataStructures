# ---------------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------------

class Stack:

    # initialize stack
    def __init__(self):
        self.items = []

    # is empty?
    def isEmpty(self):
        return self.items == []

    # push an element
    def push(self, item):
        self.items.append(item)

    # pop an element
    def pop(self):
        return self.items.pop()

    # checks top value
    def top(self):
        return self.items[len(self.items)-1]

    # stacks size
    def size(self):
        return len(self.items)

    # print stack content
    def __str__(self):
        return str(self.items)

# ---------------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------------
