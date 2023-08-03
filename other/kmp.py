def kmp(text: str, pattern: str) -> int:
    n, m = len(text), len(pattern)
    next = get_next(pattern)
    i, j = 0, 0
    while i < n and j < m:
        if j == -1 or text[i] == pattern[j]:
            i += 1
            j += 1
        else:
            j = next[j]
    if j == m:
        return i - j
    else:
        return -1


def get_next(pattern: str) -> int:
    m = len(pattern)
    next = [0] * m
    next[0] = -1
    i, j = 0, -1
    while i < m - 1:
        if j == -1 or pattern[i] == pattern[j]:
            print(i, j)
            i += 1
            j += 1
            next[i] = j
        else:
            j = next[j]
    return next


if __name__ == "__main__":
    res = kmp("abddsaefjkla;", "ddsa")
    print(res)
