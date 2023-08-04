class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        t = sorted(zip(names, heights), key=lambda x: (-x[1], x[0]))
        return [x[0] for x in t]
