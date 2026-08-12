'''
    3 parts:
    - check rows
    - check columns
    - check 3x3s

    vector<bool> (9) - validate no repeats

    return false if already visited

    row:
    2 for loops:
    for i++
    reset count vec
    j++: 
    vec[board[i][j]] = visited

    col:
    vec[board[j][i]] = visited

    3x3:

'''

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            v1, v2, v3 = [False] * 9, [False] * 9, [False] * 9
            for j in range(9):
                # check row
                r = board[i][j]
                if r == '.':
                    pass
                elif v1[int(r) - 1]:
                    return False
                else:
                    v1[int(r) - 1] = True

                # check col
                c = board[j][i]
                if c == '.':
                    pass
                elif v2[int(c) - 1]:
                    return False
                else:
                    v2[int(c) - 1] = True
                
                # check 3x3 grid
                g = board[(3 * (i // 3)) + (j // 3)][(3 * (i % 3)) + (j % 3)]
                if g == '.':
                    pass
                elif v3[int(g) - 1]:
                    return False
                else:
                    v3[int(g) - 1] = True

        return True

