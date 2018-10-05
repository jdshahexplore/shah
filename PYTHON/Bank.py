#random class for generating random number

import os
import random
import pickle
import getpass

#Class for storing account details
class Bank:
    #This function displays a form for new customer
    def getdata(self):
        self.Name=input("Enter Account Holder Name\t:\t")
        self.Address=input("Enter Address\t\t\t:\t")
        self.Mobile=input("Enter Mobile Number\t\t:\t")
        self.Branch=input("Enter Branch Name\t\t:\t")
        self.Acctype=input("Enter Account type(S/C)\t\t:\t")
        self.Balance=input("Enter Balance\t\t\t:\t")
        self.Accno=str(20180000+random.randint(1,9999))
        self.Cardno=str(81020000+random.randint(1,9999))
        self.Cvv=str(random.randint(100,999))
        self.Pin=str(random.randint(1000,9999))

    #This function writes the details of customer in file
    def putfile(self):
        while os.path.exists(self.Accno):
            self.Accno=str(random.randint(1,9999))
        fout=open(self.Accno,"wb")
        pickle.dump(self,fout)
        fout.close()
        print("\n--------Account Created Successfully--------\n")
        ch=getpass.getpass("\nPress Enter\n")
        os.system('cls')
        print("\n--------------Your Credentials--------------\n")
        print("\t\tYour Account No\t:\t",self.Accno)
        print("\t\tYour Card No\t:\t",self.Cardno)
        print("\t\tYour CVV No\t:\t",self.Cvv)
        print("\t\tYour Pin No\t:\t",self.Pin)
        ch=getpass.getpass("\n\t\t\tPress Enter\n")
        os.system('cls')

#This function displays details of requested user
def putdata(acc):
    if os.path.exists(acc):
        fin=open(acc,"rb")
        b=Bank()
        b=pickle.load(fin)
        fin.close()
        pin=getpass.getpass("Enter Pin No\t\t:\t")
        os.system('cls')
        if(pin==b.Pin):
            print("Account Holder Name\t:\t",b.Name)
            print("Resident Address\t:\t",b.Address)
            print("Mobile Number\t\t:\t",b.Mobile)
            print("Bank Branch Name\t:\t",b.Branch)
            print("Account Balance\t\t:\t",b.Balance)
            print("Type of Account\t\t:\t",b.Acctype)
        else:
            print("Pin is invalid")
    else:
        print("Customer doesn't exist");
    ch=getpass.getpass("\n\t\t\tPress Enter\n")
    os.system('cls')

def menu():
    print("\n\n1: Add new Customer")
    print("2: Display Detail")

while True:
    menu()
    c=eval(input("Enter Choice : "))
    if (c==1):
        b1=Bank()
        b1.getdata()
        b1.putfile()
    elif (c==2):
        acc=input("\nEnter Account No\t:\t")
        putdata(acc)
    else:
        break;
