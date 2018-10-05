from tkinter import *
from tkinter import filedialog
from tkinter import Menu
def eventoccur():
    lbl.configure(text="Button was Clicked!!")

def openfile():
    file = filedialog.askopenfilename()

window=Tk()
window.title("ATM Simulator System")
window.geometry('400x200')
lbl = Label(window, text="Hello", font=("Arial Bold",20))
lbl.grid(column=0, row=0)
btn = Button(window, text="Click Me", bg="orange", fg="blue", command=eventoccur)
btn.grid(column=1, row=0)
menu = Menu(window)
new_item = Menu(menu)
new_item.add_command(label='open', command=openfile)
menu.add_cascade(label='File', menu=new_item)
window.config(menu=menu)
window.mainloop()
