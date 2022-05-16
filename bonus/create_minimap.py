#!/usr/bin/env python3

import numpy as np
import scipy.misc as smp
from PIL import Image
import sys
import random

img_size = 100
map_length = 100
pix_square = int(img_size / map_length)

def create_square(pos, color, data):
    i = 0
    j = 0
    for y in range(pix_square):
        for x in range(pix_square):
            i = y + pos[1]
            j = x + pos[0]
            data[i][j] = color

def create_img(tab, file):
    color = [0, 0, 0]
    data = np.zeros((img_size, img_size, 3), dtype=np.uint8)
    for y in range(map_length):
        for x in range(map_length):
            if tab[x][y] == 2: color = [230 + random.randint(0, 20), 230 + random.randint(0, 20), 230 + random.randint(0, 20)]
            elif tab[x][y] == 1: color = [50, random.randint(235, 255), 50]
            else: color = [50, 50, random.randint(235, 255)]
            create_square([x * pix_square, y * pix_square], color, data)
    img = smp.toimage(data)
    img = np.flip(img, 1)
    smp.imsave("saved_minimap.png", img)
    img = Image.open("saved_minimap.png")
    img = img.rotate(90)
    img.save("saved_minimap.png", "PNG")


def get_file_content(file):
    try:
        f = open(file, 'r')
        if f.mode == 'r':
            return f.read()
    except ValueError:
        print(ValueError)
        return None

def main():
    k = 1
    file = input("Enter file path: ")

    if file == None:
        sys.exit(84)
    content = get_file_content(file)
    list = content.split()
    tab = [None] * map_length
    for i in range(map_length):
        tab[i] = [None] * map_length
    for i in range(map_length):
        for j in range(map_length):
            if float(list[k]) > 150: tab[i][j] = 2
            elif float(list[k]) > 100: tab[i][j] = 1
            else: tab[i][j] = 0
            k += 1
    create_img(tab, file)

main()
