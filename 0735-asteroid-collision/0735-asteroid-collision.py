class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for asteroid in asteroids:
            while stack and asteroid < 0 < stack[-1]:
                top_asteroid = stack[-1]
                if abs(top_asteroid) > abs(asteroid):
                    break
                elif abs(top_asteroid) < abs(asteroid):  
                    stack.pop()
                    continue
                else:
                    stack.pop()
                    break
            else:
                stack.append(asteroid)

        return stack

        