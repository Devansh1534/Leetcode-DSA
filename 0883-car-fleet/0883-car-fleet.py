class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [(pos, (target - pos) / spd) for pos, spd in zip(position, speed)]
        cars.sort(reverse=True, key=lambda x: x[0])
        fleets = 0
        max_time = 0
        for pos, time in cars:
            if time > max_time:
                max_time = time
                fleets += 1
        
        return fleets
