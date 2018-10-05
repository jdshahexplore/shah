from tkinter import *

def allclear():
    print("all clear");

def clear():
    print("clear");

def module():
    print("module");

def divide():
    print("divide");
    
calc=Tk()
calc.geometry("400x500")
calc.title("Calculator")
calc.configure(bg="gray")

equation=StringVar()
res=Entry(calc, textvariable=equation, height=1, width=5)
res.grid(columnspan=4)
acl=Button(calc, text="AC", font=("Serif",20), bg="black", fg="white", command=allclear, height=1, width=5)
acl.grid(row=2,column=0)
cl=Button(calc, text="C", font=("Serif",20), bg="black", fg="white", command=clear, height=1, width=5)
cl.grid(row=2,column=1)
mod=Button(calc, text="%", font=("Serif",20), bg="black", fg="white", command=module, height=1, width=5)
mod.grid(row=2,column=2)
div=Button(calc, text="/", font=("Serif",20), bg="black", fg="white", command=divide, height=1, width=5)
div.grid(row=2,column=3)

calc.mainloop()
