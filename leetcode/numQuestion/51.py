'''
N皇后问n题，给定一个n，返回所有不同的解决方案
即，在 n * n 的棋盘上，放置 n 个皇后，使每横行，每竖列，每斜行都只有一个皇后
'''

# version_1 use arrays to record

from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def generateBoard() -> List :
            board = list()
            for i in range(n):
                row[queens[i]] = "Q"
                board.append("".join(row))
                row[queens[i]] = "."
            return board

        def backtrack(row: int):
            if row == n:
                board = generateBoard()
                solutions.append(board)
            else:
                for i in range(n):
                    if i in columns or row - i in diagonal1 or  row + i in diagonal2:
                        continue
                    queens[row]  = i 
                    columns.add(i)
                    diagonal1.add(row - i)
                    diagonal2.add(row + i)
                    backtrack(row + 1)
                    columns.remove(i)
                    diagonal1.remove(row - i)
                    diagonal2.remove(row + i)

        solutions = list()
        queens = [-1] * n 
        columns = set()
        diagonal1 = set()
        diagonal2 = set()
        row = ["."] * n
        backtrack(0)
        return solutions 



# version_2 use bit operation to record
class Solution:
    def solveNQueens_bit(self, n: int) -> List[List[str]]:
        def generateBoard():
            board = list()
            for i in range(n):
                row[queens[i]] = "Q"
                board.append("".join(row))
                row[queens[i]] = "."
            return board 
        
        def solve(row: int, columns: int, diagonals1: int, diagonals2: int):
            if row == n:
                board = generateBoard()
                solutions.append(board)
            else:
                availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonal2))
                while availablePositions:
                    position = availablePositions & (~availablePositions)
                    availablePositions = availablePositions & (availablePositions - 1)
                    column = bin(position - 1).count("1")
                    queens[row] = column 
                    solve(row + 1, columns | position, (diagonal1 | position) << 1, (diagonal2 | position) >> 1)
    
    solutions = list()
    queens = [-1] * n 
    row = ["."] * n 
    solve(0, 0, 0, 0)
    return solutions


if __name__ == "__main__":
    s = Solution()
    print(s.solveNQueens(4))