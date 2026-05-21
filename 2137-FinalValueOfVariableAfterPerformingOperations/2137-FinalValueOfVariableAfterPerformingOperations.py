# Last updated: 5/20/2026, 11:36:06 PM
class Solution:
    
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        x = 0
        increment_operations = ["++X","X++"]
        decrement_operations = ["--X","X--"]
        for op in operations:
            if op in increment_operations:
                x+=1
            elif op in decrement_operations:
                x-=1
        return x
        
