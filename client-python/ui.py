import client as c
from tkinter import *
from PIL import ImageTk,Image

 
window = Tk()
window.title("Unscramble")

def createLetterInput():
  letters_text = Label(window, width=20, height=1, text = "Enter Letters:")
  letters_text.grid(column=0, row=0)
  letters_input = Entry(window,width=20)
  letters_input.grid(column=1, row=0)
  return letters_input

def createMaskInput():
  mask_text = Label(window, width=20, height=1, text = "Enter Mask:")
  mask_text.grid(column=0, row=1)
  mask_input = Entry(window, width=20)
  mask_input.grid(column=1, row=1)
  return mask_input

def createShowButton():
  btn = Button(window, text="Show Words", command=clicked)
  btn.grid(columnspan=2, row=2)

def clicked():
  l         = letters.get()
  m         = mask.get()

  if l == "":
    word_area.delete(1.0, END)
    word_area.insert(END,"Insert Letters!")
  elif m == "":
    word_area.delete(1.0, END)
    word_area.insert(END,"Insert Mask!")
  else:
    words     = c.getWords(l, m)
    word_area.delete(1.0, END)
    for word in words:
      word_area.insert(END, word + "\n")

def createShowWordsArea():
  word_frame = Frame(window)
  word_frame.grid(columnspan=2, row=3)

  word_area = Text(word_frame, height=10, width=40)
  word_area.pack(side='left', fill='both', expand=True)

  scrollbar = Scrollbar(word_frame)
  word_area.config(yscrollcommand= scrollbar.set)
  scrollbar.config(command= word_area.yview)
  scrollbar.pack(side='right', fill='y')

  return word_area

letters   = createLetterInput()
mask      = createMaskInput()
button    = createShowButton()
word_area = createShowWordsArea()




window.mainloop()