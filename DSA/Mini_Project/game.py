import pygame
import random
import sys

# Initialize Pygame
pygame.init()

# Set up the display
WIDTH, HEIGHT = 800, 800
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Snake and Ladder Board")

# Define colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Block size (assuming 5x5 board)
BLOCK_SIZE = min(WIDTH, HEIGHT) // 5
# Player dot size (adjust as needed)
PLAYER_DOT_SIZE = 20

# Load custom block images (ensure correct image paths)
custom_block_images = {
    2: pygame.image.load(r"C:\Users\ADMIN\Programs\abc.png").convert_alpha(),  # Replace with actual path
    4: pygame.image.load(r"C:\Users\ADMIN\Programs\1.jpg").convert_alpha()   # Replace with actual path
}

# Ensure images are smaller than block size
for position, image in custom_block_images.items():
    if image.get_width() > BLOCK_SIZE - 10 or image.get_height() > BLOCK_SIZE - 10:
        image = pygame.transform.scale(image, (BLOCK_SIZE - 10, BLOCK_SIZE - 10))

# Load default block image and player dot (ensure correct image paths)
default_block_image = pygame.image.load(r"C:\Users\ADMIN\Programs\abc.png").convert_alpha()
player_dot = pygame.image.load(r"C:\Users\ADMIN\Programs\player.png").convert_alpha()

# Dice image size recommendation (adjust as needed)
dice_image_size = (100, 100)  # This is a suggestion, you can experiment

# Load dice images (ensure correct image paths)
dice_images = [
    pygame.image.load(r"C:\Users\ADMIN\Programs\1.jpg").convert_alpha(),
    pygame.image.load(r"C:\Users\ADMIN\Programs\2.jpg").convert_alpha(),
    pygame.image.load(r"C:\Users\ADMIN\Programs\3.jpg").convert_alpha(),
    pygame.image.load(r"C:\Users\ADMIN\Programs\4.png").convert_alpha(),
    pygame.image.load(r"C:\Users\ADMIN\Programs\5.png").convert_alpha(),
    pygame.image.load(r"C:\Users\ADMIN\Programs\6.png").convert_alpha()
]

# Ensure dice images are the recommended size or smaller
for image in dice_images:
    if image.get_width() > dice_image_size[0] or image.get_height() > dice_image_size[1]:
        image = pygame.transform.scale(image, dice_image_size)

# Game variables
player_position = 0  # Initial position
dice_value = 1  # Current dice roll

def handle_dice_roll():
    global dice_value
    dice_value = random.randint(1, 6)

# Example board layout with block numbers
board_size = 5  # 5x5 board
board = [i for i in range(board_size * board_size)]

def render_board(board):
    for idx, block in enumerate(board):
        row = idx // board_size
        col = idx % board_size
        block_rect = pygame.Rect(col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE)

        if block in custom_block_images:
            screen.blit(custom_block_images[block], block_rect)
        else:
            screen.blit(default_block_image, block_rect)

        # Draw player dot on current position
        if idx == player_position:
            player_dot_rect = player_dot.get_rect(center=block_rect.center)
            screen.blit(player_dot, player_dot_rect)

        # Draw block number
        font = pygame.font.SysFont(None, 30)
        text = font.render(str(block), True, BLACK)
        text_rect = text.get_rect(center=block_rect.center)
        screen.blit(text, text_rect)

# Main game loop
clock = pygame.time.Clock()
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                handle_dice_roll()
                player_position += dice_value
                if player_position >= len(board):
                    player_position = len(board) - 1

    screen.fill(WHITE)
    render_board(board)
    # Draw dice
    dice_rect = dice_images[dice_value - 1].get_rect(topleft=(WIDTH - dice_image_size[0], 50))
    screen.blit(dice_images[dice_value - 1], dice_rect)
    pygame.display.flip()
    clock.tick(60)  # Limit frame rate to 60 FPS
