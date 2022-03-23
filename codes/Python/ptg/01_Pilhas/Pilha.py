# ---------------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------------

class Pilha:

    # initialize pilha
    def __init__(self):
        self.items = []

    # is empty?
    def estaVazia(self):
        return self.items == []

    # insere um elemento
    def push(self, item):
        self.items.append(item)

    # remove um elemento
    def pop(self):
        return self.items.pop()

    # checa o valor do topo
    def topo(self):
        return self.items[len(self.items)-1]

    # tamanho da pilha
    def tamanho(self):
        return len(self.items)

    # imprime conteudo da pilha
    def __str__(self):
        return str(self.items)

# ---------------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------------
