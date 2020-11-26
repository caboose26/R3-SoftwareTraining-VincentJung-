import pygame
import random

# set up pygame window
WIDTH = 800
HEIGHT = 800
FPS = 30

# Define colours
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)


# initalise Pygame
pygame.init()
pygame.mixer.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Grid/Maze")
clock = pygame.time.Clock()
screen.fill(WHITE)
# setup maze
n = 20
x = 0                    
y = 0                    
w = WIDTH/(n)
h = HEIGHT/(n)

grid = []
visited = []
stack = []



#grid
def creategrid(x, y, w, h):
    for i in range(n):
        x = 0                                                       
        for j in range(n):
            pygame.draw.line(screen, BLACK, [x, y], [x + w, y])           
            pygame.draw.line(screen, BLACK, [x + w, y], [x + w, y + h])   
            pygame.draw.line(screen, BLACK, [x + w, y + h], [x, y + h])   
            pygame.draw.line(screen, BLACK, [x, y + h], [x, y])           
            grid.append((x,y))                                           
            x = x + w                                                   
        y = y + h


def push_up(x, y):
    pygame.draw.rect(screen, WHITE, (x + 1, y - w + 1, int(w-1), int((h*2)-1)), 0)       
    pygame.display.update()                                              


def push_down(x, y):
    pygame.draw.rect(screen, WHITE, (x +  1, y + 1, int(w-1), int((h*2)-1)), 0)
    pygame.display.update()


def push_left(x, y):
    pygame.draw.rect(screen, WHITE, (x - w +1, y +1, int((w*2)-1), int(h-1)), 0)
    pygame.display.update()


def push_right(x, y):
    pygame.draw.rect(screen, WHITE, (x +1, y +1, int((w*2)-1), int(h-1)), 0)
    pygame.display.update()


def single_cell( x, y):
    pygame.draw.rect(screen, BLUE, (x +1, y +1, int(w-2), int(h-2)), 0)          
    pygame.display.update()


def backtracking_cell(x, y):
    pygame.draw.rect(screen, WHITE, (x +1, y +1, int(w-2), int(h-2)), 0)        
    pygame.display.update()                                        

                                        

def create_maze(x,y):
    single_cell(x, y)                                              
    stack.append((x,y))                                            
    visited.append((x,y))                                          
    while len(stack) > 0:                                          
        cell = []                                                  
        if (x + w, y) not in visited and (x + w, y) in grid:       
            cell.append("right")                                   

        if (x - w, y) not in visited and (x - w, y) in grid:       
            cell.append("left")

        if (x , y + h) not in visited and (x , y + h) in grid:     
            cell.append("down")

        if (x, y - h) not in visited and (x , y - h) in grid:      
            cell.append("up")

        if len(cell) > 0:                                          
            cell_chosen = (random.choice(cell))                    

            if cell_chosen == "right":                             
                push_right(x, y)                                   
                                        
                x = x + w                                          
                visited.append((x, y))                              
                stack.append((x, y))                                

            elif cell_chosen == "left":
                push_left(x, y)
                
                x = x - w
                visited.append((x, y))
                stack.append((x, y))

            elif cell_chosen == "down":
                push_down(x, y)
                
                y = y + h
                visited.append((x, y))
                stack.append((x, y))

            elif cell_chosen == "up":
                push_up(x, y)
                
                y = y - h
                visited.append((x, y))
                stack.append((x, y))
        else:
            x, y = stack.pop()                                    
            single_cell(x, y)                                      
            backtracking_cell(x, y)                              


                   
creategrid(x, y, w, h)            
create_maze(x,y)               




running = True
while running:
    # keep running at the at the right speed
    clock.tick(FPS)
    # process input (events)
    for event in pygame.event.get():
        # check for closing the window
        if event.type == pygame.QUIT:
            running = False
            
pygame.quit()
