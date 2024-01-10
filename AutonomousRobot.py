'''You are given an input string that controls the movement of a robot, "F" means take a step forward, "L" means turn 90 degrees to the left and "R" means turn 90 degrees to the right. E.g. "FLF" moves the robot one step forward, then turns it left by 90 degrees, then moves the robot one step forward. Write a function that returns the minimum number of commands that the robot needs to return to its starting point after following all the input commands. You should ignore any characters that are not capital F, L, or R. Hint: you may wish to track the robot's position using (X,Y) coordinates, assuming it starts at (0,0).

For example:

"RF" returns 3 (robot must turn twice and move forward one step (eg. "RRF")
"LFRFRFR" returns 1 (robot must step forward to return)
"FxLxLxFx" returns 0 (robot is already back at its starting point)
[execution time limit] 4 seconds (py3)

[memory limit] 1 GB

[input] string directions

The directions for the robot

[output] integer

The number of commands needed to return to the starting point'''


#Solution
'''Note: Code is current not a complete solution. Only passed 9/10 test cases. Failed testcase: "FRFR"'''

import math

def solution(directions):
    angle = math.pi/2
    x = 0
    y = 0
    ans = 0
    i = 0
    
    for i in directions:
        if i == "F":
            y += math.sin(angle)
            x += math.cos(angle)
        elif i == "L":
            angle += math.pi/2
        elif i == "R":
            angle -= math.pi/2
    angle = angle % (2*math.pi)
    
    
    x =round(x)
    y = round(y)
    distance_x = -x
    distance_y = -y
    if x == 0 and y ==0:
        return 0
    elif x==0:
        if y < 0:
            ans = abs(y) + 2 * int(abs(angle - math.pi/2)/math.pi)
        else:
            ans = abs(y) + 2 * int(abs(angle -3* math.pi/2) / math.pi)
        return ans
    elif y == 0:
        if x < 0:
            ans = abs(x) + 2 * int(abs(angle)/math.pi)
        else:
            ans = abs(x) + 2 * int(abs(angle - math.pi) / math.pi)
    else:
        if (x > 0 and angle == math.pi):
            ans = 1 + abs(x) + abs(y)
        elif (y > 0 and angle == -math.pi/2):
            ans = 1+abs(x)+abs(y)
        elif (x<0 and angle == 0):
            ans = 1 +abs(x) + abs(y)
        elif (y<0 and angle == math.pi/2):
            ans = 1 + abs(x) + abs(y)
        else:
            ans = 2+abs(x) +abs(y)
            
    
    return ans