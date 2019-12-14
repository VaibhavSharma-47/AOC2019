from PIL import Image
str = "111101000111100100001001000010100011001010000100100010001010111001000011110010000010010010100001001010000001001001010000100101111000100111001111010010"
matrix = [1]*6*25

print(matrix)
for x in range(6):
    for y in range(25):
        matrix[x*25 + y]=int(str[x*25 + y])
print(matrix)
img = Image.new('RGB', (25, 6), "white")  # <--
# OR  Image.new('RGB', img1.size, "white")
cmap = {1: (255,255,255),
        0: (0,0,0),
        2: (127,127,127)}
data = [cmap[i] for i in matrix]
img.putdata(data)
img.show()
img.save('Image2.png')