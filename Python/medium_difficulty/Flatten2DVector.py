class Vector2D:
    def __init__(self, vec: List[List[int]]):
        self._flattened_list = []
        self._ptr = 0

        for l in vec:
            self._flattened_list.extend(l)

        self._size = len(self._flattened_list)

    def next(self) -> int:
        next_el = self._flattened_list[self._ptr]
        self._ptr += 1
        return next_el

    def hasNext(self) -> bool:
        return self._ptr != self._size
        


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(vec)
# param_1 = obj.next()
# param_2 = obj.hasNext()