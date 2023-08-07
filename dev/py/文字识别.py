import pytesseract
from PIL import Image
fileName = input()
text = pytesseract.image_to_string(Image.open(fileName))
print(text)
