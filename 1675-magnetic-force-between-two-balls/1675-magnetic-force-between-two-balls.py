class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        def canPlaceBalls(min_force):

            count = 1
            last_pos = position[0]
            
            for i in range(1, len(position)):
                if position[i] - last_pos >= min_force:
                    count += 1
                    last_pos = position[i]
                if count >= m:
                    return True
            return False

        low = 1
        high = position[-1] - position[0]
        best = 0
        
        while low <= high:
            mid = (low + high) // 2
            if canPlaceBalls(mid):
                best = mid
                low = mid + 1
            else:
                high = mid - 1
        
        return best


        